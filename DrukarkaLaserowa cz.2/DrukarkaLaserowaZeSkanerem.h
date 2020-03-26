#pragma once
#include "DrukarkaLaserowa.h"
#include <iostream>
#include <string>
#include <fstream>

///Klasa DrukarkaLaserowaZeSkanerem, pochodna klasy DrukarkaLaserowa
class DrukarkaLaserowaZeSkanerem : public DrukarkaLaserowa 
{
private:
	///Pole przechowujace ilosc kartek
	int ilosc_kartek;

public:
	///Kontruktor domyslny
	DrukarkaLaserowaZeSkanerem();
	///Destruktor
	~DrukarkaLaserowaZeSkanerem();
	///Funkcja zmieniajaca wybrany parametr urzadzenia
	void zmienParametryUrzadzenia(int nowy_parametr);
	///Zapisuje aktualne urzadzenie do pliku
	void zapiszUrzadzenie(DrukarkaLaserowaZeSkanerem &skaner);
	///Wczytuje aktualne urzadzenie z pliku
	void wczytajUrzadzenie(DrukarkaLaserowaZeSkanerem &skaner);
	///Funkcja wyswietlajaca rodzaj drukarki
	void wyswietlRodzajDrukarki();

	///Operator strumieniowy <<
	friend std::ostream& operator << (std::ostream &s, DrukarkaLaserowaZeSkanerem &skaner);
	///Operator strumieniowy >>
	friend std::istream& operator >> (std::istream &s, DrukarkaLaserowaZeSkanerem &skaner);
};