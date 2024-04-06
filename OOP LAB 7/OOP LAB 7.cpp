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

	Tree<char> tree;
	tree.add_node(0, 'a');
	tree.add_node(0, 'b');
	tree.add_node(1, 'c');
	tree.add_node(1, 'd');
	std::cout<<tree.get_node(1);
}



