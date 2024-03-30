#include "Mazda.h"
int RangeRover::FuelCap()
{
	return fuel_capacity;
}
double RangeRover::FuelCons()
{
	return fuel_cons;
}
int RangeRover::Speed(Weather weather)
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
const char* RangeRover::Name()
{
	return "RangeRover";
}