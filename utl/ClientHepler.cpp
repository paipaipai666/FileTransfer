#include "ClientHelper.h"
#include <QApplication>
#include <QDataStream>
#include <QTemporaryFile>
#include <QTcpSocket>
#include <QDir>
#include <QThread>
#include <QtGlobal>

ClientHelper::ClientHelper() {};

int ClientHelper::RecvFile(QString IP, QString port, QString fileName) {
    // 初始化接收环境
    QTcpSocket socket;
    socket.setReadBufferSize(65536);  // 64KB缓冲区
    
    // 连接信号槽确保实时响应
    connect(&socket, &QTcpSocket::readyRead, [&](){
        qApp->processEvents();  // 保持UI响应
    });

    // 连接服务器（带超时和重试）
    for (int retry = 0; retry < 3; ++retry) {
        socket.connectToHost(IP, port.toUShort());
        if (socket.waitForConnected(3000)) break;
        if (retry == 2) {
            emit transferFinished(false);
            return ErrorHandling("连接服务器失败");
        }
        QThread::msleep(500);
    }

    // 接收文件头（带校验）
    QDataStream in(&socket);
    in.setVersion(QDataStream::Qt_5_15);
    
    qint64 fileSize = 0;
    QElapsedTimer headerTimer;
    headerTimer.start();
    
    while (socket.bytesAvailable() < sizeof(qint64)) {
        if (headerTimer.elapsed() > 10000) {
            socket.disconnectFromHost();
            emit transferFinished(false);
            return ErrorHandling("接收文件头超时");
        }
        socket.waitForReadyRead(500);
    }
    in >> fileSize;

    // 准备接收文件
    QTemporaryFile tempFile;
    if (!tempFile.open()) {
        socket.disconnectFromHost();
        emit transferFinished(false);
        return ErrorHandling("创建临时文件失败");
    }

    // 分块接收数据
    qint64 bytesReceived = 0;
    const qint64 chunkSize = 65536;  // 64KB块
    QByteArray receiveBuffer;
    receiveBuffer.reserve(chunkSize);

    while (bytesReceived < fileSize) {
        // 动态计算等待时间（最小100ms，最大5s）
        int waitTime = qBound((long long)100,5000 - bytesReceived / 1000,(long long) 5000);
        
        if (!socket.waitForReadyRead(waitTime)) {
            if (bytesReceived == fileSize) break;  // 可能刚好接收完成
            tempFile.remove();
            socket.disconnectFromHost();
            emit transferFinished(false);
            return ErrorHandling("数据接收超时");
        }

        // 精确控制读取量
        qint64 bytesToRead = qMin(chunkSize, fileSize - bytesReceived);
        receiveBuffer = socket.read(bytesToRead);
        
        if (receiveBuffer.isEmpty()) {
            tempFile.remove();
            socket.disconnectFromHost();
            emit transferFinished(false);
            return ErrorHandling("接收到空数据块");
        }

        // 写入文件
        qint64 bytesWritten = tempFile.write(receiveBuffer);
        if (bytesWritten != receiveBuffer.size()) {
            tempFile.remove();
            socket.disconnectFromHost();
            emit transferFinished(false);
            return ErrorHandling("文件写入失败");
        }

        bytesReceived += bytesWritten;
        
        // 进度更新（限制更新频率）
        static QElapsedTimer progressTimer;
        if (progressTimer.elapsed() > 100 || bytesReceived == fileSize) {
            emit progressChanged(static_cast<int>((bytesReceived * 100) / fileSize), bytesReceived);
            progressTimer.restart();
            qApp->processEvents();  // 确保UI更新
        }
    }

    // 验证文件完整性
    if (bytesReceived != fileSize) {
        tempFile.remove();
        socket.disconnectFromHost();
        emit transferFinished(false);
        return ErrorHandling("文件不完整");
    }

    // 保存最终文件
    QString savePath = QDir::currentPath() + "/received_files/" + QFileInfo(fileName).fileName();
    if (QFile::exists(savePath)) QFile::remove(savePath);
    
    if (!tempFile.copy(savePath)) {
        tempFile.remove();
        emit transferFinished(false);
        return ErrorHandling("文件保存失败");
    }

    socket.disconnectFromHost();
    emit progressChanged(100, fileSize);
    emit transferFinished(true);
    return 0;
}