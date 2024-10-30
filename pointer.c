#include <stdio.h>

void nullPointerDereferenceExample() {
    int *ptr = NULL;
    *ptr = 42; // Dereferencing a null pointer
}

int main() {
    nullPointerDereferenceExample();
    return 0;
}