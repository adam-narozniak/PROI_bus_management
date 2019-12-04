#include <iostream>
using namespace std;
#ifndef Bak_H
#define Bak_H
class Bak {
private:
	double stan;//ile litrow jest obecnie w baku
	double pojemnosc;// w litrach
public:
	Bak(double = 40, double = 60);
	~Bak();
	void wczytaj();
	void wyswietl();
	void zmien_stan(double = 40);
	double get_pojemnosc();
	double get_stan();
	friend ostream& operator<<(ostream&, const Bak&);
	friend istream& operator>> (istream& str, Bak &b);


};
#endif