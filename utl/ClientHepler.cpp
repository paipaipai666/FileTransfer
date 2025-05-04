#include "ClientHelper.h"
#include <cstring>
#include <QObject>
extern "C"{
#include <winsock2.h> 
#include <cstdio>
}
#pragma comment(lib, "lws2_32.lib")

ClientHelper::ClientHelper() {};

int ClientHelper::RecvFile(QString IP,QString port,QString fileName){
    std::string RecvIP=IP.toStdString();
    std::string RecvPort=port.toStdString();                                                                              
    std::string RecvFileName="../../"+fileName.toStdString();

    WSADATA wsaData;
    SOCKET hSocket;
    FILE *fp;
    int fileSize,value;

    char buf[BUF_SIZE];
    int readCnt;
    SOCKADDR_IN servAdr;

    if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
        return ErrorHandling("WSAStartup() error");

    fp=fopen(RecvFileName.c_str(),"wb");
    //fileSize=(int)getFileSize(fp);
    hSocket=socket(PF_INET,SOCK_STREAM,0);

    memset(&servAdr,0,sizeof(servAdr));
    servAdr.sin_family=AF_INET;
    servAdr.sin_addr.s_addr=inet_addr(RecvIP.c_str());
    servAdr.sin_port=htons(atoi(RecvPort.c_str()));

    connect(hSocket,(SOCKADDR*)&servAdr,sizeof(servAdr));

    while((readCnt=recv(hSocket,buf,BUF_SIZE,0))!=0){
        fwrite((void*)buf,1,readCnt,fp);
    }

    fclose(fp);
    closesocket(hSocket);
    WSACleanup();
    return 0;
}