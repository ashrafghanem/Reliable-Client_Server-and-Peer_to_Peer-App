#ifndef ClientWindow_H
#define ClientWindow_H

#include <QMainWindow>
#include<QListWidget>
#include <QMessageBox>
#include<QFile>
#include<QFileDialog>
#include<QTimer>
#include<QThread>
#include"Client.h"
#include <QMediaPlayer>
namespace Ui {
class ClientWindow;
}

class ClientWindow : public QMainWindow
{
    Q_OBJECT
    Client client;
    QMessageBox msgBox;
    QString toUser,fName, saveDirectory, fileToSendPath, fileToSendName;
    QFile sntFile,rcvFile;
    int seqNumSndr,seqNumRcvr, lastACK, resentChunks=0;
    QTimer *timer;

public:
    explicit ClientWindow(QWidget *parent = 0);
    Ui::ClientWindow *ui;
    ~ClientWindow();
    QList<QByteArray> users;
    QList<QString> comingData;
    QByteArray onlineUsers;
    void closeEvent(QCloseEvent *event);
    void sendChunk(int);
    QByteArray dataToSend,data;
    int chunksNum, lastChunkSize, sSize, chunksSent;
    QMediaPlayer *notification;

private slots:
    void gotMsg();
    void on_msgBox_returnPressed();
    void getUsers();
    void on_LoginBtn_clicked();
    void on_onlineUsers_itemClicked(QListWidgetItem *item);
    void on_sendFileBtn_clicked();
    void on_selectFile_clicked();
    void timeOut();
};

#endif
