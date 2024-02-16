#include "tugas1/navigator.h"

Navigator::Navigator(ros::NodeHandle *nh) 
{
    double x_pos {0.0};
    double y_pos {0.0};
    double z_pos {0.0};
    bool increment = true;
    pub = nh->advertise<tugas1::DronePos> ("/drone_status", 1000);    
    service = nh->advertiseService("land_drone", &Navigator::landDrone, this);
    ROS_INFO("Ready to land drone if out of range");

}

void Navigator::publish(){
    tugas1::DronePos pose;
    
    if (z_pos == 0)
    {
        pose.status = "land";
    } else if (z_pos < 10){
        pose.status = "takeoff";
    } else{
        pose.status = "fly";
    }

    if (increment){
        if (x_pos <= 1000){
            pose.x = x_pos;
            x_pos++;
        } else pose.x = --x_pos;
        if (y_pos >= -1000){
            pose.y = y_pos;
            y_pos--;
        } else pose.y = ++y_pos;

        if (z_pos <= 10){
            pose.z = z_pos;
            z_pos++;
        }
    } else {
        pose.x = x_pos;
        pose.y = y_pos;
        pose.z = z_pos;
    }

    ROS_INFO ("The x pose is %f", pose.x);
    ROS_INFO ("The y pose is %f", pose.y);
    ROS_INFO ("The z pose is %f", pose.z);
    ROS_INFO ("The status is %s", pose.status.c_str());
    pub.publish(pose);

}

bool Navigator::landDrone(tugas1::Command::Request &req, tugas1::Command::Response &res)
{
    if (req.command == "land" && z_pos != 0){
    for (int i {0}; i <= 10; i++){
        z_pos--;
        ROS_INFO("Decreasing z pose to: %f", z_pos);
    }
    if (z_pos==0){
        res.response = "successs";
    }
    else {
        res.response = "failed";
    }
    ROS_INFO ("Sending back response [%s]", res.response.c_str());
    increment = false;
    } else {
        ROS_WARN ("Drone already landed");
        return 1;
    }
    
    return 0;
}