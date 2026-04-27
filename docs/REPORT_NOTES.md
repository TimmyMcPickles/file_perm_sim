# Report Notes

## Project summary

This project is a Unix-like file permission simulator written in C++. The goal is to show how an operating system can use users, groups, files, directories, ownership, and permission values to control access.

The current version has an interactive command-line interface for user and group management. The file and directory classes support the larger goal of simulating permission behavior as those features are connected to the command-line interface.

## Cybersecurity connection

File permissions are part of access control. Access control is important because users should only be able to access the files and directories they are allowed to use.

If permissions are too open, unauthorized users may be able to read, edit, or execute files. If permissions are too strict, authorized users may not be able to complete their work. This connects to the principle of least privilege, where users should only receive the access they need.

## Unix-style permission model

Unix-like systems commonly use three access categories:

```text
owner   group   others
```

Each category can have read, write, and execute permissions:

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

For example:

```text
755
```

means:

```text
owner: read, write, execute
group: read, execute
others: read, execute
```

## Files vs directories

Permissions mean different things depending on whether the item is a file or a directory.

| Permission | File Meaning | Directory Meaning |
|---|---|---|
| Read | View file contents | List directory contents |
| Write | Edit file contents | Add or remove items inside |
| Execute | Run the file | Enter or move through the directory |

This distinction is important because directory permissions control access to the folder structure itself, not just the files inside it.

## Project design notes

The project is organized around classes that match the simulator idea:

| Class | Role |
|---|---|
| `user` | Stores user information |
| `group` | Stores group information |
| `userList` | Manages users |
| `groupList` | Manages groups |
| `item` | Stores shared ownership and permission information |
| `file` | Represents file behavior |
| `directory` | Represents directory behavior |

This structure makes sense because files and directories share ownership and permission rules, but they handle actions differently.

## Conclusion

The project demonstrates how Unix-like permission rules can be modeled in C++. The current user and group commands provide the foundation, while the file and directory classes support the larger access-control simulation.
