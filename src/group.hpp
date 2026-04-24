#pragma once
#include <string>

class group{

public:
    group(std::string name, int id);

    // Getters
    const int getGID();
    const std::string getGroupName();

    // Setters
    void setGID(int id);
private:
    int gid;
    std::string groupName;
};
