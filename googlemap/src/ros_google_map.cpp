#include"stdio.h"
#include"ros/ros.h"
#include"GUI/mainwindow.h"
#include <QApplication>
#include "GUI/geocode_data_manager.h"
int main(int argc, char **argv)
{

    ros::init(argc, argv, "ros_google_map");
    ros::NodeHandle nh;

    QApplication app(argc, argv);
    MainWindow window;
//    geocode_data_manager geo;
//    geo.get_location_alttitude(24.7859852,120.9999097);
//    geo.get_location_corrdinate("nctu");
    window.show();
   return app.exec();

}
