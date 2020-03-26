#include "DrukarkaAtramentowa.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string plik_drukarka_atramentowa = "DrukarkaAtramentowa.txt"; ///<Nazwa pliku do zapisu

DrukarkaAtramentowa::DrukarkaAtramentowa() //konstruktor
{
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor DrukarkaAtramentowa" << endl;
#endif
	nazwa = "DrukarkaAtramentowa";
	marka = "Marka2";
	pamiec_wewnetrzna = 0;
	ilosc_atramentu = 2; //w litrach
}

void DrukarkaAtramentowa::wyswietlUrzadzenie()
{
	string wyswietl_rodzaj_drukarki;
	wyswietl_rodzaj_drukarki = nazwa + string(" ") + marka;
	cout << "To urzadzenie: " << wyswietl_rodzaj_drukarki << endl;
}

void DrukarkaAtramentowa::wyswietlRodzajDrukarki()
{
	cout << "Nazwa: " << nazwa << endl << "Marka: " << marka << endl << "Pamiec wewnetrzna: " << pamiec_wewnetrzna << endl << "Ilosc atrmentu: " << ilosc_atramentu << "l." << endl;
}

void DrukarkaAtramentowa::zmienNazwe(string nowa_nazwa)
{
	nazwa = nowa_nazwa;
}

void DrukarkaAtramentowa::zmienMarke(string nowa_marka)
{
	marka = nowa_marka;
}

void DrukarkaAtramentowa::zmienParametryUrzadzenia(int nowy_parametr)
{
	pamiec_wewnetrzna = nowy_parametr;
}

void DrukarkaAtramentowa::zapiszUrzadzenie(DrukarkaAtramentowa &atramentowa) //Zapisuje urzadzenie
{
#ifdef _DEBUG  
	cout << "Zapisano stan obiektu klasy DrukarkaAtramentowa" << endl;
#endif
	ofstream plik(plik_drukarka_atramentowa);
	plik << atramentowa;
	plik.close();
}

void DrukarkaAtramentowa::wczytajUrzadzenie(DrukarkaAtramentowa &atramentowa) //Wczytuje urzadzenie
{
#ifdef _DEBUG  
	cout << "Wczytano stan obiektu klasy DrukarkaAtramentowa" << endl;
#endif
	ifstream plik(plik_drukarka_atramentowa);
	plik >> atramentowa;
	plik.close();
}

void DrukarkaAtramentowa::wyswietlStan()
{
	cout << "Stan drukarki: " << stan << endl;
}

///Operator strumieniowy
std::ostream& operator << (std::ostream &a, DrukarkaAtramentowa &atramentowa)
{
	a << atramentowa.nazwa << endl << atramentowa.marka << endl << atramentowa.pamiec_wewnetrzna;
	return a;
}

///Operator strumieniowy
std::istream& operator >> (std::istream &a, DrukarkaAtramentowa &atramentowa)
{
	a >> atramentowa.nazwa >> atramentowa.marka >> atramentowa.pamiec_wewnetrzna;
	return a;
}

//destruktor
DrukarkaAtramentowa::~DrukarkaAtramentowa()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~DrukarkaAtramentowa" << endl;
	cout << "Drukarka zostala zniszczona" << endl;
#endif
}