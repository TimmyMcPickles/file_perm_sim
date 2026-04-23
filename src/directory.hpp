#pragma once
#include <string>
#include <list>
#include <iostream>

#include "file.hpp"

class directory : public file{

public:
    void addDirectory(std::string newDirectoryName); 
    void addFile(std::string newFileName);

    void delDirectory(std::string directoryName);
    void delFile(std::string fileName);

private:
    std::list<directory> subDirectoryList;
    std::list<file> fileList;

};
