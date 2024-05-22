#pragma once
#include "Contact.h"
class Coleg: public Contact
{
private:
	std::string serviciu;
	std::string adresa;
	std::string nr_telefon;

public:
	Coleg(std::string nume, std::string serv, std::string adr, std::string tel) :
		Contact(nume), serviciu(serv), adresa(adr), nr_telefon(tel) {};
	std::string GetNume() override final;
	std::string GetTip()override final;
	std::string GetAdresa();
	std::string GetNrTelefon();
	std::string GetServiciu();

};

