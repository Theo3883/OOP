#include <iostream>
#include "Array.h"
int main()
{
    Array<int> array(10);

    array += 1;
    array += 2;
    array += 1;
    array += 3;
    array.afis();
    for (auto it : array)
        std::cout << it;
    std::cout << '\n';
}

