CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -pedantic -std=c99 -Iinclude -Isrc -g


TARGET  := roost
SRC     := src/roost.c src/filetypes.c
OBJDIR  := objs
OBJS 	:= $(SRC:src/%.c=$(OBJDIR)/%.o)


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(OBJDIR)

.PHONY: all clean