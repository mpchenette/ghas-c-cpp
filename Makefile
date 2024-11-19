CC = g++
CFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lsqlite3
TARGET = main

all: $(TARGET)

$(TARGET): main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o $(LDFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean