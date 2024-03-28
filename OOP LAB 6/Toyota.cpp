#include "Toyota.h"
int Toyota::FuelCap()
{
	return fuel_capacity;
}
double Toyota::FuelCons()
{
	return fuel_cons;
}
int Toyota::Speed(Weather weather)
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
const char* Toyota::Name()
{
	return "Toyota";
}