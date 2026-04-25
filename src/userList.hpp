#pragma once
#include "user.hpp"
#include <vector>

class userList{
    public:
    userList();

    void add();
    void remove();
    int size();

    private:
    std::vector<user> list;
};
