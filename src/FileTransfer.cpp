#include "FileTransfer.h"
#include "utl/ServerHelper.h"
#include "utl/ClientHelper.h"
#include "QDir"
#include "QFileDialog"
#include <thread>
#include <QFuture>
#include <QtConcurrent/QtConcurrentRun>

FileTransfer::FileTransfer(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_FileTransfer)
{
    ui->setupUi(this);
}

FileTransfer::~FileTransfer()
{
    delete ui; 
}
void FileTransfer::on_toolButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("open a file"),"../",tr("all file(*.*)"));
    ui->fileNameEdit->setText(fileName);
}


void FileTransfer::on_pushButton_clicked()
{
    QString fileName = ui->fileNameEdit->text();
    QString port = QString::number(ui->portBox->value());
    
    ServerHelper* sh = new ServerHelper();
    QFuture<void> SendFuture = QtConcurrent::run([=]() {
        sh->SendFile(port,fileName);
        delete sh;
    });
}

void FileTransfer::on_pushButton_2_clicked()
{
    QString fileName = ui->RecvFileName->text();
    QString IP = ui->lineEdit->text();
    QString port = QString::number(ui->spinBox_2->value());

    ClientHelper* ch = new ClientHelper();  // 动态分配，避免悬空引用
    QFuture<void> RecvFuture = QtConcurrent::run([=]() {
        ch->RecvFile(IP, port, fileName);
        delete ch;  // 执行完后自动清理
    });
}

