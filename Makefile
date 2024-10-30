CC = g++
CFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lsqlite3
TARGET = main

all: $(TARGET)

$(TARGET): main.o Record.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o Record.o $(LDFLAGS)

main.o: main.cpp main.hpp Record.hpp
	$(CC) $(CFLAGS) -c main.cpp

Record.o: Record.cpp Record.hpp
	$(CC) $(CFLAGS) -c Record.cpp

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean