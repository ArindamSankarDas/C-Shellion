# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -O2 -I../include

# Output directory outside cmds/
BIN_DIR := ../bin

# All .c files in cmds/ (this dir)
SRCS := $(wildcard *.c)

# Convert cshellTouch.c → ../bin/cshellTouch
BINS := $(patsubst %.c,$(BIN_DIR)/%,$(SRCS))

# Default target
all: $(BIN_DIR) $(BINS)

# Ensure bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compile each .c to corresponding bin executable
$(BIN_DIR)/%: %.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(BIN_DIR)/*
