#pragma once
#include "Drukarka.h"
#include <iostream>
#include <string>
#include <fstream>

///Klasa DrukarkaAtramentowa, pochodna klasy Drukarka
class DrukarkaAtramentowa : public Drukarka
{
private:
	///Pole przechowujace ilosc atramentu
	int ilosc_atramentu;

protected:
	///Zmienna przechowujaca nazwe drukarki
	string nazwa;
	///Zmienna przechowujaca marke drukarki
	string marka;
	///Zmienna przechowujaca pamiec wewnetrzna drukarki
	int pamiec_wewnetrzna;

public:
	///Kontruktor domyslny
	DrukarkaAtramentowa();
	///Destruktor
	~DrukarkaAtramentowa();
	///Funkcja modyfikujaca pole nazwy
	void zmienNazwe(string nowa_nazwa);
	///Funkcja modyfikujaca pole marki
	void zmienMarke(string nowa_marka);
	///Funkcja wyswietlajaca aktualne urzadzenie
	void wyswietlUrzadzenie();
	///Funkcja wyswietlajaca rodzaj drukarki
	void wyswietlRodzajDrukarki();
	///Funkcja wyswietlajaca stan drukarki
	void wyswietlStan();
	///Zapisuje aktualne urzadzenie
	void zapiszUrzadzenie(DrukarkaAtramentowa &atramentowa);
	///Wczytuje aktualne urzadzenie
	void wczytajUrzadzenie(DrukarkaAtramentowa &atramentowa);
	///Funkcja zmieniajaca wybrany parametr urzadzeni
	void zmienParametryUrzadzenia(int nowy_parametr);

	///Operator strumieniowy <<
	friend std::ostream& operator << (std::ostream &a, DrukarkaAtramentowa &atramentowa);
	///Operator strumieniowy >>
	friend std::istream& operator >> (std::istream &a, DrukarkaAtramentowa &atramentowa);
};