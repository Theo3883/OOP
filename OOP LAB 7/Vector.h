#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
template <class T>

class Vec
{
private:
	std::vector <T> numbers;
public:
	void push(T number)
	{
		numbers.push_back(number);
	}
	T pop()
	{
		return numbers[numbers.size() - 1];
	}
	void del(int index)
	{
		if (index > numbers.size() - 1)
		{
			std::cout << "Index incorect pentru delete \n";
			return;
		}
		numbers.erase(numbers.begin() + index);
	}
	void insert(int index)
	{
		if (index > numbers.size() - 1)
		{
			std::cout << "Index incorect pentru insert \n";
			return;
		}
		numbers.insert(numbers.begin() + index);
	}
	void sortt()
	{
		std::sort(numbers.begin(), numbers.end());
	}
	T get(int index)
	{
		if (index > numbers.size() - 1)
		{
			std::cout << "Index incorect pentru get \n";
			return nullptr;
		}
		return numbers[index];
	}
	void set(T number, int index)
	{
		if (index > numbers.size() - 1)
		{
			std::cout << "Index incorect pentru set \n";
			return;
		}
		numbers[index] = number;
	}
	int count()
	{
		return numbers.size();
	}
	int firstIndexOf(T number)
	{
		int size = numbers.size();
		for (int i = 0; i < size; i++)
			if (numbers[i] == T)
				return i;
	}

};

