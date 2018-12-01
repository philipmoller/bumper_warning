#include <ros/ros.h>
#include <kobuki_msgs/BumperEvent.h>
#include <kobuki_msgs/CliffEvent.h>


ros::Subscriber sub_bumper;
ros::Subscriber sub_cliff;
//ros::Subscriber sub_teleop;


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
}

void clbk_cliff(const kobuki_msgs::CliffEvent::ConstPtr& asd){
  //sub_teleop.shutdown();
  ROS_INFO("Cliff detected, move back!");
}

int main(int argc, char **argv){

  ros::init(argc, argv, "bumper_warning");
  ros::NodeHandle n;

  sub_bumper = n.subscribe("/mobile_base/events/bumper", 1, clbk_bumper);

  sub_cliff = n.subscribe("/mobile_base/events/cliff", 10, clbk_cliff);

  //sub_teleop = n.subscribe("/cmd_vel_mux/input/teleop", 10, )


  ros::spin();
}
