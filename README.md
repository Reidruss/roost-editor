# Roost Editor

Roost is a lightweight, terminal-based text editor written in C. It is designed for simplicity and speed, providing basic text editing features directly in your terminal.

## Features

- Syntax highlighting for C/C++ files
- Basic navigation (arrow keys, page up/down, home/end)
- File opening and saving
- Status messages
- Line highlighting
- Simple, hackable codebase

## Building

To build Roost, ensure you have `gcc` installed. Run:

```bash
make
```

This will compile `roost.c` and produce the executable `roost`.

## Usage

To start editing a file:

```bash
./roost <filename>
```

If the file does not exist, Roost will create it upon saving.

## Directory Structure

```
roost.c        # Main editor source code
Makefile       # Build instructions
README.md      # Project documentation
```

## Example

```bash
./roost test.txt
```

## Author

Reidruss
