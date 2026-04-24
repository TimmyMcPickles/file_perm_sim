#pragma once
#include "user.hpp"
#include <string>

user::user(std::string username, int id){
    setUID(id);
    setUsername(username);
}

const std::string user::getUsername(){
    return username;
}

const int user::getUID(){
    return uid;
}

void user::setUID(int id){
    uid = id;
}

void user::setUsername(std::string username){
    username = username;
}
