#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "Command.h"
#include "ZorkUL.h"
#include <QTimer>
#include "Wordle.h"

bool doesPlayerHaveKey = false; //global variable

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    zork = new ZorkUL();

    ui->MainOutput->setVisible(true);
    ui->MainOutput->setText("Welcome to Zork, Explore this dungeon and try to find an escape");

    ui->MainOutput->setVisible(true);
    QTimer::singleShot(4000, this, [this] () { ui->MainOutput->setText("room = a.\nno items in room\nexits = east north south west"); });

    wordle = new Wordle();
    ui->WordleInput->setVisible(true);

    changeImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushTake_clicked()//todo
{
    Room* currentRoom = zork->getCurrentRoom();
    if (currentRoom->shortDescription() == "g") {
        ui->MainOutput->setText("You have picked up the lost key!!!!");
        doesPlayerHaveKey = true;
        QPixmap d15(":/Images/ImageFiles/keys.png");
        ui->ImageOutput->setPixmap(d15);
        ui->ImageOutput->setScaledContents(true);

    } else {
        QString notInRoom =  "item is not in room";
        ui->MainOutput->setText(notInRoom);
        }
     }


void MainWindow::on_pushInteract_clicked()//todo
{
    Room* currentRoom = zork->getCurrentRoom();
    if (currentRoom->shortDescription() == "l" && doesPlayerHaveKey == true) {

        ui->WordleInput->setVisible(true);

    } else if (currentRoom->shortDescription() == "l" && doesPlayerHaveKey == false) {
        ui->MainOutput->setText("You do not have a key!");
    }
}

void MainWindow::on_pushNorth_clicked()
{
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

    changeImage();
}

void MainWindow::on_pushSouth_clicked()
{
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

    changeImage();

}

void MainWindow::on_pushEast_clicked()
{
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

    changeImage();

}

void MainWindow::on_pushWest_clicked()
{
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

    changeImage();

}

void MainWindow::on_pushQuit_clicked()
{
    exit(0);

}

void MainWindow::on_pushTeleport_clicked()
{
    string roomName;
    int randomNum = rand() % 11;
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
        }
    string tp = zork->teleport(roomName);
    QString tpString = QString::fromStdString(tp);
    ui->MainOutput->setText(tpString);
    changeImage();
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

void MainWindow::changeImage()
{
    Room* currentRoom = zork->getCurrentRoom();

    if (currentRoom->shortDescription() == "a") {
        QPixmap d1(":/Images/ImageFiles/dungeon1.png");
        ui->ImageOutput->setPixmap(d1);
        ui->ImageOutput->setScaledContents(true);
    } else if (currentRoom->shortDescription() == "b") {
        QPixmap d2(":/Images/ImageFiles/dungeon2.png");
        ui->ImageOutput->setPixmap(d2);
        ui->ImageOutput->setScaledContents(true);
    } else if (currentRoom->shortDescription() == "c") {
        QPixmap d3(":/Images/ImageFiles/dungeon3.png");
        ui->ImageOutput->setPixmap(d3);
        ui->ImageOutput->setScaledContents(true);
    } else if (currentRoom->shortDescription() == "d") {
        QPixmap d4(":/Images/ImageFiles/dungeon4.png");
        ui->ImageOutput->setPixmap(d4);
        ui->ImageOutput->setScaledContents(true);
    } else if (currentRoom->shortDescription() == "e") {
        QPixmap d5(":/Images/ImageFiles/dungeon5.png");
        ui->ImageOutput->setPixmap(d5);
        ui->ImageOutput->setScaledContents(true);
    } else if (currentRoom->shortDescription() == "f") {
        QPixmap d6(":/Images/ImageFiles/dungeon6.png");
        ui->ImageOutput->setPixmap(d6);
        ui->ImageOutput->setScaledContents(true);
    } else if (currentRoom->shortDescription() == "g") {
        QPixmap d7(":/Images/ImageFiles/dungeon7.png");
        ui->ImageOutput->setPixmap(d7);
        ui->ImageOutput->setScaledContents(true);
    } else if (currentRoom->shortDescription() == "h") {
        QPixmap d8(":/Images/ImageFiles/dungeon8.png");
        ui->ImageOutput->setPixmap(d8);
        ui->ImageOutput->setScaledContents(true);
    } else if (currentRoom->shortDescription() == "i") {
        QPixmap d9(":/Images/ImageFiles/dungeon9.png");
        ui->ImageOutput->setPixmap(d9);
        ui->ImageOutput->setScaledContents(true);
    } else if (currentRoom->shortDescription() == "j") {
        QPixmap d10(":/Images/ImageFiles/dungeon10.png");
        ui->ImageOutput->setPixmap(d10);
        ui->ImageOutput->setScaledContents(true);
    } else if (currentRoom->shortDescription() == "k") {
        QPixmap d11(":/Images/ImageFiles/dungeon11.png");
        ui->ImageOutput->setPixmap(d11);
        ui->ImageOutput->setScaledContents(true);
    } else if (currentRoom->shortDescription() == "l" && doesPlayerHaveKey == true) {
        QPixmap d12(":/Images/ImageFiles/dungeon12.png");
        ui->ImageOutput->setPixmap(d12);
        ui->ImageOutput->setScaledContents(true);
        ui->MainOutput->setText("There is a game on the wall, interact with it to play.");
    } else if (currentRoom->shortDescription() == "l" && doesPlayerHaveKey == false) {
        QPixmap d14(":/Images/ImageFiles/keyhole.png");
        ui->ImageOutput->setPixmap(d14);
        ui->ImageOutput->setScaledContents(true);
        ui->MainOutput->setText("The door is locked, go look for a key!");
    }
//    QPixmap d13(":/Images/ImageFiles/escape.png");
//    ui->ImageOutput->setPixmap(d13);
//    ui->ImageOutput->setScaledContents(true);
}

