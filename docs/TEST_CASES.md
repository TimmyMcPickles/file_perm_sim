# Test Cases

These are simple test cases we can use to check the simulator as it develops.

## Current command tests

| Command | Expected Result |
|---|---|
| `help` | command menu is displayed |
| `adduser alice 1001` | user is created |
| `adduser alice 1001` twice | second command gives duplicate user error |
| `adduser bob abc` | error because UID is not an integer |
| `adduser bob -1` | error because UID is negative |
| `listusers` | user information/count is displayed |
| `deluser alice` | user is deleted |
| `deluser missinguser` | error because user does not exist |
| `addgroup students 100` | group is created |
| `addgroup students 100` twice | second command gives duplicate group error |
| `addgroup staff abc` | error because GID is not an integer |
| `addgroup staff -1` | error because GID is negative |
| `listgroups` | group information/count is displayed |
| `delgroup students` | group is deleted |
| `delgroup missinggroup` | error because group does not exist |
| `exit` | program exits |

## Planned permission tests

These can be used once file and directory commands are fully connected.

| Permission | User Type | Action | Expected Result |
|---:|---|---|---|
| `600` | owner | read | allowed |
| `600` | owner | write | allowed |
| `600` | other | read | denied |
| `644` | other | read | allowed |
| `644` | other | write | denied |
| `755` | other | execute | allowed |
| `640` | group member | read | allowed |
| `640` | group member | write | denied |

## Planned directory tests

| Permission | Action | Expected Result |
|---:|---|---|
| `700` | create file as owner | allowed |
| `755` | create file as other | denied |
| `777` | create file as other | allowed |
| `555` | list directory | allowed |
| `333` | list directory | denied |
