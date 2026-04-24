//Kayden McClung 04/23/2026
#pragma once
#include <list>
#include <algorithm>

#include "item.hpp"
#include "file.hpp"
#include "user.hpp"


class directory : public item{

public:
    directory(std::string newDirectoryName, const user& ownerUser, const directory* parentDirectory);

    void addDirectory(std::string newDirectoryName, const user& ownerUser); 
    void addFile(std::string newFileName, const user& ownerUser);

    void delDirectory(std::string directoryName);
    void delFile(std::string fileName);

    void displayList() const;
    void displayPath() const;

    //open a directory from the list
    void openDirectory(); // TODO

private:
    std::list<directory*> subDirectoryList;
    std::list<file*> fileList;
    directory *parent; //parent to parent directory

    // TODO:

    directory* getParent(); //returns pointer to parent directory

    void empty();   //called when a directory is deleted within another directory; empties the lists
    void print();   //prints out selfs
};
