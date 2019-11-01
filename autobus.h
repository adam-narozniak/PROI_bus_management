#include <iostream>
#include "kierowca.h"
#include "miejsca.h"
#include "Bak.h"
#include "silnik.h"
#include "pasazerowie.h"

#ifndef Autobus_H
#define Autobus_H
using namespace std;

class Autobus {
	string nr_rej;
	string marka;
	Silnik * silnik;
	Bak *bak;
	Kierowca *kierowca;
	Miejsca *miejsca;
	Pasazerowie *pasazerowie;

public:
	//dla Autobusu
	Autobus(string = "BRAK", string = "BMW", double = 2.2, double = 190, int = 1, double = 40, double = 60, int = 30, int = 80, int = 2);// , int = 30, int = 24, int = 2);
	~Autobus();
	Autobus(const Autobus &);
	void wczytaj();
	void wyswietl();
	Autobus & operator =(const Autobus &);
	//gety
	string get_nr_rej();
	string get_marka();
	Silnik *get_silnik();
	Bak *get_bak();
	Kierowca *get_kierowca();
	Miejsca *get_miejsca();
	Pasazerowie *get_pasazerowie();
	//dla kierowcy
	Kierowca* stworz_kierowce(string = "brak", string = "brak", int = -1);
	void przypisz_kierowce(Kierowca * = NULL);
	Kierowca * zamien_kierowce(Kierowca * = NULL);
	//dla baku
	void tankuj(double = 60.0);
	//dla silnika
	bool operator > (const Autobus &) const;
	bool operator < (const Autobus &) const;
	Autobus operator !();
	

};
#endif
