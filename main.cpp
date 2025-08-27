#include <iostream>
#include "location.h"
#include "drone.h"
using namespace std;
int main() {
    
    Location LocOne("intLoc",10,20,40);
    Location LocAnother("strLoc",0,0,0);
    LocAnother.setLoc("13,14,15");

    cout << std::boolalpha;

    cout << LocOne.isItMe("intLoc") << '\n';   
    cout << LocOne.isItMe("desert") << '\n';   
    cout << LocAnother.getX() << '\n';         
    cout << LocAnother.getY() << '\n';         
    cout << LocAnother.getZ() << '\n';         
    cout << LocOne.isOccupied() << '\n';       
    LocOne.setLoc("100,2,2");                       
    cout << LocOne.getX() << '\n';             
    cout << LocOne.getY() << '\n';             
    cout << LocOne.getZ() << '\n';             

    
    Drone d("drone1234567",LocOne);                 
    cout << d.hasID("randomID0192") << '\n';   
    d.printID();                                    
    d.showBattery();                                
    d.showLoc();
}
