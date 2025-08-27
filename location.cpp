#include "location.h"

// Default constructor
Location::Location() {
    this->alias="";
    this->coordX=0;
    this->coordY=0;
    this->coordZ=0;
    this->occupied=false;
}

// Parameterized constructor
Location::Location(const string& alias, int x, int y, int z) {
    this->alias=alias;
    this->coordX=x;
    this->coordY=y;
    this->coordZ=z;
    this->occupied=false;
}

Location::Location(string loc, string alias){
    string clean = "";
    for(char c : loc) {
        if(c != ' ') clean += c; 
    }
    size_t fi = clean.find(',');
    size_t se = clean.find(',', fi + 1);

    coordX = stoi(clean.substr(0, fi));
    coordY = stoi(clean.substr(fi + 1, se- fi - 1));
    coordZ = stoi(clean.substr(se + 1));
    this->alias = alias;
    this->occupied = false;
}

bool Location::check(int x, int y, int z) const {
    
    if(x>MAX_COORD ||x <0) return false;
	if(y>MAX_COORD ||y <0) return false;
	if(z>MAX_COORD ||z <0) return false;
    return true;
}

bool Location::isItMe(const string& alias) const {
    return this->alias==alias;
}

bool Location::isOccupied() const {
    return this->occupied;
}

void Location:: occupy() {
    if (this->isOccupied()) {
        cout << this->alias << "Already Occupied" << endl;
        return ;
    }
    this->occupied = true;
}

void Location::setLoc(int x, int y, int z) {
    
	if(!check(x,y,z)) return;
	this->coordX=x;
	this->coordY=y;
	this->coordZ=z;
}

void Location::setLoc(const string& loc) {
    string s=loc;
    string x,y,z;
    int cx,cy,cz;
    int count=0;
    for(auto a:s){
        if(a!=','){
            if(count==0) x+=a;
            if(count==1) y+=a;
            if(count==2) z+=a;
        }
        else count++;
    }
    cx=stoi(x);
    cy=stoi(y);
    cz=stoi(z);
    this->setLoc(cx,cy,cz);
}

void Location::setX(int x) {
	if(!check(x,0,0)) return;
	this->coordX=x;
}

void Location::setY(int y) {
        if(!check(0,y,0)) return;
        this->coordY=y;
}

void Location::setZ(int z) {
	if(!check(0,0,z)) return;
        this->coordZ=z;
}

int Location::getX() const {
    return this->coordX;
}

int Location::getY() const {
    return this->coordY;
}

int Location::getZ() const {
    return this->coordZ;
}
