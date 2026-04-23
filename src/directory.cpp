#pragma once
#include "directory.hpp"

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