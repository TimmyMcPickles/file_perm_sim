#pragma once

#include "item.hpp"


class file : public item{

public:
std::string read();

private:
std::string content;

};