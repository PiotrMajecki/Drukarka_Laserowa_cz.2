#include "DrukarkaLaserowa.h"
#include "DrukarkaAtramentowa.h"
#include "DrukarkaLaserowaZeSkanerem.h"
#include "Drukarka.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string nowa_nazwa; ///<Zmienna przechowujaca nowa nazwe drukarki
string nowa_marka; ///<Zmienna przechowujaca nowa marke drukarki
int opcja; ///<zmienna uzywana do wyboru opcji w menu

///Glowny program
int main()
{
	DrukarkaLaserowa drukarka1;
	DrukarkaAtramentowa drukarka2;
	DrukarkaLaserowaZeSkanerem drukarka3;
	int urzadzenie = 1;
	cout << "Wybrano obiekt domyslny: DrukarkaLaserowa";
	cout << endl;

	//Menu programu
	do {
		switch (opcja)
		{
		case 0:
			cout << "MENU PROGRAMU" << endl;
			cout << "-------------------------------" << endl;
			cout << "Wybierz opcje:" << endl;
			cout << "1: Zmien urzadzenie" << endl;
			cout << "2: Wyswietl aktualne urzadznenie" << endl;
			cout << "3: Zmien nazwe drukarki" << endl;
			cout << "4: Zmien marke drukarki" << endl;
			cout << "5: Zapis urzadzenia do pliku" << endl;
			cout << "6: Odczyt urzadzenia z pliku" << endl;
			cout << "7: Testowanie urzadzenia" << endl;
			cout << "9: Zamknij program" << endl;
			cout << "-------------------------------" << endl;
			cout << "Opcja: ";
			cin >> opcja;
			break;

		case 1:
			do {
				cout << "Zmien urzadzenie: " << endl;
				cout << "[1 - DrukarkaLaserowa  2 - DrukarkaAtramentowa  3 - DrukarkaLaserowaZeSkanerem]" << endl << "Urzadzenie: ";
				cin >> urzadzenie;
				cout << endl;
			} while (urzadzenie != 1 && urzadzenie != 2 && urzadzenie != 3);

			opcja = 0;
			break;

		case 2:
			if (urzadzenie == 1)
				drukarka1.wyswietlUrzadzenie();
			else if (urzadzenie == 2)
				drukarka2.wyswietlUrzadzenie();
			else
				drukarka3.wyswietlUrzadzenie();

			opcja = 0;
			break;

		case 3:
			cout << "Podaj nowa nazwe drukarki: ";
			cin >> nowa_nazwa;
			if (urzadzenie == 1)
				drukarka1.zmienNazwe(nowa_nazwa);
			else if (urzadzenie == 2)
				drukarka2.zmienNazwe(nowa_nazwa);
			else
				drukarka3.zmienNazwe(nowa_nazwa);
	
			cout << "Nazwa drukarki zostala zmieniona." << endl;
			opcja = 0;
			break;

		case 4:
			cout << "Podaj nowa marke drukarki: ";
			cin >> nowa_marka;
			if (urzadzenie == 1)
				drukarka1.zmienMarke(nowa_marka);
			else if (urzadzenie == 2)
				drukarka2.zmienMarke(nowa_marka);
			else
				drukarka3.zmienMarke(nowa_marka);

			cout << "Marka drukarki zostala zmieniona." << endl;
			opcja = 0;
			break;

		case 5:
		{
			if (urzadzenie == 1)
				drukarka1.zapiszUrzadzenie(drukarka1);
			else if (urzadzenie == 2)
				drukarka2.zapiszUrzadzenie(drukarka2);
			else
				drukarka3.zapiszUrzadzenie(drukarka3);

			cout << "Zapisano dane do zewnetrzenego pliku" << endl;
			opcja = 0;
			break;
		}
		case 6:
		{
			if (urzadzenie == 1)
				drukarka1.wczytajUrzadzenie(drukarka1);
			else if (urzadzenie == 2)
				drukarka2.wczytajUrzadzenie(drukarka2);
			else
				drukarka3.wczytajUrzadzenie(drukarka3);
			cout << "Wczytano dane z zewnetrzenego pliku" << endl;
			opcja = 0;
			break;
		}
		case 7:
		{
			DrukarkaLaserowa DrukarkaLaserowa;
			DrukarkaAtramentowa DrukarkaAtramentowa;
			DrukarkaLaserowaZeSkanerem DrukarkaLaserowaZeSkanerem;

			cout << "Polimorfizm z uzyciem tablicy wskaznikow na obiekty klasy podstawowej" << endl;
			Drukarka *urzadzenie1[3];
			urzadzenie1[0] = &DrukarkaLaserowa;
			urzadzenie1[1] = &DrukarkaAtramentowa;
			urzadzenie1[2] = &DrukarkaLaserowaZeSkanerem;

			for (int i = 0; i < 3; i++)
			{
				int wartosc = 3;
				urzadzenie1[i]->zmienParametryUrzadzenia(wartosc);
				urzadzenie1[i]->wyswietlRodzajDrukarki();
			}

			cout << "Testowanie zapisu dla klasy DrukarkaLaserowa" << endl;
			DrukarkaLaserowa.zapiszUrzadzenie(DrukarkaLaserowa);
			DrukarkaLaserowa.wczytajUrzadzenie(DrukarkaLaserowa);

			cout << "Testowanie zapisu dla klasy DrukarkaAtramentowa" << endl;
			DrukarkaAtramentowa.zapiszUrzadzenie(DrukarkaAtramentowa);
			DrukarkaAtramentowa.wczytajUrzadzenie(DrukarkaAtramentowa);

			cout << "Testowanie zapisu dla klasy DrukarkaLaserowaZeSkanerem" << endl;
			DrukarkaLaserowaZeSkanerem.zapiszUrzadzenie(DrukarkaLaserowaZeSkanerem);
			DrukarkaLaserowaZeSkanerem.wczytajUrzadzenie(DrukarkaLaserowaZeSkanerem);

			cout << "Metody wirtualne na wektor urzadzenie" << endl;
			vector <Drukarka*> urzadzenie3;
			urzadzenie3.push_back(&DrukarkaLaserowa);
			urzadzenie3.push_back(&DrukarkaAtramentowa);
			urzadzenie3.push_back(&DrukarkaLaserowaZeSkanerem);
		
			opcja = 0;
			break;

		}
		default:
			cout << "Wybrano niepoprawna opcje." << endl;
			opcja = 0;
		}
	} while (opcja != 9);
	return 0;
}