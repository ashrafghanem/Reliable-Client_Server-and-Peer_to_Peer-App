#ifndef ServerWindow_H
#define ServerWindow_H

#include <QMainWindow>
#include"Server.h"
#include <QMessageBox>

namespace Ui {
class ServerWindow;
}

class ServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerWindow(QWidget *parent = 0);
    Ui::ServerWindow *ui;
    void closeEvent(QCloseEvent *event);
    ~ServerWindow();

private slots:
    void on_startServerBtn_clicked();
    void UpdateStatus();
    void updateOnlineUsers();


private:
    QMessageBox msgBox;
    Server Server;
};

#endif
