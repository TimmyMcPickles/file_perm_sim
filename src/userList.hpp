#pragma once
#include "user.hpp"
#include <vector>

class userList{
    public:
    userList();

    void add(user name);
    void remove();
    int size();

    private:
    std::vector<user> users;
};
