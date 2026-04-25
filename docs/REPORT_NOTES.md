# Report Notes

## Project summary

Our project is a Unix-like file permission simulator written in C++. The goal is to show how users, groups, files, directories, and permissions work in a simulated environment.

The current version includes an interactive command-line interface with user and group management. The file and directory permission features are part of the larger project goal as the classes are connected together.

## Current features

The simulator currently supports basic commands for:

- adding users
- deleting users
- listing users
- adding groups
- deleting groups
- listing groups
- displaying help
- exiting the program

The project also includes a CMake build setup.

## Why this matters

File permissions are important in cybersecurity because they control who can access information. If permissions are too open, the wrong user may be able to view, edit, or run files. If permissions are too strict, the correct user may be blocked.

## Basic permission model

Unix-like systems use three permission categories:

```text
owner group others
```

Each category can have:

```text
r = read
w = write
x = execute
```

The numeric values are:

```text
read = 4
write = 2
execute = 1
```

Example:

```text
755
```

Means:

```text
owner: read, write, execute
group: read, execute
others: read, execute
```

## Files and directories

For files:

- read means view the file
- write means edit the file
- execute means run the file

For directories:

- read means list the directory
- write means add or remove items inside
- execute means enter or move through the directory

## Project design

The project is separated into classes:

| Class | Purpose |
|---|---|
| `user` | stores user information |
| `group` | stores group information |
| `userList` | manages users |
| `groupList` | manages groups |
| `item` | stores shared ownership and permission information |
| `file` | handles file actions |
| `directory` | handles directory actions |

## Conclusion

This project connects to cybersecurity because permissions are a basic part of access control. The current version builds the user/group foundation, and the file/directory classes support the larger goal of simulating Unix-like file permissions.
