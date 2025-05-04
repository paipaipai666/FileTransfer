/********************************************************************************
** Form generated from reading UI file 'FileTransfer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILETRANSFER_H
#define UI_FILETRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileTransfer
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *ServerPage;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QLabel *label_4;
    QWidget *tab_2;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLabel *label_7;
    QSpinBox *spinBox_2;
    QLabel *label_8;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QComboBox *comboBox;
    QToolButton *toolButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FileTransfer)
    {
        if (FileTransfer->objectName().isEmpty())
            FileTransfer->setObjectName(QString::fromUtf8("FileTransfer"));
        FileTransfer->resize(800, 600);
        centralwidget = new QWidget(FileTransfer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(9, -1, 751, 431));
        ServerPage = new QWidget();
        ServerPage->setObjectName(QString::fromUtf8("ServerPage"));
        label = new QLabel(ServerPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 91, 21));
        label_2 = new QLabel(ServerPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 52, 41, 20));
        label_3 = new QLabel(ServerPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 90, 41, 20));
        spinBox = new QSpinBox(ServerPage);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(70, 90, 71, 22));
        pushButton = new QPushButton(ServerPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 120, 281, 31));
        label_4 = new QLabel(ServerPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 190, 61, 21));
        tabWidget->addTab(ServerPage, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 20, 91, 21));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 50, 51, 16));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 50, 113, 20));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 82, 41, 20));
        spinBox_2 = new QSpinBox(tab_2);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(70, 80, 81, 22));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 110, 41, 16));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 130, 241, 31));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 170, 61, 21));
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 200, 191, 22));
        toolButton = new QToolButton(tab_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(230, 200, 51, 21));
        tabWidget->addTab(tab_2, QString());
        FileTransfer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(FileTransfer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FileTransfer->setStatusBar(statusbar);

        retranslateUi(FileTransfer);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(FileTransfer);
    } // setupUi

    void retranslateUi(QMainWindow *FileTransfer)
    {
        FileTransfer->setWindowTitle(QCoreApplication::translate("FileTransfer", "FileTransfer", nullptr));
        label->setText(QCoreApplication::translate("FileTransfer", "\346\234\215\345\212\241\345\231\250\347\253\257\346\216\247\345\210\266\351\235\242\346\235\277", nullptr));
        label_2->setText(QCoreApplication::translate("FileTransfer", "\347\212\266\346\200\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("FileTransfer", "\347\233\221\345\220\254\347\253\257\345\217\243\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("FileTransfer", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
        label_4->setText(QCoreApplication::translate("FileTransfer", "\346\226\207\344\273\266\346\216\245\346\224\266\345\214\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ServerPage), QCoreApplication::translate("FileTransfer", "\346\234\215\345\212\241\345\231\250\347\253\257", nullptr));
        label_5->setText(QCoreApplication::translate("FileTransfer", "\345\256\242\346\210\267\347\253\257\346\216\247\345\210\266\351\235\242\346\235\277", nullptr));
        label_6->setText(QCoreApplication::translate("FileTransfer", "\346\234\215\345\212\241\345\231\250IP\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("FileTransfer", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("FileTransfer", "\347\212\266\346\200\201\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FileTransfer", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        label_9->setText(QCoreApplication::translate("FileTransfer", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        toolButton->setText(QCoreApplication::translate("FileTransfer", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("FileTransfer", "\345\256\242\346\210\267\347\253\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileTransfer: public Ui_FileTransfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILETRANSFER_H
