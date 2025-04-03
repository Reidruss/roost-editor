#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

/* defines */
#define CTRL_KEY(k) ((k) & 0x1f)

/* data */
struct editorConfig {
    int rows;
    int columns;
    struct termios term;
};

struct editorConfig E;

/* terminal */

void die(const char *s) { 
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
    perror(s);
    exit(1);
}

void disableRawMode() {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.term) == -1) {
        die("tcsetattr");
    }    
}

void enableRawMode() {
    if (tcgetattr(STDIN_FILENO, &E.term) == -1) {
        die("tcgetattr");
    }
    atexit(disableRawMode);

    struct termios raw = E.term;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
        die("tcsetattr");
    }
}

char editorReadKey() {
    int nread;
    char c;
    while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
        if (nread == -1 && errno != EAGAIN) { 
            die("read");
        }
    }
    return c;
}

int getWindowSize(int *rows, int *columns) {
    struct winsize ws;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
        return -1;
    } else {
        *columns = ws.ws_col;
        *rows = ws.ws_row;
        return 0;
    }
}

/* output */

void editorDrawRows() {
    int y;
    for (y = 0; y < E.rows; ++y) {
        write(STDOUT_FILENO, "~\r\n", 3);
    }
}

// escape character is "\x1b"
// "[2J" clears entire screen
// "[H" positions the cursor
void editorRefreshScreen() {
    write(STDOUT_FILENO, "\x1b[2J", 4); // escape character \x1b
    write(STDOUT_FILENO, "\x1b[H", 3);

    editorDrawRows();

    write(STDOUT_FILENO, "\x1b[H", 3);
}

/* input */

void editorProcessKeypress() {
    char c = editorReadKey();
    switch (c) {
        case CTRL_KEY('q'):
            write(STDOUT_FILENO, "\x1b[2J", 4);
            write(STDOUT_FILENO, "\x1b[H", 3);
            exit(0);
            break;
    }
}


/* init */

void initEditor() {
    if (getWindowSize(&E.rows, &E.columns) == -1) {
        die("getWindowSize");
    }
}

int main(void) {
    enableRawMode();
    initEditor();


    while (1) {
        editorRefreshScreen();
        editorProcessKeypress();
    }
    return 0;
}
