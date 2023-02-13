#pragma once
#include <iostream>
#include "GestiuneConturi.h"
#include "ConturiEconomii-S.h"
#include "ConturiCurente.h"
class Meniu
{
public:
	static Meniu* getInstanta()
	{
		if (instanta == nullptr)
		{
			instanta = new Meniu();
		}
		return instanta;
	}
	static void deleteInstanta()
	{
		if (instanta != nullptr)
		{
			delete instanta;
		}
		instanta = nullptr;
	}
	~Meniu() {};
	void adaugaContBancar()
	{
		cout << "\nAdauga un cont bancar!";
		cout << "\n------------------------------";
		cout << "\nAlegeti tipul de cont:" << "\nCont de Economii->1 || Cont Curent->2" << endl;
		int optiune;
		cin >> optiune;
		if (optiune != 1 && optiune != 2)
		{
			throw TipContInvalid("Optiunea aleasa de dumneavoastra nu exista!");
		}
		if (optiune == 1)
		{
			CE.creare_cont();

		}
		if (optiune == 2)
		{
			CC.creare_cont();
		}

	}
	void afiseazaConturiBancare()
	{
		CE.afisare_cont();
		CC.afisare_cont();
	}
	void afisNrConturiEconomii()
	{
		CE.afisNrConturiEconomii();
	}
	void afisDetaliiBanca() {
		CE.afisareDetaliiBanca();
	}
	void done()
	{
		CE.destruct();
	}
private:
	static Meniu* instanta;
	GestiuneConturi<ContEconomii> CE;
	GestiuneConturi<ContCurent> CC;
};