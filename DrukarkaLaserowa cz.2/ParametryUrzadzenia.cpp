#include "ParametryUrzadzenia.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string plik_parametry_urzadzenia = "ParametryUrzadzenia.txt"; ///<Nazwa pliku do zapisu stanu obiektu

ParametryUrzadzenia::ParametryUrzadzenia() //konstruktor
{
#ifdef DEBUG
	cout << "Wywolano konstruktor ParametryUrzadzenia" << endl;
#endif
	rodzaj_urzadzenia = "drukarka laserowa";
	ocena = 4;
	typ_wyswietlacz = "prostokat";
}

void ParametryUrzadzenia::wyswietlRodzajDrukarki() //obiekt automatyczny
{
	cout << "Rodzaj urzadzenia: " << rodzaj_urzadzenia << endl;
	cout << "Ocena: " << ocena << endl;
	cout << "Wyswietlacz: " << typ_wyswietlacz << endl;
}

void ParametryUrzadzenia::zapiszUrzadzenie(ParametryUrzadzenia &parametry) //zapisuje urzadzenie
{
#ifdef _DEBUG  
	cout << "Zapisano stan obiektu klasy ParametryUrzadzenia" << endl;
#endif
	ofstream plik(plik_parametry_urzadzenia);
	plik << parametry;
	plik.close();
}

void ParametryUrzadzenia::wczytajUrzadzenie(ParametryUrzadzenia &parametry) //wczytuje urzadzenie
{
#ifdef _DEBUG  
	cout << "Wczytano stan obiektu klasy ParametryUrzadzenia" << endl;
#endif
	ifstream plik(plik_parametry_urzadzenia);
	plik >> parametry;
	plik.close();
}

///Zdefiniowany operator strumieniowy
std::ostream& operator << (std::ostream &p, ParametryUrzadzenia &parametry)
{
	p << parametry.rodzaj_urzadzenia << endl << parametry.ocena << endl << parametry.typ_wyswietlacz;
	return p;
}

///Zdefiniowany operator strumieniowy
std::istream& operator >> (std::istream &p, ParametryUrzadzenia &parametry)
{
	p >> parametry.rodzaj_urzadzenia >> parametry.ocena >> parametry.typ_wyswietlacz;
	return p;
}

ParametryUrzadzenia::~ParametryUrzadzenia() //destruktor
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~ParametryUrzadzenia" << endl;
	cout << "Wylaczono drukarke" << endl;
#endif
}