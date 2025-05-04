#include "ServerHelper.h"
#include <QDataStream>
#include <QTcpServer>
#include <QHostAddress>
#include <QTcpSocket>
#include <QFileInfo>

ServerHelper::ServerHelper() {};

int ServerHelper::SendFile(QString port, QString fileName) {
    // 检查文件
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        emit transferFinished(false);
        return ErrorHandling("无法打开文件");
    }

    // 创建服务器
    QTcpServer server;
    if (!server.listen(QHostAddress::Any, port.toUShort())) {
        file.close();
        emit transferFinished(false);
        return ErrorHandling("启动服务器失败");
    }

    // 等待客户端连接
    if (!server.waitForNewConnection(30000)) {
        file.close();
        emit transferFinished(false);
        return ErrorHandling("等待客户端连接超时");
    }

    QTcpSocket* clientSocket = server.nextPendingConnection();
    
    // 发送文件头(包含文件大小)
    QDataStream out(clientSocket);
    out.setVersion(QDataStream::Qt_5_15);
    out << file.size();

    // 发送文件内容
    qint64 bytesSent = 0;
    while (!file.atEnd()) {
        QByteArray buffer = file.read(4096);
        qint64 bytesWritten = clientSocket->write(buffer);
        if (bytesWritten == -1 || !clientSocket->waitForBytesWritten(5000)) {
            file.close();
            clientSocket->close();
            emit transferFinished(false);
            return ErrorHandling("发送数据失败");
        }
        bytesSent += bytesWritten;
        
        // 更新进度
        int percent = static_cast<int>((bytesSent * 100) / file.size());
        emit progressChanged(percent, bytesSent);
    }

    file.close();
    clientSocket->disconnectFromHost();
    if (clientSocket->state() != QAbstractSocket::UnconnectedState) {
        clientSocket->waitForDisconnected(1000);
    }
    delete clientSocket;
    
    emit transferFinished(true);
    return 0;
}