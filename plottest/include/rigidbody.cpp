#include "rigidbody.h"

rigidbody::rigidbody(std::string name)
{
  pose_sub=nh.subscribe<geometry_msgs::PoseStamped>(name,10,&rigidbody::pose_cb,this);
}


void rigidbody::pose_cb(const geometry_msgs::PoseStamped::ConstPtr &msg)
{

   this->data.x=msg->pose.position.x;
   this->data.y=msg->pose.position.y;
   this->data.z=msg->pose.position.z;
}
