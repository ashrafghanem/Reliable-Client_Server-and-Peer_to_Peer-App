#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QUdpSocket>
#include <QMainWindow>
#include<QHostAddress>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void readPendingDatagrams();

private slots:
    void on_turnEditBtn_clicked();
    void on_typeMessage_returnPressed();
    void on_clearWinBtn_clicked();

    void on_connectBtn_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket *udpSocket ;
    QHostAddress srcIP,dstIP;
    quint16 srcPort,dstPort;
};

#endif // MAINWINDOW_H
