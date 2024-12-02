# compiler and flags
CC = gcc
CFLAGS = -Wall -g

# source files and object files
SRCS = main.c day1.c # Add more source files here
OBJS = $(SRCS:.c=.o)

# output executable
TARGET = aoc24

# default target: compile and link the executable
all: $(TARGET)

# linking the object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# compiling source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean up compiled files
clean:
	rm -f $(OBJS) $(TARGET)