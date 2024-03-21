#include "Number.h"
int Number::GetDigitsCount()
{
	return numbersize;
}
void Number::Print()
{
	std::cout << number<<'\n';
}
int Number::GetBase()
{
	return base;
}
void Number::SwitchBase(int newBase)
{
	if (base == newBase)
		return;
	if (base < 2 || base > 16)
	{
		std::cout << "Incorrect base"<<'\n';
		return;
	}
	unsigned long long tempnumber = switchtonumber();
	(*this) = Number(tempnumber, newBase);
}
unsigned long long Number::switchtonumber() const
{
	unsigned long long tempnumber = 0;
	for (int i = 0; i < numbersize; i++)
		tempnumber = tempnumber * base + digit(i);
	return tempnumber;
}
int Number::digit(int index) const
{
	if (number[index] > 'A')
		return number[index] - 'A' + 10;
	return number[index] - '0';
}
Number::Number(unsigned long long tempnumber, int newBase) : base(newBase), numbersize(1), number(nullptr)
{
	if (!tempnumber)
	{
		number = new char[2];
		number[0] = '0';
		number[1] = '\0';
	}
	else
	{
		long long tmp = tempnumber;
		while (tmp >= base) {
			tmp /= base;
			numbersize++;
		}
		tmp = tempnumber;
		number = new char[numbersize + 1];
		for (int i = numbersize- 1; i >= 0; --i) {
			int mod = tmp % base;
			if (mod >= 0 && mod <= 9) {
				number[i] = mod + '0';
			}
			else if (mod >= 10 && mod <= 15) {
				number[i] = mod - 10 + 'A';
			}
			tmp /= base;
		}
		number[numbersize] = '\0';
	}
}
Number::Number(const char* value, int base) : base(base), numbersize(strlen(value))
{
	number = new char[numbersize + 1];
	memcpy(number, value, numbersize);
	number[numbersize] = '\0';
}
Number::Number(int value)
{
	Number(unsigned long long(value), 10);
}
Number::~Number()
{
		delete[] number;
}
Number::Number(const Number& from_number): base(from_number.base), numbersize(from_number.numbersize)
{
	number = new char[numbersize+1];
	memcpy(number, from_number.number, numbersize);
	number[numbersize] = '\0';

}
Number::Number(Number&& mv) noexcept : base(mv.base), numbersize(mv.numbersize)
{
	number = mv.number;
	mv.number = nullptr;
	mv.base = 0;
	mv.numbersize = 0;
}
int Number::operator[](size_t i) const
{
	return number[i];
}
Number& Number::operator=(Number&& mv) noexcept
{
	if (this != &mv) 
	{ 
		//delete[] number; 
		base = mv.base;
		numbersize = mv.numbersize;
		number = mv.number;
		mv.number = nullptr;
	}
	return (*this);
}
Number& Number::operator=(const char* value)
{
	if (numbersize < strlen(value))
	{
		delete[] number;
		number = new char[strlen(value)];
	}
	numbersize = strlen(value);
	memcpy(number, value, numbersize);
	number[numbersize] = '\0';
	return(*this);
}
Number& Number::operator+=(const Number& right) 
{
	int tmpbase;
	unsigned long long left = switchtonumber();
	unsigned long long rightt = right.switchtonumber();
	left += rightt;
	if (base < right.base)
		 tmpbase = right.base;
	else
		tmpbase = base;
	return (*this) = Number(left, tmpbase);
}
Number& Number::operator-=(const Number& right)
{
	int tmpbase;
	unsigned long long left = switchtonumber();
	unsigned long long rightt = right.switchtonumber();
	left -= rightt;
	if (base < right.base)
		tmpbase = right.base;
	else
		tmpbase = base;
	return (*this) = Number(left, tmpbase);
}
Number operator+(const Number& left, const Number& right)
{
	Number tempnumber(left);
	tempnumber += right;
	return tempnumber;
}
Number operator-(const Number& left, const Number& right)
{
	Number tempnumber(left);
	tempnumber -= right;
	return tempnumber;
}
Number& Number::operator--()
{
	if (numbersize == 1)
	{
		std::cout << "You have only one digit"<<'\n';
		return (*this);
	}
	memcpy(number, number + 1, numbersize);
	numbersize--;
	number[numbersize] = '\0';
	return (*this);
}
Number& Number::operator--(int)
{
	if (numbersize == 1)
	{
		std::cout << "You have only one digit" << '\n';
		return (*this);
	}
	numbersize--;
	number[numbersize] = '\0';
	return (*this);
}
bool Number::operator>(const Number& right) const
{
	unsigned long long leftt = switchtonumber();
	unsigned long long rightt = right.switchtonumber();
	return leftt > rightt;
}

bool Number::operator>=(const Number& right) const
{
	unsigned long long leftt = switchtonumber();
	unsigned long long rightt = right.switchtonumber();
	return leftt >= rightt;
}
bool Number::operator<(const Number& right) const
{
	unsigned long long leftt = switchtonumber();
	unsigned long long rightt = right.switchtonumber();
	return leftt < rightt;
}
bool Number::operator<=(const Number& right) const
{
	unsigned long long leftt = switchtonumber();
	unsigned long long rightt = right.switchtonumber();
	return leftt <= rightt;
}
bool Number::operator==(const Number& right) const
{
	unsigned long long leftt = switchtonumber();
	unsigned long long rightt = right.switchtonumber();
	return leftt == rightt;
}