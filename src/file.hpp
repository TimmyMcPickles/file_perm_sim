//Kayden McClung 04/23/2026
#pragma once
#include "item.hpp"

#include "user.hpp"


class file : public item{

public:
file(std::string newFileName, const user& ownerUser);

std::string read(); //TODO:
void write(); // TODO:
void execute(); // TODO:

private:
std::string content = "Lorem Ipsum";

};