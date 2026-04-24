#pragma once
#include "user.hpp"

user::user(std::string username, int id){
    setUID(id);
    setUsername(username);
}

int user::getUID(){
    return uid;
}

void user::setUID(int id){
    uid = id;
}

void user::setUsername(std::string username){
    username = username;
}
