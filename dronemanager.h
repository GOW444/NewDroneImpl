#ifndef DRONEMANAGER_H
#define DRONEMANAGER_H

#include<iostream>
#include"drone.h"
#define MAX_DRONES 10

using namespace std;

class DroneManager{
    private:

    Drone drones[MAX_DRONES];//array of drones
    int drone_count;

    public:

    DroneManager();
    void process_command(string cmd);
    void create_drone(string id,Location l=Location());
    void delete_drone(string id);//check for drone count in main //break out if count==0
    void move(string id,Location l);
    void recharge(string id);
    void show_loc(string id);
    void show_last_loc(string id);
    void show_battery(string id);
    void come_2_base(string id);

};

#endif