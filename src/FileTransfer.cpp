#include "FileTransfer.h"
#include "utl/ServerHelper.h"
#include "utl/ClientHelper.h"
#include "QDir"
#include "QFileDialog"
#include <QFuture>
#include <QtConcurrent/QtConcurrentRun>

FileTransfer::FileTransfer(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_FileTransfer)
{
    ui->setupUi(this);

    setWindowIcon(QIcon("://logo.ico"));


    QString progressStyle = R"(
        QProgressBar {
            border: 2px solid grey;
            border-radius: 5px;
            text-align: center;
            background: #f0f0f0;
            height: 20px;
        }
        QProgressBar::chunk {
            background-color: #4CAF50;
            width: 10px;
            border-radius: 3px;
        }
    )";
    
    ui->serverProgressBar->setStyleSheet(progressStyle);
    ui->clientProgressBar->setStyleSheet(progressStyle);
    
    // 初始化页面切换动画
    m_tabAnimation = new QPropertyAnimation(ui->tabWidget, "pos");
    m_tabAnimation->setDuration(300);
    m_tabAnimation->setEasingCurve(QEasingCurve::OutBack);
    
    // 连接tab切换信号
    connect(ui->tabWidget, &QTabWidget::currentChanged, [this](int index) {
        QPoint startPos = ui->tabWidget->pos();
        QPoint endPos = startPos;
        
        if (index == 0) { // 切换到服务器页
            startPos.setX(startPos.x() - 20);
        } else { // 切换到客户端页
            startPos.setX(startPos.x() + 20);
        }
        
        m_tabAnimation->setStartValue(startPos);
        m_tabAnimation->setEndValue(endPos);
        m_tabAnimation->start();
    });
    
    setupButtonAnimations();
}

FileTransfer::~FileTransfer()
{
    delete ui; 
}

void FileTransfer::showStatusMessage(const QString& message, bool isError)
{
    QLabel* statusLabel = ui->tabWidget->currentIndex() == 0 
        ? ui->label_2 
        : ui->label_8;
    
    statusLabel->setText("状态: " + message);
    
    // 创建颜色动画
    QPropertyAnimation* colorAnim = new QPropertyAnimation(statusLabel, "color");
    colorAnim->setDuration(1000);
    colorAnim->setStartValue(isError ? QColor(255, 0, 0) : QColor(0, 180, 0));
    colorAnim->setEndValue(QColor(0, 0, 0));
    colorAnim->start(QAbstractAnimation::DeleteWhenStopped);
    
    // 创建缩放动画
    QPropertyAnimation* scaleAnim = new QPropertyAnimation(statusLabel, "geometry");
    scaleAnim->setDuration(300);
    QRect startRect = statusLabel->geometry();
    QRect endRect = startRect;
    startRect.setWidth(startRect.width() * 1.1);
    scaleAnim->setStartValue(startRect);
    scaleAnim->setEndValue(endRect);
    scaleAnim->setEasingCurve(QEasingCurve::OutBack);
    scaleAnim->start(QAbstractAnimation::DeleteWhenStopped);
}

void FileTransfer::setupButtonAnimations()
{
    // 为所有按钮添加基本样式
    QString buttonStyle = R"(
        QPushButton {
            background-color: #4a6baf;
            color: white;
            border: none;
            padding: 10px;
            border-radius: 5px;
            transition: all 0.3s ease;
        }
        QPushButton:hover {
            background-color: #3a5a9f;
            transform: translateY(-2px);
            box-shadow: 0 4px 8px rgba(0,0,0,0.2);
        }
        QPushButton:pressed {
            transform: translateY(1px);
            box-shadow: none;
        }
    )";
    
    ui->pushButton->setStyleSheet(buttonStyle);
    ui->pushButton_2->setStyleSheet(buttonStyle);
    ui->toolButton->setStyleSheet(buttonStyle);
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

    connect(sh, &ServerHelper::progressChanged, this, &FileTransfer::onServerProgressChanged);
    connect(sh, &ServerHelper::transferFinished, this, [this](bool success) {
        showStatusMessage(success ? "文件发送完成" : "文件发送失败", !success);
        if(success) ui->serverProgressBar->setValue(100);
    });

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

    connect(ch, &ClientHelper::progressChanged, this, &FileTransfer::onClientProgressChanged);
    connect(ch, &ClientHelper::transferFinished, this, [this](bool success) {
        showStatusMessage(success ? "文件接收完成" : "文件接收失败", !success);
        if(success) ui->clientProgressBar->setValue(100);
    });
    
    QFuture<void> RecvFuture = QtConcurrent::run([=]() {
        ch->RecvFile(IP, port, fileName);
        delete ch;  // 执行完后自动清理
    });
}

void FileTransfer::onServerProgressChanged(int percent)
{
    ui->serverProgressBar->setValue(percent);
    ui->serverProgressBar->setFormat(QString("发送中: %1%").arg(percent));
}

void FileTransfer::onClientProgressChanged(int percent)
{
    ui->clientProgressBar->setValue(percent);
    ui->clientProgressBar->setFormat(QString("接收中: %1%").arg(percent));
}
