//Kayden McClung 04/23/2026
#pragma once
#include "file.hpp"

file::file(std::string newFileName, const user& ownerUser) {
    // TODO: implement getting user/group info; get permissions from umask too

    setName(newFileName); 

}