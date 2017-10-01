#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"stdio.h"
#include "qgraphicsview.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  this->setWindowTitle("ros_qt_template");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{

}
