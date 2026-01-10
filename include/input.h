/**
 * input.h
 * Header file for input handling and cursor movement.
 */

#ifndef INPUT_H
#define INPUT_H

char *editorPrompt(char *prompt, void (*callback)(char *, int));
void editorMoveCursor(int key);
void editorProcessKeypress();

#endif