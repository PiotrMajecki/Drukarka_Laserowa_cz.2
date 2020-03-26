#include <string>
#include <iostream>
#include <fstream>
#include "DrukarkaLaserowaZeSkanerem.h"

using namespace std;

string plik_drukarka_laserowa_ze_skanerem = "DrukarkaLaserowaZeSkanerem.txt"; ///<Nazwa pliku do zapisu stanu

DrukarkaLaserowaZeSkanerem::DrukarkaLaserowaZeSkanerem() //konstruktor
{
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor DrukarkaLaserowaZeSkanerem" << endl;
#endif
	nazwa = "DrukarkaLaserowaZeSkanerem";
	marka = "Marka3";
	ilosc_kartek = 150;
	liczba_obiektow++;
}

void DrukarkaLaserowaZeSkanerem::zmienParametryUrzadzenia(int nowy_parametr) {
#ifdef _DEBUG  
	cout << "Wywolano metode wirutalna w klasie DrukarkaLaserowaZeSkanerem" << endl;
#endif
	ilosc_kartek = nowy_parametr;
}

void DrukarkaLaserowaZeSkanerem::zapiszUrzadzenie(DrukarkaLaserowaZeSkanerem &skaner) //zapisuje urzadzenie
{
#ifdef _DEBUG  
	cout << "Zapisano urzadzenie klasy DrukarkaLaserowaZeSkanerem" << endl;
#endif
	ofstream plik(plik_drukarka_laserowa_ze_skanerem);
	plik << skaner;
	plik.close();
}

void DrukarkaLaserowaZeSkanerem::wczytajUrzadzenie(DrukarkaLaserowaZeSkanerem &skaner) //wczytuje urzadzenie
{
#ifdef _DEBUG  
	cout << "Wczytano urzadzenie klasy DrukarkaLaserowaZeSkanerem" << endl;
#endif
	ifstream plik(plik_drukarka_laserowa_ze_skanerem);
	plik >> skaner;
	plik.close();
}

void DrukarkaLaserowaZeSkanerem::wyswietlRodzajDrukarki()
{
	cout << "Nazwa: " << nazwa << endl << "Marka: " << marka << endl << "Pamiec wewnetrzna: " << pamiec_wewnetrzna << endl << "Ilosc kartek: " << ilosc_kartek << endl;
}

///Zdefiniowany operator strumieniowy
std::ostream& operator << (std::ostream &s, DrukarkaLaserowaZeSkanerem &skaner) 
{
	s << skaner.nazwa << endl << skaner.marka << endl << skaner.pamiec_wewnetrzna << endl << skaner.ilosc_kartek;
	return s;
}

///Zdefiniowany operator strumieniowy
std::istream& operator >> (std::istream& s, DrukarkaLaserowaZeSkanerem &skaner) 
{
	s >> skaner.nazwa >> skaner.marka >> skaner.pamiec_wewnetrzna >> skaner.ilosc_kartek;
	return s;
}

DrukarkaLaserowaZeSkanerem::~DrukarkaLaserowaZeSkanerem() //destruktor
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~DrukarkaLaserowaZeSkanerem" << endl;
#endif
	--liczba_obiektow;
}