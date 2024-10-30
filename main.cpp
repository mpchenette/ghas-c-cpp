#include <iostream>
#include <cstring>
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

    return 0;
}