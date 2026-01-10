/**
 * terminal.h
 * Header file for terminal manipulation functions.
 */

#ifndef TERMINAL_H
#define TERMINAL_H

void die(const char *s);
void disableRawMode();
void enableRawMode();
int editorReadKey();
int getCursorPosition(int *rows, int *columns);
int getWindowSize(int *rows, int *columns);

#endif