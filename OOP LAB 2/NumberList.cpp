#include "./NumberList.h"
#include <iostream>
void NumberList::Init()
{
    count = 0;
    size = 32;
}

void NumberList::Add(int x)
{
    if(count >= size )
    {
        int *b = new int[2*size];
        size *=2;
        for(int i=0;i<count;i++)
            b[i]=numbers[i];
        delete[] numbers;
        this->numbers=b;
    }
    else
        numbers[count++]=x;
}
void NumberList::Sort()
{
    for(int i=0;i<count-1;i++)
        for(int j=i+1;j<count;j++)
        if(this->numbers[i] > this->numbers[j])
        {
            int temp = this->numbers[i];
            this->numbers[i]=this->numbers[j];
            this->numbers[j]=temp;
        }
}
void NumberList::Print()
{
    for(int i=0;i<count;i++)
        printf("%d",this->numbers[i]);
        printf("%c"," ");
}