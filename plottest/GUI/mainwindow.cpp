
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    r1("/vrpn_client_node/RigidBody1/pose"),
    x(1),y(1)
{
     ui->setupUi(this);
     this->setWindowTitle("plottest");

     timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()),this, SLOT(sub_loop()));
     //looprate
     timer->start(10);

    ui->customplot->addGraph();
    ui->customplot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsNone);
    ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customplot->graph(0)->setData(x, y);
    ui->customplot->xAxis->setLabel("x");
    ui->customplot->yAxis->setLabel("y");

    // set axes ranges, so we see all data:
    ui->customplot->xAxis->setRange(-3, 3);
    ui->customplot->yAxis->setRange(-3, 3);

}

MainWindow::~MainWindow()
{
    delete ui;
  delete timer;
}
void MainWindow::sub_loop()
{
  if(ros::ok())
  {
    ros::spinOnce();
    x[0]=r1.data.x;
    y[0]=r1.data.y;
    printf("%lf %lf \n",x[0],y[0]);

    ui->customplot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsNone);
    ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customplot->graph(0)->setData(x, y);
    ui->customplot->xAxis->setLabel("x");
    ui->customplot->yAxis->setLabel("y");
    ui->customplot->replot();
  }
  else
  {
     QApplication::quit();
  }

}
