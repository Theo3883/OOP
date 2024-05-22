#pragma once
#include "Contact.h"
class Cunoscut:public Contact
{
private:
	std::string nr_telefon;
public:
	Cunoscut(std::string nume, std::string tel) : Contact(nume), nr_telefon(tel) {};
	std::string GetNume() override final;
	std::string GetTip() override final;
	std::string GetNrTelefon();
};

