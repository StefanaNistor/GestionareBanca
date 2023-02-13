#pragma once
#include <iostream>
using namespace std;
#include<string>

class RetreagereInvalida : public exception {
public:
	RetreagereInvalida(string mesaj) : exception(mesaj.c_str()) { }
};
class DobandaInvalida : public exception {
public:
	DobandaInvalida(string mesaj) : exception(mesaj.c_str()) { }
};
class TipContInvalid : public exception {
public:
	TipContInvalid(string mesaj) : exception(mesaj.c_str()) { }
};