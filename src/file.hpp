//Kayden McClung 04/23/2026
#pragma once
#include "item.hpp"

#include "user.hpp"


class file : public item{

public:
file(std::string newFileName, const user& ownerUser);

void read(const user& ownerUser, const group& ownerGroup); //could be changed to print to terminal
void write(const user& ownerUser, const group& ownerGroup); // TODO:
void execute(const user& ownerUser, const group& ownerGroup); // TODO:

private:
std::string content = "Lorem Ipsum";

};