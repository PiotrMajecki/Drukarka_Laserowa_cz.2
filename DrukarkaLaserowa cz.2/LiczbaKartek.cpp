#include "LiczbaKartek.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string plik_liczba_kartek = "LiczbaKartek.txt"; ///<Nazwa pliku do zapisu stanu obiektu

LiczbaKartek::LiczbaKartek() //konstruktor
{
#ifdef DEBUG  
	cout << "Wywolano konstruktor LiczbaKartek" << endl;
#endif
	ilosc_kartek = 100;
}

void LiczbaKartek::wyswietlKartki() //obiekt automatyczny
{
	cout << "Ilosc kartek: " << ilosc_kartek << endl;
}
void LiczbaKartek::wymianaKartek(int nowa_ilosc_kartek) //obiekt dynamiczny
{
	ilosc_kartek = nowa_ilosc_kartek;
}

void LiczbaKartek::zmniejszKartki()
{
	if (ilosc_kartek >= 1)
		ilosc_kartek = ilosc_kartek - 1;
}

void LiczbaKartek::zapiszUrzadzenie(LiczbaKartek &kartki) //Zapisuje urzadzenie
{
#ifdef _DEBUG  
	cout << "Zapisano stan obiektu klasy LiczbaKartek" << endl;
#endif
	ofstream plik(plik_liczba_kartek);
	plik << kartki;
	plik.close();
}

void LiczbaKartek::wczytajUrzadzenie(LiczbaKartek &kartki) //Wczytuje urzadzenie
{
#ifdef _DEBUG  
	cout << "Wczytano stan obiektu klasy LiczbaKartek" << endl;
#endif
	ifstream plik(plik_liczba_kartek);
	plik >> kartki;
	plik.close();
}

///Zdefiniowany operator strumieniowy
std::ostream& operator << (std::ostream &k, LiczbaKartek &kartki)
{
	k << kartki.ilosc_kartek;
	return k;
}

///Zdefiniowany operator strumieniowy
std::istream& operator >> (std::istream &k, LiczbaKartek &kartki) 
{
	k >> kartki.ilosc_kartek;
	return k;
}

LiczbaKartek::~LiczbaKartek() //destruktor
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~LiczbaKartek" << endl;
	cout << "Wylaczono drukarke" << endl;
#endif
}