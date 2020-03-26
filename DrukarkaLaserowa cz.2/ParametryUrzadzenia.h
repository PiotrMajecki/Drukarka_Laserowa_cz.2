#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

///Klasa ParametryUrzadzenia, podklasa klasy DrukatkaLaserowa
class ParametryUrzadzenia
{
private:
	///Pole przechwujace rodzaj urzadzenia
	string rodzaj_urzadzenia;
	///Pole przechwujace ocene
	int ocena;
	///Pole przechwujace typ wyswietlacza
	string typ_wyswietlacz;

public:
	///Konstruktor domyslny
	ParametryUrzadzenia();
	///Destruktor
	~ParametryUrzadzenia();
	///Funkcja wyswietlajaca rodzaj drukarki
	void wyswietlRodzajDrukarki();

	///Zapisuje aktualne urzadzenie do pliku
	void zapiszUrzadzenie(ParametryUrzadzenia &parametry);
	///Wczytuje aktualne urzadzenie z pliku
	void wczytajUrzadzenie(ParametryUrzadzenia &parametry);

	///Operator strumieniowy <<
	friend std::ostream& operator << (std::ostream &p, ParametryUrzadzenia &parametry);
	///Operator strumieniowy >>
	friend std::istream& operator >> (std::istream &p, ParametryUrzadzenia &parametry);
};