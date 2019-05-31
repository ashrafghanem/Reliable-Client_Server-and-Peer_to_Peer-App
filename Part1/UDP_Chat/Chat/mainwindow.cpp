#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Chat Program");
    udpSocket = new QUdpSocket(this);
}

void MainWindow::readPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()){
        QByteArray buffer;
        buffer.resize(udpSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        udpSocket->readDatagram(buffer.data(), buffer.size(),&sender, &senderPort);
        ui->messages->append("<font color=red> Client:</font>"+QString(buffer.data()));
    }
}
MainWindow::~MainWindow()
{
    delete ui;
    udpSocket->close();
}
void MainWindow::on_turnEditBtn_clicked()
{
    if(ui->turnEditBtn->text()=="Turn Editing On"){
        ui->srcIP->setReadOnly(false);
        ui->srcPort->setReadOnly(false);
        ui->dstIP->setReadOnly(false);
        ui->dstPort->setReadOnly(false);
        ui->turnEditBtn->setText("Turn Editing Off");
    }
    else{
        ui->srcIP->setReadOnly(true);
        ui->srcPort->setReadOnly(true);
        ui->dstIP->setReadOnly(true);
        ui->dstPort->setReadOnly(true);
        ui->turnEditBtn->setText("Turn Editing On");
    }
}

void MainWindow::on_typeMessage_returnPressed()
{
    if(ui->typeMessage->text().isEmpty()==false){
        QString word=ui->typeMessage->text();
        QByteArray buffer;
        buffer=word.toUtf8();
        udpSocket->writeDatagram(buffer, dstIP, dstPort);
        ui->messages->append("<font color=blue> Me:</font>"+word);
        ui->typeMessage->clear();
    }
}

void MainWindow::on_clearWinBtn_clicked()
{
    ui->messages->clear();
}

void MainWindow::on_connectBtn_clicked()
{
    srcIP = ui->srcIP->text();
    dstIP = ui->dstIP->text();
    srcPort = ui->srcPort->text().toShort();
    dstPort = ui->dstPort->text().toShort();

    udpSocket->bind(QHostAddress(srcIP),srcPort);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(readPendingDatagrams()));
}
