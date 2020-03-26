#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

///Klasa abstrakcyjna
class Drukarka
{
private:
	///Pole przechowujace rodzaj drukarki
	string rodzaj_drukarki;

protected:
	///Zmienna przechowujaca stan
	string stan;

public:
	///Kontruktor domyslny
	Drukarka();
	///Destruktor wirtualny
	virtual ~Drukarka();
	///Zmienna wirtualna
	virtual void zmienParametryUrzadzenia(int nowy_parametr) = 0;
	///Zmienaa wirtualna
	virtual void wyswietlRodzajDrukarki() = 0;
	///Funkcja wyswietlajaca stan
	void wyswietlStan();

	///Operator strumieniowy <<
	friend std::ostream& operator << (std::ostream &d, Drukarka &drukarka);
	///Operator strumieniowy >>
	friend std::istream& operator >> (std::istream &d, Drukarka &drukarka);
};