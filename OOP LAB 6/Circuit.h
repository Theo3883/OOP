#pragma once
#include <iostream>
#include "Dacia.h"
#include "Ford.h"
#include "Mazda.h"
#include "Toyota.h"
#include "Mercedes.h"
#include "Weather.h"
#include <vector>
#include <algorithm>
struct ceva {
	int index;
	double time;
};
class Circuit {
private:
	int length;
	Weather current_weather;
	std::vector <Car*> cars;

	std::vector <ceva> finished_cars;
	std::vector <int> unfinished_cars;
public:
	void SetLength(int clength);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void ceva();

};