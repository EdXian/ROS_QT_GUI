#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QtWebEngineWidgets/QWebEngineSettings>

#include "QFileInfo"
#include "geocode_data_manager.h"
#include "QDebug"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //geocode_data_manager geo;
    //QString str;
      QWebEngineView* webview = new QWebEngineView;
      QUrl url = QUrl("qrc:/html/map.html");

      //url.setUrl(QUrl::fromLocalFile("map.html"));

      // QUrl::fromLocalFile("map.html");
      //webview->setUrl(QUrl::fromLocalFile("map.html"));
      QString s=QFileInfo("googlemap/map.html").absoluteFilePath();

     qDebug()<< s;
      // webview->page()->load(url);
     webview->setUrl(s);
      // webview->page()->runJavaScript();
       ui->verticalLayout->addWidget(webview);

}

MainWindow::~MainWindow()
{
    delete ui;
}
