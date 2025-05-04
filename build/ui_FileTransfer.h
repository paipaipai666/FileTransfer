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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileTransfer
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_6;
    QTabWidget *tabWidget;
    QWidget *ServerPage;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpinBox *portBox;
    QPushButton *pushButton;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *fileNameEdit;
    QToolButton *toolButton;
    QWidget *ClientPage;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QSpinBox *spinBox_2;
    QLabel *label_8;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLineEdit *RecvFileName;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FileTransfer)
    {
        if (FileTransfer->objectName().isEmpty())
            FileTransfer->setObjectName(QString::fromUtf8("FileTransfer"));
        FileTransfer->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FileTransfer->sizePolicy().hasHeightForWidth());
        FileTransfer->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(FileTransfer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_6 = new QHBoxLayout(centralwidget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        ServerPage = new QWidget();
        ServerPage->setObjectName(QString::fromUtf8("ServerPage"));
        horizontalLayout_7 = new QHBoxLayout(ServerPage);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ServerPage);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(ServerPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(ServerPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        portBox = new QSpinBox(ServerPage);
        portBox->setObjectName(QString::fromUtf8("portBox"));
        portBox->setMinimum(1);
        portBox->setMaximum(65535);

        horizontalLayout->addWidget(portBox);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(ServerPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(16777215, 300));

        verticalLayout->addWidget(pushButton);

        label_9 = new QLabel(ServerPage);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        fileNameEdit = new QLineEdit(ServerPage);
        fileNameEdit->setObjectName(QString::fromUtf8("fileNameEdit"));

        horizontalLayout_2->addWidget(fileNameEdit);

        toolButton = new QToolButton(ServerPage);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout_2->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_7->addLayout(verticalLayout);

        tabWidget->addTab(ServerPage, QString());
        ClientPage = new QWidget();
        ClientPage->setObjectName(QString::fromUtf8("ClientPage"));
        horizontalLayout_5 = new QHBoxLayout(ClientPage);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_5 = new QLabel(ClientPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(ClientPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        lineEdit = new QLineEdit(ClientPage);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_7 = new QLabel(ClientPage);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        spinBox_2 = new QSpinBox(ClientPage);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(65535);

        horizontalLayout_4->addWidget(spinBox_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_8 = new QLabel(ClientPage);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        pushButton_2 = new QPushButton(ClientPage);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(16777215, 300));

        verticalLayout_2->addWidget(pushButton_2);

        label_4 = new QLabel(ClientPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        RecvFileName = new QLineEdit(ClientPage);
        RecvFileName->setObjectName(QString::fromUtf8("RecvFileName"));

        verticalLayout_2->addWidget(RecvFileName);


        horizontalLayout_5->addLayout(verticalLayout_2);

        tabWidget->addTab(ClientPage, QString());

        horizontalLayout_6->addWidget(tabWidget);

        FileTransfer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(FileTransfer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FileTransfer->setStatusBar(statusbar);

        retranslateUi(FileTransfer);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FileTransfer);
    } // setupUi

    void retranslateUi(QMainWindow *FileTransfer)
    {
        FileTransfer->setWindowTitle(QCoreApplication::translate("FileTransfer", "FileTransfer", nullptr));
        label->setText(QCoreApplication::translate("FileTransfer", "\346\234\215\345\212\241\345\231\250\347\253\257\346\216\247\345\210\266\351\235\242\346\235\277", nullptr));
        label_2->setText(QCoreApplication::translate("FileTransfer", "\347\212\266\346\200\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("FileTransfer", "\347\233\221\345\220\254\347\253\257\345\217\243\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("FileTransfer", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
        label_9->setText(QCoreApplication::translate("FileTransfer", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        toolButton->setText(QCoreApplication::translate("FileTransfer", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ServerPage), QCoreApplication::translate("FileTransfer", "\346\234\215\345\212\241\345\231\250\347\253\257", nullptr));
        label_5->setText(QCoreApplication::translate("FileTransfer", "\345\256\242\346\210\267\347\253\257\346\216\247\345\210\266\351\235\242\346\235\277", nullptr));
        label_6->setText(QCoreApplication::translate("FileTransfer", "\346\234\215\345\212\241\345\231\250IP\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("FileTransfer", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("FileTransfer", "\347\212\266\346\200\201\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FileTransfer", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        label_4->setText(QCoreApplication::translate("FileTransfer", "\346\226\207\344\273\266\346\216\245\346\224\266\345\214\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ClientPage), QCoreApplication::translate("FileTransfer", "\345\256\242\346\210\267\347\253\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileTransfer: public Ui_FileTransfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILETRANSFER_H
