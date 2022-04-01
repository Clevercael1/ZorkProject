#include "mainwindow.h"
#include "ZorkUL.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //ZorkUL temp;
    //temp.play();
    MainWindow w;
    w.show();
    return a.exec();
}
