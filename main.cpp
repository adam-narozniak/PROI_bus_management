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
void test_konsturkora_kopiujacego();
void test_podklas();
void test_porownania_mocy();
void test_tankowania_do_pelna();
void test_dodawania_pasazerow();
void test_operatorow_incrementacji();
int main(void) {
	//Autobus a1("ww0012", "mercedes", 2.2, 190, 1, 10, 60, 10, 40, 1);
	//a1.wyswietl();
	//test_tankowania_do_pelna();
	//test();
	//test_podklas();
	//test_porownania_mocy();
	//test_konsturkora_kopiujacego();
	test_dodawania_pasazerow();

}

void test() {
	cout << "Funkcja testujaca" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Tworze podstawowa klase Autobus" << endl;
	cout << "--------------------------------------------------" << endl;
	Autobus autobus1("WWL0000", "MBD");
	autobus1.wyswietl();
	autobus1.stworz_kierowce();


	
	//Autobus * autobus02 = new Autobus("WWL0000", "MBD");;

	Autobus autobus2(autobus1);
	cout << "AUTOBUS 2" << endl;
	autobus2.wyswietl();
	cout << "--------------------------------------------------" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "TANKOWANIE KOPII 03" << endl;
	autobus2.tankuj(50);
	autobus2.wyswietl();
	cout << "```````````````````````````````````````````````````" << endl;
	cout << "Przypisanie kierowcy do autobusu 03" << endl;
	cout << "--------------------------------------------------" << endl;
	Kierowca *kierowca01 = new Kierowca("miroslaw", "pajak", 34534);
	autobus2.przypisz_kierowce(kierowca01);
	cout << "--------------------------------------------------" << endl;
	cout << "Po zmianach2" << endl;
	autobus2.wyswietl();
	cout << "Po zmianach 1" << endl;
	autobus1.wyswietl();
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

}
void test_dodawania_pasazerow() {
	Autobus a1;
	cout << "Proba przypisania bez kierowcy" << endl;
	a1.dodaj_kierowce("Janek", "Nowak", 12345);
	a1.dodaj_pasazerow(30, 24, 2);
	a1.wyswietl();
	++a1;
	a1.wyswietl();

}

