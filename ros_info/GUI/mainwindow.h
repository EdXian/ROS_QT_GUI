#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ros/ros.h"
#include <QMainWindow>
#include "QLabel"
#include "QDialog"
#include "QListView"
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
    Ui::MainWindow *ui;
    ros::NodeHandlePtr nh;

    void ros_info_update();
    bool getRosTopics(ros::master::V_TopicInfo& topics);
};

#endif // MAINWINDOW_H
