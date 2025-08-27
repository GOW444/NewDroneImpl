#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <string>
#include "location.h"
using namespace std;

class Drone {
private:
    // add attributes
    string ID;
    int battery;
    Location currentLoc;
    Location lastLoc;
    Location baseLoc;
    static const int MAX_BATTERY = 100;

    int getDistance(const Location& loc);
    void discharge(int distance);

public:
    // Constructors
    Drone();
    Drone(const string& id, const Location& startLoc);

    void setID(const string& id);
    void showLoc() const;
    void showLastLoc() const;
    void showBattery() const;
    void recharge();
    bool hasID(const string &checkID) const;
    void printID() const;
    
    // Move to Location
    bool move(const Location& loc);
    bool comeToBase();
};

#endif
