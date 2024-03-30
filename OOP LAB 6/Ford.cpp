#include "Ford.h"
int Fiat::FuelCap()
{
	return fuel_capacity;
}
double Fiat::FuelCons()
{
	return fuel_cons;
}
int Fiat::Speed(Weather weather)
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
const char* Fiat::Name()
{
	return "Fiat";
}