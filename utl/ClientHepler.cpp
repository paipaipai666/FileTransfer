#include "ClientHelper.h"
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
#define wsConnect ::connect

ClientHelper::ClientHelper() {};

int ClientHelper::RecvFile(QString IP, QString port, QString fileName) {
    std::string RecvIP = IP.toStdString();
    std::string RecvPort = port.toStdString();                                                                              
    // 将相对路径转换为绝对路径
    QFileInfo fileInfo(fileName);
    QString absolutePath = fileInfo.absoluteFilePath();
    
    // 检查目录是否存在，不存在则创建
    QDir().mkpath(QFileInfo(absolutePath).absolutePath());

    WSADATA wsaData;
    SOCKET hSocket;
    long long totalReceived = 0;

    char buf[BUF_SIZE];
    int readCnt;
    SOCKADDR_IN servAdr;

    if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        emit transferFinished(false);
        return ErrorHandling("WSAStartup() error");
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "File open error:" << file.errorString();
        emit transferFinished(false);
        return ErrorHandling("File open error");
    }

    hSocket = socket(PF_INET, SOCK_STREAM, 0);
    if(hSocket == INVALID_SOCKET) {
        file.close();
        emit transferFinished(false);
        return ErrorHandling("Socket creation error");
    }

    memset(&servAdr, 0, sizeof(servAdr));
    servAdr.sin_family = AF_INET;
    servAdr.sin_addr.s_addr = inet_addr(RecvIP.c_str());
    servAdr.sin_port = htons(atoi(RecvPort.c_str()));

    if(wsConnect(hSocket, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR) {
        file.close();
        closesocket(hSocket);
        emit transferFinished(false);
        return ErrorHandling("Connect error");
    }

    // 接收文件大小
    qint64 fileSize = 0;
    if (recv(hSocket, reinterpret_cast<char*>(&fileSize), sizeof(fileSize), 0) <= 0) {
        file.close();
        emit transferFinished(false);
        return ErrorHandling("Failed to receive file size");
    }

    while((readCnt = recv(hSocket, buf, BUF_SIZE, 0)) > 0) {
        qint64 written = file.write(buf, readCnt);
        if(written != readCnt) {
            file.close();
            emit transferFinished(false);
            return ErrorHandling("File write error");
        }
        
        // 计算并发送进度
        if(fileSize > 0) {
            int percent = static_cast<int>((totalReceived * 100) / fileSize);
            emit progressChanged(percent);
        }
    }

    file.close();
    closesocket(hSocket);
    WSACleanup();
    emit transferFinished(true);
    return 0;
}