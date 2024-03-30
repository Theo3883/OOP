#pragma once
#include "Car.h"
class BMW : public Car
{
private:
	double FuelCons() final override;
	int FuelCap() final override;
	int Speed(Weather condition) final override;
	const char* Name() final override;
public:
	BMW() :Car(70, 6.5) {};
};


