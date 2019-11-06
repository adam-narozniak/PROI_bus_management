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
using namespace std;


void test_konsturkora_kopiujacego();

void test_podklas();

void test_operatorow();
void test_dodawania_rowerow();
void test_operatorow_incrementacji();
void test_przesiadki();
void test_edycji_pasazerow();

int main(void) {
#ifdef _DEBUG
	test_operatorow();
#endif

	/*Autobus a1("ww0012", "mercedes", 2.2, 190, 1, 10, 60, 10, 40, 1);
	a1.wyswietl();
	a1.dodaj_kierowce();
	a1.jedz();
	a1.wyswietl();*/

	//test();


	//test_tankowania_do_pelna();

	//test_podklas();
	//test_porownania_mocy();
	//test_konsturkora_kopiujacego();
	//test_dodawania_rowerow();
	//test_przesiadki();


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



void test_konsturkora_kopiujacego() {
	cout << "KONSTRUKTOR KOPIUJACY kopia 1 w 2" << endl;
	Autobus a1("ww0012", "mercedes", 2.2, 190, 1, 10, 60);
	cout << "Przed zmianami 1" << endl;
	a1.wyswietl();
	Autobus a2(a1);
	cout << "TANKOWANIE KOPII - autobus 2" << endl;
	a2.tankuj(50);
	cout << "Po zmianach 1" << endl;
	a1.wyswietl();
	cout << "Po zmianach 2" << endl;
	a2.wyswietl();
}
void test_operatorow_incrementacji() {
	Autobus a1("WW0000", "BMW", 2.2, 190, 1, 80, 100, 30, 50, 3);
	a1.wyswietl();
	++a1;
	a1.wyswietl();
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

void test_edycji_pasazerow() { // obecnie nie mozliwa w uzyciu, metoda prywatna, aby nie podmienic zle
	Autobus a1("wwl", "lada", 2.5, 190, 1, 41, 62, 32, 87, 3);
	a1.dodaj_kierowce();
	a1.dodaj_pasazerow(120, 23, 2);
	a1.wyswietl();
	a1.edytuj_pasazerow(200, 150, 5);
	a1.wyswietl();
}
void test_operatorow() {
	//test_porownania_mocy();
	//test_tankowania_do_pelna();
	test_dodawania_rowerow();
	//test_operatorow_incrementacji();
	//test_przesiadki();
	//test_edycji_pasazerow();

}