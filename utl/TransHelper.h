#pragma once
#include <QString>
#include <QObject>
#include <QDebug>
#include <QFile>

class TransHelper : public QObject{
public:
    int BUF_SIZE = 4096;
public:
    inline qint64 getFileSize(const QString &fileName)
    {
        QFile file(fileName);
        return file.size();
    }

    inline int ErrorHandling(const char *message)
    {
        qCritical() << message;
        return 1;
    }
};
