#pragma once
#include "Car.h"
class Mercedes : public Car
{
private:
	double FuelCons() final override;
	int FuelCap() final override;
	int Speed(Weather condition) final override;
	const char* Name() final override;
public:
	Mercedes() :Car(100, 9) {};
};

