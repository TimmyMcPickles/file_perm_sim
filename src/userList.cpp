#include "userList.hpp"

userList::userList(){
}

void userList::add(user newUser){
    // Add user to map, keyed by username
    // If username already exists, this will update it
    users[newUser.getUsername()] = newUser;
}

void userList::remove(std::string username){
    // Remove user by username
    if (users.find(username) != users.end()) {
        users.erase(username);
    }
}

int userList::size(){
    return users.size();
}

user* userList::getUser(std::string username){
    // Return pointer to user if exists, nullptr otherwise
    if (users.find(username) != users.end()) {
        return &users[username];
    }
    return nullptr;
}

bool userList::userExists(std::string username){
    // Check if user exists in map
    return users.find(username) != users.end();
}
