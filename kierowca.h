#include <iostream>
using namespace std;
#ifndef Kierowca_H
#define Kierowca_H
class Kierowca {
public:
	string imie;
	string nazwisko;
	int id;
	Kierowca(string = "brak", string = "brak", int = -1);
	~Kierowca();
	void wczytaj();
	void wyswietl();
};
#endif