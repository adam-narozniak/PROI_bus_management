#include <iostream>
using namespace std;
#ifndef Bak_H
#define Bak_H
class Bak {

	double pojemnosc;// w litrach
	double stan;//ile litrow jest obecnie w baku
public:
	Bak(double = 40, double = 60);
	~Bak();
	void wczytaj();
	void wyswietl();
	void zmien_stan(double = 60);
	double get_pojemnosc();
	double get_stan();
};
#endif