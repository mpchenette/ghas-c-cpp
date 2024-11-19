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
    // WORKING
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




    // NOT WORKING
    uint16_t len2;
    char szVar2[16] = "hello world....";
    len2 = (uint16_t)strlen(szVar2);
    if (len2)
    {
        char *ptr2 = (char *)calloc(1, 15 * sizeof(char));
        if (ptr2)
        {
            strcpy(ptr2, szVar2);
        }
    }
    return 0;
}