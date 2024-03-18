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
    a.BubbleSort(false);
    a.Print();
    int v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Sort b(v, 9);
    b.QuickSort(true);
    b.Print();
    std::vector <int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Sort c(v1);
    c.InsertSort(true);
    c.Print();
    Sort d(1, 100, 10);
    d.BubbleSort(false);
    d.Print();
    return 0;

}

