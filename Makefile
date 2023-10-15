# Makefile

CC = gcc
CFLAGS = -Wall

# Add time.c to the list of source files
UFILES = test.c time.c

# Target executable
TARGET = test

# Source files
SRC = test.c time.c

# Header files
HEADERS = time.h

# Object files
OBJ = $(SRC:.c=.o)

# Build rule for the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Build rule for object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Add a rule to compile time.o
time.o: time.c
	$(CC) $(CFLAGS) -c time.c -o time.o

# Phony target to clean up generated files
clean:
	rm -f $(TARGET) $(OBJ)
