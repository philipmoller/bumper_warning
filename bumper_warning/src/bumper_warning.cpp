#include <ros/ros.h>
#include <kobuki_msgs/BumperEvent.h>

void clbk_bumper(const kobuki_msgs::BumperEvent::ConstPtr& msg){
  ROS_ERROR("Obstacle hit, move back!");

  ros::Duration(3).sleep();

}

int main(int argc, char **argv){

  ros::init(argc, argv, "bumper_warning");
  ros::NodeHandle n;

  ros::Subscriber sub_bumper = n.subscribe("/mobile_base/events/bumper", 1, clbk_bumper);

  if(BumperEvent = true){
    break;
  }


  ros::spin();
}
