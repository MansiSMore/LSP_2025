# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -O2

# Target binary name
TARGET = app

# Source files
SRC = main.c

# Default target
all: $(TARGET)

# Build rule
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Run the application
run: $(TARGET)
	./$(TARGET)

# Clean generated files
clean:
	rm -f $(TARGET)
