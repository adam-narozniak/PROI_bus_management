#include <iostream>
#include "kierowca.h"
#include "miejsca.h"
#include "Bak.h"
#include "silnik.h"
#include "pasazerowie.h"
#include "virtualna.h"
#ifndef Samochod_H
#define Samochod_H
class Samochod : public Pojazd {
protected:
	string nr_rej;
	string marka;
	Silnik * silnik;
	Bak *bak;
public:
	Samochod(string = "BRAK", string = "Audi", double = 1.6, double = 120, int = 1, double = 40, double = 60);
	void wyswietl();
	friend ostream& operator<<(ostream&, const Samochod &);
	void jedz();
	void zapisz(string ="output.txt");
};
#endif