CC = g++
CFLAGS = -Wall -Wextra -std=c++11
TARGET = main

all: $(TARGET)

$(TARGET): main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean