# Command Reference

These are the commands currently shown in the simulator or planned for later file permission features.

## Current commands

These commands are currently part of the command-line interface.

### `help`

Shows the available commands.

Example:

```text
help
```

Expected result: the simulator prints the command menu.

### `adduser`

Creates a new user.

Example:

```text
adduser alice 1001
```

Expected result: user `alice` is created with UID `1001`.

### `deluser`

Deletes an existing user.

Example:

```text
deluser alice
```

Expected result: user `alice` is removed.

### `listusers`

Lists the users currently stored in the simulator.

Example:

```text
listusers
```

Expected result: the simulator displays the current user count/list information.

### `addgroup`

Creates a new group.

Example:

```text
addgroup students 100
```

Expected result: group `students` is created with GID `100`.

### `delgroup`

Deletes an existing group.

Example:

```text
delgroup students
```

Expected result: group `students` is removed.

### `listgroups`

Lists the groups currently stored in the simulator.

Example:

```text
listgroups
```

Expected result: the simulator displays the current group count/list information.

### `exit` / `quit`

Exits the simulator.

Example:

```text
exit
```

Expected result: the simulator closes.

## Planned file permission commands

These commands are not the main working commands yet, but they match the overall project goal.

| Command | Purpose |
|---|---|
| `mkdir` | create a directory |
| `touch` | create a file |
| `rmdir` | remove a directory |
| `rm` | remove a file |
| `chmod` | change permissions |
| `chgrp` | change group ownership |
| `ls -l` | list files/directories with permissions |
