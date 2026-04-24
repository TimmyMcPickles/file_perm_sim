//Kayden McClung 04/23/2026
#pragma once
#include "directory.hpp"

directory::directory(std::string newDirectoryName, const user& ownerUser, const directory* parentDirectory) {
    // TODO: implement getting user/group info; get permissions from umask too

    setName(newDirectoryName); 

}

//creates a new directory and pushes it to back of directories list
void directory::addDirectory(std::string newDirectoryName, const user& ownerUser) {
    // TODO: Implement permissions check

    //searches list to make sure there isn't a duplicate in this loacation
    auto temp = std::find_if(subDirectoryList.begin(), subDirectoryList.end(), [&newDirectoryName](const directory& current) {
        return current.getName() == newDirectoryName;
    });

    if (temp == subDirectoryList.end()) {
        subDirectoryList.push_back(new directory(newDirectoryName, ownerUser, this));
    } else {
        std::cout << "Error: already a directory under that name in this location" << std::endl;
    }
    return;
} 

void directory::addFile(std::string newFileName, const user& ownerUser) {
    // TODO: Implement permissions check

    //searches list to make sure there isn't a duplicate in this loacation
    auto temp = std::find_if(fileList.begin(), fileList.end(), [&newFileName](const directory& current) {
        return current.getName() == newFileName;
    });

    if (temp == fileList.end()) {
        fileList.push_back(new file(newFileName, ownerUser));
    } else {
        std::cout << "Error: already a file under that name in this location" << std::endl;
    }
    return;
}

//searches list for directory and deletes it if its there
void directory::delDirectory(std::string directoryName) {
    // TODO: Implement permissions check

    // searches list for a directory that that matches the name provided
    auto temp = std::find_if(subDirectoryList.begin(), subDirectoryList.end(), [&directoryName](const directory& current) {
        return current.getName() == directoryName;
    });

    if (temp != subDirectoryList.end()) { //directory found
        delete *temp;
        subDirectoryList.erase(temp);
    } else {
        std::cout << "Error: no such directory found." << std::endl;
    }
    return;
}

void directory::delFile(std::string fileName) {
    // TODO: Implement permissions check

    // searches list for a directory that that matches the name provided
    auto temp = std::find_if(fileList.begin(), fileList.end(), [&fileName](const file& current) {
        return current.getName() == fileName;
    });

    if (temp != fileList.end()) { //directory found
        delete *temp;
        fileList.erase(temp);
    } else {
        std::cout << "Error: no such file found." << std::endl;
    }
    return;
}

// TODO:
void directory::displayList() const {
    // TODO: Implement permissions check

}

// TODO:
void directory::displayPath() const {
    // TODO: Implement permissions check

}

