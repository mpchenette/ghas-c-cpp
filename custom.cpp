#include <cstdlib>
#include <cstring>

void example() {
    // Allocate memory for 5 characters
    char *buffer = (char *)calloc(5, sizeof(char));

    // Source string is longer than the allocated buffer
    const char *source = "Hello, World!";

    // This strcpy call will cause a buffer overflow
    strcpy(buffer, source);
}

int main() {
    example();
    return 0;
}