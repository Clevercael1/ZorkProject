#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "Command.h"
#include "ZorkUL.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    zork = new ZorkUL();

    QPixmap dir("C:/Users/caelo/Documents/ZorkProject/ImageFiles/dog");
    ui->ImageOutput->setPixmap(dir);
    ui->ImageOutput->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushTake_clicked()
{
}

void MainWindow::on_pushDrop_clicked()
{

}

void MainWindow::on_pushNorth_clicked()
{
    //ZorkUL zork;
    Room* currentRoom = zork->getCurrentRoom();

    try {
    currentRoom = currentRoom->nextRoom("north");
    } catch(char const* s) {
        ui->ExceptionLabel->setVisible(true);
        QString exceptionString = QString::fromStdString("No more rooms to the north");
        ui->ExceptionLabel->setText(exceptionString);
        QTimer::singleShot(5000, ui->ExceptionLabel, &QLabel::hide); //wait 10 seconds then hide error message
    }

    zork->setCurrentRoom(currentRoom);
    //string output = zork->getCurrentRoom()->shortDescription() + "\n";

    string output = currentRoom->longDescription();
    QString qstr = QString::fromStdString(output);
    ui->MainOutput->setText(qstr);
} //currentroom not changing? why?

void MainWindow::on_pushSouth_clicked()
{
    //ZorkUL zork;
    Room* currentRoom = zork->getCurrentRoom();

    try {
    currentRoom = currentRoom->nextRoom("south");
    } catch(char const* s) {
        ui->ExceptionLabel->setVisible(true);
        QString exceptionString = QString::fromStdString("No more rooms to the south");
        ui->ExceptionLabel->setText(exceptionString);
        QTimer::singleShot(5000, ui->ExceptionLabel, &QLabel::hide); //wait 10 seconds then hide error message
    }

    zork->setCurrentRoom(currentRoom);

    string output = currentRoom->longDescription();
    QString qstr = QString::fromStdString(output);
    ui->MainOutput->setText(qstr);

}

void MainWindow::on_pushEast_clicked()
{
    //ZorkUL zork;
    Room* currentRoom = zork->getCurrentRoom();

    try {
    currentRoom = currentRoom->nextRoom("east");
    } catch(char const* s) {
        ui->ExceptionLabel->setVisible(true);
        QString exceptionString = QString::fromStdString("No more rooms to the east");
        ui->ExceptionLabel->setText(exceptionString);
        QTimer::singleShot(5000, ui->ExceptionLabel, &QLabel::hide); //wait 10 seconds then hide error message
    }

    zork->setCurrentRoom(currentRoom);

    string output = currentRoom->longDescription();
    QString qstr = QString::fromStdString(output);
    ui->MainOutput->setText(qstr);

}

void MainWindow::on_pushWest_clicked()
{
    //ZorkUL zork;
    Room* currentRoom = zork->getCurrentRoom();

    try {
    currentRoom = currentRoom->nextRoom("west");
    } catch(char const* s) {
        ui->ExceptionLabel->setVisible(true);
        QString exceptionString = QString::fromStdString("No more rooms to the west");
        ui->ExceptionLabel->setText(exceptionString);
        QTimer::singleShot(5000, ui->ExceptionLabel, &QLabel::hide); //wait 10 seconds then hide error message
    }

    zork->setCurrentRoom(currentRoom);

    string output = currentRoom->longDescription();
    QString qstr = QString::fromStdString(output);
    ui->MainOutput->setText(qstr);

}

void MainWindow::on_pushQuit_clicked()
{
    exit(0);

}

void MainWindow::on_pushTeleport_clicked()
{
    string roomName;
    int randomNum = rand() % 12;
        switch(randomNum) {
        case(0):
            roomName = "a";
            break;
        case(1):
            roomName = "b";
            break;
        case(2):
            roomName = "c";
            break;
        case(3):
            roomName = "d";
            break;
        case(4):
            roomName = "e";
            break;
        case(5):
            roomName = "f";
            break;
        case(6):
            roomName = "g";
            break;
        case(7):
            roomName = "h";
            break;
        case(8):
            roomName = "i";
            break;
        case(9):
            roomName = "j";
            break;
        case(10):
            roomName = "k";
            break;
        case(11):
            roomName = "l";
            break;
        }
    zork->teleport(roomName);

}

void MainWindow::on_pushMap_pressed()
{
    ui->MainOutput->setText("[h] --- [f] --- [g]\n             |         \n             |         \n[c] --- [a] --- [b]\n             |         \n             |         \n[i] --- [d] --- [e]\n |                 \n |                 \n[j] --- [k] --- [l]");

}


void MainWindow::on_pushMap_released()
{
    Room* currentRoom = zork->getCurrentRoom();
    string output = currentRoom->longDescription();
    QString qstr = QString::fromStdString(output);
    ui->MainOutput->setText(qstr);
}

