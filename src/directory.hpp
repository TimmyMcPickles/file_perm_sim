#pragma once
#include <string>
#include <list>

class directory{

public:
    std::string getName();
    //void addItem(type newItem); 
private:
    std::string directoryName;
    std::list<std::string> items;
};
