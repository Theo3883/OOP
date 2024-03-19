#pragma once
#include <vector>
#include <stdarg.h>
#include <iostream>
#include <string>
#include <initializer_list>
class Sort
{
private:
    int* array;
    int size;
    void quickSort(int p, int q, bool ascendent); ///ca sa accesez vectorul
public:
    // add constuctors
    Sort(int minim, int maxim, int elemcount);
    Sort(std::initializer_list <int> v);
    Sort(int v[], int elemcount);
    Sort(int elemcount, ...);
    Sort(std::string s);
    void InsertSort(bool ascendent);
    void QuickSort(bool ascendent);
    void BubbleSort(bool ascendent);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};