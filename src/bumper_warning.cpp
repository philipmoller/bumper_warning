#include <ros/ros.h>
#include <kobuki_msgs/BumperEvent.h>
#include <kobuki_msgs/CliffEvent.h>


ros::Subscriber sub_bumper;
ros::Subscriber sub_cliff;

void clbk_bumper(const kobuki_msgs::BumperEvent::ConstPtr& msg){
  if(msg->bumper == 1){
    ROS_INFO("Center bumper activated, move back");
  }
  else if(msg->bumper == 0){
    ROS_INFO("Left bumper activated, turn right");
  }
  else if(msg->bumper == 2){
    ROS_INFO("Right bumper activated, turn left");
  }
  system("q");

}

void clbk_cliff(const kobuki_msgs::CliffEvent::ConstPtr& asd){
  if(asd->sensor == 1){
    ROS_INFO("Cliff infront, move back!");
  }
  else if(asd->sensor == 0){
    ROS_INFO("Cliff on left side, turn right!");
  }
  else if(asd->sensor == 2){
    ROS_INFO("Cliff on right side, turn left!");
  }
  system("q");
}

int main(int argc, char **argv){

  ros::init(argc, argv, "bumper_warning");
  ros::NodeHandle n;

  sub_bumper = n.subscribe("/mobile_base/events/bumper", 1, clbk_bumper);

  sub_cliff = n.subscribe("/mobile_base/events/cliff", 10, clbk_cliff);


  ros::spin();
}
