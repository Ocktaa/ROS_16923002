
#include "tugas1/commander.h"

Commander::Commander(ros::NodeHandle *nh)
{
    nodeclass = nh;
    sub = nh->subscribe("/drone_status", 1000, &Commander::commanderCallBack, this);
    client = nodeclass->serviceClient<tugas1::Command>("land_drone");

}

void Commander::commanderCallBack(const tugas1::DronePos& pose){
    ROS_INFO("I heard the x position is: %f", pose.x);
    ROS_INFO("I heard the y position is: %f", pose.y);
    ROS_INFO("I heard the z position is: %f", pose.z);
    ROS_INFO("I heard the drone status is: %s", pose.status.c_str());

    if (pose.x > 500 || pose.y < -400){
        
        callLandDrone();
    }

}

void Commander::callLandDrone(){
    tugas1::Command srv;
    srv.request.command = "land";
    if (client.call(srv))
    {
        ROS_INFO("Drone land is: %s", srv.response.response.c_str());
    }
    else{
        ROS_ERROR("Failed to call service land_drone");
    }
}
