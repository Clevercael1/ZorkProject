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
}

MainWindow::~MainWindow()
{
    delete ui;
}
