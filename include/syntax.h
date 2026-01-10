/**
 * syntax.h
 * Header file for syntax highlighting logic.
 */

#ifndef SYNTAX_H
#define SYNTAX_H

#include "data.h"

int is_separator(int c);
void editorUpdateSyntax(erow *row);
int editorSyntaxToColor(int hl);
void editorSelectSyntaxHighlight();

#endif