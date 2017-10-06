#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ros/ros.h"
#include "include/rigidbody.h"
#include "qgraphicsview.h"
#include"stdio.h"
#include "math.h"
#include <QApplication>
#include<QTimer>
#include "ui_mainwindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void sub_loop();

private:
    //ros::Rate loop_rate;
    ros::NodeHandle nh;
    ros::Subscriber sub;
    QTimer *timer;
    Ui::MainWindow *ui;
    rigidbody r1;

    QVector<double> x,y;
};

#endif // MAINWINDOW_H
