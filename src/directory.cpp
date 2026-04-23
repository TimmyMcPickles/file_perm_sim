#pragma once
#include "directory.hpp"

directory::directory(std::string newDirectoryName, const user& ownerUser, const directory*) {
    // TODO: implement getting user/group info; get permissions from umask too

    setName(newDirectoryName); 

}

//creates a new directory and pushes it to back of directories list
void directory::addDirectory(std::string newDirectoryName, const user& ownerUser) {
    // TODO: check to make sure name isn't duplicated

    subDirectoryList.push_back(new directory(newDirectoryName, ownerUser, this));
    return;
} 

void directory::addFile(std::string newFileName) {

}

//searches list for directory and deletes it if its there
void directory::delDirectory(std::string directoryName) {
    // searches list for a directory that that matches the name provided
    auto temp = std::find_if(subDirectoryList.begin(), subDirectoryList.end(), [&directoryName](const directory& current) {
        return current.getName() == directoryName;
    });

    if (temp != subDirectoryList.end()) { //directory found
        delete *temp;
        subDirectoryList.erase(temp);
    } else {
        std::cout << "No such directory found." << std::endl;
    }

    return;
}

void directory::delFile(std::string fileName) {

}

void directory::displayList() {

}
void directory::displayPath() {

}