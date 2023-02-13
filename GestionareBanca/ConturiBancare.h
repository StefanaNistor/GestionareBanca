#pragma once
#include <iostream>
#include <string>
using namespace std;

class ConturiBancare {
protected:
	int ID;
	string detinator_nume;
	string detinator_prenume;
	string dataDeschidere;
	long double sold;
public:
	virtual ~ConturiBancare() {}
	ConturiBancare(string nume = "", string prenume = "", string data = "", double sold = 0)
	{
		this->detinator_nume = nume;
		this->detinator_prenume = prenume;
		this->dataDeschidere = data;
		this->sold = sold;
	}
	// --------------
	string getDetinatorNume() {
		return this->detinator_nume;
	}
	string getDetinatorPrenume() {
		return this->detinator_prenume;
	}
	string getdataDeschidere()
	{
		return this->dataDeschidere;
	}
	double getSold()
	{
		return this->sold;
	}
	static ConturiBancare* creare(int optiune);
	// --------------
	ConturiBancare(const ConturiBancare& copy)
	{
		this->detinator_nume = copy.detinator_nume;
		this->detinator_prenume = copy.detinator_prenume;
		this->dataDeschidere = copy.dataDeschidere;
		this->sold = copy.sold;
	}
	ConturiBancare& operator=(ConturiBancare& other)
	{
		if (this != &other)
		{
			this->detinator_nume = other.detinator_nume;
			this->detinator_prenume = other.detinator_prenume;
			this->dataDeschidere = other.dataDeschidere;
			this->sold = other.sold;
		}
		return *this;
	}
	// --------------
	friend ostream& operator<<(ostream& console, ConturiBancare& c);
	friend istream& operator>>(istream& console, ConturiBancare& c);
	// --------------
	virtual void citire() {
		cout << "\nFurnizati numele si prenumele detinatorului: ";
		cin >> detinator_nume;
		cin >> detinator_prenume;
		cout << "\nFurnizati data deschiderii contului (DD-MON-YYYY): ";
		cin >> dataDeschidere;
		cout << "\nFurnizati soldul curent al contului: ";
		cin >> sold;
		cout << endl;
	};
	virtual void afisare()
	{
		cout << "\nNumele si prenumele detinatorului este: " << detinator_nume << " " << detinator_prenume;
		cout << "\nData deschiderii contului este: " << dataDeschidere;
		cout << "\nSoldul curent al contului este: " << sold;
	};
};