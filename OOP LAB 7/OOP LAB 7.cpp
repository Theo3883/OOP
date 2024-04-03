#include <iostream>
float operator"" _Kelvin(unsigned long long Cels)
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
}



