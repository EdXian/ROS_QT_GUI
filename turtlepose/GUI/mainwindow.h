#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ros/ros.h"
#include "ui_mainwindow.h"
#include"stdio.h"
#include"turtlesim/Pose.h"
#include"QTimer"
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



  void on_pushButton_clicked();

private:
    ros::NodeHandlePtr nh;
    ros::Subscriber tp_pose_sub;
    turtlesim::Pose t_pose;
    ros::Rate loop_rate;
    Ui::MainWindow *ui;

  void tp_callback(const turtlesim::Pose::ConstPtr& msg);
};

#endif // MAINWINDOW_H
