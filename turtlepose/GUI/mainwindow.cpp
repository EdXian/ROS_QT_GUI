#include "mainwindow.h"
#include "QTextCursor"
#include <QApplication>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    loop_rate(100),
    nh(new ros::NodeHandle)
{
    ui->setupUi(this);
    this->setWindowTitle("turtlepose");
    //callback function in class method

    tp_pose_sub=nh->subscribe<turtlesim::Pose>("/turtle1/pose",10,&MainWindow::tp_callback,this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(sub_loop()));
    //looprate
    timer->start(200);

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}
void MainWindow::sub_loop()
{
  if(ros::ok())
  {
    ros::spinOnce();  //go into callback function
    ss<<"x = "<<t_pose.x<<"y = "<<t_pose.y<<"theta = "<<t_pose.theta<<endl;
    str=ss.str();
    ui->textEdit->setText(str.c_str());

    QTextCursor cursor =ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);
  }else
  {

    QApplication::quit();
    //delete ui;
  }

}
 void MainWindow::tp_callback(const turtlesim::Pose::ConstPtr& msg)
{
  t_pose.x=msg->x;
  t_pose.y=msg->y;
  t_pose.theta=msg->theta;
}
