#include <iostream>
#include "autobus.h"
#include <string>
#include "kierowca.h"
#include "bak.h"
#include "silnik.h"
#include "miejsca.h"
using namespace std;

void test();
int main(void) {
	test();


}

void test() {
	cout << "Funkcja testujaca" << endl;
	cout << "Tworze podstawowa klase Autobus" << endl;
	Autobus autobus01("WWL0000", "MBD", 13);
	autobus01.wyswietl();
	cout << "--------------------------------------------------" << endl;
	Kierowca kierowca01;
	kierowca01.wyswietl();
	cout << "--------------------------------------------------" << endl;

	Bak bak01;
	bak01.wyswietl();
	cout << "--------------------------------------------------" << endl;

	Silnik silnik01;
	silnik01.wyswietl();
	cout << "--------------------------------------------------" << endl;

	Miejsca miejsca01;
	miejsca01.wyswietl();
	cout << "--------------------------------------------------" << endl;
	cout << "Test kostruktora kopiujacego" << endl;
	Autobus autobus02(autobus01);
	autobus02.wyswietl();
	cout << "Modyfikacja drugiego (nowo powstalego obiektu)" << endl;
	autobus02.wczytaj();
	cout << "Porownanie dwoch obiektow (w celu sprawdzenia ze dzialam na nowo powstalym obiekcie, a nie na starym do ktorego mam wskaznik" << endl;
	cout << "-------------------01-------------------------------" << endl;
	autobus01.wyswietl();
	cout << "-------------------02-------------------------------" << endl;
	autobus02.wyswietl();


	

	
}