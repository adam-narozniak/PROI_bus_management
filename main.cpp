#include <iostream>
#include "autobus.h"
#include <string>
#include "kierowca.h"
#include "bak.h"
#include "silnik.h"
#include "miejsca.h"
#include "pasazerowie.h"
using namespace std;

void test();
void test_podklasy();
void test_porownania_mocy();
void test_tankowania_do_pelna();
int main(void) {
	//Autobus a1("ww0012", "mercedes", 2.2, 190, 1, 10, 60);
	//cout << a1.get_bak()->get_stan() << endl;
	test_tankowania_do_pelna();
	//test();
}

void test() {
	cout << "Funkcja testujaca" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Tworze podstawowa klase Autobus" << endl;
	cout << "--------------------------------------------------" << endl;
	Autobus autobus01("WWL0000", "MBD");
	autobus01.wyswietl();

	autobus01.stworz_kierowce();


	cout << "KONSTRUKTOR KOPIUJACY kopia 01 w 03" << endl;
	//Autobus * autobus02 = new Autobus("WWL0000", "MBD");;

	Autobus autobus03(autobus01);
	cout << "AUTOBUS 03" << endl;
	autobus03.wyswietl();
	cout << "--------------------------------------------------" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "TANKOWANIE KOPII 03" << endl;
	autobus03.tankuj(50);
	autobus03.wyswietl();
	cout << "```````````````````````````````````````````````````" << endl;
	cout << "Przypisanie kierowcy do autobusu 03" << endl;
	cout << "--------------------------------------------------" << endl;
	Kierowca *kierowca01 = new Kierowca("miroslaw", "pajak", 34534);
	autobus03.przypisz_kierowce(kierowca01);
	cout << "--------------------------------------------------" << endl;
	cout << "Po zmianach03" << endl;
	autobus03.wyswietl();
	cout << "Po zmianach 01" << endl;
	autobus01.wyswietl();
	cout << "Jak widac zmiany nie dotknely 01" << endl << "Konstruktor kopiujacy dziala poprawnie" << endl;
	


	
	/*cout << "Test kostruktora kopiujacego" << endl;
	Autobus autobus02(autobus01);
	autobus02.wyswietl();
	cout << "Modyfikacja drugiego (nowo powstalego obiektu)" << endl;
	autobus02.wczytaj();
	cout << "Porownanie dwoch obiektow (w celu sprawdzenia ze dzialam na nowo powstalym obiekcie, a nie na starym do ktorego mam wskaznik" << endl;
	cout << "-------------------01-------------------------------" << endl;
	autobus01.wyswietl();
	cout << "-------------------02-------------------------------" << endl;
	autobus02.wyswietl();
	cout << "--------------------------------------------------" << endl;*/


	
	

	
}
void test_podklasy() {
	Miejsca miejsca01;
	miejsca01.wyswietl();
	cout << "--------------------------------------------------" << endl;

	Bak bak01(34, 60);
	bak01.wyswietl();
	cout << "--------------------------------------------------" << endl;

	Pasazerowie pas01(10, 12, 3);
	pas01.wyswietl();
	cout << "--------------------------------------------------" << endl;

	Silnik silnik01(1.9, 130, 1);
	silnik01.wyswietl();
	cout << "--------------------------------------------------" << endl;
}

void test_porownania_mocy() {//dziala 
	Autobus a1("ww0012", "mercedes", 2.2, 190, 1);
	Autobus a2("wk3465", "bmw", 2.2, 200, 2);
	bool test;
	test = a1 > a2;
	cout << test << endl;
}

void test_tankowania_do_pelna() {
	//wymaga poprawki potem
	Autobus a1("ww0012", "mercedes", 2.2, 190, 1, 10, 60);
	a1.wyswietl();
	a1 = !a1;
	a1.wyswietl();
}