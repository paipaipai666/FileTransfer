#include "FileTransfer.h"
#include "utl/ServerHelper.h"
#include "utl/ServerHelper.h"
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
}

