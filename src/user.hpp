#pragma once
#include <string>

class user{
public:

    // Getters
    user(std::string username, int id);
    const int getUID();
    const std::string getUsername();

    // Setters
    void setUID(int id);
    void setUsername(std::string username);
private:
    int uid;
    std::string username;
};
