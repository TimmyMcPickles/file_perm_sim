//Kayden McClung 04/23/2026
#pragma once
#include <string>
#include <iostream>
#include "user.hpp"
#include "group.hpp"

class item{

public:
    //get Functions
    std::string getName() const;
    std::string getOwnerName() const;
    int getOwnerUID() const;
    std::string getOwnerGroup() const;
    int getOwnerGID() const;
    int getPerm() const;

    //set Functions
    void setName(std::string newName);
    void setOwnerUser(const user& newOwner);    //TODO:
    void setOwnerGroup(const group& newGroup);  //TODO:
    void setPerm(int newPerm);
    
    //checks if permissions are elligble
    bool permCheck(const user& currentUser, const group& currentGroup, std::string permType) const; //either r, w, or x

private:
    //variables
    std::string name;
    std::string ownerUser;
    int ownerUID;
    std::string ownerGroup;
    int ownerGID;
    int perm; //int storing permissions value, hundreth's place = user, tenth's = group, and one's = other users

    //private functions
    bool checkOctal(int num);

};
