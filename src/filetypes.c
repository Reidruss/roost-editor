/**
 * filetypes.c
 * Definitions for supported file types and their syntax highlighting rules.
 */

#include "data.h"
#include "filetypes.h"

char *C_HL_extensions[] = { ".c", ".h", ".cpp", NULL };

char *C_HL_keywords[] = {
    "switch", "if", "while", "for", "break", "continue", "return", "else",
    "struct", "union", "typedef", "static", "enum", "class", "case",

    "int", "long", "double", "float", "char", "unsigned", "signed", "void",
    NULL
};

struct editorSyntax HLDB[] = {
    {
        "c",
        C_HL_extensions,
        C_HL_keywords,
        "//", "/*", "*/",
        HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS
    },
};

unsigned int HLDB_ENTRIES = sizeof(HLDB) / sizeof(HLDB[0]);
