//Kayden McClung 04/23/2026
#pragma once
#include "item.hpp"

#include "user.hpp"


class file : public item{

public:
file(std::string newFileName, const user& ownerUser, const group& ownerGroup);

void read(const user& ownerUser, const group& ownerGroup); 
void write(std::string newContent,const user& ownerUser, const group& ownerGroup); 
void execute(const user& ownerUser, const group& ownerGroup); 

private:
std::string content = "Lorem Ipsum";

};