#include <iostream>
#include <string>
#include <vector>
#include "Sort.h"
int main()
{
    std::string s;
    s.push_back('1');
    s.push_back('0');
    s.push_back(',');
    s.push_back('4');
    s.push_back('0');
    s.push_back(',');
    s.push_back('1');
    s.push_back('0');
    s.push_back('0');
    s.push_back(',');
    s.push_back('5');
    s.push_back(',');
    s.push_back('7');
    s.push_back('0');
    Sort a(s);
    a.QuickSort(false);
    a.Print();

}

