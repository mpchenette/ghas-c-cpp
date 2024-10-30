#include <stdio.h>
#include <string.h>

void bufferOverflowExample(const char *input) {
    char buffer[10];
    strcpy(buffer, input); // Potential buffer overflow if input is larger than 10 characters
    printf("Buffer content: %s\n", buffer);
}

int main() {
    bufferOverflowExample("This is a very long input that will overflow the buffer");
    return 0;
}