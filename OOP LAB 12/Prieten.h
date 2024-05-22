#pragma once
#include "Contact.h"
class Prieten : public Contact
{
private:
	std::string data_nastere;
	std::string adresa;
	std::string nr_telefon;
public:
	Prieten(std::string nume, std::string nastere, std::string adr, std::string tel) :
		Contact(nume), data_nastere(nastere), adresa(adr), nr_telefon(tel) {};
	std::string GetNume() override final;
	std::string GetTip()override final;
	std::string GetAdresa();
	std::string GetDataNastere();
	std::string GetNrTelefon();
};

