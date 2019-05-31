#ifndef Client_H
#define Client_H

#include <QObject>
#include<QtNetwork/QUdpSocket>
#include<QtNetwork/QTcpSocket>


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    bool send(QString dstIP, QString dstPort, QString msg);
    void connectToServer(QString hostIP, QString hostPort, QString srcip, QString srcport, QString username);
    void close();
    QUdpSocket *UDPsocket;
    QTcpSocket *TCPsocket;
    QString message;
    QHostAddress senderIP;
    quint16 senderPort;
    bool isOnline=false;
    QByteArray buffer;


public slots:
    void ReadPendingDatagram();

private:
    QByteArray dataToServer;
};

#endif
