/**
 * file_io.h
 * Header file for file I/O operations.
 */

#ifndef FILE_IO_H
#define FILE_IO_H

char *editorRowsToString(int *buflen);
void editorOpen(char *filename);
void editorSave();

#endif