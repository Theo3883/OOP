#include "Mercedes.h"
int Seat::FuelCap()
{
	return fuel_capacity;
}
double Seat::FuelCons()
{
	return fuel_cons;
}
int Seat::Speed(Weather weather)
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
const char* Seat::Name()
{
	return "Seat";
}