# Define the compiler
CC = gcc

# Define the compiler flags
CFLAGS = -Wall -Wextra -Werror

# Define the source files
SRCS = pointer.c vars.c sql.c buffer.c

# Define the object files
OBJS = $(SRCS:.c=.o)

# Define the executable names
EXES = pointer vars sql buffer

# Default target
all: $(EXES)

# Rule to build the pointer executable
pointer: pointer.o
    $(CC) $(CFLAGS) -o pointer pointer.o

# Rule to build the vars executable
vars: vars.o
    $(CC) $(CFLAGS) -o vars vars.o

# Rule to build the sql executable
sql: sql.o
    $(CC) $(CFLAGS) -o sql sql.o -lsqlite3

# Rule to build the buffer executable
buffer: buffer.o
    $(CC) $(CFLAGS) -o buffer buffer.o

# Rule to build object files
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
    rm -f $(OBJS) $(EXES)

.PHONY: all clean