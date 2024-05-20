#include <iostream>
#include <algorithm>
template <class T>
class Sorting
{
private:
    bool compare(T left, T right)
    {
        return left > right;
    }
     static void heapify(T* &a, int n, int i)
    {
        int t = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left<n && compare(a[left],a[t]))
            t = right;
        if (right<n && compare(a[right],a[t]))
            t = right;
        if (t != i)
        {
            std::swap(a[i], a[t]);
            heapify(a, n, t);
        }
    }
public:
    static void heapsort(T* &a, int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapfy(a, n, i);
        for (int i = n - 1; i > 0; i--)
        {
            std::swap(a[0], a[i]);
            heapify(a, i, 0);
        }
    }
};
template <typename T>
void sort(T* &list, int n)
{
    Sorting<int>::heapsort(list, n);
}
int main()
{
    int* list;
    list = new int[10];
    list[0] = 5;
    list[1] = 2;
    list[2] = 1;
    list[3] = 3;
    sort(list, 4);
    for (int i = 0; i < 4; i++)
        std::cout << list[i];
    delete[] list;
}

