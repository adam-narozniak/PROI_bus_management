#include <iostream>
using namespace std;
#ifndef Bak_H
#define Bak_H
class Bak {
public:
	double pojemnosc;// w litrach
	double stan;//ile litrow jest obecnie w baku
	Bak(double = 60, double = 60);
	~Bak();
	void wczytaj();
	void wyswietl();
};
#endif