#include "./NumberList.h"
#include <iostream>
using namespace std;
int main()
{
    NumberList a;
    int x;
    for(int i=1;i<=10;i++)
    {
        cin>>x;
        a.Add(x);
    }
    a.Sort();
    a.Print();
}