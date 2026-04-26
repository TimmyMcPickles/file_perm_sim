// Ethan Prescott
#include "user.hpp"
#include <string>

user::user(){
    uid = 0;
    username = "";
}

user::user(std::string username, int id){
    setUID(id);
    setUsername(username);
}

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
