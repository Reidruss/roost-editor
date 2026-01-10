# Roost Editor

Roost is a lightweight, terminal-based text editor written in C. It is designed for simplicity and speed, providing basic text editing features directly in your terminal.

## Features

- **Syntax Highlighting:** Support for C/C++ files.
- **Navigation:** Arrow keys, Page Up/Down, Home/End support.
- **File I/O:** Open existing files or create new ones; save changes to disk.
- **Search:** Incremental search with highlighting (Ctrl-F).
- **Modular Design:** Cleanly separated into logical components for easier maintenance.
- **Unit Tests:** Integrated test suite to ensure core logic reliability.

## Building

To build Roost, ensure you have `gcc` installed. Run:

```bash
make
```

This will compile the source files in `src/` and produce the executable `roost`.

### Running Tests

To run the unit test suite:

```bash
make test
```

## Usage

To start editing a file:

```bash
./roost <filename>
```

If the file does not exist, Roost will create it upon saving.

### Key Bindings

- `Ctrl-S`: Save file
- `Ctrl-Q`: Quit (warns if there are unsaved changes)
- `Ctrl-F`: Search in file
- `Arrows`: Move cursor
- `Page Up/Down`: Scroll a full page
- `Home/End`: Jump to start/end of line

## Directory Structure

```
.
├── include/       # Header files (.h)
├── src/           # Source files (.c)
├── tests/         # Unit tests and test artifacts
├── objs/          # Compiled object files (generated)
├── Makefile       # Build instructions
└── README.md      # Project documentation
```

## Author

Reidruss