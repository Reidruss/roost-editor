#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

/* defines */
#define CTRL_KEY(k) ((k) & 0x1f)

/* data */
struct termios term;

/* terminal */

void die(const char *s) {
    perror(s);
    exit(1);
}

void disableRawMode() {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &term) == -1) {
        die("tcsetattr");
    }    
}

void enableRawMode() {
    if (tcgetattr(STDIN_FILENO, &term) == -1) {
        die("tcgetattr");
    }
    atexit(disableRawMode);

    struct termios raw = term;
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

/* output */

// escape character is "\x1b"
// "[2J" clears entire screen
// "[H" positions the cursor
void editorRefreshScreen() {
    write(STDOUT_FILENO, "\x1b[2J", 4); // escape character \x1b
    write(STDOUT_FILENO, "\x1b[H", 3);
}

/* input */

void editorProcessKeypress() {
    char c = editorReadKey();
    switch (c) {
        case CTRL_KEY('q'):
            exit(0);
            break;
    }
}


/* init */

int main(void) {
    enableRawMode();
    while (1) {
        editorRefreshScreen();
        editorProcessKeypress();
    }
    return 0;
}
