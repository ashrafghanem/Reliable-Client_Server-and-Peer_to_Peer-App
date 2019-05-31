#include "Client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    UDPsocket = new QUdpSocket(this);
    TCPsocket = new QTcpSocket(this);
    connect(UDPsocket, SIGNAL(readyRead()),this,SLOT(ReadPendingDatagram()));
}

void Client::ReadPendingDatagram(){
    if(UDPsocket->hasPendingDatagrams()){
        buffer.resize(UDPsocket->pendingDatagramSize());
        UDPsocket->readDatagram(buffer.data(),buffer.size(),&senderIP,&senderPort);
        message = buffer;
    }
}

bool Client::send(QString dstIP, QString dstPort, QString msg){

    QByteArray data;
    data.append(msg);
    if(UDPsocket->writeDatagram(data, QHostAddress(dstIP), dstPort.toUInt())!=-1){
        return true;
    }
    return false;
}

void Client::connectToServer(QString hostIP, QString hostPort, QString srcIP, QString srcPort, QString username){
    QHostAddress UDPIP ;
    UDPIP.setAddress(srcIP);
    quint16 UDPPort = srcPort.toUInt();
    if(UDPsocket->isValid()){
        UDPsocket->abort();
    }
    UDPsocket->bind(UDPIP, UDPPort);

    QHostAddress IP ;
    IP.setAddress(hostIP);
    quint16 Port = hostPort.toUInt();
    TCPsocket->connectToHost(IP, Port, QIODevice::ReadWrite);
    dataToServer.append(username+" ("+srcIP+","+srcPort+")");
    TCPsocket->write(dataToServer);
    isOnline=true;
}

void Client::close(){
    TCPsocket->write("Close"+dataToServer);
    dataToServer.clear();
    UDPsocket->close();
    TCPsocket->close();
    isOnline=false;
}
