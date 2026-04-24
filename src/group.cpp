#pragma once
#include "group.hpp"

group::group(std::string name, int id){
    groupName = name;
    gid = id;
}

int group::getGID(){return gid;}

void group::setGID(int id){
    gid = id;
}
