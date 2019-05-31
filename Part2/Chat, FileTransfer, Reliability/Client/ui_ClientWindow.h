/********************************************************************************
** Form generated from reading UI file 'ClientWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QWidget *centralWidget;
    QPushButton *LoginBtn;
    QTextEdit *chatBox;
    QLineEdit *serverIP;
    QLineEdit *serverPort;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *srcIP;
    QLineEdit *srcPort;
    QLineEdit *dstIP;
    QLineEdit *dstPort;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *statusLbl;
    QLabel *label_9;
    QListWidget *onlineUsers;
    QFrame *line;
    QLabel *label;
    QLineEdit *Username;
    QPushButton *sendFileBtn;
    QPushButton *selectFile;
    QLabel *status;
    QSpinBox *error;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *totalChunksLbl;
    QLabel *chunksResentLbl;
    QLabel *label_14;
    QLabel *label_12;
    QLabel *chunksSentLbl;
    QFrame *line_2;
    QLineEdit *msgBox;

    void setupUi(QMainWindow *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName(QStringLiteral("ClientWindow"));
        ClientWindow->setEnabled(true);
        ClientWindow->resize(713, 470);
        ClientWindow->setMinimumSize(QSize(713, 470));
        ClientWindow->setMaximumSize(QSize(713, 470));
        centralWidget = new QWidget(ClientWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LoginBtn = new QPushButton(centralWidget);
        LoginBtn->setObjectName(QStringLiteral("LoginBtn"));
        LoginBtn->setGeometry(QRect(429, 192, 111, 41));
        QFont font;
        font.setFamily(QStringLiteral("Segoe Marker"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        LoginBtn->setFont(font);
        chatBox = new QTextEdit(centralWidget);
        chatBox->setObjectName(QStringLiteral("chatBox"));
        chatBox->setEnabled(true);
        chatBox->setGeometry(QRect(10, 19, 311, 351));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe Marker"));
        font1.setPointSize(11);
        chatBox->setFont(font1);
        chatBox->setReadOnly(true);
        serverIP = new QLineEdit(centralWidget);
        serverIP->setObjectName(QStringLiteral("serverIP"));
        serverIP->setGeometry(QRect(429, 62, 111, 20));
        QFont font2;
        font2.setPointSize(9);
        serverIP->setFont(font2);
        serverPort = new QLineEdit(centralWidget);
        serverPort->setObjectName(QStringLiteral("serverPort"));
        serverPort->setGeometry(QRect(429, 88, 111, 20));
        serverPort->setFont(font2);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(334, 62, 91, 16));
        label_2->setFont(font2);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(334, 88, 101, 21));
        label_3->setFont(font2);
        srcIP = new QLineEdit(centralWidget);
        srcIP->setObjectName(QStringLiteral("srcIP"));
        srcIP->setGeometry(QRect(429, 132, 111, 20));
        srcIP->setFont(font2);
        srcPort = new QLineEdit(centralWidget);
        srcPort->setObjectName(QStringLiteral("srcPort"));
        srcPort->setGeometry(QRect(429, 158, 111, 20));
        srcPort->setFont(font2);
        dstIP = new QLineEdit(centralWidget);
        dstIP->setObjectName(QStringLiteral("dstIP"));
        dstIP->setGeometry(QRect(429, 262, 111, 20));
        dstIP->setFont(font2);
        dstIP->setReadOnly(true);
        dstPort = new QLineEdit(centralWidget);
        dstPort->setObjectName(QStringLiteral("dstPort"));
        dstPort->setGeometry(QRect(429, 292, 111, 20));
        dstPort->setFont(font2);
        dstPort->setReadOnly(true);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(334, 134, 61, 16));
        label_5->setFont(font2);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(334, 160, 71, 16));
        label_6->setFont(font2);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(334, 262, 71, 21));
        label_7->setFont(font2);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(334, 292, 81, 21));
        label_8->setFont(font2);
        statusLbl = new QLabel(centralWidget);
        statusLbl->setObjectName(QStringLiteral("statusLbl"));
        statusLbl->setGeometry(QRect(14, 433, 41, 25));
        statusLbl->setFont(font2);
        statusLbl->setAutoFillBackground(false);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(554, -1, 91, 21));
        label_9->setFont(font2);
        onlineUsers = new QListWidget(centralWidget);
        onlineUsers->setObjectName(QStringLiteral("onlineUsers"));
        onlineUsers->setGeometry(QRect(554, 20, 151, 351));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(338, 232, 191, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(334, 24, 71, 21));
        label->setFont(font2);
        Username = new QLineEdit(centralWidget);
        Username->setObjectName(QStringLiteral("Username"));
        Username->setGeometry(QRect(429, 20, 111, 31));
        QFont font3;
        font3.setPointSize(10);
        Username->setFont(font3);
        sendFileBtn = new QPushButton(centralWidget);
        sendFileBtn->setObjectName(QStringLiteral("sendFileBtn"));
        sendFileBtn->setGeometry(QRect(440, 337, 101, 31));
        sendFileBtn->setFont(font2);
        selectFile = new QPushButton(centralWidget);
        selectFile->setObjectName(QStringLiteral("selectFile"));
        selectFile->setGeometry(QRect(333, 337, 100, 31));
        selectFile->setFont(font2);
        status = new QLabel(centralWidget);
        status->setObjectName(QStringLiteral("status"));
        status->setGeometry(QRect(58, 433, 451, 25));
        status->setFont(font2);
        error = new QSpinBox(centralWidget);
        error->setObjectName(QStringLiteral("error"));
        error->setGeometry(QRect(489, 404, 51, 21));
        error->setFont(font2);
        error->setMaximum(100);
        error->setValue(0);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(557, 379, 81, 20));
        label_10->setFont(font2);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(558, 424, 91, 21));
        label_11->setFont(font2);
        totalChunksLbl = new QLabel(centralWidget);
        totalChunksLbl->setObjectName(QStringLiteral("totalChunksLbl"));
        totalChunksLbl->setGeometry(QRect(651, 379, 51, 21));
        totalChunksLbl->setFont(font2);
        chunksResentLbl = new QLabel(centralWidget);
        chunksResentLbl->setObjectName(QStringLiteral("chunksResentLbl"));
        chunksResentLbl->setGeometry(QRect(651, 424, 51, 20));
        chunksResentLbl->setFont(font2);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(434, 404, 51, 21));
        label_14->setFont(font2);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(558, 401, 81, 21));
        label_12->setFont(font2);
        chunksSentLbl = new QLabel(centralWidget);
        chunksSentLbl->setObjectName(QStringLiteral("chunksSentLbl"));
        chunksSentLbl->setGeometry(QRect(651, 402, 51, 20));
        chunksSentLbl->setFont(font2);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(340, 317, 191, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        msgBox = new QLineEdit(centralWidget);
        msgBox->setObjectName(QStringLiteral("msgBox"));
        msgBox->setGeometry(QRect(10, 381, 311, 31));
        msgBox->setFont(font1);
        ClientWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(Username, serverIP);
        QWidget::setTabOrder(serverIP, serverPort);
        QWidget::setTabOrder(serverPort, srcIP);
        QWidget::setTabOrder(srcIP, srcPort);
        QWidget::setTabOrder(srcPort, LoginBtn);
        QWidget::setTabOrder(LoginBtn, dstIP);
        QWidget::setTabOrder(dstIP, dstPort);
        QWidget::setTabOrder(dstPort, onlineUsers);
        QWidget::setTabOrder(onlineUsers, sendFileBtn);
        QWidget::setTabOrder(sendFileBtn, selectFile);
        QWidget::setTabOrder(selectFile, error);
        QWidget::setTabOrder(error, msgBox);
        QWidget::setTabOrder(msgBox, chatBox);

        retranslateUi(ClientWindow);

        QMetaObject::connectSlotsByName(ClientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClientWindow)
    {
        ClientWindow->setWindowTitle(QApplication::translate("ClientWindow", "Client", 0));
        LoginBtn->setText(QApplication::translate("ClientWindow", "Login", 0));
        serverIP->setPlaceholderText(QApplication::translate("ClientWindow", "Server IP", 0));
        serverPort->setPlaceholderText(QApplication::translate("ClientWindow", "Server Port", 0));
        label_2->setText(QApplication::translate("ClientWindow", "TCP Server IP:", 0));
        label_3->setText(QApplication::translate("ClientWindow", "TCP Server Port:", 0));
        srcIP->setPlaceholderText(QApplication::translate("ClientWindow", "Local IP", 0));
        srcPort->setPlaceholderText(QApplication::translate("ClientWindow", "Local Port", 0));
        dstIP->setPlaceholderText(QApplication::translate("ClientWindow", "Remote IP", 0));
        dstPort->setPlaceholderText(QApplication::translate("ClientWindow", "Remote Port", 0));
        label_5->setText(QApplication::translate("ClientWindow", "Local IP:", 0));
        label_6->setText(QApplication::translate("ClientWindow", "Local Port:", 0));
        label_7->setText(QApplication::translate("ClientWindow", "Remote IP:", 0));
        label_8->setText(QApplication::translate("ClientWindow", "Remote Port:", 0));
        statusLbl->setText(QApplication::translate("ClientWindow", "Status:", 0));
        label_9->setText(QApplication::translate("ClientWindow", " Online Users:", 0));
        label->setText(QApplication::translate("ClientWindow", "Username:", 0));
        Username->setPlaceholderText(QApplication::translate("ClientWindow", "Username", 0));
        sendFileBtn->setText(QApplication::translate("ClientWindow", "Send File", 0));
        selectFile->setText(QApplication::translate("ClientWindow", "Select File", 0));
        status->setText(QString());
        label_10->setText(QApplication::translate("ClientWindow", "Total Chunks:", 0));
        label_11->setText(QApplication::translate("ClientWindow", "Chunks Resent:", 0));
        totalChunksLbl->setText(QApplication::translate("ClientWindow", "0", 0));
        chunksResentLbl->setText(QApplication::translate("ClientWindow", "0", 0));
        label_14->setText(QApplication::translate("ClientWindow", "Error(%) ", 0));
        label_12->setText(QApplication::translate("ClientWindow", "Chunks Sent:", 0));
        chunksSentLbl->setText(QApplication::translate("ClientWindow", "0", 0));
        msgBox->setPlaceholderText(QApplication::translate("ClientWindow", "Type Your Message Here!", 0));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
