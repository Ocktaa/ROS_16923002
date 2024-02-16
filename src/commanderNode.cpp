#include "tugas1/commander.h"
#include "ros/ros.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "commanderNode");
    ros::NodeHandle nh;

    Commander nc = Commander(&nh);
    ros::spin();

    return 0;
}