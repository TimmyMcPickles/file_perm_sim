#pragma once
#include "group.hpp"
#include <map>

class groupList{
    public:
    groupList();

    void add(group newGroup);
    void remove(std::string groupname);
    int size();

    group* getGroup(std::string groupname);
    bool groupExists(std::string groupname);

    private:
    std::map<std::string, group> groups;
};
