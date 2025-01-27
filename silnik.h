#include <iostream>
#include <string>
#include <vector> 
using namespace std;
#ifndef Silnik_H
#define Silnik_H
class Silnik {
	double pojemnosc;	//w litrach
	double moc;			// w KM
	int typ;
public:
	static const char * typy_silnika[];
	Silnik(double pojemnosc = 2.2, double moc = 190, int typ = 1);
	Silnik(Silnik &);
	~Silnik();
	void wczytaj();
	void wyswietl();
	double get_pojemnosc();
	double get_moc();
	int get_typ();
	friend ostream& operator<<(ostream&, const Silnik&);
	friend istream& operator>> (istream& str, Silnik &b);
};
#endif
