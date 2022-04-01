#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "Command.h"
#include "ZorkUL.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap dir("C:/Users/caelo/Documents/ZorkProject/ImageFiles/dog");
    ui->ImageOutput->setPixmap(dir);
    ui->ImageOutput->setScaledContents(true);


    pushMap = new QPushButton(this);
    pushMap->setText("Display Map");
    pushMap->setGeometry(QRect(QPoint(20, 10), QSize(101, 61)));
    connect(pushMap, SIGNAL(clicked()), this, SLOT(on_pushMap_clicked()));


    pushTake = new QPushButton(this);
    pushTake->setText("Pickup Item");
    pushTake->setGeometry(QRect(QPoint(140, 10), QSize(101, 61)));
    connect(pushTake, SIGNAL(clicked()), this, SLOT(on_pushTake_clicked()));

    pushDrop = new QPushButton(this);
    pushDrop->setText("Drop Item");
    pushDrop->setGeometry(QRect(QPoint(260, 10), QSize(101, 61)));
    connect(pushDrop, SIGNAL(clicked()), this, SLOT(on_pushDrop_clicked()));

    pushNorth = new QPushButton(this);
    pushNorth->setText("Go North");
    pushNorth->setGeometry(QRect(QPoint(500, 10), QSize(101, 61)));
    connect(pushNorth, SIGNAL(clicked()), this, SLOT(on_pushNorth_clicked()));

    pushSouth = new QPushButton(this);
    pushSouth->setText("Go South");
    pushSouth->setGeometry(QRect(QPoint(500, 150), QSize(101, 61)));
    connect(pushSouth, SIGNAL(clicked()), this, SLOT(on_pushSouth_clicked()));

    pushEast = new QPushButton(this);
    pushEast->setText("Go East");
    pushEast->setGeometry(QRect(QPoint(600, 80), QSize(101, 61)));
    connect(pushEast, SIGNAL(clicked()), this, SLOT(on_pushEast_clicked()));

    pushWest = new QPushButton(this);
    pushWest->setText("Go West");
    pushWest->setGeometry(QRect(QPoint(400, 80), QSize(101, 61)));
    connect(pushWest, SIGNAL(clicked()), this, SLOT(on_pushWest_clicked()));

    pushQuit = new QPushButton(this);
    pushQuit->setText("Quit Game");
    pushQuit->setGeometry(QRect(QPoint(680, 10), QSize(101, 61)));
    connect(pushQuit, SIGNAL(clicked()), this, SLOT(on_pushQuit_clicked()));

    pushTeleport = new QPushButton(this);
    pushTeleport->setText("Teleport");
    pushTeleport->setGeometry(QRect(QPoint(380, 10), QSize(101, 61)));
    connect(pushTeleport, SIGNAL(clicked()), this, SLOT(on_pushTeleport_clicked()));




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushMap_clicked()
{
    ui->MainOutput->setText("[h] --- [f] --- [g]\n         |         \n         |         \n[c] --- [a] --- [b]\n         |         \n         |         \n[i] --- [d] --- [e]\n |                 \n |                 \n[j] --- [k] --- [l]");

}

void MainWindow::on_pushTake_clicked()
{
}

void MainWindow::on_pushDrop_clicked()
{

}

void MainWindow::on_pushNorth_clicked()
{
    ZorkUL obj;
    Room* nextRoom = obj.currentRoom->nextRoom("north");
    obj.currentRoom = nextRoom;
    string output = obj.currentRoom->longDescription();
    QString qstr = QString::fromStdString(output);
    ui->MainOutput->setText(qstr);
}

void MainWindow::on_pushSouth_clicked()
{

}

void MainWindow::on_pushEast_clicked()
{

}

void MainWindow::on_pushWest_clicked()
{

}

void MainWindow::on_pushQuit_clicked()
{
    exit(0);

}

void MainWindow::on_pushTeleport_clicked()
{

}
