#include <iostream>
#include "kierowca.h"
#include "miejsca.h"
#include "Bak.h"
#include "silnik.h"

#ifndef Autobus_H
#define Autobus_H
using namespace std;

class Autobus {
	string nr_rej;
	string marka;
	int liczba_miejsc;
	Silnik * silnik;
	Bak *bak;
	Kierowca *kierowca;


	/*Bak * bak;
	Miejsca * miejsca;
	Kierowca * kierowca;
	*/
public:
	Autobus(string = "BRAK", string = "BMW", int = 12, double = -1.0, double = -1.0, int = -1);
	~Autobus();
	Autobus(const Autobus &);
	void wczytaj();
	void wyswietl();
	Kierowca* stworz_kierowce(string = "brak", string = "brak", int = -1);
	bool przypisz_kierowce(Kierowca * = NULL);
	Kierowca * zamien_kierowce(Kierowca * = NULL);
	void tankuj(double = 60.0);

};
#endif
