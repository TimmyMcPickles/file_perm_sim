// Ethan Prescott
#include "groupList.hpp"

groupList::groupList(){
}

void groupList::add(group newGroup){
    // Add group to map, keyed by group name
    // If group name already exists, this will update it
    groups[newGroup.getGroupName()] = newGroup;
}

void groupList::remove(std::string groupName){
    // Remove group by group name
    if (groups.find(groupName) != groups.end()) {
        groups.erase(groupName);
    }
}

int groupList::size(){
    return groups.size();
}

group* groupList::getGroup(std::string groupName){
    // Return pointer to group if found, nullptr otherwise
    auto it = groups.find(groupName);
    if (it != groups.end()) {
        return &(it->second);
    }
    return nullptr;
}

bool groupList::groupExists(std::string groupName){
    // Check if group exists in the list
    return groups.find(groupName) != groups.end();
}
