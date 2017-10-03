#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"stdio.h"
#include "qgraphicsview.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
    // generate some data:
  /*
    QVector<double> x(201), y(201); // initialize with entries 0..100
    for (int i=0; i<201; ++i)
    {
      x[i] = i/25.0 - 3; // x goes from -1 to 1
      y[i] = sin(x[i]*x[i]); // let's plot a quadratic function
    }
  */


    QVector<double> x(4) , y(4);

    x[0] = 0; y[0]= 0.8;
    x[1] = 0; y[1]= -0.8;
    x[2] = 1; y[2]= 0.0;
    x[3] = 0; y[3]= 0.8;


    ui->customplot->addGraph();

    ui->customplot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsNone);
     ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customplot->graph(0)->setData(x, y);
    ui->customplot->xAxis->setLabel("x");
    ui->customplot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customplot->xAxis->setRange(-3, 3);
    ui->customplot->yAxis->setRange(-3, 3);
    ui->customplot->replot();

  this->setWindowTitle("plottest");

}

MainWindow::~MainWindow()
{
    delete ui;
}


