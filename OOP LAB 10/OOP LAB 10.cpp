#include <iostream>
#include "Array.h"
int main()
{
    Array<int> array(10);

    array += 1;
    array += 2;
    array += 1;
    array += 3;
    for (auto it : array)
        std::cout << it;
    auto it = array.begin();
    --it;
    std::cout << '\n';
}

