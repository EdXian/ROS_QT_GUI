#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ros/ros.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    nh(new ros::NodeHandle)
{
    ui->setupUi(this);
    this->setWindowTitle("ros_info");
    this->ros_info_update();
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_pushButton_clicked()
{
 this->ros_info_update();
}
void MainWindow::ros_info_update()
{
  std::string topic_info,node_info;
  ros::master::V_TopicInfo rostopic_list;
  ros::V_string rosnode_list;
  if(ros::ok())
  {

      ROS_INFO("master is established");

      const std::string host_info=ros::master::getHost();
      std::cout<<"---------ros host-------"<<std::endl;
      std::cout<<"host name : "<<host_info.c_str()<<std::endl;


      std::cout<<"---------port-------"<<std::endl;
      uint32_t port_info=ros::master::getPort();
      std::cout<<"port : "<<port_info<<std::endl;


      std::cout<<"---------URI-------"<<std::endl;
      std::string URI_info=ros::master::getURI();
      std::cout<<"URI : "<<URI_info.c_str()<<std::endl;
      ui->ros_ip_textEdit->setText(URI_info.c_str());

      std::cout<<"----rosnode list---"<<std::endl;
      ros::master::getNodes(rosnode_list);
      for(ros::V_string::iterator it = rosnode_list.begin() ; it !=rosnode_list.end() ; it++)
      {
        std::string node_str=*(it);
        std::cout << "node" <<it-rosnode_list.begin()<<":"<<*(it) <<std::endl;
        //ui->nodes_textEdit->setText(node_str.c_str());
        node_info+=node_str.c_str();
        node_info+="\n";
      }
      ui->nodes_textEdit->setText(node_info.c_str());
      std::cout<<"----rostopic list---"<<std::endl;
      // ros::master::getTopics(rostopic_list);
       getRosTopics(rostopic_list);
      for (ros::master::V_TopicInfo::iterator it = rostopic_list.begin() ; it != rostopic_list.end(); it++)
      {
         ros::master::TopicInfo& info = *it;

        std::cout << "topic \t" << it - rostopic_list.begin()
                  << ": \t" << info.name<<"  \t"
                  <<"  type: "<< info.datatype
                  << std::endl;
        topic_info+=info.name;
        topic_info+="\n";
//        topic_info+=info.datatype;
//        topic_info+="\n";
      }
       ui->topics_textEdit->setText(topic_info.c_str());

  }else
  {
    ROS_INFO("master is not exit");
  }

}
