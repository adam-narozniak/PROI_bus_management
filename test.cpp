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
	test_edycji_pasazerow();
	test_podklas();

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

void test_edycji_pasazerow() { // obecnie nie mozliwa w uzyciu, metoda prywatna, aby nie podmienic zle
	Autobus a1("wwl", "lada", 2.5, 190, 1, 41, 62, 32, 87, 3);
	a1.dodaj_kierowce();
	a1.dodaj_pasazerow(50, 23, 2);
	a1.wyswietl();
	a1.edytuj_pasazerow(200, 150, 5);
	a1.wyswietl();
}

void test_konsturkora_kopiujacego() {
	cout << "KONSTRUKTOR KOPIUJACY kopia 1 w 2" << endl;
	Autobus a1("ww0012", "mercedes", 2.2, 190, 1, 10, 60);
	a1.dodaj_kierowce();
	cout << "Przed zmianami 1" << endl;
	a1.wyswietl();
	Autobus a2(a1);
	cout << "TANKOWANIE KOPII + dodanie pasazerow - autobus 2" << endl;
	a2.tankuj(50);
	a2.dodaj_pasazerow();
	cout << "Po zmianach 1" << endl;
	a1.wyswietl();
	cout << "Po zmianach 2" << endl;
	a2.wyswietl();
}

void test_podklas() {
	cout << endl;
	Silnik silnik01(1.9, 130, 1);
	silnik01.wyswietl();

	Bak bak01(34, 60);
	bak01.wyswietl();

	Kierowca k("Jan", "Nowak", 01234);
	k.wyswietl();

	Miejsca miejsca01;
	miejsca01.wyswietl();

	Pasazerowie pas01(10, 12, 3);
	pas01.wyswietl();
	cout << endl;
}
void test_dodawania_rowerow() {
	Autobus a1;
	cout << "Proba przypisania bez kierowcy" << endl;
	++a1;
	a1.dodaj_kierowce("Janek", "Nowak", 12345);
	a1.dodaj_pasazerow(30, 24, 2);
	a1.wyswietl();
	cout << "DODANIE ROWERU" << endl;
	++a1;
	a1.wyswietl();
	cout << "ODJECIE ROWERU" << endl;
	--a1;
	a1.wyswietl();

}
void test_przesiadki() {
	Autobus a1, a2("wwl", "lada", 2.5, 190, 1, 41, 62, 32, 87, 3);
	a1.dodaj_kierowce();
	a2.dodaj_kierowce("Janek", "Nowak", 12345);
	a2.dodaj_pasazerow(120, 23, 2);
	a1.wyswietl();
	a2.wyswietl();
	a1 << a2;
	a1.wyswietl();
	a2.wyswietl();

}

void test_wysiadki() {
	Autobus a1("WW0000", "BMW", 2.2, 190, 1, 80, 100, 30, 50, 3);
	a1.dodaj_kierowce();
	a1.dodaj_pasazerow();
	a1.wyswietl();
	Autobus a2 = -a1;
	a2.wyswietl();
}
void test_operatorow() {
	test_porownania_mocy();
	test_tankowania_do_pelna();
	test_dodawania_rowerow();
	test_przesiadki();
	test_wysiadki();


}