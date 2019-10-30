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
	Autobus autobus01;
	autobus01.wyswietl();
	autobus01.wczytaj();
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


	
}