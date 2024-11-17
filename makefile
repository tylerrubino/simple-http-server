# compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# directories and files
TARGET = build/simple-http-server
SRCS = src/main.c src/http_server.c src/response.c
OBJS = $(SRCS:.c=.o)

# build final executable
all: $(TARGET)

# link object files to create final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean up generated files
clean:
	rm -f $(OBJS) $(target)