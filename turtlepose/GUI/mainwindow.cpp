#include "mainwindow.h"

using namespace std;
std::string str;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    loop_rate(100),
    nh(new ros::NodeHandle)

{
    ui->setupUi(this);
    this->setWindowTitle("turtlepose");
    tp_pose_sub=nh->subscribe<turtlesim::Pose>
        ("/turtle1/pose",10,&MainWindow::tp_callback,this);
   // ui->textEdit->setText("werq"); MainWindow::tp_callback(turtlesim::Pose::ConstPtr& msg)
}
//test /turtle1/pose
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  while(ros::ok()){

     printf("%f %f %f \n",t_pose.x,t_pose.y,t_pose.theta);
     ros::spinOnce();
     loop_rate.sleep();
  }
}

 void MainWindow::tp_callback(const turtlesim::Pose::ConstPtr& msg)
{
  //ui->textEdit->setText("werq");
 //
  t_pose.x=msg->x;
  t_pose.y=msg->y;
  t_pose.theta=msg->theta;

}
