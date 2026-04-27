# Test Cases

These test cases are meant to help the group check the simulator as features are added. They are split into current tests and future permission tests.

## Current user command tests

| Test | Command | Expected Result |
|---|---|---|
| Add valid user | `adduser alice 1001` | User is created |
| Duplicate user | `adduser alice 1001` twice | Second command gives an error |
| Invalid UID | `adduser bob abc` | Error because UID is not an integer |
| Negative UID | `adduser bob -1` | Error because UID is negative |
| List users | `listusers` | User information/count is displayed |
| Delete existing user | `deluser alice` | User is deleted |
| Delete missing user | `deluser missinguser` | Error because user does not exist |

## Current group command tests

| Test | Command | Expected Result |
|---|---|---|
| Add valid group | `addgroup students 100` | Group is created |
| Duplicate group | `addgroup students 100` twice | Second command gives an error |
| Invalid GID | `addgroup staff abc` | Error because GID is not an integer |
| Negative GID | `addgroup staff -1` | Error because GID is negative |
| List groups | `listgroups` | Group information/count is displayed |
| Delete existing group | `delgroup students` | Group is deleted |
| Delete missing group | `delgroup missinggroup` | Error because group does not exist |

## Utility command tests

| Test | Command | Expected Result |
|---|---|---|
| Help menu | `help` | Available commands are displayed |
| Unknown command | `badcommand` | Unknown command error is shown |
| Exit program | `exit` | Program closes |
| Quit program | `quit` | Program closes |

## Planned permission behavior tests

These tests can be used once file and directory actions are connected to the command-line interface.

| Permission | User Type | Action | Expected Result |
|---:|---|---|---|
| `600` | Owner | Read file | Allowed |
| `600` | Owner | Write file | Allowed |
| `600` | Other user | Read file | Denied |
| `644` | Other user | Read file | Allowed |
| `644` | Other user | Write file | Denied |
| `755` | Other user | Execute file | Allowed |
| `640` | Group member | Read file | Allowed |
| `640` | Group member | Write file | Denied |

## Planned directory behavior tests

| Permission | Action | Expected Result |
|---:|---|---|
| `700` | Owner creates file/directory | Allowed |
| `755` | Other user creates file/directory | Denied |
| `777` | Other user creates file/directory | Allowed |
| `555` | User lists directory | Allowed |
| `333` | User lists directory | Denied |
