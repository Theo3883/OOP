#pragma once
#include "Car.h"
class RangeRover : public Car
{
private:
	double FuelCons() final override;
	int FuelCap() final override;
	int Speed(Weather condition) final override;
	const char* Name() final override;
public:
	RangeRover() :Car(40, 4) {};
};


