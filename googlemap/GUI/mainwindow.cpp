#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QTimer"

//#include "mavros_msgs/Waypoint.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    webview(new QWebEngineView(this)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    gps_pub = nh.advertise<mavros_msgs::GlobalPositionTarget>("gps_set",10);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(sub_loop()));
    //looprate
    timer->start(200);

    QUrl url = QUrl("qrc:/map.html");


    webview->page()->load(url);
    ui->verticalLayout->addWidget(webview);
    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
    /*
     * var mapOptions =
                {
                    center: new google.maps.LatLng( 25.0339639, 121.5644722),
                    zoom: 6,
                };
     *
     * */
    //QString caption = "test";
    /*
     * var marker = new google.maps.Marker({
     */
   // QString add_markers = QString("function ABC(){};");



    //webview->page()->runJavaScript("document.documentElement.contentEditable = true",[](const QVariant &result){ qDebug() << result; });

   // webview->page()->runJavaScript("'Java' + 'Script'" ,[](const QVariant &result){ qDebug() << result.toBool(); });

        geocode_data_manager geo;


        geo.get_location_corrdinate("nctu",this->east,this->north);
        this->alt=geo.get_location_alttitude(this->north,this->east);
        qDebug()<<"coordinate : "<<east<<north<<this->alt;

}
void MainWindow::sub_loop()
{
  if(ros::ok())
  {
    gps_target.latitude=this->north;
    gps_target.longitude=this->east;
    gps_target.altitude=this->alt;
    gps_pub.publish(gps_target);

  }else
  {

    QApplication::quit();

  }

}
MainWindow::~MainWindow()
{
    delete ui;
}
