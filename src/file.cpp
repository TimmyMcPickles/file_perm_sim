//Kayden McClung 04/23/2026
#pragma once
#include "file.hpp"

file::file(std::string newFileName, const user& ownerUser, const group& ownerGroup) {
    setName(newFileName);
    setOwnerUser(ownerUser);
    setOwnerGroup(ownerGroup);
    setPerm(775);
}

void file::read(const user& ownerUser, const group& ownerGroup) {  //could be changed to print to terminal
    if (permCheck(ownerUser, ownerGroup, "r") == true) std::cout << "file content: " << content << std::endl;
    else std::cout << "Error: do not have permissions for action" << std::endl;
    return;
}

void file::write(std::string newContent, const user& ownerUser, const group& ownerGroup) {
    if (permCheck(ownerUser, ownerGroup, "w") == true) content = newContent;
    else std::cout << "Error: do not have permissions for action" << std::endl;
    return;
}

void file::execute(const user& ownerUser, const group& ownerGroup) {
    if (permCheck(ownerUser, ownerGroup, "x") == true) std::cout << getName() << " executed successfully" << std::endl;
    else std::cout << "Error: do not have permissions for action" << std::endl;
    return;
}