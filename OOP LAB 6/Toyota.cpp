#include "Toyota.h"
int BMW::FuelCap()
{
	return fuel_capacity;
}
double BMW::FuelCons()
{
	return fuel_cons;
}
int BMW::Speed(Weather weather)
{
	switch (weather)
	{
	case Rain:
		return 65;
		break;
	case Sunny:
		return 86;
		break;
	case Snow:
		return 65;
		break;
	default:
		break;
	}
}
const char* BMW::Name()
{
	return "BMW";
}