#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.setWindowFlags(Qt::WindowStaysOnTopHint |
                          Qt::CustomizeWindowHint);
    window.setGeometry(QRect(400,100,400,300)); // TO BE SET TO SAMPLE POSITION LATER
    window.show();

    return a.exec();
}
