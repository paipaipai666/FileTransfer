#include "ServerHelper.h"
#include <QDataStream>
#include <QTcpServer>
#include <QHostAddress>
#include <QTcpSocket>
#include <QFileInfo>
#include <QElapsedTimer>

ServerHelper::ServerHelper() {};

int ServerHelper::SendFile(QString port, QString fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        emit transferFinished(false);
        return ErrorHandling("无法打开源文件");
    }

    // 建立服务器（复用地址）
    QTcpServer server;
    if (!server.listen(QHostAddress::Any, port.toUShort())) {
        file.close();
        emit transferFinished(false);
        return ErrorHandling("端口监听失败");
    }

    // 等待连接（带超时）
    if (!server.waitForNewConnection(30000)) {
        file.close();
        emit transferFinished(false);
        return ErrorHandling("等待客户端连接超时");
    }

    QTcpSocket* clientSocket = server.nextPendingConnection();
    clientSocket->setSocketOption(QAbstractSocket::LowDelayOption, 1);  // 禁用Nagle算法

    // 发送文件头
    QDataStream out(clientSocket);
    out.setVersion(QDataStream::Qt_5_15);
    out << file.size();
    clientSocket->waitForBytesWritten();

    // 分块发送数据
    qint64 bytesSent = 0;
    const qint64 chunkSize = 65536;  // 64KB块
    QByteArray sendBuffer;

    while (!file.atEnd()) {
        sendBuffer = file.read(chunkSize);
        qint64 bytesWritten = clientSocket->write(sendBuffer);
        
        if (bytesWritten == -1 || !clientSocket->waitForBytesWritten(30000)) {
            file.close();
            clientSocket->abort();
            emit transferFinished(false);
            return ErrorHandling("网络发送失败");
        }

        bytesSent += bytesWritten;
        
        // 控制进度更新频率
        static QElapsedTimer progressTimer;
        if (progressTimer.elapsed() > 100 || bytesSent == file.size()) {
            emit progressChanged(static_cast<int>((bytesSent * 100) / file.size()), bytesSent);
            progressTimer.restart();
        }
    }

    // 确保所有数据发送完成
    clientSocket->waitForBytesWritten();
    file.close();

    // 优雅关闭连接
    clientSocket->disconnectFromHost();
    if (clientSocket->state() != QAbstractSocket::UnconnectedState) {
        clientSocket->waitForDisconnected(1000);
    }

    emit progressChanged(100, file.size());
    emit transferFinished(true);
    return 0;
}