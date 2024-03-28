#include "Ford.h"
int Ford::FuelCap()
{
	return fuel_capacity;
}
double Ford::FuelCons()
{
	return fuel_cons;
}
int Ford::Speed(Weather weather)
{
	switch (weather)
	{
	case Rain:
		return 60;
		break;
	case Sunny:
		return 90;
		break;
	case Snow:
		return 45;
		break;
	default:
		break;
	}
}
const char* Ford::Name()
{
	return "Ford";
}