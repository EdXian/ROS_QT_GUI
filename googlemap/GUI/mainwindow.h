#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QtWebEngineWidgets/QWebEngineSettings>

#include "QFileInfo"
#include "geocode_data_manager.h"
#include "QDebug"
#include <QtWebChannel/QtWebChannel>
#include "ros/ros.h"
#include "mavros_msgs/GlobalPositionTarget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:
    void sub_loop();
private:
    ros::NodeHandle nh;
    ros::Publisher gps_pub;
    QTimer *timer;
    Ui::MainWindow *ui;
    QWebEngineView* webview;
    mavros_msgs::GlobalPositionTarget gps_target;
    double east,north,alt;
};

#endif // MAINWINDOW_H
