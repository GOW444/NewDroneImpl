#include "drone.h"
#include <cmath>
// Constructor implementations
Drone::Drone() {
    ID = "";
    battery = MAX_BATTERY;
    currentLoc = Location();
    lastLoc = Location();
    baseLoc=Location();
}

Drone::Drone(const string& id, const Location& startLoc) {
    ID = id;
    battery = MAX_BATTERY;
    currentLoc = startLoc;
    lastLoc = startLoc;
    baseLoc=startLoc;
}

// Private method implementations
int Drone::getDistance(const Location& loc) {
    // implement calculate distance
    int dx = abs(currentLoc.getX() - loc.getX());
    int dy = abs(currentLoc.getY() - loc.getY());
    int dz = abs(currentLoc.getZ() - loc.getZ());
    return (int)sqrt(dx*dx + dy*dy+dz*dz);
}

void Drone::discharge(int distance) {
    // discharge according to the distance amount
    battery -= distance;
    if (battery < 0) battery = 0;
}

// Public method implementations
void Drone::setID(const string& id) {
    // fill in, should include length check for 12
    if (id.length() == 12) {
        ID = id;
    } else {
        return;
    }
}

void Drone::showLoc() const {
    // fill in
    cout << currentLoc.getX() << "," << currentLoc.getY() << "," << currentLoc.getZ()<< endl;
}

void Drone::showLastLoc() const {
    // fill in
    cout << lastLoc.getX() << "," << lastLoc.getY() << "," << lastLoc.getZ() << endl;
}

void Drone::showBattery() const {
    // fill in
    cout << battery << endl;
}

void Drone::recharge() {
    // fill in
    battery = MAX_BATTERY;
}

bool Drone::hasID(const string &checkID) const {
    // should return true if this->ID is equal to checkID. Use C++ string library function/operator
    return this->ID == checkID;
}

void Drone::printID() const {
    // fill in to print Drone's own ID
    cout << ID << endl;
}

bool Drone::move(const Location& loc) {
    // implement the logic using private methods getDistance(loc), discharge(), setLoc() 
    // do not cout
    int distance = getDistance(loc);
    if (battery < distance) {
        return false; // insufficient battery
    }
    
    lastLoc = currentLoc; // save current location as last location
    discharge(distance);  // drain battery
    currentLoc.setLoc(loc.getX(), loc.getY(), loc.getZ()); // move to new location
    
    return true; // return true if move was successful, otherwise return false
}

bool Drone::comeToBase() {
    // implement using this->move
    // do not cout
    return this->move(this->baseLoc); // return true if move was successful, otherwise return false
}
