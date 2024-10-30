#include <stdio.h>
#include "main.h"

void uninitializedVariableExample() {
    int x;
    printf("Value of x: %d\n", x); // Use of uninitialized variable
}

void nullPointerDereferenceExample() {
    int *ptr = NULL;
    *ptr = 42; // Dereferencing a null pointer
}

void bufferOverflowExample(const char *input) {
    char buffer[10];
    strcpy(buffer, input); // Potential buffer overflow if input is larger than 10 characters
    printf("Buffer content: %s\n", buffer);
}

int main() {
    printf("Hello, World!\n");
    
    // vars.c
    uninitializedVariableExample();

    // pointer.c
    nullPointerDereferenceExample();

    // buffer.c
    bufferOverflowExample("This is a very long input that will overflow the buffer");

    return 0;
}