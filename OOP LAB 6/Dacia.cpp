#include "Dacia.h"
int Volvo::FuelCap()
{
	return fuel_capacity;
}
double Volvo::FuelCons()
{
	return fuel_cons;
}
int Volvo::Speed(Weather weather)
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
const char* Volvo::Name()
{
	return "Volvo";
}
