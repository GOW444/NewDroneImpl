#ifndef LOCATION_H
#define LOCATION_H   

#include <iostream>
#include <string>
using namespace std;

class Location {
    static const int MAX_COORD = 100; 
    string alias;
    int coordX;
    int coordY;
    int coordZ;
    bool occupied;
private:
    //helper function to check if a location is valid
	bool check(int x,int y, int z) const;

public:
    Location();
    Location(const string& alias, int x, int y, int z);
    Location(string loc,string alias);
    bool isItMe(const string& alias) const;
    bool isOccupied() const;
    void occupy();

    void setLoc(int x, int y, int z);
    void setLoc(const string& loc);

    void setX(int x);
    void setY(int y);
    void setZ(int z);

    int getX() const;
    int getY() const;
    int getZ() const;
};

#endif