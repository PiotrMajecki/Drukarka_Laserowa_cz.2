#include "DrukarkaLaserowa.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int DrukarkaLaserowa::liczba_obiektow = 0;
string plik_drukarka_laserowa = "DrukarkaLaserowa.txt"; ///<Nazwa pliku do zapisu

DrukarkaLaserowa::DrukarkaLaserowa() //konstruktor
{
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor DrukarkaLaserowa" << endl;
#endif
	liczba_kartek = NULL;
	nazwa = "DrukarkaLaserowa";
	marka = "Marka1";
	pamiec_wewnetrzna = 0;
	liczba_obiektow++;
}

DrukarkaLaserowa::DrukarkaLaserowa(int pamiec)
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor DrukarkaLaserowa" << endl;
#endif
	liczba_obiektow++;
	pamiec_wewnetrzna = pamiec;
	nazwa = "DrukarkaLaserowa";
	marka = "Marka1";
}

DrukarkaLaserowa::DrukarkaLaserowa(const DrukarkaLaserowa &drukarka_laserowa)
{
	nazwa = drukarka_laserowa.nazwa;
	liczba_kartek = new LiczbaKartek;
	liczba_kartek = drukarka_laserowa.liczba_kartek;
	poziom_tuszu = drukarka_laserowa.poziom_tuszu;
	parametry_urzadzenia = drukarka_laserowa.parametry_urzadzenia;
	nazwa = drukarka_laserowa.nazwa;
	marka = drukarka_laserowa.marka;
	pamiec_wewnetrzna = drukarka_laserowa.pamiec_wewnetrzna;
}

void DrukarkaLaserowa::wyswietlIlosc()
{
	cout << liczba_obiektow;
}

void DrukarkaLaserowa::wyswietlUrzadzenie()
{
	string wyswietl_rodzaj_drukarki;
	wyswietl_rodzaj_drukarki = nazwa + string(" ") + marka;
	cout << "To urzadzenie: " << wyswietl_rodzaj_drukarki << endl;
}

void DrukarkaLaserowa::wyswietlRodzajDrukarki()
{
	cout << "Nazwa: " << nazwa << endl << "Marka: " << marka << endl << "Pamiec wewnetrzna: " << pamiec_wewnetrzna << endl;
}

void DrukarkaLaserowa::zmienNazwe(string nowa_nazwa)
{
	nazwa = nowa_nazwa;
}

void DrukarkaLaserowa::zmienMarke(string nowa_marka)
{
	marka = nowa_marka;
}

void DrukarkaLaserowa::zmienParametryUrzadzenia(int nowy_parametr) 
{
	pamiec_wewnetrzna = nowy_parametr;
}

void DrukarkaLaserowa::zapiszUrzadzenie(DrukarkaLaserowa &drukarka_laserowa) //Zapisuje urzadzenie
{
#ifdef _DEBUG  
	cout << "Zapisano stan obiektu klasy DrukarkaLaserowa" << endl;
#endif
	ofstream plik(plik_drukarka_laserowa);
	plik << drukarka_laserowa;
	plik.close();
	drukarka_laserowa.parametry_urzadzenia.zapiszUrzadzenie(drukarka_laserowa.parametry_urzadzenia);
}

void DrukarkaLaserowa::wczytajUrzadzenie(DrukarkaLaserowa &drukarka_laserowa) //Wczytuje urzadzenie
{
#ifdef _DEBUG  
	cout << "Wczytano stan obiektu klasy DrukarkaLaserowa" << endl;
#endif
	ifstream plik(plik_drukarka_laserowa);
	plik >> drukarka_laserowa;
	plik.close();
	drukarka_laserowa.parametry_urzadzenia.wczytajUrzadzenie(drukarka_laserowa.parametry_urzadzenia);
}
void DrukarkaLaserowa::wyswietlStan()
{
	cout << "Stan drukarki: " << stan << endl;
}

//operatory
///Operator =
bool DrukarkaLaserowa::operator == (const DrukarkaLaserowa &drukarka_laserowa)
{
	if (drukarka_laserowa.pamiec_wewnetrzna == pamiec_wewnetrzna)
		return true;
	else
		return false;
}

///Operator >
bool DrukarkaLaserowa::operator > (const DrukarkaLaserowa &drukarka_laserowa)
{
	if (drukarka_laserowa.pamiec_wewnetrzna > pamiec_wewnetrzna)
		return true;
	else
		return false;
}

///Operator <
bool DrukarkaLaserowa::operator < (const DrukarkaLaserowa &drukarka_laserowa)
{
	if (drukarka_laserowa.pamiec_wewnetrzna < pamiec_wewnetrzna)
		return true;
	else
		return false;
}

///Operator +
DrukarkaLaserowa DrukarkaLaserowa::operator + (const DrukarkaLaserowa &drukarka_laserowa)
{
	DrukarkaLaserowa suma(0);
	suma.pamiec_wewnetrzna = drukarka_laserowa.pamiec_wewnetrzna + pamiec_wewnetrzna;
	return suma;
}

///Operator *
DrukarkaLaserowa DrukarkaLaserowa::operator * (const DrukarkaLaserowa &drukarka_laserowa)
{
	DrukarkaLaserowa iloczyn(0);
	iloczyn.pamiec_wewnetrzna = drukarka_laserowa.pamiec_wewnetrzna * pamiec_wewnetrzna;
	return iloczyn;
}

///Operator =
DrukarkaLaserowa & DrukarkaLaserowa::operator = (const DrukarkaLaserowa &drukarka_laserowa)
{
	pamiec_wewnetrzna = drukarka_laserowa.pamiec_wewnetrzna;
	nazwa = drukarka_laserowa.nazwa;
	marka = drukarka_laserowa.marka;

	return *this;
}

///Operator +=
DrukarkaLaserowa & DrukarkaLaserowa::operator += (const DrukarkaLaserowa &drukarka_laserowa)
{
	pamiec_wewnetrzna += drukarka_laserowa.pamiec_wewnetrzna;
	return *this;
}

///Operator -=
DrukarkaLaserowa & DrukarkaLaserowa::operator -= (const DrukarkaLaserowa &drukarka_laserowa)
{
	pamiec_wewnetrzna -= drukarka_laserowa.pamiec_wewnetrzna;
	return *this;
}

///Operator ++
DrukarkaLaserowa & DrukarkaLaserowa::operator ++ (int)
{
	pamiec_wewnetrzna++;
	return *this;
}

///Operator --
DrukarkaLaserowa & DrukarkaLaserowa::operator -- (int)
{
	if (pamiec_wewnetrzna != 0)
		pamiec_wewnetrzna--;
	return *this;
}

///Operator strumieniowy
std::ostream& operator << (std::ostream &l, DrukarkaLaserowa &drukarka_laserowa)
{
	l << drukarka_laserowa.nazwa << endl << drukarka_laserowa.marka << endl << drukarka_laserowa.pamiec_wewnetrzna;
	return l;
}

///Operator strumieniowy
std::istream& operator >> (std::istream &l, DrukarkaLaserowa &drukarka_laserowa)
{
	l >> drukarka_laserowa.nazwa >> drukarka_laserowa.marka >> drukarka_laserowa.pamiec_wewnetrzna;
	return l;
}

//destruktor
DrukarkaLaserowa::~DrukarkaLaserowa()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~DrukarkaLaserowa" << endl;
	cout << "Drukarka zostala zniszczona" << endl;
#endif
	--liczba_obiektow;
}