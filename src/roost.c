#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "terminal.h"
#include "file_io.h"
#include "output.h"
#include "input.h"

struct editorConfig E;

void initEditor() {
    E.cx = 0;
    E.cy = 0;
    E.rx = 0;
    E.rowoff = 0;
    E.coloff = 0;
    E.numrows = 0;
    E.row = NULL;
    E.dirty = 0;
    E.filename = NULL;
    E.statusmsg[0] = '\0';
    E.syntax = NULL;
    E.statusmsg_time = 0;

    if (getWindowSize(&E.rows, &E.columns) == -1) {
        die("getWindowSize");
    }
    E.rows -= 2;
}

int main(int argc, char *argv[]) {
    enableRawMode();
    initEditor();
    if (argc >= 2) {
        editorOpen(argv[1]);
    }

    editorSetStatusMessage(
                            "HELP: Ctrl-S = save | Ctrl-Q = quit | Ctrl-F = find"
                          );

    while (1) {
        editorRefreshScreen();
        editorProcessKeypress();
    }
    return 0;
}