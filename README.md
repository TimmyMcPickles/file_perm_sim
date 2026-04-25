# File Permission Simulator

A Unix-like file permission simulator written in C++ that allows you to test and understand how file permissions and user/group management work in Unix-like operating systems.

## Description

This project simulates core Unix file permission concepts including:
- User and group management
- File and directory creation
- Permission checking (read, write, execute)
- UID and GID assignment
- File ownership and group assignment

## Prerequisites

### All Platforms
- CMake 3.10 or higher
- C++17 or later compiler

### Linux/macOS
- GCC or Clang compiler
- Standard build tools

### Windows
- Visual Studio 2015 or later with C++ support, OR
- MinGW with CMake

## Installation & Build

### Step 1: Clone or Download the Project

```bash
cd file_perm_sim
```

### Step 2: Create a Build Directory

```bash
mkdir build
cd build
```

### Step 3: Generate Build Files

```bash
cmake ..
```

### Step 4: Build the Project

```bash
cmake --build .
```

## Running the Program

After building, run the executable from the build directory:

### Linux/macOS
```bash
./file_perm_sim
```

### Windows
```bash
./file_perm_sim.exe
```

## Available Commands

### User Management
- `adduser <username> <uid>` - Create a new user
- `deluser <username>` - Delete a user
- `listusers` - Display all users in the system

### Group Management
- `addgroup <groupname> <gid>` - Create a new group
- `delgroup <groupname>` - Delete a group
- `listgroups` - Display all groups in the system

### Utility
- `help` - Display all available commands
- `exit` or `quit` - Exit the program

## Example Usage

```bash
> adduser alice 1001
Successfully created user 'alice' with UID 1001.

> addgroup developers 100
Successfully created group 'developers' with GID 100.

> listusers
=== Users ===
Total users: 1
==============

> deluser alice
Successfully deleted user 'alice'.

> exit
Goodbye!
```

## Project Structure

```
file_perm_sim/
├── CMakeLists.txt          # Build configuration file
├── README.md               # This file
├── LICENSE
├── .gitignore
└── src/
    ├── main.cpp            # Main entry point and CLI
    ├── item.hpp/.cpp       # Base class for files and directories
    ├── file.hpp/.cpp       # File class
    ├── directory.hpp/.cpp  # Directory class
    ├── user.hpp/.cpp       # User class
    ├── group.hpp/.cpp      # Group class
    ├── userList.hpp/.cpp   # User management container
    └── groupList.hpp/.cpp  # Group management container
```

## Features

- ✅ Interactive command-line interface
- ✅ User and group creation/deletion
- ✅ Hash map-based efficient user/group lookup
- ✅ Input validation and error handling
- ✅ Cross-platform support (Linux, macOS, Windows)

## Future Features

- File and directory creation
- Permission modification (chmod)
- Ownership changes (chown)
- File listing with permission display
- Permission checking based on user/group
- Advanced file operations (read, write, execute)

## Troubleshooting

### CMake not found
- **Linux**: `sudo apt install cmake`
- **macOS**: `brew install cmake`
- **Windows**: Download from https://cmake.org/download/

### Compiler errors
- Ensure you have C++17 or later support
- On older systems, you may need to install a newer compiler version

### Build fails on Windows
- Try using Visual Studio 2019 or later
- Alternatively, install MinGW and ensure it's in your PATH

## Authors

- Kayden McClung
- Ethan Prescott

## License

See LICENSE file for details
