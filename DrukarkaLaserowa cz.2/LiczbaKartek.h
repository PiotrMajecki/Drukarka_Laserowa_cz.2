#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

///Klasa LiczbaKartek, podklasa klasy DrukarkaLaserowa
class LiczbaKartek
{
private:
	///Pole przechowuj¹ce ilosc kartek
	int ilosc_kartek;

public:
	///Kontruktor domyslny
	LiczbaKartek();
	///destruktor
	~LiczbaKartek();
	///Funkcja wyswietlajaca aktualna ilosc kartek
	void wyswietlKartki();
	///Funkcja zmniejszajaca ilosc kartek
	void zmniejszKartki();
	///Funkcja zmieniajaca ilosc kartek
	void wymianaKartek(int nowa_ilosc_kartek);

	///Zapisuje aktualne urzadzenie do pliku
	void zapiszUrzadzenie(LiczbaKartek &kartki);
	///Wczytuje aktualne urzadzenie z pliku
	void wczytajUrzadzenie(LiczbaKartek &kartki);

	///Operator strumieniowy <<
	friend std::ostream& operator << (std::ostream &k, LiczbaKartek &kartki);
	///Operator strumieniowy >>
	friend std::istream& operator >> (std::istream &k, LiczbaKartek &kartki);
};