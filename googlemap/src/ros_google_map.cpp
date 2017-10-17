#include"stdio.h"
#include"ros/ros.h"
#include"GUI/mainwindow.h"
#include <QApplication>

int main(int argc, char **argv)
{
//    ros::init(argc, argv, "ros_google_map");
//    ros::NodeHandle nh;
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
   return app.exec();

}
