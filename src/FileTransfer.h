#pragma once
#include "ui_FileTransfer.h"
#include <QMainWindow>

class FileTransfer : public QMainWindow {
    Q_OBJECT
    
public:
    FileTransfer(QWidget* parent = nullptr);
    ~FileTransfer();

private:
    Ui_FileTransfer* ui;
};