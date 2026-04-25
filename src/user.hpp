// Ethan Prescott
#pragma once
#include <string>

class user{
public:

    // Getters
    user(std::string username, int id);
    int getUID();
    std::string getUsername();

    // Setters
    void setUID(int id);
    void setUsername(std::string name);
private:
    int uid;
    std::string username;
};
