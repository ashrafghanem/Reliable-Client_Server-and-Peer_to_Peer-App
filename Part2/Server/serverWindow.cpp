#include "ServerWindow.h"
#include "ui_ServerWindow.h"

ServerWindow::ServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
    connect(Server.serverSocket, SIGNAL(newConnection()),this, SLOT(UpdateStatus()));
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::on_startServerBtn_clicked()
{
    if(ui->startServerBtn->text()=="Start Server"){
        if(ui->serverPort->text()!="" && ui->serverIP->text()!=""){
            QString IP = ui->serverIP->text();
            Server.startListening(IP, ui->serverPort->text());
            if(Server.serverSocket->isListening()){
                ui->serverStatusLbl->setText("Status : Server started.");
                ui->startServerBtn->setText("Stop Server");
                ui->startServerBtn->setStyleSheet("QPushButton {color: red;}");
                ui->serverPort->setReadOnly(true);
                ui->serverIP->setReadOnly(true);
            }
            else{
                ui->serverStatusLbl->setText("Status : Server couldn't start.");
            }
        }
        else{
            msgBox.setWindowTitle("Attribute Missing");
            if(ui->serverIP->text()=="" && ui->serverPort->text()=="")
                msgBox.setText("Set IP Address and Port Number!");
            else if(ui->serverPort->text()=="")
                msgBox.setText("Set Port Number!");
            else if(ui->serverIP->text()=="")
                msgBox.setText("Set IP Address!");
            msgBox.show();
        }
    }
    else{
        Server.stopServer();
        ui->startServerBtn->setText("Start Server");
        ui->startServerBtn->setStyleSheet("QPushButton {color: black;}");
        ui->serverStatusLbl->setText("Status : Server stopped.");
        ui->onlineUsers->clear();
        ui->serverPort->setReadOnly(false);
        ui->serverIP->setReadOnly(false);
    }
}

void ServerWindow::UpdateStatus(){
    connect(Server.sockets.last(), SIGNAL(readyRead()),this , SLOT(updateOnlineUsers()));
}

void ServerWindow::updateOnlineUsers(){
    ui->onlineUsers->clear();
    foreach (QString user, Server.clients) {
        if (!user.isEmpty())
            ui->onlineUsers->addItem(user);
    }
}

void ServerWindow::closeEvent(QCloseEvent *event){
    Server.stopServer();
}
