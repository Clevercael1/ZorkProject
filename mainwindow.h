#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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
    void on_pushButton3_clicked();
    void on_pushButton4_clicked();
    void on_pushButton5_clicked();


private:
    Ui::MainWindow *ui;
    // requires an #include<QPushButton> at the top of the file
    QPushButton *pushMap;
    QPushButton *push_button3;
    QPushButton *push_button4;
    QPushButton *push_button5;

};
#endif // MAINWINDOW_H
