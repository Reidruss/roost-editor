CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -pedantic -std=c99 -Iinclude -Isrc -g


TARGET  := roost
SRC     := src/roost.c src/filetypes.c src/terminal.c src/syntax.c src/row.c src/editor.c src/file_io.c src/find.c src/buffer.c src/output.c src/input.c
OBJDIR  := objs
OBJS 	:= $(SRC:src/%.c=$(OBJDIR)/%.o)

TEST_TARGET := unit_tests
TEST_SRC    := tests/unit_tests.c
# Objects needed for tests (excluding roost.o which has main)
TEST_OBJS   := $(OBJDIR)/buffer.o $(OBJDIR)/syntax.o $(OBJDIR)/filetypes.o


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_SRC) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(TEST_SRC) $(TEST_OBJS)

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_TARGET)
	rm -rf $(OBJDIR)

.PHONY: all clean test