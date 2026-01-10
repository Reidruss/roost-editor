/**
 * output.h
 * Header file for output and screen drawing operations.
 */

#ifndef OUTPUT_H
#define OUTPUT_H

#include "buffer.h"

void editorScroll();
void editorDrawRows(struct abuf *ab);
void editorDrawStatusBar(struct abuf *ab);
void editorDrawMessageBar(struct abuf *ab);
void editorRefreshScreen();
void editorSetStatusMessage(const char *fmt, ...);

#endif