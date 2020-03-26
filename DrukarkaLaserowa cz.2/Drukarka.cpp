#include <iostream>
#include <string>
#include <fstream>
#include "Drukarka.h"

using namespace std;

Drukarka::Drukarka() //konstruktor
{
	#ifdef _DEBUG  
		cout << "Wywolano domyslny konstruktor Drukarka" << endl;
	#endif
		rodzaj_drukarki = "domyslna_drukarka";
		stan = "Wlaczona";
}

void Drukarka::wyswietlStan()
{
	cout << "Stan drukarki: " << stan << endl;
}

///Zdefiniowany operator strumieniowy
std::ostream& operator << (std::ostream &d, Drukarka &drukarka) 
{
	d << drukarka.rodzaj_drukarki;
	return d;
}

///Zdefiniowany operator strumieniowy
std::istream& operator >> (std::istream& d, Drukarka &drukarka)
{
	d >> drukarka.rodzaj_drukarki;
	return d;
}

Drukarka::~Drukarka() //destruktor
{
	#ifdef _DEBUG
		cout << "Wywolano destruktor ~Drukarka" << endl;
	#endif
}