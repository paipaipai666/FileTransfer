#pragma once
#include "ui_FileTransfer.h"
#include <QMainWindow>

class FileTransfer : public QMainWindow {
    Q_OBJECT
    
public:
    FileTransfer(QWidget* parent = nullptr);
    ~FileTransfer();

private slots:
    void on_toolButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui_FileTransfer* ui;
};
