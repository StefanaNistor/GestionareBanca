#pragma once
#include "ConturiBancare.h"
#include"Exceptii.h"
#include <string>
#include <iostream>
using namespace std;


class ContEconomii : public ConturiBancare {

public:
	~ContEconomii() {}
	ContEconomii(string nume = "", string prenume = "", string data = "", double sold = 0, int tipDobanda = 6)
	{
		this->detinator_nume = nume;
		this->detinator_prenume = prenume;
		this->dataDeschidere = data;
		this->sold = sold;
		if (tipDobanda != 3 && tipDobanda != 6 && tipDobanda != 12)
		{
			throw DobandaInvalida("Nu oferim serviciile dobanzii pe acest numar de luni!");
		}
		else
		{
			this->tipDobanda = tipDobanda;
		}
		this->dobanda = getDobanda();
	}
	// --------------
	double getDobanda() {
		int nrZile = 0;
		if (this->tipDobanda == 3) { nrZile = 90; }
		else {
			if (this->tipDobanda == 6) { nrZile = 180; }
			else if (this->tipDobanda == 12) { nrZile = 360; }
		}

		this->dobanda = (this->sold * nrZile * this->RATA_DOBANZII) / (360 * 100);
		return this->dobanda;
	}
	void SchimbareDobanda(int nouDobanda)
	{
		if (nouDobanda != 3 && nouDobanda != 6 && nouDobanda != 12)
		{
			throw DobandaInvalida("Nu oferim serviciile dobanzii pe acest numar de luni!");
		}
		else { this->tipDobanda = nouDobanda; }
	}
	// --------------
	ContEconomii(const ContEconomii& copy) : ConturiBancare(copy)
	{
		this->dobanda = copy.dobanda;
		this->tipDobanda = copy.tipDobanda;
	}
	ContEconomii& operator=(ContEconomii& other)
	{
		if (this != &other) {
			this->ConturiBancare::operator=(other);
			this->dobanda = other.dobanda;
			this->tipDobanda = other.tipDobanda;
			return *this;
		}
	}
	// --------------
	friend ostream& operator<<(ostream& console, ContEconomii& ce);
	friend istream& operator>>(istream& console, ContEconomii& ce);
	// --------------
	void citire() {
		ConturiBancare::citire();
		cout << "Oferta dobanzii oferite pe numarul de luni de(3,6 sau 12):";
		cin >> tipDobanda;
		if (tipDobanda != 3 && tipDobanda != 6 && tipDobanda != 12)
		{
			throw DobandaInvalida("Nu oferim serviciile dobanzii pe acest numar de luni!");
		}
		cout << endl;
	};
	void afisare() {
		ConturiBancare::afisare();
		cout << "\nTipul dobanzii este de: " << tipDobanda << " luni";
		cout << "\nDobanda este: ";
		int nrZile = 0;
		if (tipDobanda == 3) { nrZile = 90; }
		else {
			if (tipDobanda == 6) { nrZile = 180; }
			else if (tipDobanda == 12) { nrZile = 360; }
		}

		dobanda = (sold * nrZile * RATA_DOBANZII) / (360 * 100);
		cout << dobanda << " RON";
		cout << endl;
	};
private:
	double dobanda;
	static const float RATA_DOBANZII;
	int tipDobanda;
};