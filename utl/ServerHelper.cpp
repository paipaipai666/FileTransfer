#include "ServerHelper.h"
#include <cstring>
#include <QObject>
#include <QThread>
#include <QFileInfo>
#include <QDir>
#include <QDebug>
extern "C"{
#include <winsock2.h> 
#include <cstdio>
}
#pragma comment(lib, "lws2_32.lib")

ServerHelper::ServerHelper() {};

int ServerHelper::SendFile(QString port, QString fileName) {
    std::string SendPort = port.toStdString();
    // 将相对路径转换为绝对路径
    QFileInfo fileInfo(fileName);
    QString absolutePath = fileInfo.absoluteFilePath();
    
    // 检查文件是否存在
    if (!QFile::exists(absolutePath)) {
        qDebug() << "File not found:" << absolutePath;
        emit transferFinished(false);
        return ErrorHandling("File not found");
    }

    WSADATA wsaData;
    SOCKET hServSock, hClntSock;
    FILE *fp;
    long long totalSent = 0;
    int value;
    char buf[BUF_SIZE];
    int readCnt;

    SOCKADDR_IN servAdr, clntAdr;
    int clntAdrSz;

    if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
        return ErrorHandling("WSAStartup() error");

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "File open error:" << file.errorString();
        emit transferFinished(false);
        return ErrorHandling("File open error");
    }

    // 发送文件大小
    qint64 fileSize = file.size();
    send(hClntSock, (char*)&fileSize, sizeof(fileSize), 0);

    hServSock = socket(PF_INET, SOCK_STREAM, 0);
    if(hServSock == INVALID_SOCKET) {
        file.close();
        emit transferFinished(false);
        return ErrorHandling("Socket creation error");
    }

    memset(&servAdr, 0, sizeof(servAdr));
    servAdr.sin_family = AF_INET;
    servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAdr.sin_port = htons(atoi(SendPort.c_str()));

    if(bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR) {
        file.close();
        closesocket(hServSock);
        emit transferFinished(false);
        return ErrorHandling("Bind error");
    }

    listen(hServSock, 5);

    clntAdrSz = sizeof(clntAdr);
    hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &clntAdrSz);
    if(hClntSock == INVALID_SOCKET) {
        file.close();
        closesocket(hServSock);
        emit transferFinished(false);
        return ErrorHandling("Accept error");
    }

    while(!file.atEnd()) {
        QByteArray buffer = file.read(BUF_SIZE);
        int sent = send(hClntSock, buffer.constData(), buffer.size(), 0);
        if (sent != buffer.size()) {
            file.close();
            emit transferFinished(false);
            return ErrorHandling("Send error");
        }

        totalSent += sent;
        
        // 计算并发送进度
        int percent = static_cast<int>((totalSent * 100) / fileSize);
        emit progressChanged(percent);
    }

    file.close();
    closesocket(hClntSock);
    closesocket(hServSock);
    emit transferFinished(true);
    return 0;
}
