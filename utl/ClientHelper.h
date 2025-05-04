#pragma once
#include "TransHelper.h"
#include <QString>
#include <QObject>  // 添加这行

extern "C"{
    #include <winsock2.h> 
}

class ClientHelper : public TransHelper{  // 修改继承
    Q_OBJECT  // 添加这行
    
public:
    ClientHelper();
    int RecvFile(QString IP, QString port, QString fileName);
    
signals:
    void progressChanged(int percent,qint64 bytesReceived);
    void transferFinished(bool success);
};