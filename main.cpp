#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "main.hpp"
#include "Record.hpp"
#include <sstream>
#include <sqlite3.h>

enum privileges {
    NONE,
    READ,
    WRITE,
    FULL
};

void uninitializedVariableExample() {
    int x;
    std::cout << "Value of x: " << x << std::endl; // Use of uninitialized variable
}

void nullPointerDereferenceExample() {
    int *ptr = nullptr;
    *ptr = 42; // Dereferencing a null pointer
}

void foo() {
    std::cout << "Inside foo" << std::endl;
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

void sqlInjectionExample(const char *userInput) {
    sqlite3 *db;
    char *errMsg = 0;
    int rc = sqlite3_open(":memory:", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    std::ostringstream sql;
    sql << "SELECT * FROM users WHERE name = '" << userInput << "';"; // Potential SQL injection
    rc = sqlite3_exec(db, sql.str().c_str(), 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    sqlite3_close(db);
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

class Base {
public:
    int x;
};

class Derived: public Base {
public:
	int y;
};

void dereference_base(Base *b) {
	b[2].x;
}

void dereference_derived(Derived *d) {
	d[2].x;
}

static const int* xptr;

void localAddressEscapes() {
  int x = 0;
  xptr = &x;
}

void example1() {
  localAddressEscapes();
  const int* x = xptr; // BAD: This pointer points to expired stack allocated memory.
}

void work(const char* str) {
    std::cout << "Working with string: " << str << std::endl;
}
// BAD: the concatenated string is deallocated when `c_str` returns. So `work`
// is given a pointer to invalid memory.
void work_with_combined_string_bad(std::string s1, std::string s2) {
  const char* combined_string = (s1 + s2).c_str();
  work(combined_string);
}

void restrict_privileges(privileges entitlements) {
    std::cout << "Working with string: " << entitlements << std::endl;
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

    // sql.cpp
    sqlInjectionExample("'; DROP TABLE users; --");

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

    Derived d[4];
    dereference_base(d); // BAD: implicit conversion to Base*
    dereference_derived(d); // GOOD: implicit conversion to Derived*, which will be the right size

    foo();

    enum privileges entitlements = NONE;
    bool is_admin = false;
    if (is_admin)
        entitlements = FULL, // BAD

    restrict_privileges(entitlements);
    return 0;
}