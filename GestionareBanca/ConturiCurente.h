#pragma once
#include <iostream>
#include "ConturiBancare.h"
#include "Exceptii.h"
#include <string>
using namespace std;

class ContCurent : public ConturiBancare {

public:
	~ContCurent() {};
	ContCurent(const ContCurent& copy) : ConturiBancare(copy)
	{
		this->nrTranzactii = copy.nrTranzactii;
		this->nrDepuneri = copy.nrDepuneri;
		this->nrRetrageri = copy.nrRetrageri;
		this->nrTranzactiiOnline = copy.nrTranzactiiOnline;
		this->banca = copy.banca;
		this->taxaOnline = copy.taxaOnline;
		this->taxaBanca = copy.taxaBanca;
	}
	ContCurent& operator=(ContCurent& other)
	{
		if (this != &other) {
			this->ConturiBancare::operator=(other);
			this->nrDepuneri = other.nrDepuneri;
			this->nrRetrageri = other.nrRetrageri;
			this->nrTranzactiiOnline = other.nrTranzactiiOnline;
			this->nrTranzactiiBancaDif = other.nrTranzactiiBancaDif;
			this->banca = other.banca;
			this->taxaOnline = other.taxaOnline;
			this->taxaBanca = other.taxaBanca;
			this->taxaTranzactii = other.taxaTranzactii;
		}
		return *this;
	}
	//--------------
	int getNrDepuneri()
	{
		return this->nrDepuneri;
	}
	int getNrRetrageri()
	{
		return this->nrRetrageri;
	}
	int getNrTranzactii()
	{
		this->nrTranzactii = this->nrDepuneri + this->nrRetrageri;
		return this->nrTranzactii;
	}
	bool isTranzBanca() {
		if (banca = 0) cout << "Tranzactia nu a fost facuta la banca noastra.";
		else cout << "Tranzactia a fost facuta la banca noastra.";
	}
	float getTaxaOnline() {

		this->taxaOnline = (this->taxaOnline + 0.5) * nrTranzactiiOnline;

		return this->taxaOnline;
	}
	float getTaxaTranzactii() {
		int tr = 0;
		tr = this->TRANZACTII_GRATUITE - (this->nrDepuneri + this->nrRetrageri);
		if (tr < 0)
		{
			this->taxaTranzactii = (taxaTranzactii + 1) * abs(tr);

		}
		return this->taxaTranzactii;
	}
	float getTaxaBanca() {

		this->taxaBanca = (this->taxaBanca + 2) * this->nrTranzactiiBancaDif;
		return this->taxaBanca;
	}
	// --------------
	ContCurent(string nume = "", string prenume = "", string data = "", long double sold = 0, int depuneri = 0, int retrageri = 0)
	{
		this->detinator_nume = nume;
		this->detinator_prenume = prenume;
		this->dataDeschidere = data;
		this->sold = sold;
		this->nrDepuneri = depuneri;
		this->nrRetrageri = retrageri;
	}
	void DepunereBani(bool banca, long double valoare)
	{
		++this->nrDepuneri;
		this->banca = banca;
		this->sold = this->sold + valoare;
		if (this->banca == 0) { ++this->nrTranzactiiBancaDif; }
	}
	void RetragereBaniFizic(bool banca, long double valoare)
	{
		++this->nrRetrageri;
		this->banca = banca;
		if (valoare > this->sold)
		{
			throw RetreagereInvalida("Nu dispui de suficienti bani!");
		}
		else { this->sold = this->sold - valoare; }
		if (this->banca == 0) { ++this->nrTranzactiiBancaDif; }
	}
	void RetragereBaniOnline(long double valoare)
	{
		++this->nrRetrageri;
		++this->nrTranzactiiOnline;
		if (valoare > this->sold)
		{
			throw RetreagereInvalida("Nu dispui de suficienti bani!");
		}
		else { this->sold = this->sold - valoare; }

		++this->nrTranzactiiOnline;
	}
	// --------------
	friend ostream& operator<<(ostream& console, ContCurent& cc);
	friend istream& operator>>(istream& console, ContCurent& cc);
	// --------------
	void citire() {
		ConturiBancare::citire();
		cout << "\nNumar Depuneri: ";
		cin >> nrDepuneri;
		cout << "\nNumar Retrageri: ";
		cin >> nrRetrageri;
		cout << endl;
	};
	void afisare() {
		ConturiBancare::afisare();
		cout << "\nNumarul de depuneri este: " << nrDepuneri;
		cout << "\nNumarul de retrageri este: " << nrRetrageri;
		cout << "\nNumarul de tranzactii totale este: " << nrDepuneri + nrRetrageri;
		cout << "\nNumarul de tranzactii online este: " << nrTranzactiiOnline;
		cout << "\nNumarul de tranzactii la alta banca este: " << nrTranzactiiBancaDif;
		cout << endl;
	};
private:
	static const int TRANZACTII_GRATUITE;
	int nrTranzactii = 0;
	int nrDepuneri;
	int nrRetrageri;
	int nrTranzactiiOnline = 0;
	int nrTranzactiiBancaDif = 0;
	bool banca = 1;
	float taxaOnline = 0;
	float taxaBanca = 0;
	float taxaTranzactii = 0;
};