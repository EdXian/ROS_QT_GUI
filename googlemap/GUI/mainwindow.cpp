#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QtWebEngineWidgets/QWebEngineSettings>
#include "QJsonArray"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWebEngineView* webview = new QWebEngineView;
    QUrl url = QUrl("https://www.google.com.tw/maps/search/Google+Maps+API+warning:+NoApiKeys/@24.787318, 120.997413,15z/data=!3m1!4b1");

   // QUrl url = QUrl("https://maps.googleapis.com/maps/api/timezone/json?location=39.6034810,-119.6822510&timestamp=1331161200&key=AIzaSyA5DKH5FfPDz6NAvqWTzuMOowQ2-Z6YXxA");

    //QUrl url = QUrl("qrc:/map.html");
//    url.setHost();
//    url.setPort(10000);
    webview->page()->load(url);
    ui->verticalLayout->addWidget(webview);
}

MainWindow::~MainWindow()
{
    delete ui;
}
