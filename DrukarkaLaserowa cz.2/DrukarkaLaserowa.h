#pragma once
#include "Drukarka.h"
#include "ParametryUrzadzenia.h"
#include "PoziomTuszu.h"
#include "LiczbaKartek.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

///Klasa DrukarkaLaserowa, pochodna klasy Drukarka
class DrukarkaLaserowa : public Drukarka
{
private:
	///Podklasa klasy DrukarkaLaserowa
	LiczbaKartek *liczba_kartek;
	///Podklasa klasy DrukarkaLaserowa
	PoziomTuszu poziom_tuszu;
	///Podklasa klasy DrukarkaLaserowa
	ParametryUrzadzenia parametry_urzadzenia;

protected:
	///Zmienna statyczna, przechowujaca liczbe utworzonych obiektow
	static int liczba_obiektow;
	///Zmienna przechowujaca nazwe drukarki
	string nazwa;
	///Zmienna przechowujaca marke drukarki
	string marka;
	///Zmienna przechowujaca pamiec wewnetrzna drukarki
	int pamiec_wewnetrzna;

public:
	///Kontruktor domyslny
	DrukarkaLaserowa();
	///Konstruktor
	DrukarkaLaserowa(int pamiec);
	///Destruktor
	~DrukarkaLaserowa();
	///Konstruktor kopiujacy
	DrukarkaLaserowa(const DrukarkaLaserowa &drukarka_laserowa); 
	///Funkcja modyfikujaca pole nazwy
	void zmienNazwe(string nowa_nazwa);
	///Funkcja modyfikujaca pole marki
	void zmienMarke(string nowa_marka);
	///Funkcja wyswietlajaca aktualne urzadzenie
	void wyswietlUrzadzenie();
	///Funkcja wyswietlajaca rodzaj drukarki
	void wyswietlRodzajDrukarki();
	///Funkcja Wyswietlajaca ilsc stworzonych obiektow
	void wyswietlIlosc();
	///Zapisuje aktualne urzadzenie
	void zapiszUrzadzenie(DrukarkaLaserowa &drukarka_laserowa);
	///Wczytuje aktualne urzadzenie
	void wczytajUrzadzenie(DrukarkaLaserowa &drukarka_laserowa);
	///Funkcja zmieniajaca wybrany parametr urzadzeni
	void zmienParametryUrzadzenia(int nowy_parametr);
	///Funkcja wyswietlajaca stan drukarki
	void wyswietlStan();

	///operator ==
	bool operator == (const DrukarkaLaserowa &drukarka_laserowa);
	///operator >
	bool operator > (const DrukarkaLaserowa &drukarka_laserowa);
	///operator <
	bool operator < (const DrukarkaLaserowa &drukarka_laserowa);
	///operator =
	DrukarkaLaserowa& operator = (const DrukarkaLaserowa &drukarka_laserowa);
	///operator +
	DrukarkaLaserowa operator + (const DrukarkaLaserowa &drukarka_laserowa);
	///operator *
	DrukarkaLaserowa operator * (const DrukarkaLaserowa &drukarka_laserowa);
	///operator +=
	DrukarkaLaserowa& operator += (const DrukarkaLaserowa &drukarka_laserowa);
	///operator -=
	DrukarkaLaserowa& operator -= (const DrukarkaLaserowa &drukarka_laserowa);
	///operator ++
	DrukarkaLaserowa& operator ++ (int);
	///operator --
	DrukarkaLaserowa& operator -- (int);

	///Operator strumieniowy <<
	friend std::ostream& operator << (std::ostream &l, DrukarkaLaserowa &drukarka_laserowa);
	///Operator strumieniowy >>
	friend std::istream& operator >> (std::istream &l, DrukarkaLaserowa &drukarka_laserowa);
};