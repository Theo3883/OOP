// OOP LAB 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdarg.h>
#include "Math.h";
#include "Canvas.h";
#include <cstring>
using namespace std;
int main()
{
	Canvas a(20, 20);
	a.DrawRect(5, 5, 10, 10, 'a');
	a.Print();
}

