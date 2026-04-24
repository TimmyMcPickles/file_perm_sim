#pragma once
#include <string>

class group{

public:
    group(std::string name, int id);
    int getGID();
    void setGID(int id);
private:
    int gid;
    std::string groupName;
};
