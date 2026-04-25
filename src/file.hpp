//Kayden McClung 04/23/2026
#pragma once
#include "item.hpp"

#include "user.hpp"


class file : public item{

public:
//constructor
file(std::string newFileName,  user& ownerUser,  group& ownerGroup);

//prints file content if permissions are valid
void read( user& ownerUser,  group& ownerGroup); 
//changes file content if permissions are valid
void write(std::string newContent, user& ownerUser,  group& ownerGroup); 
//prints that file is executed if permissions are valid
void execute( user& ownerUser,  group& ownerGroup); 

private:
std::string content = "Lorem Ipsum";

};