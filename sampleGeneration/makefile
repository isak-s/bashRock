# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Linker flags
LDFLAGS = -lm

# Output binary
TARGET = wavegen

# Source and object files
SRC = main.c wave_forms.c
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Linking the target
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Compiling each .c into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Optional: phony targets
.PHONY: all clean
