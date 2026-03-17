# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

TARGET = tictactoe.exe

SRCS = main.c ui.c game_logic.c
OBJS = $(SRC:.c=.o)

# Compiling
$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) $(CFLAGS)

# Run compiled file
run: $(TARGET)
	./$(TARGET)

# Clean compiled files
clean:
	rm -f $(TARGET)

# Phony declarations
.PHONY: run clean
