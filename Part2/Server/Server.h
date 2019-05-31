#ifndef Server_H
#define Server_H

#include <QObject>
#include<QTcpServer>
#include<QTcpSocket>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    void startListening(QString IP, QString port);
    void stopServer();
    QTcpServer *serverSocket;
    QList<QTcpSocket*> sockets;
    QByteArray clientMsg;
    QByteArray onlineUsers;
    QList<QByteArray> clients;

public slots:
    void NewConnection();
    void getData();

};

#endif
