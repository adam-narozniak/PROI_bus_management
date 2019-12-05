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
	void przerejestruj(string = "WK 7654");
	friend ostream& operator<<(ostream&, const Samochod &);
	friend istream& operator>>(istream&, Samochod &);
	void jedz();
	void tankuj(double = 60.0);
	void zapisz(string ="outputs.txt");
	void odczytaj(string = "outputs.txt");
};
#endif