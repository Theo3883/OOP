#include "Agenda.h"
Contact* Agenda::Cauta(std::string nume)
{
	for (int i = 0; i < contacte.size(); i++)
		if (contacte[i]->GetNume() == nume)
			return contacte[i];
	return nullptr;
}
std::vector<Contact*> Agenda::GetPrieteni()
{
	std::vector<Contact*> temp;
	for (int i = 0; i < contacte.size(); i++)
		if (contacte[i]->GetTip() == "prieten")
			temp.push_back(contacte[i]);
	return temp;
}
void Agenda::Sterge(std::string nume)
{
	for (int i = 0; i < contacte.size(); i++)
		if (contacte[i]->GetNume() == nume)
			contacte.erase(contacte.begin() + i);
}
void Agenda::Adauga(Contact* c)
{
	contacte.push_back(c);
}
