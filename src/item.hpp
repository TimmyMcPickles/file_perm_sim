//Kayden McClung 04/23/2026
#pragma once
#include <string>
#include <iostream>
#include "user.hpp"
#include "group.hpp"

class item{

public:
    //get Functions

    //returns name
    std::string getName() const;
    //returns owner username
    std::string getOwnerName() const;
    //returns UID of owner
    int getOwnerUID() const;
    //returns name of owner Group
    std::string getOwnerGroup() const;
    //returns GID of owner group
    int getOwnerGID() const;
    //returns permission values
    int getPerm() const;


    //set Functions

    //sets Name
    void setName(std::string newName);
    //sets owner username and UID
    void setOwnerUser(user& newOwner);
    //sets owner group name and GID
    void setOwnerGroup(group& newGroup);
    //sets perm
    void setPerm(int newPerm);
    

    //other functions

    //returns bool if permissions are elligble
    bool permCheck(user& currentUser, group& currentGroup, std::string permType) const; //either r, w, or x
    //prints out name, ownership info, and permissions
    void print() const;

private:
    //variables
    std::string name;
    std::string ownerUser;
    int ownerUID;
    std::string ownerGroup;
    int ownerGID;
    int perm; //int storing permissions value, hundreth's place = user, tenth's = group, and one's = other users

    //private functions

    //returns true or false if int is in correct octal format for permissions
    bool checkOctal(int num);

};
