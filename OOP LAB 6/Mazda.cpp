#include "Mazda.h"
int Mazda::FuelCap()
{
	return fuel_capacity;
}
double Mazda::FuelCons()
{
	return fuel_cons;
}
int Mazda::Speed(Weather weather)
{
	switch (weather)
	{
	case Rain:
		return 40;
		break;
	case Sunny:
		return 70;
		break;
	case Snow:
		return 30;
		break;
	default:
		break;
	}
}
const char* Mazda::Name()
{
	return "Mazda";
}