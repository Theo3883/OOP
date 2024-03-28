#include "Circuit.h"
void Circuit::SetLength(int clength)
{
	length = clength;
}
void Circuit::SetWeather(Weather weather)
{
	current_weather = weather;
}
void Circuit::AddCar(Car* car)
{
	cars.push_back(car);
}
bool cmp(ceva left, ceva right)
{
	return left.time < right.time;
}
void Circuit::Race()
{
	int cars_number = cars.size();
	for (int i = 0; i < cars_number; i++)
	{
		if (cars[i]->FuelCons() * length / 100 > cars[i]->FuelCap())
			unfinished_cars.push_back(i);
		else
		{
			double result = length / cars[i]->Speed(current_weather);
			finished_cars.push_back({ i, result });
		}
	}
	sort(finished_cars.begin(), finished_cars.end(), cmp);
}
void Circuit::ShowFinalRanks()
{
	std::cout << "Final Ranks: \n";
	int cars_finished = finished_cars.size();
	for (int i = 0; i < cars_finished; i++)
		std::cout << cars[finished_cars[i].index]->Name() << ": " << finished_cars[i].time * 60 << " minutes \n";
	
}
void Circuit::ShowWhoDidNotFinish()
{
	int cars_unfinished = unfinished_cars.size();
	std::cout << "Cars that did not finish: \n";
	for (int i = 0; i < cars_unfinished; i++)
		std::cout << cars[unfinished_cars[i]]->Name() << '\n';
}