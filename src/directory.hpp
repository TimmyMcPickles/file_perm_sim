#pragma once
#include <string>
#include <list>

class directory{

public:
    std::string getName();
    std::string getOwnerName();
    int getOwnerUID();
    std::string getOwnerGroup();
    int getOwnerGID();
    void addDirectory(std::string newDirectoryName); 
    void addFile(std::string newFileName);

private:
    std::string directoryName;
    std::list<directory> subDirectoryList;
    //std::list<file> fileList;
    std::string ownerUser;
    int ownerUID;
    int userPerm[3];
    std::string ownerGroup;
    int ownerGID;
    int groupPerm[3];
    int otherPerm[3];

};
