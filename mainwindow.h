#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "ZorkUL.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    friend class ZorkUL; //friendship

private slots:
    //void on_pushMap_clicked();
    void on_pushTake_clicked();
    void on_pushNorth_clicked();
    void on_pushSouth_clicked();
    void on_pushEast_clicked();
    void on_pushWest_clicked();
    void on_pushQuit_clicked();
    void on_pushTeleport_clicked();
    void on_pushMap_pressed();
    void on_pushMap_released();
    void on_pushInteract_clicked();
    void changeImage();

    void on_WordleInput_returnPressed();

private:
    Ui::MainWindow *ui;

    ZorkUL *zork;

protected:
    int numOfTries = 0;

};
#endif // MAINWINDOW_H
