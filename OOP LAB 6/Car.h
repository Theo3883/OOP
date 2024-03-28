#pragma once
#include "Weather.h"
class Car
{
protected:
	int fuel_capacity;
	double fuel_cons;
	int avgspeed;
	Car(int fuelcap, double fuelcons) : fuel_capacity(fuelcap), fuel_cons(fuelcons),avgspeed(0) {};
	
public:
	virtual double FuelCons() { return 0; };
	virtual int FuelCap() { return 0; };
	virtual int Speed(Weather condition) { return 0; };
	virtual const char* Name() { return "0"; };
};

