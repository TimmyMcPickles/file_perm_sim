#pragma once
#include <string>

class user{
public:
    user(std::string username, int id);
    int getUID();
    void setUID(int id);
    void setUsername(std::string username);
private:
    int uid;
    std::string username;
};
