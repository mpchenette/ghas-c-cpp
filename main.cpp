#include <iostream>
#include <cstring>
#include <cstdio>
#include "main.h"

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

    return 0;
}