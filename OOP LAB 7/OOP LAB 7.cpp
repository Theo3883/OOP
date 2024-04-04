#include <iostream>
/*float operator"" _Kelvin(unsigned long long Cels)
{
	return static_cast<float>(Cels) + 273.15;
}
float operator"" _Fahrenheit(unsigned long long Cels)
{
	return (static_cast<float>(Cels) *1.8) +32.;
}
int main() {
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;
	std::cout << a << " " << b;
	return 0;
}*/
#include "Vector.h"
int main()
{
	Vec<float> number;
	number.push(5);
	number.push(2.57);
	number.push(.3);
	number.sortt();
	//number.set(, 2);
	std::cout << number.pop();
}



