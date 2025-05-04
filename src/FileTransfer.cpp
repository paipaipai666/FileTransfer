#include "FileTransfer.h"
#include "utl/ServerHelper.h"
#include "utl/ClientHelper.h"
#include "QDir"
#include "QFileDialog"

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

    sh->SendFile(port,fileName);
    delete sh;
}


void FileTransfer::on_pushButton_2_clicked()
{
    QString fileName = ui->RecvFileName->text();
    QString IP = ui->lineEdit->text();
    QString port = QString::number(ui->spinBox_2->value());
    ClientHelper* ch = new ClientHelper();

    ch->RecvFile(IP,port,fileName);
    delete ch;
}

