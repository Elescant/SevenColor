#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    if(w.config())
    {}
    else
    {
//        exit(1);
    }

    return a.exec();
}
