//Kayden McClung 04/23/2026
#pragma once
#include "file.hpp"

file::file(std::string newFileName, const user& ownerUser) {
    // TODO: implement getting user/group info; get permissions from umask too

    setName(newFileName); 

}

void file::read(const user& ownerUser, const group& ownerGroup) {  //could be changed to print to terminal
    if (permCheck(ownerUser, ownerGroup, "r") == true){
        // TODO
    }
    return;
}

void file::write(const user& ownerUser, const group& ownerGroup) {
    if (permCheck(ownerUser, ownerGroup, "w") == true){
        // TODO
    }
    return;
}

void file::execute(const user& ownerUser, const group& ownerGroup) {
    if (permCheck(ownerUser, ownerGroup, "x") == true) std::cout << getName() << " executed successfully" << std::endl;
    else std::cout << "Error: do not have permissions for action" << std::endl;
    return;
}