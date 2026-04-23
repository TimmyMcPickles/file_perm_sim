#pragma once
#include "directory.hpp"

//Get Functions

std::string directory::getName() {
    return directoryName;
}

std::string directory::getOwnerName() {
    return ownerUser;
}

int directory::getOwnerUID() {
    return ownerUID;
}
std::string directory::getOwnerGroup() {
    return ownerGroup;
}

int directory::getOwnerGID() {
    return ownerGID;
}

int directory::getPerm() {
    return perm;
}


//Set Functions

void directory::setPerm(int newPerm) {
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
bool directory::checkOctal(int num) {
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