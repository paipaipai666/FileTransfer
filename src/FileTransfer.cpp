#include "FileTransfer.h"

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