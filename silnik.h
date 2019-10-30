#include <iostream>
using namespace std;
#ifndef Silnik_H
#define Silnik_H
class Silnik {
public:
	double pojemnosc;//w litrach
	double moc;// w KM
	int typ;
	Silnik(double =-1.0, double = -1.0, int = -1);
	~Silnik();
	void wczytaj();
	void wyswietl();
};
#endif
