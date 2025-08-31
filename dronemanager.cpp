#include "dronemanager.h"

//Constructor
DroneManager::DroneManager(){
    this->drone_count=0;
}

int DroneManager::getDrone_Count(){
    return drone_count;
}

void DroneManager::process_command(string cmd){
    //array to break and store the individual words/integers(for coordinates)
    string subcmds[5];
    int count=0;//count of no. of subcmds-1(-1 for 0-based indexing)
    int start=0;

    //breaking the entire line into subcmnds based on spaces(' ')
    for(int i=0;i<cmd.length();i++){
        if(cmd[i]==' '){
            subcmds[count]=cmd.substr(start,i-start);
            start=i+1;
            count++;            
        }
    }
    subcmds[count]=cmd.substr(start);
    string main_cmd=subcmds[0];
    string id=subcmds[1];
    if(id.length()!=12) return;//length of id should be 12

    if(count+1==5){
        //only for move and create command
        int x=stoi(subcmds[2]);
        int y=stoi(subcmds[3]);
        int z=stoi(subcmds[4]);
        Location loc=Location();
        loc.setLoc(x,y,z);
        if(main_cmd=="CREATE_DRONE"){
            create_drone(id,loc);
            return;
        }
        if(main_cmd=="MOVE"){
            move(id,loc);
            return;
        }
    }
    else{
        if(main_cmd=="CREATE_DRONE"){
            //if no location is given
            create_drone(id); return;
        }
        if(main_cmd=="SHOW_BATTERY"){
            show_battery(id); return;
        }
        if(main_cmd=="SHOW_LOC"){
            show_loc(id); return;
        }
        
        if(main_cmd=="SHOW_LAST_LOC"){
            show_last_loc(id); return;
        }
        
        if(main_cmd=="RECHARGE"){
            recharge(id); return;
        }
        
        if(main_cmd=="COME_TO_BASE"){
            come_2_base(id); return;
        }
        
        if(main_cmd=="DELETE_DRONE"){
            delete_drone(id); return;//break out of the while loop,if count==0
        }

    }    
}

void DroneManager::create_drone(string id,Location l=Location()){
    if(id.length()!=12) return;
    Drone new_drone = Drone(id, l);


    (this->drone_count)++;
    cout<<"CREATE_DRONE "<<id<<" DONE\n";
}

void DroneManager::delete_drone(string id){
    if(id.length()!=12) return;

    for(auto d:this->drones){
        if(d.hasID(id)){
            //delete

            (this->drone_count)--;
            return;
        }

    }
    cout<<"DELETE_DRONE FAILED.DRONE "<<id<<" DOES NOT EXIST\n";
}

void DroneManager::move(string id,Location l){
    if(id.length()!=12) return;
    int x=l.getX();
    int y=l.getY();
    int z=l.getZ();

    Location locations[]={Location("",x+1,y,z),Location("",x,y+1,z),Location("",x,y,z+1),Location("",x-1,y,z),Location("",x,y-1,z),Location("",x,y,z-1)};

    bool available=true;//if location l is available
    for(int i=0;i<MAX_DRONES;i++){
        if(drones[i].getLocation().getX()==x && drones[i].getLocation().getY()==y && drones[i].getLocation().getZ()==z ){
            available=false;
            break; //conflict with location
        }
    }

    if(available){
        for(int i=0;i<MAX_DRONES;i++){
            if(drones[i].hasID(id)){
                bool moved=drones[i].move(l);
                if(moved) cout<<true;
                else cout<<false;
                return;
            }
        }
    }

    for(auto l:locations){
        x=l.getX();
        y=l.getY();
        z=l.getZ();
        bool check=true;
        for(int i=0;i<MAX_DRONES;i++){
            if(drones[i].getLocation().getX()==x && drones[i].getLocation().getY()==y && drones[i].getLocation().getZ()==z ){
                check=false;
                break; //conflict with location
            }
        }
            if(check){
                for(int i=0;i<MAX_DRONES;i++){
                    if(drones[i].hasID(id)){
                        bool moved=drones[i].move(l);
                        if(moved) cout<<true;
                        else cout<<false;
                    return;
                    }
                }    
            }
    }
    
}

void DroneManager::recharge(string id){
    if(id.length()!=12) return ;
    for(auto d:this->drones){
        if(d.hasID(id)){
            d.recharge();
            cout<<"RECHARGE DONE\n";
            return;
        }
    }
}

void DroneManager::show_loc(string id){
    if(id.length()!=12) return;
    for(auto d:this->drones){
        if(d.hasID(id)){
            d.showLoc();
            //update the cout of showLoc in drone.cpp
            return;
        }
    }
}

void DroneManager::show_last_loc(string id){
    if(id.length()!=12) return;
    for(auto d:this->drones){
        if(d.hasID(id)){
            d.showLastLoc();
            //update the cout of showLastLoc in drone.cpp
            return;
        }
    }    
}

void DroneManager::show_battery(string id){
    if(id.length()!=12) return;
    for(auto d:this->drones){
        if(d.hasID(id)){
            d.showBattery();
            //update the cout of showbattery in drone.cpp
            return;
        }
    }    
}

void DroneManager::come_2_base(string id){
    if(id.length()!=12) return;
    for(auto d:this->drones){
        if(d.hasID(id)){
            d.comeToBase(); return;
        }
    }
    //write the cout statements
}

