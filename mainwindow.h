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

private slots:
    void on_pushMap_clicked();
    void on_pushTake_clicked();
    void on_pushDrop_clicked();
    void on_pushNorth_clicked();
    void on_pushSouth_clicked();
    void on_pushEast_clicked();
    void on_pushWest_clicked();
    void on_pushQuit_clicked();
    void on_pushTeleport_clicked();


private:
    Ui::MainWindow *ui;

    // requires an #include<QPushButton> at the top of the file
    QPushButton *pushMap;
    QPushButton *pushTake;
    QPushButton *pushDrop;
    QPushButton *pushNorth;
    QPushButton *pushSouth;
    QPushButton *pushEast;
    QPushButton *pushWest;
    QPushButton *pushQuit;
    QPushButton *pushTeleport;

};
#endif // MAINWINDOW_H
