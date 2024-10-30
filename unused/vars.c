#include <stdio.h>

void uninitializedVariableExample() {
    int x;
    printf("Value of x: %d\n", x); // Use of uninitialized variable
}

int main() {
    uninitializedVariableExample();
    return 0;
}