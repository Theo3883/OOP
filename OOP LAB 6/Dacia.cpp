#include "Dacia.h"
int Dacia::FuelCap()
{
	return fuel_capacity;
}
double Dacia::FuelCons()
{
	return fuel_cons;
}
int Dacia::Speed(Weather weather)
{
	switch (weather)
	{
	case Rain:
		return 50;
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
const char* Dacia::Name()
{
	return "Dacia";
}
