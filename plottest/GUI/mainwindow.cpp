
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
//    r1("/vrpn_client_node/RigidBody1/pose"),
//    x(1),y(1)
      ,x(10),y(10)
{
     ui->setupUi(this);
     this->setWindowTitle("plottest");


    getRosTopics(topic_list);
    for(ros::master::V_TopicInfo::iterator it=topic_list.begin();it!=topic_list.end();it++)
    {
      ros::master::TopicInfo& info = *it;
      if(info.name.compare(0,5,"/vrpn")==0)
      {
        rigidbody_list.push_back(info.name);
      }
    }
    for(int i=0;i<rigidbody_list.size();i++)
    {
      rigidbody_group.push_back(new rigidbody(rigidbody_list[i]));
    }
    /*

    ui->customplot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsNone);
    ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    */
   //ui->customplot->addGraph();


    for(int i=0;i<10;i++)
    {
      ui->customplot->addGraph();
    }

    ui->customplot->xAxis->setLabel("x");
    ui->customplot->yAxis->setLabel("y");

    // set axes ranges, so we see all data:
    ui->customplot->xAxis->setRange(-3, 3);
    ui->customplot->yAxis->setRange(-3, 3);

    for(int i=0;i<50;i++)
    {
      ros::spinOnce();
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(sub_loop()));
    //looprate
    timer->start(10);

}

MainWindow::~MainWindow()
{
    delete ui;
  delete timer;

}
void MainWindow::sub_loop()
{
  //count++;
  if(ros::ok())
  {

     ros::spinOnce();
     ui->customplot->graph(0)->setPen(QPen(Qt::red));
     ui->customplot->graph(1)->setPen(QPen(Qt::black));
     ui->customplot->graph(2)->setPen(QPen(Qt::blue));
     ui->customplot->graph(3)->setPen(QPen(Qt::darkGreen));

     for(int i=0;i<rigidbody_group.size();i++)
     {
         x[i].push_back(rigidbody_group[i]->data.x);
         y[i].push_back(rigidbody_group[i]->data.y);
         ui->customplot->graph(i)->setLineStyle(QCPGraph::LineStyle::lsNone);
         ui->customplot->graph(i)->setScatterStyle(QCPScatterStyle::ssCircle);
         ui->customplot->graph(i)->setData(x[i], y[i]);

     }
     if(x[0].size()>400)
     {
       for(int i=0;i<rigidbody_group.size();i++)
       {
//           x[i].push_back(rigidbody_group[i]->data.x);
//           y[i].push_back(rigidbody_group[i]->data.y);
         x[i].pop_front();
         y[i].pop_front();
       }
     }

    ui->customplot->xAxis->setLabel("x");
    ui->customplot->yAxis->setLabel("y");
    ui->customplot->replot();
  }
  else
  {
     QApplication::quit();
  }
}

bool MainWindow::getRosTopics(ros::master::V_TopicInfo& topics){
    XmlRpc::XmlRpcValue args, result, payload;
    args[0] = ros::this_node::getName();
    std::string str;
    if (!ros::master::execute("getTopicTypes", args, result, payload, true)){
        std::cout << "Failed!" << std::endl;
        return false;
    }

    topics.clear();
    for (int i = 0; i < payload.size(); ++i)
        topics.push_back(ros::master::TopicInfo(std::string(payload[i][0]), std::string(payload[i][1])));
    return true;
}
