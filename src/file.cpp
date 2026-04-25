//Kayden McClung 04/23/2026
#include "file.hpp"

//Constructor
file::file(std::string newFileName, user& ownerUser, group& ownerGroup) {
    setName(newFileName);
    setOwnerUser(ownerUser);
    setOwnerGroup(ownerGroup);
    setPerm(775);
}

//prints file content if permissions are valid
void file::read( user& ownerUser,  group& ownerGroup) {  //could be changed to print to terminal
    if (permCheck(ownerUser, ownerGroup, "r") == true) std::cout << "file content: " << content << std::endl;
    else std::cout << "Error: do not have permissions for action" << std::endl;
    return;
}

//changes file content if permissions are valid
void file::write(std::string newContent,  user& ownerUser,  group& ownerGroup) {
    if (permCheck(ownerUser, ownerGroup, "w") == true) content = newContent;
    else std::cout << "Error: do not have permissions for action" << std::endl;
    return;
}

//prints that file is executed if permissions are valid
void file::execute( user& ownerUser,  group& ownerGroup) {
    if (permCheck(ownerUser, ownerGroup, "x") == true) std::cout << getName() << " executed successfully" << std::endl;
    else std::cout << "Error: do not have permissions for action" << std::endl;
    return;
}
