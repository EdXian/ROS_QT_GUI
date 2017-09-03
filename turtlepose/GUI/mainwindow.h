#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include "ros/ros.h"
#include "ui_mainwindow.h"
#include"stdio.h"
#include"turtlesim/Pose.h"

#include <sstream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     Ui::MainWindow *ui;
private slots:

  void sub_loop();
  void on_pushButton_clicked();

private:
    ros::NodeHandlePtr nh;
    ros::Subscriber tp_pose_sub;
    ros::Rate loop_rate;
    turtlesim::Pose t_pose;
    std::string str;
    std::stringstream ss;
    QTimer *timer;

    void tp_callback(const turtlesim::Pose::ConstPtr& msg);
};

#endif // MAINWINDOW_H
