#pragma once
#include <string>
#include <list>
#include <iostream>

class item{

public:
    //get Functions
    std::string getName();
    std::string getOwnerName();
    int getOwnerUID();
    std::string getOwnerGroup();
    int getOwnerGID();
    int getPerm();

    //set Functions
    void setOwnerUser(std::string newOwnerName);
    void setOwnerUser(int newOwnerUID);
    void setPerm(int newPerm);

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
