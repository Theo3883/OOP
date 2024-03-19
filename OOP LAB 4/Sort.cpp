#include "Sort.h"
Sort::Sort(int minim, int maxim, int elemcount) : size(elemcount)
{
	array = new int[size];
	for (int i = 0; i < size; i++)
		array[i] = rand() % (maxim - minim + 1)+minim;
}
Sort::Sort(std::initializer_list <int> v) : size(v.size())
{
	array = new int[v.size() + 1];
	int j = 0;
	for (auto i =v.begin() ; i < v.end(); i++)
		array[j++] = *i;
}
Sort::Sort(int v[], int elemcount) : size(elemcount)
{
	array = new int[size];
	for (int i = 0; i < size; i++)
		array[i] = v[i];
}
Sort::Sort(int elemcount, ...) : size(elemcount)
{
	array = new int[size];
	va_list args;
	va_start(args, size);
	for (int i = 0; i < size; i++)
		array[i] = va_arg(args, int);
	va_end(args);
}
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
	array = new int[numbers.size() + 1];
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
	if (index >= size || index <0)
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
		while (p > 0 && (array[p] < array[p - 1]) == ascendent)
		{
			std::swap(array[p], array[p - 1]);
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
			if ((array[i] > array[i + 1]) == ascendent)
			{
				std::swap(array[i], array[i + 1]);
				sortat = false;
			}
	} while (!sortat);
}
void Sort::quickSort(int st, int dr, bool ascendent)
{
	if (st < dr)
	{
		//pivotul este inițial v[st]
		int m = (st + dr) / 2;
		int aux = array[st];
		array[st] = array[m];
		array[m] = aux;
		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if ((array[i] > array[j]) == ascendent)
			{
				std::swap(array[i], array[j]);
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		quickSort(st, i - 1, ascendent);
		quickSort(i + 1, dr, ascendent);
	}
}
void Sort::QuickSort(bool ascendent)
{
	quickSort(0, size - 1, ascendent);
}
