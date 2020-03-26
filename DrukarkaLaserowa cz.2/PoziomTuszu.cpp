#include "PoziomTuszu.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

string plik_poziom_tuszu = "PoziomTuszu.txt"; ///<Nazwa pliku do zapisu stanu obiektu

PoziomTuszu::PoziomTuszu() //kostruktor
{
#ifdef DEBUG  
	cout << "Wywolano konstruktor PoziomTuszu" << endl;
#endif
	ilosc_tuszu = 85; //w %
	rodzaj_tuszu = "czarno-bialy";
}

void PoziomTuszu::wyswietlStanTuszu() //obiekt automatyczny
{
	cout << "Ilosc tuszu: " << ilosc_tuszu << endl;
	cout << "Rodzaj tuszu: " << rodzaj_tuszu << endl;
}

void PoziomTuszu::zapiszUrzadzenie(PoziomTuszu &poziom) //Zapisuje urzadzenie
{
	#ifdef _DEBUG  
		cout << "Zapisano stan obiektu klasy PoziomTuszu" << endl;
	#endif
		ofstream plik(plik_poziom_tuszu);
		plik << poziom;
		plik.close();
}

void PoziomTuszu::wczytajUrzadzenie(PoziomTuszu &poziom) //Wczytuje urzadzenie
{
	#ifdef _DEBUG  
		cout << "Wczytano stan obiektu klasy PoziomTuszu" << endl;
	#endif
		ifstream plik(plik_poziom_tuszu);
		plik >> poziom;
		plik.close();
}

///Zdefiniowany operator strumieniowy
std::ostream& operator << (std::ostream &t, PoziomTuszu &poziom)
{
	t << poziom.ilosc_tuszu << endl << poziom.rodzaj_tuszu;
	return t;
}

///Zdefiniowany operator strumieniowy
std::istream& operator >> (std::istream &t, PoziomTuszu &poziom)
{
	t >> poziom.ilosc_tuszu >> poziom.rodzaj_tuszu;
	return t;
}

PoziomTuszu::~PoziomTuszu() //destruktor
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~PoziomTuszu" << endl;
	cout << "Wylaczono drukarke" << endl;
#endif	
}