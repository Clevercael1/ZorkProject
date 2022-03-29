#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap dir("C:/Users/caelo/Documents/ZorkProject/ImageFiles/dog");
    ui->ImageOutput->setPixmap(dir);
    ui->ImageOutput->setScaledContents(true);



    pushMap = new QPushButton(this);
    pushMap->setText("Display Map"); //todo
    pushMap->setGeometry(QRect(QPoint(20, 10), QSize(101, 61)));
    connect(pushMap, SIGNAL(clicked()), this, SLOT(on_pushMap_clicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushMap_clicked()
{
    ui->MainOutput->setText("Hi!!!!!!"); //todo
}
