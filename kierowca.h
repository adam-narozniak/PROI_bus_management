#include <iostream>
using namespace std;
#ifndef Kierowca_H
#define Kierowca_H
class Kierowca {

	string imie;
	string nazwisko;
	int id;
public:
	Kierowca(string = "brak", string = "brak", int = -1);
	~Kierowca();
	void wczytaj();
	void wyswietl();
};
#endif