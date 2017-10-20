#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QtWebEngineWidgets/QWebEngineSettings>

#include "geocode_data_manager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    geocode_data_manager geo;
    //QString str;
   QWebEngineView* webview = new QWebEngineView; //address=1600+Amphitheatre+Parkway,+Mountain+View,+CA  https://maps.googleapis.com/maps/api/geocode/json?latlng=40.714224,-73.961452&key=YOUR_API_KEY
      QUrl url = QUrl("https://maps.googleapis.com/maps/api/geocode/json?address=taipei101&key=AIzaSyADViN2MPMwHpiKa4E6KnXiNfQH-KoGwAk");
     //QUrl url = QUrl("https://www.google.com.tw/maps/@24.785981, 120.997351,16z?hl=zh-TW");
      // QUrl url = QUrl("https://maps.googleapis.com/maps/api/js?key=AIzaSyCSyQJ3wxBdwdN3WjYy2_A15lMINE6lBu0&libraries=drawing");

     // QUrl url = QUrl("qrc:/map.html");
       webview->page()->load(url);
      // webview->page()->runJavaScript();
       ui->verticalLayout->addWidget(webview);

}

MainWindow::~MainWindow()
{
    delete ui;
}
