#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

///Klasa PoziomTuszu, podklasa klasy DrukarkaLaserowa
class PoziomTuszu
{
private:
	///Pole przechwujace ilosc tuszu
	int ilosc_tuszu;
	///Pole przechowujace rodzaj tuszu
	string rodzaj_tuszu;

public:
	///Konstruktor domyslny
	PoziomTuszu();
	///Destruktor
	~PoziomTuszu();
	///Funkcja wyswietlajaca stan tuszu
	void wyswietlStanTuszu();

	///Zapisuje aktualne urzadzenie do pliku
	void zapiszUrzadzenie(PoziomTuszu &poziom);
	///Wczytuje aktualne urzadzenie z pliku
	void wczytajUrzadzenie(PoziomTuszu &poziom);

	///Operator strumieniowy <<
	friend std::ostream& operator << (std::ostream &t, PoziomTuszu &poziom);
	///Operator strumieniowy >>
	friend std::istream& operator >> (std::istream &t, PoziomTuszu &poziom);
};