#pragma once
#include "Car.h"
class Volvo : public Car
{
private:
	double FuelCons() final override;
	int FuelCap() final override;
	int Speed(Weather condition) final override;
	const char* Name() final override;
public: 
	Volvo() :Car(10, 11) {};
};

