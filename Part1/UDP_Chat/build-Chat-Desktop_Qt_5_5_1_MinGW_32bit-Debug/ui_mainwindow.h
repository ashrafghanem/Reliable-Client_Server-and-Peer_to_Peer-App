/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *typeMessage;
    QPushButton *turnEditBtn;
    QLineEdit *srcIP;
    QTextEdit *messages;
    QLineEdit *srcPort;
    QLineEdit *dstIP;
    QLineEdit *dstPort;
    QPushButton *clearWinBtn;
    QPushButton *connectBtn;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(539, 412);
        MainWindow->setMinimumSize(QSize(539, 412));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        typeMessage = new QLineEdit(centralWidget);
        typeMessage->setObjectName(QStringLiteral("typeMessage"));
        typeMessage->setGeometry(QRect(10, 320, 281, 31));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        typeMessage->setFont(font);
        turnEditBtn = new QPushButton(centralWidget);
        turnEditBtn->setObjectName(QStringLiteral("turnEditBtn"));
        turnEditBtn->setGeometry(QRect(340, 30, 131, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        turnEditBtn->setFont(font1);
        srcIP = new QLineEdit(centralWidget);
        srcIP->setObjectName(QStringLiteral("srcIP"));
        srcIP->setEnabled(true);
        srcIP->setGeometry(QRect(340, 100, 171, 31));
        QFont font2;
        font2.setPointSize(10);
        srcIP->setFont(font2);
        srcIP->setAutoFillBackground(false);
        srcIP->setFrame(true);
        srcIP->setDragEnabled(false);
        srcIP->setReadOnly(true);
        srcIP->setCursorMoveStyle(Qt::LogicalMoveStyle);
        messages = new QTextEdit(centralWidget);
        messages->setObjectName(QStringLiteral("messages"));
        messages->setGeometry(QRect(10, 10, 281, 291));
        messages->setFont(font2);
        messages->setReadOnly(true);
        srcPort = new QLineEdit(centralWidget);
        srcPort->setObjectName(QStringLiteral("srcPort"));
        srcPort->setEnabled(true);
        srcPort->setGeometry(QRect(340, 140, 171, 31));
        srcPort->setFont(font2);
        srcPort->setReadOnly(true);
        dstIP = new QLineEdit(centralWidget);
        dstIP->setObjectName(QStringLiteral("dstIP"));
        dstIP->setGeometry(QRect(340, 180, 171, 31));
        dstIP->setFont(font2);
        dstIP->setReadOnly(true);
        dstPort = new QLineEdit(centralWidget);
        dstPort->setObjectName(QStringLiteral("dstPort"));
        dstPort->setGeometry(QRect(340, 220, 171, 31));
        dstPort->setFont(font2);
        dstPort->setReadOnly(true);
        clearWinBtn = new QPushButton(centralWidget);
        clearWinBtn->setObjectName(QStringLiteral("clearWinBtn"));
        clearWinBtn->setGeometry(QRect(140, 360, 151, 31));
        clearWinBtn->setFont(font1);
        connectBtn = new QPushButton(centralWidget);
        connectBtn->setObjectName(QStringLiteral("connectBtn"));
        connectBtn->setGeometry(QRect(380, 260, 131, 31));
        connectBtn->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        QWidget::setTabOrder(srcIP, srcPort);
        QWidget::setTabOrder(srcPort, dstIP);
        QWidget::setTabOrder(dstIP, dstPort);
        QWidget::setTabOrder(dstPort, typeMessage);
        QWidget::setTabOrder(typeMessage, messages);
        QWidget::setTabOrder(messages, clearWinBtn);
        QWidget::setTabOrder(clearWinBtn, turnEditBtn);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        typeMessage->setPlaceholderText(QApplication::translate("MainWindow", "Write message here!", 0));
        turnEditBtn->setText(QApplication::translate("MainWindow", "Turn Editing On", 0));
#ifndef QT_NO_STATUSTIP
        srcIP->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        srcIP->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        srcIP->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        srcIP->setInputMask(QString());
        srcIP->setText(QString());
        srcIP->setPlaceholderText(QApplication::translate("MainWindow", "Source IP", 0));
#ifndef QT_NO_STATUSTIP
        srcPort->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        srcPort->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        srcPort->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        srcPort->setInputMask(QString());
        srcPort->setText(QString());
        srcPort->setPlaceholderText(QApplication::translate("MainWindow", "Source Port NO.", 0));
#ifndef QT_NO_STATUSTIP
        dstIP->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        dstIP->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        dstIP->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        dstIP->setInputMask(QString());
        dstIP->setText(QString());
        dstIP->setPlaceholderText(QApplication::translate("MainWindow", "Destination IP", 0));
#ifndef QT_NO_STATUSTIP
        dstPort->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        dstPort->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        dstPort->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        dstPort->setInputMask(QString());
        dstPort->setText(QString());
        dstPort->setPlaceholderText(QApplication::translate("MainWindow", "Destination Port NO.", 0));
        clearWinBtn->setText(QApplication::translate("MainWindow", "Clear Chat Window", 0));
        connectBtn->setText(QApplication::translate("MainWindow", "Connect", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
