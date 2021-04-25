#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

ros::Publisher velocity_publisher;

//method to move robot straight
void move(double distance);
void rotate(bool clockwise);

int main(int argc, char **argv)
{
  //initialize new ROS node robot_move 

  ros::init(argc,argv,"robot_move");
  ros::NodeHandle n;
  velocity_publisher=n.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",1000);
  
   move(3.3);
   rotate(0);
   move(1.5);
   rotate(1); 
   move(4.0);
   
	   
  
  return 0;

}

void move(double distance)
{
   geometry_msgs::Twist vel_msg;
  vel_msg.linear.x =1;
  vel_msg.linear.y =0;
   vel_msg.linear.z =0;
   
   vel_msg.angular.x = 0;
   vel_msg.angular.y = 0;
   vel_msg.angular.z =0;
   double t0 = ros::Time::now().toSec();
   double current_distance = 0.0;
  ros::Rate loop_rate(100);
  
   do{
	   velocity_publisher.publish(vel_msg);
	   double t1 = ros::Time::now().toSec();
	   current_distance = (t1-t0);
	   ros::spinOnce();
	   loop_rate.sleep();
	   
   }while(current_distance<distance);
    vel_msg.linear.x =0;
   velocity_publisher.publish(vel_msg);

  
    
}
void rotate(bool clockwise)
{ 
   geometry_msgs::Twist vel_msg;
           vel_msg.linear.x =0;
	   vel_msg.linear.y =0;
	   vel_msg.linear.z =0;
	  
	   vel_msg.angular.x = 0;
	   vel_msg.angular.y = 0;
	    vel_msg.angular.z = 3.14159265359*20/180.0;
	    if (clockwise)
	   	vel_msg.angular.z =-1* vel_msg.angular.z ;
	   
	   	

	    double t0 = ros::Time::now().toSec();
	   double current_angle = 0.0;
	   ros::Rate loop_rate(1000);
	   do{
		   velocity_publisher.publish(vel_msg);
		   double t1 = ros::Time::now().toSec();
		   current_angle = (3.14159265359*20)/(180.0) * (t1-t0);
		   ros::spinOnce();
		   loop_rate.sleep();
		  
	   }while(current_angle<(3.14159265359*80)/(180.0));
	   vel_msg.angular.z =0;
	   velocity_publisher.publish(vel_msg);


}
