#pragma once
#include "TransHelper.h"
#include <QString>
extern "C"{
    #include <winsock2.h> 
}

class ServerHelper : public TransHelper{
public:
    ServerHelper();
    //~ServerHelper();
    int SendFile(QString port,QString fileName);
};