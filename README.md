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
**Option 1: Visual Studio (Recommended)**
- Visual Studio 2015 or later with C++ support

**Option 2: MinGW (Command Line)**
- MinGW with GCC compiler
- CMake

## Installation & Build

### Linux/macOS

1. Navigate to the project directory:
```bash
cd file_perm_sim
```

2. Create a build directory:
```bash
mkdir build
cd build
```

3. Generate build files:
```bash
cmake ..
```

4. Build the project:
```bash
cmake --build .
```

5. Run the program:
```bash
./file_perm_sim
```

### Windows with Visual Studio

1. Navigate to the project directory:
```bash
cd file_perm_sim
```

2. Create a build directory:
```bash
mkdir build
cd build
```

3. Generate build files (CMake will auto-detect Visual Studio):
```bash
cmake ..
```

4. Build the project:
```bash
cmake --build .
```

5. Run the program:
```bash
./file_perm_sim.exe
```

### Windows with MinGW (Command Line)

**Important:** You MUST specify the MinGW generator when using CMake with MinGW.

1. Navigate to the project directory:
```bash
cd file_perm_sim
```

2. Create a build directory:
```bash
mkdir build
cd build
```

3. Generate build files with MinGW generator:
```bash
cmake -G "MinGW Makefiles" ..
```

4. Build the project:
```bash
cmake --build .
```

5. Run the program:
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

```
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

### Windows: "nmake not found" or compiler errors
This happens when CMake tries to use Visual Studio but it's not installed. Use the MinGW generator instead:
```bash
cmake -G "MinGW Makefiles" ..
```

### Windows MinGW: CMake still fails after using -G "MinGW Makefiles"
MinGW might not be in your system PATH. Try one of these solutions:

**Solution 1: Add MinGW to PATH**
- Find your MinGW installation (usually `C:\MinGW` or `C:\Program Files\MinGW`)
- Add `<MinGW-path>\bin` to your system PATH environment variable
- Restart your terminal and try again

**Solution 2: Specify compiler explicitly**
```bash
cmake -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=C:\MinGW\bin\g++.exe ..
```

**Solution 3: Use full path to CMake**
```bash
"C:\Program Files\CMake\bin\cmake.exe" -G "MinGW Makefiles" ..
```

### Compiler errors (all platforms)
- Ensure you have C++17 or later support
- On older systems, you may need to install a newer compiler version

### Build succeeds but executable won't run
- Ensure all dependencies are in your PATH
- Try running from the build directory where the executable was created

## Authors

- Kayden McClung
- Ethan Prescott
- Christopher Farquer
- Lee Carter

## License

See LICENSE file for details
