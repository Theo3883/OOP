#pragma once
#include "Car.h"
class Ford : public Car
{
private:
	double FuelCons() final override;
	int FuelCap() final override;
	int Speed(Weather condition) final override;
	const char* Name() final override;
public:
	Ford() :Car(40, 4.5) {};
};

