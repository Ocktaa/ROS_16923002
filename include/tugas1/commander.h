#include "ros/ros.h"
#include "tugas1/DronePos.h"
#include "tugas1/Command.h"

#ifndef _COMMANDER_H_
#define _COMMANDER_H_

class Commander {
    private:
    ros::NodeHandle *nodeclass;
    ros::Subscriber sub;
    ros::ServiceClient client;

    public:
    Commander(ros::NodeHandle *nh);
    void commanderCallBack(const tugas1::DronePos& pose);
    void callLandDrone();
};

#endif