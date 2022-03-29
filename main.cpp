#include "mainwindow.h"
#include "ZorkUL.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ZorkUL temp;
    temp.play();
    w.show();
    return a.exec();
}
