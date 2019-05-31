/********************************************************************************
** Form generated from reading UI file 'ServerWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWINDOW_H
#define UI_SERVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *serverPort;
    QLabel *label;
    QPushButton *startServerBtn;
    QLabel *serverStatusLbl;
    QListWidget *onlineUsers;
    QLineEdit *serverIP;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QMainWindow *ServerWindow)
    {
        if (ServerWindow->objectName().isEmpty())
            ServerWindow->setObjectName(QStringLiteral("ServerWindow"));
        ServerWindow->resize(280, 438);
        ServerWindow->setMinimumSize(QSize(280, 438));
        ServerWindow->setMaximumSize(QSize(280, 438));
        centralwidget = new QWidget(ServerWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        serverPort = new QLineEdit(centralwidget);
        serverPort->setObjectName(QStringLiteral("serverPort"));
        serverPort->setGeometry(QRect(40, 40, 113, 20));
        QFont font;
        font.setPointSize(9);
        serverPort->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 41, 31, 16));
        startServerBtn = new QPushButton(centralwidget);
        startServerBtn->setObjectName(QStringLiteral("startServerBtn"));
        startServerBtn->setGeometry(QRect(172, 16, 91, 41));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        startServerBtn->setFont(font1);
        serverStatusLbl = new QLabel(centralwidget);
        serverStatusLbl->setObjectName(QStringLiteral("serverStatusLbl"));
        serverStatusLbl->setGeometry(QRect(13, 405, 251, 21));
        onlineUsers = new QListWidget(centralwidget);
        onlineUsers->setObjectName(QStringLiteral("onlineUsers"));
        onlineUsers->setGeometry(QRect(10, 100, 261, 301));
        serverIP = new QLineEdit(centralwidget);
        serverIP->setObjectName(QStringLiteral("serverIP"));
        serverIP->setGeometry(QRect(40, 9, 113, 20));
        serverIP->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 31, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(13, 77, 91, 16));
        QFont font2;
        font2.setPointSize(10);
        label_3->setFont(font2);
        ServerWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(serverIP, serverPort);
        QWidget::setTabOrder(serverPort, onlineUsers);
        QWidget::setTabOrder(onlineUsers, startServerBtn);

        retranslateUi(ServerWindow);

        QMetaObject::connectSlotsByName(ServerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ServerWindow)
    {
        ServerWindow->setWindowTitle(QApplication::translate("ServerWindow", "Server", 0));
        serverPort->setPlaceholderText(QApplication::translate("ServerWindow", "Port Number", 0));
        label->setText(QApplication::translate("ServerWindow", "Port:", 0));
        startServerBtn->setText(QApplication::translate("ServerWindow", "Start Server", 0));
        serverStatusLbl->setText(QApplication::translate("ServerWindow", "Status:", 0));
        serverIP->setPlaceholderText(QApplication::translate("ServerWindow", "IP Address", 0));
        label_2->setText(QApplication::translate("ServerWindow", "IP:", 0));
        label_3->setText(QApplication::translate("ServerWindow", "Online Clients:", 0));
    } // retranslateUi

};

namespace Ui {
    class ServerWindow: public Ui_ServerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
