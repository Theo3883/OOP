#pragma once
#include <iostream>
#include <cstring>
class Number
{
	// add data members
	int base;
	char* number;
	int numbersize;
private:
	unsigned long long switchtonumber() const;
	int digit(int index) const;
	Number(unsigned long long tempnumber, int newBase);
public:

	//constructors

	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number(int value);

	//copy/move constructor
	Number(const Number& from_number); 
	Number(Number&& mv) noexcept;

	// operators
	
	int operator[](size_t i) const;

	Number& operator=(Number&& mv) noexcept;
	Number& operator=(const char* value);

	Number& operator+=(const Number& right);
	Number& operator-=(const Number& right);

	friend Number operator+(const Number& left, const Number& right);
	friend Number operator-(const Number& left, const Number& right);

	Number& operator--();
	Number& operator--(int);

	bool operator>(const Number& right) const;
	bool operator>= (const Number& right) const;
	bool operator< (const Number& right) const;
	bool operator<= (const Number& right) const;
	bool operator== (const Number& right) const;

	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount(); // returns the number of digits for the current number
	int GetBase(); // returns the current base
};
