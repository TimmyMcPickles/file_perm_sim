// Ethan Prescott
#include "group.hpp"

group::group(std::string name, int id){
    groupName = name;
    gid = id;
}

std::string group::getGroupName(){
    return groupName;
}

int group::getGID(){return gid;}

void group::setGID(int id){
    gid = id;
}
