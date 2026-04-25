//Kayden McClung 04/23/2026
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

void item::setOwnerUser(const user& newOwner) {
    //ownerUser = newOwner.getName(); TODO: uncomment and match function name
    //ownerUID = newOwner.getUID(); TODO: uncomment
}

void item::setOwnerGroup(const group& newGroup) {
    //ownerGroup = newGroup.getName(); TODO: uncomment and match function name
    //ownerGID = newGroup.getGID(); TODO: uncomment
} 

void item::setPerm(int newPerm) {
    //checks to make sure passed int is valid
    if (checkOctal(newPerm) == false) {
        std::cout << "Error: invalid permission value" << std::endl;
    }else {
        perm = newPerm;
    }
    return;

}


// other public

bool item::permCheck(const user& currentUser, const group& currentGroup, std::string permType) const{
    bool r = false;
    bool w = false;
    bool x = false;
    bool output = false;

    int permValue = getPerm();
    /*if (currentUser.getUID() == getOwnerUID()) {
        permValue = permValue - (permValue % 10);
        permValue /= 10;
        permValue = permValue - (permValue % 10);
        permValue /=10;
    } else if (currentGroup.getGID() == getOwnerGID()){
        permValue = permValue - (permValue % 10);
        permValue /= 10;
    }
    */

    //figures out what permissions it has
    if ((permValue - 4) >= 0) {
        permValue -= 4;
        r = true;
    }
    if ((permValue - 2) >= 0) {
        permValue -= 2;
        w = true;
    }
    if ((permValue - 1) >= 0) {
        permValue -= 1;
        x = true;
    }

    if (permType == "r" & r == true) output = true;
    else if (permType == "w" & w == true) output = true;
    else if (permType == "x" & x == true) output = true;
    return output;
}

void item::print() const{
    bool r;
    bool w;
    bool x;
    std::string oPerm = "";
    std::string gPerm = "";
    std::string uPerm = "";
    int num = getPerm();
    
    //permissions string for others
    int digit = num % 10;
    if ((digit - 4) >= 0) {
        digit -= 4;
        oPerm.push_back('r');
    } else oPerm.push_back('-');
    if ((digit - 2) >= 0) {
        digit -= 2;
        oPerm.push_back('w');
    } else oPerm.push_back('-');
    if ((digit - 1) >= 0) {
        digit -= 1;
        oPerm.push_back('x');
    } else oPerm.push_back('-');
    num -= digit;
    num /= 10;

    //permissions string for group
    int digit = num % 10;
    if ((digit - 4) >= 0) {
        digit -= 4;
        gPerm.push_back('r');
    } else gPerm.push_back('-');
    if ((digit - 2) >= 0) {
        digit -= 2;
        gPerm.push_back('w');
    } else gPerm.push_back('-');
    if ((digit - 1) >= 0) {
        digit -= 1;
        gPerm.push_back('x');
    } else gPerm.push_back('-');
    num -= digit;
    num /= 10;

    //permissions string for users
    int digit = num % 10;
    if ((digit - 4) >= 0) {
        digit -= 4;
        uPerm.push_back('r');
    } else uPerm.push_back('-');
    if ((digit - 2) >= 0) {
        digit -= 2;
        uPerm.push_back('w');
    } else uPerm.push_back('-');
    if ((digit - 1) >= 0) {
        digit -= 1;
        uPerm.push_back('x');
    } else uPerm.push_back('-');

    std::cout << uPerm << " " << gPerm << " " << oPerm << " " << ownerUser << " " << ownerGroup << " " << name << std::endl;
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