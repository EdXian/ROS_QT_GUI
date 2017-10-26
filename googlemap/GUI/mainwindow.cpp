#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QtWebEngineWidgets/QWebEngineSettings>

#include "QFileInfo"
#include "geocode_data_manager.h"
#include "QDebug"
#include <QtWebChannel/QtWebChannel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWebEngineView* webview = new QWebEngineView;
    QUrl url = QUrl("qrc:/map.html");


    webview->page()->load(url);
    ui->verticalLayout->addWidget(webview);
    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
    /*
     * var mapOptions =
                {
                    center: new google.maps.LatLng( 25.0339639, 121.5644722),
                    zoom: 6,
                };
     *
     * */
    QString caption = "test";
    /*
     * var marker = new google.maps.Marker({
     */
    QString add_markers =
    QString("function initMap(){  ")+
    QString("var A = {lat: 25.0339639, lng: 121.5644722};")+
    QString("var marker = new google.maps.Marker({")+
    QString("position: A,")+
    QString("map: map ")+
    QString("});")+
    QString("}");

    QString title("h3 My Google Maps Demo /h3 ");

    webview->page()->runJavaScript("document.documentElement.contentEditable = true",[](const QVariant &result){ qDebug() << result; });

    webview->page()->runJavaScript(title,[](const QVariant &result){ qDebug() << result.toString(); });
     webview->page()->load(url);
}

MainWindow::~MainWindow()
{
    delete ui;
}
