#include <iostream>
#include "Map.h"
/*int main()
{
    std::cout << "Hello World!\n";
}*/
int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n"
            , index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n"
            , index, key, value);
    }
    Map<int, const char*> p;
    p[10] = "C++";
    p[20] = "result";
    p[30] = "Poo";
    if (m.Includes(p))
        std::cout << "DA";
    else
        std::cout << "NU";
    return 0;
}

