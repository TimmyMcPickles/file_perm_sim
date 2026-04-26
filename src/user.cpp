// Ethan Prescott
#include "user.hpp"
#include <string>

user::user(std::string username, int id){
    setUID(id);
    setUsername(username);
}

user::user(){};

std::string user::getUsername(){
    return username;
}

int user::getUID(){
    return uid;
}

void user::setUID(int id){
    uid = id;
}

void user::setUsername(std::string name){
    username = name;
}
