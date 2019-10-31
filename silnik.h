#include <iostream>
using namespace std;
#ifndef Silnik_H
#define Silnik_H
class Silnik {
	double pojemnosc;//w litrach
	double moc;// w KM
	int typ;
public:
	int typ;
	Silnik(double pojemnosc =-1.0, double moc = -1.0, int typ = -1);
	~Silnik();
	void wczytaj();
	void wyswietl();
	double get_pojemnosc();
	double get_moc();
	int get_typ();
};
#endif
