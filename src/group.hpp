// Ethan Prescott
#pragma once
#include <string>

class group{

public:
group();
group(std::string name, int id);

    // Getters
    int getGID();
    std::string getGroupName();

    // Setters
    void setGID(int id);
private:
    int gid;
    std::string groupName;
};
