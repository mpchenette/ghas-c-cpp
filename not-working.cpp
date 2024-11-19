#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>

void *OSacquireinternal(size_t Size, int lineNum, const char *fileName)
{
    if (Size > 0)
        return (calloc(1, Size));
    else
    {
        assert(false);
        return (NULL);
    }
}

#define OSacquire(a) OSacquireinternal(a, __LINE__, __FILE__)


int main()
{
    uint16_t len;
    char szVar[16] = "hello world....";
    len = (uint16_t)strlen(szVar);
    if (len)
    {
        char *ptr = (char *)calloc(1, 15 * sizeof(char));
        if (ptr)
        {
            strcpy(ptr, szVar);
        }
    }
    return 0;
}