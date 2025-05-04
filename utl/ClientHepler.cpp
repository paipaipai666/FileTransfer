#include "ClientHelper.h"
#include <QDataStream>
#include <QTemporaryFile>
#include <QTcpSocket>
#include <QDir>

ClientHelper::ClientHelper() {};

int ClientHelper::RecvFile(QString IP, QString port, QString fileName) {
    // 准备接收目录
    QDir recvDir("received_files");
    if (!recvDir.exists()) {
        if (!recvDir.mkpath(".")) {
            return ErrorHandling("无法创建接收目录");
        }
    }
    
    QString savePath = recvDir.absoluteFilePath(QFileInfo(fileName).fileName());
    QTemporaryFile tempFile(savePath + ".XXXXXX");
    
    if (!tempFile.open()) {
        return ErrorHandling("无法创建临时文件");
    }

    // 建立连接
    QTcpSocket socket;
    socket.connectToHost(IP, port.toUShort());
    
    if (!socket.waitForConnected(5000)) {
        return ErrorHandling(QString("连接超时: %1").arg(socket.errorString()).toUtf8().constData());
    }

    // 接收文件头（文件大小）
    QDataStream in(&socket);
    in.setVersion(QDataStream::Qt_5_15);
    
    qint64 fileSize = 0;
    if (socket.bytesAvailable() < sizeof(qint64)) {
        if (!socket.waitForReadyRead(10000)) {
            return ErrorHandling("等待文件头超时");
        }
    }
    
    in >> fileSize;
    qDebug() << "待接收文件大小:" << fileSize << "字节";

    // 接收文件内容
    qint64 bytesReceived = 0;
    QByteArray buffer;
    
    while (bytesReceived < fileSize) {
        if (!socket.waitForReadyRead(30000)) { // 30秒超时
            tempFile.remove();
            return ErrorHandling("接收数据超时");
        }
        
        buffer = socket.read(qMin(fileSize - bytesReceived, (qint64)65536)); // 64KB缓冲区
        if (buffer.isEmpty()) {
            tempFile.remove();
            return ErrorHandling("接收空数据包");
        }
        
        qint64 bytesWritten = tempFile.write(buffer);
        if (bytesWritten != buffer.size()) {
            tempFile.remove();
            return ErrorHandling("写入文件失败");
        }
        
        bytesReceived += bytesWritten;
        emit progressChanged(static_cast<int>((bytesReceived * 100) / fileSize), bytesReceived);
    }

    tempFile.close();
    
    // 重命名为最终文件
    if (QFile::exists(savePath)) {
        QFile::remove(savePath);
    }
    
    if (!tempFile.copy(savePath)) {
        return ErrorHandling("文件重命名失败");
    }
    
    qDebug() << "文件接收完成，保存路径:" << QDir::toNativeSeparators(savePath);
    emit transferFinished(true);
    return 0;
}