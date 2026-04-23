#pragma once
#include <string>
#include <list>
#include <iostream>

class directory{

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

    void addDirectory(std::string newDirectoryName); 
    void addFile(std::string newFileName);

private:
    std::string directoryName;
    std::list<directory> subDirectoryList;
    //std::list<file> fileList;
    std::string ownerUser;
    int ownerUID;
    std::string ownerGroup;
    int ownerGID;
    int perm; //int storing permissions value, hundreth's place = user, tenths = group, and last is other users

    bool checkOctal(int num);

};
