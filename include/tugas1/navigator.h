#include <ros/ros.h>
#include "tugas1/DronePos.h"
#include "tugas1/Command.h"

#ifndef _NAVIGATOR_H_
#define _NAVIGATOR_H_


class Navigator {
    private:
    double x_pos;
    double y_pos;
    double z_pos;
    bool increment;
    ros::Publisher pub;
    ros::ServiceServer service;
    
    
    public:
    Navigator(ros::NodeHandle *nh);
    void publish();

    bool landDrone(tugas1::Command::Request &req, tugas1::Command::Response &res);

};

#endif

