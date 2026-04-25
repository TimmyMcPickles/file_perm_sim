#pragma once
#include "user.hpp"
#include <map>

class userList{
    public:
    userList();

    void add(user newUser);
    void remove(std::string username);
    int size();

    // Getter methods
    user* getUser(std::string username);
    bool userExists(std::string username);

    private:
    std::map<std::string, user> users;
};
