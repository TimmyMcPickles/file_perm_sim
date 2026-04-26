#include <iostream>
#include <sstream>
#include <map>
#include <functional>
#include "item.hpp"
#include "user.hpp"
#include "group.hpp"
#include "userList.hpp"
#include "groupList.hpp"
#include "directory.hpp"

// Global database for users and groups
userList userDB;
groupList groupDB;
user *currentUser;
group *currentGroup; //if we have time, user should have a list of groups that they are in
directory *currentDir;

// Need root directory for file system simulation, but not implemented yet

// Forward declarations
void displayHelp(const std::vector<std::string>& args);
void addUser(const std::vector<std::string>& args);
void addGroup(const std::vector<std::string>& args);
void listUsers(const std::vector<std::string>& args);
void listGroups(const std::vector<std::string>& args);
void deleteUser(const std::vector<std::string>& args);
void deleteGroup(const std::vector<std::string>& args);
void exitProgram(const std::vector<std::string>& args);

void login(const std::vector<std::string>& args);
void setgroup(const std::vector<std::string>& args);

/*void makeDir(const std::vector<std::string>& args);
void pwd(const std::vector<std::string>& args);
void back(const std::vector<std::string>& args);
void removeDir(const std::vector<std::string>& args);
void makeFil(const std::vector<std::string>& args);
void removeFil(const std::vector<std::string>& args);
void openDir(const std::vector<std::string>& args);
void changePerm(const std::vector<std::string>& args);
void changeOwn(const std::vector<std::string>& args);
void changeGrp(const std::vector<std::string>& args);*/

// Command map type
using CommandHandler = std::function<void(const std::vector<std::string>&)>;
std::map<std::string, CommandHandler> commands;

void initializeCommands() {
    commands["adduser"] = addUser;
    commands["addgroup"] = addGroup;
    commands["listusers"] = listUsers;
    commands["listgroups"] = listGroups;
    commands["deluser"] = deleteUser;
    commands["delgroup"] = deleteGroup;
    commands["help"] = displayHelp;
    commands["exit"] = exitProgram;
    commands["quit"] = exitProgram;

    commands["login"] = login;
    commands["setgroup"] = setgroup;
    //commands["whoami"] = whoami; TODO

    /*commands["mkdir"] = makeDir;
    commands["pwd"] = pwd;
    commands["back"] = back;
    commands["rmdir"] = removeDir;
    commands["mkfil"] = makeFil;
    commands["rmfil"] = removeFil;
    commands["cd"] = openDir;
    commands["chmod"] = changePerm;
    commands["chown"] = changeOwn;
    commands["chgrp"] = changeGrp; */
}

std::vector<std::string> parseCommand(const std::string& input) {
    std::vector<std::string> tokens;
    std::istringstream iss(input);
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

void processCommand(const std::string& input) {
    std::vector<std::string> tokens = parseCommand(input);

    if (tokens.empty()) {
        return;
    }

    std::string command = tokens[0];

    auto it = commands.find(command);
    if (it != commands.end()) {
        it->second(tokens);
    } else {
        std::cout << "Error: Unknown command '" << command << "'. Type 'help' for available commands." << std::endl;
    }
}

void displayHelp(const std::vector<std::string>& args) {
    std::cout << "\n=== Available Commands ===" << std::endl;
    std::cout << "adduser <username> <uid>     - Create a new user" << std::endl;
    std::cout << "addgroup <groupname> <gid>   - Create a new group" << std::endl;
    std::cout << "listusers                    - Display all users" << std::endl;
    std::cout << "listgroups                   - Display all groups" << std::endl;
    std::cout << "deluser <username>           - Delete a user" << std::endl;
    std::cout << "delgroup <groupname>         - Delete a group" << std::endl;
    std::cout << "help                         - Display this help menu" << std::endl;
    std::cout << "exit, quit                   - Exit the program" << std::endl;
    std::cout << "========================\n" << std::endl;
    (void)args;
}

void addUser(const std::vector<std::string>& args) {
    if (args.size() != 3) {
        std::cout << "Error: Invalid syntax. Usage: adduser <username> <uid>" << std::endl;
        return;
    }

    std::string username = args[1];
    int uid;

    try {
        uid = std::stoi(args[2]);
    } catch (...) {
        std::cout << "Error: UID must be a valid integer." << std::endl;
        return;
    }

    if (userDB.userExists(username)) {
        std::cout << "Error: User '" << username << "' already exists." << std::endl;
        return;
    }

    if (uid < 0) {
        std::cout << "Error: UID must be a non-negative integer." << std::endl;
        return;
    }

    user newUser(username, uid);
    userDB.add(newUser);
    std::cout << "Successfully created user '" << username << "' with UID " << uid << "." << std::endl;
}

void addGroup(const std::vector<std::string>& args) {
    if (args.size() != 3) {
        std::cout << "Error: Invalid syntax. Usage: addgroup <groupname> <gid>" << std::endl;
        return;
    }

    std::string groupname = args[1];
    int gid;

    try {
        gid = std::stoi(args[2]);
    } catch (...) {
        std::cout << "Error: GID must be a valid integer." << std::endl;
        return;
    }

    if (groupDB.groupExists(groupname)) {
        std::cout << "Error: Group '" << groupname << "' already exists." << std::endl;
        return;
    }

    if (gid < 0) {
        std::cout << "Error: GID must be a non-negative integer." << std::endl;
        return;
    }

    group newGroup(groupname, gid);
    groupDB.add(newGroup);
    std::cout << "Successfully created group '" << groupname << "' with GID " << gid << "." << std::endl;
}

void listUsers(const std::vector<std::string>& args) {
    if (userDB.size() == 0) {
        std::cout << "No users in the system." << std::endl;
        (void)args;
        return;
    }

    std::cout << "\n=== Users ===" << std::endl;
    std::cout << "Total users: " << userDB.size() << std::endl;
    std::cout << "==============\n" << std::endl;
}

void listGroups(const std::vector<std::string>& args) {
    if (groupDB.size() == 0) {
        std::cout << "No groups in the system." << std::endl;
        (void)args;
        return;
    }

    std::cout << "\n=== Groups ===" << std::endl;
    std::cout << "Total groups: " << groupDB.size() << std::endl;
    std::cout << "===============\n" << std::endl;
}

void deleteUser(const std::vector<std::string>& args) {
    if (args.size() != 2) {
        std::cout << "Error: Invalid syntax. Usage: deluser <username>" << std::endl;
        return;
    }

    std::string username = args[1];

    if (!userDB.userExists(username)) {
        std::cout << "Error: User '" << username << "' does not exist." << std::endl;
        return;
    }

    userDB.remove(username);
    std::cout << "Successfully deleted user '" << username << "'." << std::endl;
}

void deleteGroup(const std::vector<std::string>& args) {
    if (args.size() != 2) {
        std::cout << "Error: Invalid syntax. Usage: delgroup <groupname>" << std::endl;
        return;
    }

    std::string groupname = args[1];

    if (!groupDB.groupExists(groupname)) {
        std::cout << "Error: Group '" << groupname << "' does not exist." << std::endl;
        return;
    }

    groupDB.remove(groupname);
    std::cout << "Successfully deleted group '" << groupname << "'." << std::endl;
}

void exitProgram(const std::vector<std::string>& args) {
    std::cout << "Goodbye!" << std::endl;
    (void)args;
    exit(0);
}



void login(const std::vector<std::string>& args) {
    if (args.size() != 2) {
        std::cout << "Error: Invalid syntax. Usage: login <username>" << std::endl;
        return;
    }

    std::string username = args[1];

    if (!userDB.userExists(username)) {
        std::cout << "Error: User '" << username << "' does not exist." << std::endl;
        return;
    }

    currentUser = userDB.getUser(username);
    std::cout << "Successfully logged in as " << username << std::endl;
}

void setgroup(const std::vector<std::string>& args) {
    if (args.size() != 2) {
        std::cout << "Error: Invalid syntax. Usage: setgroup <groupname>" << std::endl;
        return;
    }

    std::string groupname = args[1];

    if (!userDB.userExists(groupname)) {
        std::cout << "Error: Group '" << groupname << "' does not exist." << std::endl;
        return;
    }

    currentUser = userDB.getUser(groupname);
    std::cout << "Successfully set group to " << groupname << std::endl;
}



void makeDir(const std::vector<std::string>& args) {
    if (args.size() != 2) {
        std::cout << "Error: Invalid syntax. Usage: mkdir <directoryname>" << std::endl;
        return;
    }

    std::string dirname = args[1];
}

/*void makeDir(const std::vector<std::string>& args) {

}

void pwd(const std::vector<std::string>& args) {

}

void back(const std::vector<std::string>& args) {

}

void removeDir(const std::vector<std::string>& args) {

}

void makeFil(const std::vector<std::string>& args) {

}

void removeFil(const std::vector<std::string>& args) {

}

void openDir(const std::vector<std::string>& args) {

}

void changePerm(const std::vector<std::string>& args) {

}

void changeOwn(const std::vector<std::string>& args) {

}

void changeGrp(const std::vector<std::string>& args) {

} */

void initialLogin(const std::vector<std::string>& args) {
    if (args.size() != 2) {
        std::cout << "Error: Invalid syntax. Please enter a username and UID: <username> <UID>" << std::endl;
        return;
    }

    std::string username = args[0];
    int uid;

    try {
        uid = std::stoi(args[1]);
    } catch (...) {
        std::cout << "Error: UID must be a valid integer." << std::endl;
        return;
    }

    if (uid < 0) {
        std::cout << "Error: UID must be a non-negative integer." << std::endl;
        return;
    }

    user newUser(username, uid);
    userDB.add(newUser);
    std::cout << "Successfully created user '" << username << " with UID " << uid << "." << std::endl;

    currentUser = userDB.getUser(username);
    std::cout << "Successfully logged in as " << username << std::endl;

    group newGroup(username, uid);
    groupDB.add(newGroup);
    std::cout << "Default group created as " << username << " with GID set to " << uid << std::endl;

    currentGroup = groupDB.getGroup(username);
    std::cout << "Successfully set group to " << username << std::endl;
}

int main() {
    initializeCommands();

    std::string input;
    std::cout << "Welcome to the Unix-like File Permission Simulator!" << std::endl;

    while (userDB.size() == 0) {
        std::cout << "Please enter a username and user id: <username> <UID>" << std::endl;
        std::cout << "> ";
        std::getline(std::cin, input);

        if (!input.empty()) {
            std::vector<std::string> tokens = parseCommand(input);
            initialLogin(tokens);
        }
    }
    std::string rootname = "root";
    directory root(rootname, *currentUser, *currentGroup, NULL);
    //*currentDir = root;


    std::cout << "Type 'help' to see available commands." << std::endl;
    std::cout << std::endl;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (!input.empty()) {
            processCommand(input);
        }
    }

    return 0;
}
