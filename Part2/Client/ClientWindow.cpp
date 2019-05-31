#include "ClientWindow.h"
#include "ui_ClientWindow.h"

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    connect(client.UDPsocket,SIGNAL(readyRead()),this,SLOT(gotMsg()));
    connect(client.TCPsocket, SIGNAL(readyRead()), this, SLOT(getUsers()));

    ui->error->setMaximum(100);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeOut()));

    saveDirectory="C:\\Users\\ans_g\\Desktop";

    ui->selectFile->setEnabled(false);
    ui->sendFileBtn->setEnabled(false);
    notification = new QMediaPlayer();
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::gotMsg(){
    QMessageBox::StandardButton reply;

    if(client.message.mid(0,4)=="FILE"){
        notification->setMedia(QUrl("C:/Qt/Projects/Client/notification.wav"));
        notification->play();

        fName = client.message.remove("FILE");
        reply = QMessageBox::question(this, "Recieving File","Do you want to receive \""+fName+"\" \nfrom "+
                                      client.senderIP.toString()+", "+QString::number(client.senderPort) +"?" ,QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes){
            notification->stop();
            saveDirectory = QFileDialog::getExistingDirectory(this, tr("Open Directory"), saveDirectory,  QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
            rcvFile.setFileName(fName);
            QDir::setCurrent(saveDirectory);
            rcvFile.open(QIODevice::WriteOnly);

            // The receiving client sends an approvement to the sending client.
            // FA = File Accepted.
            client.send(client.senderIP.toString(),QString::number(client.senderPort),"FA");
            ui->status->setText("Recieveing File ...");
            seqNumRcvr=0;
        }
        else{
            // The receiving client sends a disapprovement to the sending client.
            // FNA = File Not Accepted.
            notification->stop();
            client.send(client.senderIP.toString(),QString::number(client.senderPort),"FNA");
        }
    }

    else if(client.message.contains("DATA")){
        int index = client.message.indexOf("DATA");
        if(client.message.mid(index-1,1).toInt()==seqNumRcvr){
            client.buffer.remove(0,index+4);

            comingData = client.message.split("checksum");
            if(qChecksum(client.buffer,client.buffer.size())==comingData.at(0).toUInt()){
                rcvFile.write(client.buffer,client.buffer.size());
                seqNumRcvr = !seqNumRcvr;
            }
        }
        client.send(client.senderIP.toString(),QString::number(client.senderPort),QString::number(seqNumRcvr)+"ACK");
    }

    /*else if(client.message.mid(1,4)=="DATA"){
        if(client.message.mid(0,1).toInt()==seqNumRcvr){
            client.buffer.remove(0,5);

            rcvFile.write(client.buffer,client.buffer.size());
            seqNumRcvr = !seqNumRcvr;
        }
        client.send(client.senderIP.toString(),QString::number(client.senderPort),QString::number(seqNumRcvr)+"ACK");
    }*/

    else if(client.message.mid(1,3)=="ACK"){
        // error is just to force the timer to timeout and so resends the packets.
        int rand = qrand()%100;
        if(rand>ui->error->value()){
            sendChunk(client.message.mid(0,1).toInt());
        }
        else{
            qDebug()<<"timeout\n";
        }
    }
    // EOF = End of File.
    else if(client.message.mid(0,3)=="EOF"){
        rcvFile.close();
        ui->status->setText("File has been received successfully.");
    }
    else if(client.message.mid(0,2)=="FA"){
        sendChunk(0);
    }
    else if(client.message.mid(0,3)=="FNA"){
        ui->status->setText("Receiver refused to receive the file!");
    }

    else if(client.message.mid(0,3)=="MSG"){
        notification->setMedia(QUrl("C:/Qt/Projects/Client/message.wav"));
        notification->play();
        client.message.remove(0,3);
        QList<QString> messageReceived = client.message.split(':');
        QString sender = messageReceived.at(0);
        ui->chatBox->append("<font color=red>"+sender+": </font>"+messageReceived.at(1));
        ui->status->setText("Recieved From "+client.senderIP.toString()+", Port number :"+QString::number(client.senderPort));
    }
}

void ClientWindow::on_LoginBtn_clicked()
{
    if(ui->LoginBtn->text()=="Login"){
        if (ui->Username->text()!="" && ui->serverIP->text()!="" && ui->serverPort->text()!=""
                &&ui->srcIP->text()!="" && ui->srcPort->text()!="") {
            if(ui->serverIP->text() == ui->srcIP->text() && ui->srcPort->text()==ui->serverPort->text()){
                msgBox.setWindowTitle("Port Violation");
                msgBox.setText("Client Cannot have the same port as the server's.");
                msgBox.show();
            }
            else{
                client.connectToServer(ui->serverIP->text(),ui->serverPort->text(), ui->srcIP->text(), ui->srcPort->text(), ui->Username->text());
                ui->status->setText("Local IP is set, "+ui->srcIP->text()+", Port number:"+ui->srcPort->text());
                ui->LoginBtn->setText("Logout");
                ui->LoginBtn->setStyleSheet("QPushButton {color: red;}");
                ui->chatBox->clear();
                ui->Username->setReadOnly(true);
                ui->serverIP->setEnabled(false);
                ui->serverPort->setEnabled(false);
                ui->srcIP->setEnabled(false);
                ui->srcPort->setEnabled(false);
                ui->selectFile->setEnabled(true);
            }
        }
        else{
            msgBox.setWindowTitle("Attribute Missing");
            msgBox.setText("Missing login information! Check them out.");
            msgBox.show();
        }
    }
    else{
        users.clear();
        client.close();
        ui->onlineUsers->clear();
        ui->status->setText("Logged out.");
        ui->LoginBtn->setText("Login");
        ui->LoginBtn->setStyleSheet("QPushButton {color: black;}");
        ui->Username->setReadOnly(false);
        ui->serverIP->setEnabled(true);
        ui->serverPort->setEnabled(true);
        ui->srcIP->setEnabled(true);
        ui->srcPort->setEnabled(true);
        ui->dstIP->setText("");
        ui->dstPort->setText("");

        ui->selectFile->setEnabled(false);
        ui->sendFileBtn->setEnabled(false);
    }
}
void ClientWindow::on_msgBox_returnPressed(){
    if(client.isOnline){
        if (ui->dstIP->text()!="" && ui->dstPort->text()!="") {
            if(ui->msgBox->text()!=""){
                if(client.send(ui->dstIP->text(),ui->dstPort->text(),"MSG" + ui->Username->text()+" : "+ui->msgBox->text())){
                    notification->setMedia(QUrl("C:/Qt/Projects/Client/message.wav"));
                    notification->play();

                    ui->status->setText("Sent to destination: "+ui->dstIP->text()+", Port number:"+ui->dstPort->text());
                    ui->chatBox->append("<font color=blue>You to "+toUser+": </font>"+ui->msgBox->text());
                    ui->msgBox->clear();
                }
            }
        }
        else{
            msgBox.setWindowTitle("Error");
            msgBox.setText("Choose a receiver to send messages to!");
            msgBox.show();
        }
    }
    else{
        msgBox.setWindowTitle("Error");
        msgBox.setText("You have to log in first!");
        msgBox.show();
    }
}

void ClientWindow::getUsers(){
    onlineUsers = client.TCPsocket->readAll();
    if(onlineUsers.contains("Server Stopped")){
        ui->status->setText("Logged out.");
        ui->LoginBtn->setText("Login");
        ui->LoginBtn->setStyleSheet("QPushButton {color: black;}");
        ui->Username->setReadOnly(false);
        ui->serverIP->setEnabled(true);
        ui->serverPort->setEnabled(true);
        ui->srcIP->setEnabled(true);
        ui->srcPort->setEnabled(true);
        users.clear();
        client.close();
        ui->onlineUsers->clear();
        msgBox.setWindowTitle("Error");
        msgBox.setText("The server has been stopped!");
        msgBox.show();
    }
    else{
        users = onlineUsers.split('/');
        ui->onlineUsers->clear();
        foreach (QString user, users) {
            if(!user.isEmpty())
                ui->onlineUsers->addItem(user);
        }
    }
}

void ClientWindow::on_onlineUsers_itemClicked(QListWidgetItem *item)
{
    // Item is of the form: userName (IP,Port)
    QList<QString> user,address,port;
    user = item->text().split('(');
    toUser = user.at(0);

    address = user.at(1).split(',');
    ui->dstIP->setText(address.at(0));

    port = address.at(1).split(')');
    ui->dstPort->setText(port.at(0));
}

void ClientWindow::on_sendFileBtn_clicked()
{
    if (ui->dstIP->text()!="" && ui->dstPort->text()!=""){
        ui->status->setText("Sending File ...");
        client.send(ui->dstIP->text(),ui->dstPort->text(),fileToSendName);

        lastChunkSize = sntFile.size()%1024;
        if(lastChunkSize==0){
            chunksNum = (sntFile.size()/1024);
        }
        else{
            chunksNum = (sntFile.size()/1024)+1;
        }
        chunksSent=0;
        seqNumSndr=1;
        ui->totalChunksLbl->setText(QString::number(chunksNum));
        resentChunks=0;
        ui->chunksResentLbl->setText(QString::number(resentChunks));
        ui->sendFileBtn->setEnabled(false);
    }

    else{
        msgBox.setWindowTitle("Error");
        msgBox.setText("Choose a receiver to send a file to!");
        msgBox.show();
    }
}

void ClientWindow::sendChunk(int seqNum){
    timer->stop();
    if (chunksSent==chunksNum) {
        client.send(ui->dstIP->text(),ui->dstPort->text(),"EOF");
        sntFile.close();
        ui->status->setText("File has been sent successfully.");
    }
    else{
        if (lastChunkSize!=0 && chunksSent+1==chunksNum) {
            sSize=lastChunkSize;
        }
        else{
            sSize=1024;
        }
        // It's not accessed in the first reading process only.
        if(seqNum==seqNumSndr){
            // To read from the end of the chuncks already sent.
            sntFile.seek((chunksSent)*1024);
            seqNumSndr = !seqNumSndr;
        }
        data=sntFile.read(sSize);

        quint16 checkSum = qChecksum(data,data.size());
        dataToSend = QByteArray::number(checkSum)+"checksum"+QByteArray::number(seqNum)+"DATA"+data;

        client.UDPsocket->writeDatagram(dataToSend,QHostAddress(ui->dstIP->text()), ui->dstPort->text().toUInt());
        timer->start(100); // 100 msec
        chunksSent+=1;
        lastACK = seqNum;
        ui->chunksSentLbl->setText(QString::number(chunksSent));
    }
}

void ClientWindow::timeOut(){
    chunksSent-=1;
    resentChunks+=1;
    ui->chunksResentLbl->setText(QString::number(resentChunks));
    sendChunk(lastACK);
}
void ClientWindow::on_selectFile_clicked()
{
    fileToSendPath = QFileDialog::getOpenFileName(this,tr("Choose a file to send"),saveDirectory,tr("Files (*.*)"));
    QFileInfo FileInfo(fileToSendPath);
    if(FileInfo.fileName().isEmpty()){
        return;
    }
    sntFile.setFileName(FileInfo.fileName());
    QDir::setCurrent(FileInfo.absolutePath());
    if(!sntFile.open(QIODevice::ReadOnly)){
        msgBox.setWindowTitle("Error");
        msgBox.setText("The file cannot be opened!");
        msgBox.show();
        return;
    }
    ui->sendFileBtn->setEnabled(true);
    fileToSendName = "FILE"+FileInfo.fileName();
    ui->status->setText("File :\""+FileInfo.fileName()+"\" of size "+QString::number(sntFile.size()/1024.0)+" KB is ready.");
}
void ClientWindow::closeEvent(QCloseEvent *event){
    if(client.isOnline){
        client.close();
    }
}
