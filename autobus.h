#include <iostream>
#include "kierowca.h"

#ifndef Autobus_H
#define Autobus_H
using namespace std;

class Autobus {
public:
	string nr_rej;
	string marka;
	int liczba_miejsc;
	Autobus(string = "BRAK", string = "BMW", int = 12);
	~Autobus();
	Autobus(const Autobus &);
	void wczytaj();
	void wyswietl();
};
#endif
