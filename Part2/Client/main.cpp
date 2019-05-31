#include <QApplication>
#include"ClientWindow.h"
#include"Client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientWindow x;
    x.show();
    return a.exec();
}
