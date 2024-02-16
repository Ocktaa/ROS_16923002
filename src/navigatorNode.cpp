#include "tugas1/navigator.h"
#include "ros/ros.h"


int main(int argc, char** argv){
    ros::init(argc, argv, "navigatorNode");
    ros::NodeHandle nh;
    Navigator nc = Navigator(&nh);
    ros::Rate loop_rate(1);
    while (ros::ok()){
        nc.publish();
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}