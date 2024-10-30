#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "main.hpp"
#include "Record.hpp"


void uninitializedVariableExample() {
    int x;
    std::cout << "Value of x: " << x << std::endl; // Use of uninitialized variable
}

void nullPointerDereferenceExample() {
    int *ptr = nullptr;
    *ptr = 42; // Dereferencing a null pointer
}

void bufferOverflowExample(const char *input) {
    char buffer[10];
    std::strcpy(buffer, input); // Potential buffer overflow if input is larger than 10 characters
    std::cout << "Buffer content: " << buffer << std::endl;
}

void insecureHttpRequestExample() {
    const char *url = "http://example.com"; // Insecure URL
    std::cout << "Making an insecure HTTP request to: " << url << std::endl;
    // Simulate an HTTP request (actual network code omitted for simplicity)
}

void unsafeGetsExample() {
    char buffer[10];
    std::cout << "Enter a string: ";
    gets(buffer); // Unsafe function, can cause buffer overflow
    std::cout << "You entered: " << buffer << std::endl;
}

void unsafeStrcpyExample(const char *input) {
    char buffer[10];
    strcpy(buffer, input); // Unsafe function, can cause buffer overflow
    std::cout << "Buffer content: " << buffer << std::endl;
}

void unsafeSprintfExample(const char *input) {
    char buffer[10];
    sprintf(buffer, "%s", input); // Unsafe function, can cause buffer overflow
    std::cout << "Buffer content: " << buffer << std::endl;
}

void unsafeStrcatExample(const char *input) {
    char buffer[10] = "Hello";
    strcat(buffer, input); // Unsafe function, can cause buffer overflow
    std::cout << "Buffer content: " << buffer << std::endl;
}

void formatStringVulnerabilityExample(const char *input) {
    char buffer[100];
    sprintf(buffer, input); // Format string vulnerability
    std::cout << "Buffer content: " << buffer << std::endl;
}

void commandInjectionExample(const char *input) {
    char command[100];
    sprintf(command, "ls %s", input); // Command injection vulnerability
    system(command);
}

void fopenWithoutCheckExample(const char *filename) {
    FILE *file = fopen(filename, "r");
    // No check for null pointer
    fprintf(file, "Writing to file without checking if it was opened successfully.\n");
    fclose(file);
}

bool signedOverflowCheck(int n1, unsigned short delta) {
    return n1 + delta < n1; // BAD
}

Record *mkRecord(int value) {
	Record myRecord(value);

	return &myRecord; // BAD: returns a pointer to `myRecord`, which is a stack-allocated object.
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    
    // vars.cpp
    uninitializedVariableExample();

    // pointer.cpp
    nullPointerDereferenceExample();

    // buffer.cpp
    bufferOverflowExample("This is a very long input that will overflow the buffer");

    // Demonstrate insecure HTTP request
    insecureHttpRequestExample();

    // Demonstrate unsafe functions
    unsafeGetsExample();
    unsafeStrcpyExample("This is a very long input that will overflow the buffer");
    unsafeSprintfExample("This is a very long input that will overflow the buffer");
    unsafeStrcatExample("This is a very long input that will overflow the buffer");
    formatStringVulnerabilityExample("This is a format string vulnerability");
    commandInjectionExample("This is a command injection vulnerability");
    fopenWithoutCheckExample("nonexistentfile.txt");
		signedOverflowCheck(100, 200);

		Record *record = mkRecord(42);
    std::cout << "Record value: " << record->getValue() << std::endl;
    delete record;


    return 0;
}