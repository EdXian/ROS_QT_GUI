#include"stdio.h"
#include"ros/ros.h"
#include"GUI/mainwindow.h"
#include <QApplication>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ros_qt_template");
  QApplication app(argc, argv);
  MainWindow window;
  window.show();
 return app.exec();
}
