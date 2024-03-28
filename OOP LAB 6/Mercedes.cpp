#include "Mercedes.h"
int Mercedes::FuelCap()
{
	return fuel_capacity;
}
double Mercedes::FuelCons()
{
	return fuel_cons;
}
int Mercedes::Speed(Weather weather)
{
	switch (weather)
	{
	case Rain:
		return 70;
		break;
	case Sunny:
		return 110;
		break;
	case Snow:
		return 50;
		break;
	default:
		break;
	}
}
const char* Mercedes::Name()
{
	return "Mercedes";
}