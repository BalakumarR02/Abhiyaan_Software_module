#include "ros/ros.h"
#include "std_msgs/String.h"

std_msgs::String msg2;

void callback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("%s %s", msg->data.c_str(),msg2.data.c_str());
}

void callback1(const std_msgs::String::ConstPtr& msg)
{
   msg2.data=msg->data;
}
int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "listapp");

  
  ros::NodeHandle n;

  ros::Subscriber sub2 = n.subscribe("/autonomy", 10, callback1);
  ros::Subscriber sub1 = n.subscribe("/team_abhiyaan", 10, callback);
  

  
  ros::spin();

  return 0;
}
