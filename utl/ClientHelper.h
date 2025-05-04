#pragma once
#include "TransHelper.h"
#include <QString>
extern "C"{
    #include <winsock2.h> 
}

class ClientHelper : public TransHelper{
public:
    ClientHelper();
private:
    int RecvFile(QString IP,QString port,QString fileName);
};