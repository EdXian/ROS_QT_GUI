#ifndef RIGIDBODY_H
#define RIGIDBODY_H
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "string.h"
#include "GUI/qcustomplot.h"
#include<QTimer>
#include <qapplication.h>
class rigidbody
{
public:

  rigidbody(std::string name);
   geometry_msgs::Point data;
private:
   void sub_loop();
  ros::NodeHandle nh;
  ros::Subscriber pose_sub;
  QTimer *timer;
  void pose_cb(const geometry_msgs::PoseStamped::ConstPtr& msg);
};

#endif // RIGIDBODY_H
