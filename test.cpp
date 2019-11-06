#include <iostream>
#include <iomanip>
#include <string>
#include "autobus.h"
#include "kierowca.h"
#include "bak.h"
#include "silnik.h"
#include "miejsca.h"
#include "pasazerowie.h"
#include "test.h"
#include "test.h"
void test() {
	cout << "Funkcja testujaca" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Tworze podstawowa klase Autobus" << endl;
	cout << "--------------------------------------------------" << endl;
	Autobus a1("WW0000", "BMW", 2.2, 190, 1, 80, 100, 30, 50, 3);
	a1.wyswietl();
	//kierowca
	a1.dodaj_kierowce();
	cout << "KOPIA" << endl;
	Autobus a2(a1);
	cout << "AUTOBUS 2" << endl;
	cout << "AUTOBUS 2 - JEDZ" << endl;
	a2.jedz();
	a2.wyswietl();
	cout << "--------------------------------------------------" << endl;
	cout << "TANKOWANIE KOPII" << endl;
	a2.tankuj(90);
	cout << "PASAZEROWIE W A2" << endl;
	a2.dodaj_pasazerow(30, 24, 1);
	a2.wyswietl();
	cout << "KANAR - wywolanie funkcji" << endl;
	a2.kanar();
	a2.wyswietl();
	{
		cout << "LOKALNIE" << endl;
		Autobus a3("WW0001", "Mercedes", 2.4, 180, 1, 80, 100, 30, 50, 3);
		a3.wyswietl();
	}
	cout << "DYNAMICZNIE" << endl;
	Autobus * pa;
	pa = new Autobus("WW 0932");
	pa->wyswietl();
	cout << "Dodaj kierowce, przerejestruj, dodaj pasazerow, tankuj" << endl;
	pa->dodaj_kierowce("Kamil", "Stok", 2);
	pa->dodaj_pasazerow();
	pa->tankuj(100);
	pa->przerejestruj("WW 8734");
	pa->wyswietl();

}

void test_porownania_mocy() {
	cout << "TEST POROWNANIA MOCY" << endl;
	Autobus a1("ww0012", "mercedes", 2.2, 190, 1);
	Autobus a2("wk3465", "bmw", 2.2, 200, 2);
	bool test;
	test = a1 < a2;
	cout << test << endl;
}

void test_tankowania_do_pelna() {
	Autobus a1("ww0012", "mercedes", 2.2, 190, 1, 10, 60);
	a1.wyswietl();
	!a1;
	a1.wyswietl();
}
