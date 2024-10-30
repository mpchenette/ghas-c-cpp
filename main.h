#ifndef MAIN_H
#define MAIN_H

void uninitializedVariableExample();
void nullPointerDereferenceExample();
void bufferOverflowExample(const char *input);
void insecureHttpRequestExample();
void unsafeGetsExample();
void unsafeStrcpyExample(const char *input);
void unsafeSprintfExample(const char *input);
void unsafeStrcatExample(const char *input);
void formatStringVulnerabilityExample(const char *input);
void commandInjectionExample(const char *input);
void fopenWithoutCheckExample(const char *filename);

#endif // MAIN_H