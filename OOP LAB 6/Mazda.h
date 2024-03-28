#pragma once
#include "Car.h"
class Mazda : public Car
{
private:
	double FuelCons() final override;
	int FuelCap() final override;
	int Speed(Weather condition) final override;
	const char* Name() final override;
public:
	Mazda() :Car(40, 4) {};
};


