#include <iostream>
using namespace std;
#ifndef Kierowca_H
#define Kierowca_H
class Kierowca {
	string imie;
	string nazwisko;
	int id;
public:
	Kierowca(string = "Jan", string = "Nowak", int = 1);
	~Kierowca();
	Kierowca(Kierowca &);
	void wczytaj();
	void wyswietl();
	string get_imie();
	string get_nazwisko();
	int get_id();
	friend ostream& operator<<(ostream&, const Kierowca&);
	friend istream& operator>>(istream&, Kierowca&);
};
#endif