# Command Reference Notes

This file is meant to support testing and the final report. The main README already explains how to build and run the program, so this document focuses only on the simulator commands and how they relate to the project goal.

## Current working commands

The current command-line interface supports basic user and group management.

| Command | Purpose | Example |
|---|---|---|
| `help` | Shows the command menu | `help` |
| `adduser <username> <uid>` | Creates a user | `adduser alice 1001` |
| `deluser <username>` | Deletes a user | `deluser alice` |
| `listusers` | Lists stored users | `listusers` |
| `addgroup <groupname> <gid>` | Creates a group | `addgroup students 100` |
| `delgroup <groupname>` | Deletes a group | `delgroup students` |
| `listgroups` | Lists stored groups | `listgroups` |
| `exit` / `quit` | Exits the program | `exit` |

## Planned or in-progress filesystem commands

These commands match the larger file-permission simulator goal. Some file and directory class behavior exists, but these commands still need to be connected through the main command-line interface.

| Command | Purpose |
|---|---|
| `mkdir` | Create a directory |
| `rmdir` | Remove a directory |
| `mkfil` | Create a file |
| `rmfil` | Remove a file |
| `cd` | Change/open directory |
| `chmod` | Change permission value |
| `chown` | Change owner |
| `chgrp` | Change group ownership |

## Notes

The current user and group commands are important because file permissions depend on users, groups, UIDs, GIDs, owners, and group ownership. The filesystem commands will build on this foundation.
