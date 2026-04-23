#pragma once
#include "item.hpp"

//Get Functions

std::string item::getName() const {
    return name;
}

std::string item::getOwnerName() const {
    return ownerUser;
}

int item::getOwnerUID() const {
    return ownerUID;
}
std::string item::getOwnerGroup() const {
    return ownerGroup;
}

int item::getOwnerGID() const {
    return ownerGID;
}

int item::getPerm() const {
    return perm;
}


//Set Functions

void item::setName(std::string newName) {
    name = newName;
}

void item::setPerm(int newPerm) {
    //check to make sure passed int is valid
    if (checkOctal(newPerm) == false) {
        std::cout << "Error: invalid permission value" << std::endl;
    }else {
        perm = newPerm;
    }
    return;

}


//private functions

//returns true if no digits are above 7 (aka octal)
bool item::checkOctal(int num) {
    bool output = true;

    //num shouldn't be greater than 777 for our purposes so check that first
    if (num > 777 or num < 0) {
        output = false;
    }

    //checks all the digits individually to make sure none are 8 or higher
    else {
        while (num > 0 and output == true) {
            int digit = num % 10;
            if (digit < 8) output = false;
            num -= digit;
            num /= 10;
        }
    }

    return output;
}