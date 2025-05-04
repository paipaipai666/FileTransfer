#include "FileTransfer.h"

#include <QApplication>
#include <QFile>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleFile("./style/main.qss");
    styleFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleFile.readAll());
    a.setStyleSheet(styleSheet);
    FileTransfer w;
    w.show();
    return a.exec();
}