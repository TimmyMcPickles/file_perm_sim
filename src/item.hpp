#pragma once
#include <string>
#include <iostream>

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
