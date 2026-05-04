//Kayden McClung 04/23/2026
#include "directory.hpp"

directory::directory(std::string newDirectoryName,  user& ownerUser,  group& ownerGroup, directory* parentDirectory) {
    setName(newDirectoryName);
    setOwnerUser(ownerUser);
    setOwnerGroup(ownerGroup);
    parent = parentDirectory;
    if (parent == NULL) setPerm(777);
    else setPerm(775);
}

//creates a new directory and pushes it to back of directories list if permissions are valid
void directory::addDirectory(std::string newDirectoryName,  user& ownerUser,  group& ownerGroup) {
    if (permCheck(ownerUser, ownerGroup, "w") == true){

        //searches list to make sure there isn't a duplicate in this loacation
        auto temp = std::find_if(subDirectoryList.begin(), subDirectoryList.end(), [&newDirectoryName](const directory* current) {
            return current->getName() == newDirectoryName;
        });

        if (temp == subDirectoryList.end()) {
            subDirectoryList.push_back(new directory(newDirectoryName, ownerUser, ownerGroup, this));
            std::cout << newDirectoryName << " has been successfully created" << std::endl;
        } else {
            std::cout << "Error: already a directory under that name in this location" << std::endl;
        }
    } else std::cout << "Error: do not have permissions for action" << std::endl;

    return;
}

//creates file and adds it to list if permissions are valid
void directory::addFile(std::string newFileName,  user& ownerUser,  group& ownerGroup) {
    if (permCheck(ownerUser, ownerGroup, "w") == true){

        //searches list to make sure there isn't a duplicate in this loacation
        auto temp = std::find_if(fileList.begin(), fileList.end(), [&newFileName](const file* current) {
            return current->getName() == newFileName;
        });

        if (temp == fileList.end()) {
            fileList.push_back(new file(newFileName, ownerUser, ownerGroup));
            std::cout << newFileName << " has been successfully created" << std::endl;
        } else {
            std::cout << "Error: already a file under that name in this location" << std::endl;
        }
    } else std::cout << "Error: do not have permissions for action" << std::endl;

    return;
}

//searches list for directory and deletes it iif permissions are valid
void directory::delDirectory(std::string directoryName,  user& ownerUser,  group& ownerGroup) {
    if (permCheck(ownerUser, ownerGroup, "w") == true){

        // searches list for a directory that that matches the name provided
        auto temp = std::find_if(subDirectoryList.begin(), subDirectoryList.end(), [&directoryName](const directory* current) {
            return current->getName() == directoryName;
        });

        if (temp != subDirectoryList.end()) { //directory found
            if ( (*temp)->subDirectoryList.empty() == false or (*temp)->fileList.empty() == false) (*temp)->empty();
            delete *temp;
            subDirectoryList.erase(temp);
            std::cout << directoryName << " has been successfully deleted." << std::endl;

        } else {
            std::cout << "Error: no such directory found." << std::endl;
        }
    } else std::cout << "Error: do not have permissions for action" << std::endl;


    return;
}

//searches for specified file and deletes it from list if permissions are valid
void directory::delFile(std::string fileName,  user& ownerUser,  group& ownerGroup) {
    if (permCheck(ownerUser, ownerGroup, "w") == true){

        // searches list for a directory that that matches the name provided
        auto temp = std::find_if(fileList.begin(), fileList.end(), [&fileName](const file* current) {
            return current->getName() == fileName;
        });

        if (temp != fileList.end()) { //directory found
            delete *temp;
            fileList.erase(temp);
            std::cout << fileName << " has been successfully deleted." << std::endl;
        } else {
            std::cout << "Error: no such file found." << std::endl;
        }
    } else std::cout << "Error: do not have permissions for action" << std::endl;

    return;
}

//prints out list of objects in both lists and their permissions
void directory::displayList(  user& ownerUser,  group& ownerGroup) const {
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

//prints out directory path
void directory::displayPath() const {
    std::string output;
    std::string slash = "\\";
    std::string currentName = getName(); // \currentname
    directory *current = getParent();
    output = slash + currentName;
    while (current != NULL) {
        current->getParent();
        output = currentName + output;
        output = slash + output;
    }

    std::cout << output << std::endl;
    return;
}

//returns pointer to specified subDirectory, specifically for open command
directory* directory::getSubDirectory(std::string dirName, user& ownerUser,  group& ownerGroup) {
    auto temp = std::find_if(subDirectoryList.begin(), subDirectoryList.end(), [&dirName](const directory* current) {
        return current->getName() == dirName;
    });

    if (temp == subDirectoryList.end()) {
        *temp = NULL;
        std::cout << "Error: could not locate directory named " << dirName << std::endl;
    }
    else if (permCheck(ownerUser, ownerGroup, "x") == false) {
        *temp = NULL;
        std::cout << "Error: invalid permissions to open directory" << std::endl;
    }
    return *temp;
}

//searches list for directory and returns it, this should be reused for getsubdirectory but meh
directory* directory::findDirectory(std::string dirName) {
    auto temp = std::find_if(subDirectoryList.begin(), subDirectoryList.end(), [&dirName](const directory* current) {
        return current->getName() == dirName;
    });

    if (temp == subDirectoryList.end()) *temp = NULL;
    return *temp;
}

//searches list for file and returns it
file* directory::findFile(std::string filName) {
    auto temp = std::find_if(fileList.begin(), fileList.end(), [&filName](const file* current) {
        return current->getName() == filName;
    });

    if (temp == fileList.end()) *temp = NULL;
    return *temp;   
}

//ensures no hanging pointer, empties lists and deletes objects in them.
directory::~directory() {
    parent = NULL;
    empty();
}


//private functions:


//returns pointer to parent directory
directory* directory::getParent() const {
    return parent;
}

//empties the lists directory
void directory::empty() {
    //emptying subDirectoryLists
    if (subDirectoryList.empty() == false) {
        for (auto& dir : subDirectoryList) {
            if (dir->subDirectoryList.empty() == false or dir->fileList.empty() == false) dir->empty();
            delete dir;
        }
        subDirectoryList.clear();
    }

    //emptying fileList
    if (fileList.empty() == false) {
        for (auto& fil : fileList)  delete fil;
        fileList.clear();
    }

    return;
}
