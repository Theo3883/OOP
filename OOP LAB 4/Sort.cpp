#include "Sort.h"
Sort::Sort(int minim, int maxim, int elemcount) : size(elemcount)
{
	array = new int[size];
	for (int i = 0; i < size; i++)
		array[i] = rand() % (maxim - minim + 1);
}
Sort::Sort(std::vector <int> v) : size(v.size())
{
	array = new int[v.size()+1];
	for (int i = 0; i < size; i++)
		array[i] = v[i];
}
Sort::Sort(int v[], int elemcount) : size(elemcount)
{
	array = new int[size];
	for (int i = 0; i < size; i++)
		array[i] = v[i];
}
/*Sort::Sort(int elemcount, ...) : size(elemcount)
{
	array = new int[size];
	va_list args;
	va_start(args, size);
	for (int i = 0; i < size; i++)
		array[i] = va_arg(args, int);
	va_end(args);
}*/
Sort::Sort(std::string s) 
{
	std::vector <int> numbers;
	int i = 0;
	int l = s.size();
	int tempnumber = 0;;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == ',')
		{
			numbers.push_back(tempnumber);
			tempnumber = 0;
		}
		else
			tempnumber = tempnumber * 10 + (s[i] - '0');
	}
	numbers.push_back(tempnumber);
	array = new int[numbers.size()+1];
	size = numbers.size();
	for (int i = 0; i < size; i++)
		array[i] = numbers[i];
}
void Sort::Print()
{
	for (int i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << '\n';
}
int  Sort::GetElementsCount()
{
	return size;
}
int  Sort::GetElementFromIndex(int index)
{
	if (index >= size)
	{
		std::cout << "Invalid index";
		return -1;
	}
	return array[index];
}
void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < size; i++)
	{
		int p = i;
		while (p > 0 && array[p] < array[p - 1])
		{
			int aux = array[p];
			array[p] = array[p - 1];
			array[p - 1] = aux;
			p--;
		}
	}
}
void Sort::BubbleSort(bool ascendent)
{
	bool sortat;
	do
	{
		sortat = true;
		for (int i = 0; i < size - 1; i++)
			if ((array[i] > array[i + 1])==ascendent)
			{
				std::swap(array[i], array[i + 1]);
				sortat = false;
			}
	} while (!sortat);
}
int Sort::partitionare(int p, int q)
{
	int x = array[p];
	int i = p + 1;
	int j = q;
	while (i <= j)
	{
		if (array[i] <= x)
			i++;
		if (array[j] >= x)
			j--;
		if (i<j && array[i]>x && array[j] < x)
		{
			std::swap(array[i], array[j]);
			i++;
			j--;
		}
	}
	int k = i - 1;
	array[p] = array[k];
	array[k] = x;
	return k;
}
void Sort::quickSort(int p, int q)
{
	int k;
	if (p < q)
	{
		k = partitionare( p, q);
		quickSort(p, k - 1);
		quickSort(k + 1, q);
	}
}
void Sort::QuickSort(bool ascendent)
{
	quickSort(0, size-1);
}