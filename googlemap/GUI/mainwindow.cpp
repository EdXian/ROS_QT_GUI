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

    QWebEngineView* webview = new QWebEngineView;
    QUrl url = QUrl("qrc:/html/map.html");
    webview->page()->load(url);
    ui->verticalLayout->addWidget(webview);

}

MainWindow::~MainWindow()
{
    delete ui;
}
