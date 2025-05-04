#pragma once
#include "ui_FileTransfer.h"
#include <QMainWindow>
#include <QPropertyAnimation>
#include <QMovie>

class FileTransfer : public QMainWindow {
    Q_OBJECT
    
public:
    FileTransfer(QWidget* parent = nullptr);
    ~FileTransfer();

private slots:
    void on_toolButton_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void showStatusMessage(const QString& message, bool isError = false);

private:
    void setupButtonAnimations();
    
private:
    Ui_FileTransfer* ui;
    QPropertyAnimation* m_tabAnimation;
    QMovie* m_loadingMovie;
};