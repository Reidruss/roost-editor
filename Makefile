CC      := gcc
CFLAGS  := -Wall -Wextra -pedantic -std=c99
TARGET  := roost
SRC     := roost.c filetypes.c
OBJ     := $(SRC:.c=.o)


all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean


