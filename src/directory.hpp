//Kayden McClung 04/23/2026
#pragma once
#include <list>
#include <algorithm>

#include "item.hpp"
#include "file.hpp"
#include "user.hpp"


class directory : public item{

public:
    //constructory
    directory(std::string newDirectoryName,  user& ownerUser,  group& ownerGroup, directory* parentDirectory);

    //creates a new directory and adds it to subDirectoryList
    void addDirectory(std::string newDirectoryName,  user& ownerUser,  group& ownerGroup);
    //creates a new file and adds it to fileList
    void addFile(std::string newFileName,  user& ownerUser,  group& ownerGroup);

    //searches for directory in subDirectoryList and deletes it
    void delDirectory(std::string directoryName,  user& ownerUser,  group& ownerGroup);
    //searches for file in fileList and deletes it
    void delFile(std::string fileName,  user& ownerUser,  group& ownerGroup);

    //prints a list of subDirectories, files, and permissions
    void displayList( user& ownerUser,  group& ownerGroup) const;
    //prints out file path
    void displayPath() const;

    //returns pointer to a subdeirectoy that matches the name; returns null pointer if its not found
    directory* getSubDirectory(std::string dirName); 

    //removes hanging pointer and deletes all smaller lists
    ~directory();

private:
    std::list<directory*> subDirectoryList;
    std::list<file*> fileList;
    directory *parent; //pointer to parent directory

    //pointer to parentDirectory
    directory* getParent() const; //returns pointer to parent directory

    //empties both subDirectoryList and fileList and deletes objects in them
    void empty();   //called when a directory is deleted within another directory; empties the lists
};
