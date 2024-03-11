#include "Math.h"
#include <stdarg.h>
#include <cstring>
int Math :: Add(int larg, int rarg)
{
	return larg + rarg;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double larg, double rarg)
{
	return (int)(larg + rarg);
}
int Math::Add(double a, double b, double c)
{
	return (int)(a + b + c);
}
int Math::Mul(int larg, int rarg)
{
	return larg * rarg;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double larg, double rarg)
{
	return (int)(larg * rarg);
}
int Math::Mul(double a, double b, double c)
{
	return (int)(a * b * c);
}
int Math::Add(int count, ...)
{
	int sum = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
		sum += va_arg(args, int);
	va_end(args);
	return sum;
}
char* Math::Add(const char* larg, const char* rarg)
{
	if (larg == nullptr || rarg == nullptr)
		return nullptr;
	auto len = strlen(larg) + strlen(rarg) + 1;
	auto final = new char[len];
	strcpy_s(final, len,larg);
	strcat_s(final, len, rarg);
	return final;
}
