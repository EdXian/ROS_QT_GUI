#include <QApplication>
#include"stdio.h"
#include"ros/ros.h"
#include"GUI/mainwindow.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlepose");
  QApplication app(argc, argv);
  MainWindow window;
  window.show();
  //myTimer timer;
//  turtle.myTimer();
 return app.exec();

}
