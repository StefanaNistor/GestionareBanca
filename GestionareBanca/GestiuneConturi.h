#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class GestiuneConturi
{
	static int ID;
	string numeBanca = "Banca Calutilor Fericiti";
	string adresaBanca = "Ramnicu-Valcea, Strada Vodei, Nr 77";
	vector<T*> v;
public:
	void afisare_cont()
	{
		for (auto p = v.begin(); p != v.end(); p++)
			(**p).afisare();
	}
	void creare_cont()
	{
		cout << "Furnizati numarul de conturi pentru inregistrarea in banca: " << endl;
		int nr;
		cin >> nr;
		for (int i = 0; i < nr; i++)
		{
			T* t = new T();
			t->citire();
			v.push_back(t);
		}
	}
	// --------------
	GestiuneConturi(vector<T*> v = {});
	GestiuneConturi(const GestiuneConturi&);
	GestiuneConturi& operator=(GestiuneConturi&);
};