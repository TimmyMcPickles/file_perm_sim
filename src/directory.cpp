//Kayden McClung 04/23/2026
#pragma once
#include "directory.hpp"

directory::directory(std::string newDirectoryName, const user& ownerUser, const group& ownerGroup, directory* parentDirectory) {
    setName(newDirectoryName);
    setOwnerUser(ownerUser);
    setOwnerGroup(ownerGroup);
    setPerm(775);
    parent = parentDirectory;
}

//creates a new directory and pushes it to back of directories list
void directory::addDirectory(std::string newDirectoryName, const user& ownerUser, const group& ownerGroup) {
    if (permCheck(ownerUser, ownerGroup, "w") == true){

        //searches list to make sure there isn't a duplicate in this loacation
        auto temp = std::find_if(subDirectoryList.begin(), subDirectoryList.end(), [&newDirectoryName](const directory& current) {
            return current.getName() == newDirectoryName;
        });

        if (temp == subDirectoryList.end()) {
            subDirectoryList.push_back(new directory(newDirectoryName, ownerUser, ownerGroup, this));
        } else {
            std::cout << "Error: already a directory under that name in this location" << std::endl;
        }
    } else std::cout << "Error: do not have permissions for action" << std::endl;

    return;
} 

void directory::addFile(std::string newFileName, const user& ownerUser, const group& ownerGroup) {
    if (permCheck(ownerUser, ownerGroup, "w") == true){

        //searches list to make sure there isn't a duplicate in this loacation
        auto temp = std::find_if(fileList.begin(), fileList.end(), [&newFileName](const directory& current) {
            return current.getName() == newFileName;
        });

        if (temp == fileList.end()) {
            fileList.push_back(new file(newFileName, ownerUser, ownerGroup));
        } else {
            std::cout << "Error: already a file under that name in this location" << std::endl;
        }
    } else std::cout << "Error: do not have permissions for action" << std::endl;

    return;
}

//searches list for directory and deletes it if its there
void directory::delDirectory(std::string directoryName, const user& ownerUser, const group& ownerGroup) {
    if (permCheck(ownerUser, ownerGroup, "w") == true){

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
    } else std::cout << "Error: do not have permissions for action" << std::endl;

    
    return;
}

void directory::delFile(std::string fileName, const user& ownerUser, const group& ownerGroup) {
    if (permCheck(ownerUser, ownerGroup, "w") == true){

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
    } else std::cout << "Error: do not have permissions for action" << std::endl;

    return;    
}

void directory::displayList( const user& ownerUser, const group& ownerGroup) const {
    if (permCheck(ownerUser, ownerGroup, "r") == true) {
        //print directories list
        std::cout << "Directories:" << std::endl;
        for (const auto& dir : subDirectoryList) {
            dir->print();
        }
        //print file list
        std::cout << "Files:" << std::endl;
        for (const auto& fil : fileList) {
            fil->print();
        }
    } else std::cout << "Error: do not have permissions for action" << std::endl;
    return;
}

// TODO:
void directory::displayPath() const {

}

directory* directory::getSubDirectory(std::string dirName, const user& ownerUser, const group& ownerGroup) {
    auto temp = std::find_if(subDirectoryList.begin(), subDirectoryList.end(), [&dirName](const directory& current) {
        return current.getName() == dirName;
    });

    if (temp == subDirectoryList.end()) *temp = NULL;
    return *temp;
}


//private functions

//returns pointer to parent directory
directory* directory::getParent() {
    return parent;
} 

void empty();
