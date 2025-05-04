#include "FileTransfer.h"
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
    ui->comboBox->clear();
    QString path = QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this,tr("view file"),QDir::currentPath()));
    QDir dir(path);

    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::Dirs);
    QFileInfoList list = dir.entryInfoList();

    for(int i = 0;i<list.length();i++){
        QString file = list.at(i).fileName();
        ui->comboBox->addItem(file);
    }
}

