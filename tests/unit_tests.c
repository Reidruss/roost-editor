/**
 * unit_tests.c
 * Unit tests for Roost Editor components.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "buffer.h"
#include "syntax.h"
#include "data.h"

// Mock global configuration to satisfy linker dependencies for syntax.o
struct editorConfig E;

#define ASSERT_EQ(expected, actual) \
    if ((expected) != (actual)) \
    { \
        printf("  [FAIL] %s:%d: Expected %d, got %d\n", __FILE__, __LINE__, (int)(expected), (int)(actual)); \
        return 1; \
    }

#define ASSERT_STR_EQ(expected, actual) \
    if (strcmp((expected), (actual)) != 0) \
    { \
        printf("  [FAIL] %s:%d: Expected '%s', got '%s'\n", __FILE__, __LINE__, (expected), (actual)); \
        return 1; \
    }

#define RUN_TEST(name) \
    printf("Running %s...\n", #name); \
    if (name() == 0) { \
        printf("  [PASS]\n"); \
    } else { \
        failed_tests++; \
    }

// --- Tests ---

int test_abAppend()
{
    struct abuf ab = ABUF_INIT;

    // Test initial append
    abAppend(&ab, "Hello", 5);
    ASSERT_STR_EQ("Hello", ab.b);
    ASSERT_EQ(5, ab.len);

    // Test subsequent append
    abAppend(&ab, ", World", 7);
    ASSERT_STR_EQ("Hello, World", ab.b);
    ASSERT_EQ(12, ab.len);

    abFree(&ab);
    return 0;
}

int test_is_separator()
{
    // Test known separators
    ASSERT_EQ(1, is_separator(' '));
    ASSERT_EQ(1, is_separator('.'));
    ASSERT_EQ(1, is_separator('\0'));
    ASSERT_EQ(1, is_separator(','));
    ASSERT_EQ(1, is_separator('('));

    // Test non-separators
    ASSERT_EQ(0, is_separator('a'));
    ASSERT_EQ(0, is_separator('Z'));
    ASSERT_EQ(0, is_separator('1'));
    ASSERT_EQ(0, is_separator('_')); // Underscore is usually part of identifiers

    return 0;
}

int main()
{
    int failed_tests = 0;

    printf("Starting Unit Tests...\n");

    RUN_TEST(test_abAppend);
    RUN_TEST(test_is_separator);

    if (failed_tests == 0)
    {
        printf("\nAll tests passed!\n");
        return 0;
    }
    else
    {
        printf("\n%d tests failed.\n", failed_tests);
        return 1;
    }
}
