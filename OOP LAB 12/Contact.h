#pragma once
#include <string>
class Contact
{
protected:
	std::string nume;
public:
	Contact(std::string _nume) :nume(_nume) {};
	virtual std::string GetNume() =0;
	virtual std::string GetTip()=0;
};

