//O aplicatie care se ocupa cu gestiunea diferitelor conturilor bancare ale clientilor

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "ConturiBancare.h"
#include "ConturiEconomii.h"
#include "ConturiCurente.h"
#include "GestiuneConturi.h"
#include "ConturiEconomii-S.h"
#include "Meniu.h"

using namespace std;


const float ContEconomii::RATA_DOBANZII = 0.09;

const int ContCurent::TRANZACTII_GRATUITE = 10;
//---------------------- Suprascrierea operatorilor >>,<<---------------------------
ostream& operator<<(ostream& console, ConturiBancare& c)
{
	console << "\n+++++++++++++++++++++++++++++++++++++++";
	console << "\n-> Datele contului bancar:";
	console << "\n+++++++++++++++++++++++++++++++++++++++";
	console << endl;
	console << "\nNumele si preunele detinatorului este: " << c.detinator_nume << ' ' << c.detinator_prenume;
	console << "\nData in care contul a fost deschis este: " << c.dataDeschidere;
	console << "\nSoldul curent al contului este: " << c.sold << " RON";
	return console;
}
istream& operator>>(istream& console, ConturiBancare& c)
{
	cout << "\n-> Furnizati urmatoarele date ale contului bancar dorit: ";
	cout << "\nNumele si prenumele detinatorului: ";
	console >> c.detinator_nume;
	console >> c.detinator_prenume;
	cout << "\nData deschiderii: ";
	console >> c.dataDeschidere;
	cout << "\nSold curent:";
	console >> c.sold;
	return console;
}
ostream& operator<<(ostream& console, ContEconomii& ce)
{
	console << dynamic_cast<ConturiBancare&>(ce);
	console << "\nTipul de dobanda asociata contului este de: " << ce.tipDobanda << " luni";
	console << "\nDobanda acumulata in cont este de: " << ce.getDobanda() << " RON";
	return console;
}
istream& operator>>(istream& console, ContEconomii& ce)
{
	console >> dynamic_cast<ConturiBancare&>(ce);
	cout << "\nOferta dobanzii pe numarul de luni (3,6 sau 12):";
	console >> ce.tipDobanda;
	if (ce.tipDobanda != 3 && ce.tipDobanda != 6 && ce.tipDobanda != 12)
	{
		throw DobandaInvalida("Nu oferim serviciile dobanzii pe acest numar de luni!");
	}
	return console;
}
ostream& operator<<(ostream& console, ContCurent& cc)
{
	console << dynamic_cast<ConturiBancare&>(cc);
	console << "\nNumarul de tranzactii al contului este: " << cc.getNrTranzactii() << " dintre care depuneri sunt in numar de "
		<< cc.nrDepuneri << " si retrageri sunt in numar de " << cc.nrRetrageri;
	console << "\nDintre aceste tranzactii, online sunt: " << cc.nrTranzactiiOnline;
	console << "\n-----------------------------------------";
	//DACA AVETI ALTE OPERATII IN AFARA DE CELE INTRODUSE DE LA TASTATURA
	/*console << "\nTaxele acumulate in cont sunt pentru: ";
	console << "\n   >>Plati online: " << cc.getTaxaBanca() << " RON";
	console << "\n   >>Plati la alte banci: " << cc.getTaxaBanca() << " RON";*/
	console << "\n   >>Depasirea numarului de tranzactii gratuite: " << cc.getTaxaTranzactii() << " RON";
	return console;
}
istream& operator>>(istream& console, ContCurent& cc)
{
	console >> dynamic_cast<ConturiBancare&>(cc);
	cout << "\nNumarul de depuneri: ";
	console >> cc.nrDepuneri;
	cout << "\nNumarul de retrageri: ";
	console >> cc.nrRetrageri;
	return console;
}


template<class T>
GestiuneConturi<T>::GestiuneConturi(vector<T*> vec)
{
	v = vec;
}

template<class T>
int GestiuneConturi<T>::ID = ID + 1;


ConturiBancare* ConturiBancare::creare(int optiune)
{
	if (optiune == 1)
	{
		return new ContEconomii;
	}
	else
	{
		return new ContCurent;
	}
}
Meniu* Meniu::instanta = nullptr;

int main()
{
	//-------------------------------------------------TESTE FUNCTIONALITATE CLASE SI ERORI
	try {
		/*	ConturiBancare Client0;
			Client0.citire();
			Client0.afisare();*/
	//-------------------------------------- Test 1
			/*ContCurent Client1;
			cin >> Client1;
			Client1.DepunereBani(1, 100);
			Client1.DepunereBani(0, 200);
			Client1.DepunereBani(0, 500);
			Client1.RetragereBaniOnline(150);
			Client1.RetragereBaniOnline(50);
			Client1.RetragereBaniOnline(20);
			Client1.RetragereBaniFizic(0, 200);
			Client1.RetragereBaniFizic(0, 100);
			Client1.RetragereBaniFizic(1, 50);
			cout << Client1;*/
	//-------------------------------------- Test 2
			/*ContCurent Client2;
			Client2=Client1;
			cout << Client2; */
	//-------------------------------------- Test 3
			/*ContEconomii Client3("Andrei", "Matei", "16-FEBR-2006", 700, 5); //-> valoare gresita pentru dobanda
			ContEconomii Client4;
			cin >> Client4;
			cout << Client4;
			ContEconomii Client5;
			Client5 = Client4;
			cout << Client5;
			Client5.SchimbareDobanda(3);//-> valoare corecta pentru dobanda
			cout << Client5;*/
	//-------------------------------------- Test 4
			/*ContEconomii Client6;
			ContCurent Client7;
			Client6.citire();
			Client7.citire();
			Client7.RetragereBaniOnline(150);
			Client7.RetragereBaniFizic(0, 50);
			Client7.afisare();
			ContEconomii Client8(Client6);
			Client8.afisare();*/
	//-------------------------------------- Test 5
		int optiune;
		Meniu* nouMeniu = nouMeniu->getInstanta();
		optiune = 0;
		while (optiune != 5)
		{
			cout << "\n-----------------------------------------------";
			cout << "\n---------->Alegeti optiunea dorita!<-----------";
			cout << "\n-----------------------------------------------";
			cout << "\n1->Adaugare cont bancar";
			cout << "\n2->Afisare conturi bancare";
			cout << "\n3->Afisare numar conturi de economii";
			cout << "\n4->Afisare detalii despre banca";
			cout << "\n5->Iesire program";
			cout << endl;
			cin >> optiune;
			if (optiune == 1)
			{
				nouMeniu->adaugaContBancar();
				
			}
			if (optiune == 2)
			{
				nouMeniu->afiseazaConturiBancare();
			}
			if (optiune == 3)
			{
				nouMeniu->afisNrConturiEconomii();
			}
			if (optiune == 4)
			{
				nouMeniu->afisDetaliiBanca();
			}
		}
		nouMeniu->deleteInstanta();
		nouMeniu->done();
	}
	catch (RetreagereInvalida e) {
		cout << endl << "Error: " << e.what();
	}
	catch (DobandaInvalida e) {
		cout << endl << "Error: " << e.what();
	}
	catch (TipContInvalid e) {
		cout << endl << "Error: " << e.what();
	}

	return 0;
}