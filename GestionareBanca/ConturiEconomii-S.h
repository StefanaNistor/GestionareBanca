#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "GestiuneConturi.h"
#include "ConturiEconomii.h"

template<>
class GestiuneConturi<ContEconomii>
{
private:
	int nrConturi;
	vector<ContEconomii*> cont;
	string numeBanca = "Banca Calutilor Fericiti";
	string adresaBanca = "Ramnicu-Valcea, Strada Vodei, Nr 77";
public:
	GestiuneConturi<ContEconomii>(vector<ContEconomii*> c = {})
	{
		cont = c;
	}
	GestiuneConturi(const GestiuneConturi&);
	GestiuneConturi<ContEconomii> operator=(GestiuneConturi<ContEconomii>& other)
	{
		if (this != &other)
		{
			cont = other.cont;
		}
		return *this;
	}
	void destruct()
	{
		if (cont.empty() != 0)
		{
			for (auto p : cont)
			{
				delete p;
			}
		}
	}
	void afisare_cont()
	{
		for (auto p : cont)
		{

			cout << "\n-----------------------------------------------";
			cout << endl;
			cout << *p << endl;

		}
	}
	void creare_cont() {
		cout << "Furnizati numarul de conturi ce apartin bancii: " << endl;
		int nr;
		cin >> nr;
		for (int i = 0; i < nr; i++)
		{
			ContEconomii* CE = new ContEconomii();
			CE->citire();
			cont.push_back(CE);
		}
		nrConturi = nr;
	}
	void afisNrConturiEconomii()
	{
		cout << "\nNumarul total de Conturi de Economii este de: ";
		cout << nrConturi;
	}
	void afisareDetaliiBanca()
	{
		cout << "\nNumele bancii noastre este: ";
		cout << numeBanca;
		cout << "\nAdresa unde ne puteti gasii este: ";
		cout << adresaBanca;
	}
};