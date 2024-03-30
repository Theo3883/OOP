#pragma once
#include "Car.h"
class Seat : public Car
{
private:
	double FuelCons() final override;
	int FuelCap() final override;
	int Speed(Weather condition) final override;
	const char* Name() final override;
public:
	Seat() :Car(100, 9) {};
};

