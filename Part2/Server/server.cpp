#include "Server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    serverSocket = new QTcpServer(this);
    connect(serverSocket,SIGNAL(newConnection()),this,SLOT(NewConnection()));
}

void Server::NewConnection(){
    sockets.append(serverSocket->nextPendingConnection());
    connect(sockets.last(), SIGNAL(readyRead()), this, SLOT(getData()));
}

void Server::getData(){
    /* sender() returns a pointer to the already connecting client.*/
    QTcpSocket* activeSocket = qobject_cast<QTcpSocket*>(sender());
    clientMsg=activeSocket->readAll();

    /* If the client logs out */
    if(clientMsg.contains("Close")){
        sockets.removeOne(activeSocket);
        activeSocket->close();
        clientMsg.replace("Close","");
        clientMsg.append("/");
        onlineUsers.replace(clientMsg,QByteArray(""));
    }
    else{
        onlineUsers.append(clientMsg+"/");
    }

    foreach (QTcpSocket* s, sockets) {
        s->write(onlineUsers);
    }
    clients = onlineUsers.split('/');
}

void Server::startListening(QString IP, QString port){
    serverSocket->listen(QHostAddress(IP),port.toUInt());
}

void Server::stopServer(){
    foreach (QTcpSocket *y, sockets){
        y->write("Server Stopped");
        y->close();
    }
    serverSocket->close();
    clientMsg.clear();
    onlineUsers.clear();
    clients.clear();
}
