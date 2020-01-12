#include <iostream>

#ifndef Virtualna_H
#define Virtualna_H
using namespace std;

class Pojazd {
public:
	virtual void wyswietl() = 0;
	virtual void jedz() = 0;
	virtual void zapisz(string) = 0;
	virtual void odczytaj(string) = 0;
	virtual void tankuj(double = 60.0) = 0;
	virtual void przerejestruj(const string = "new") = 0;
};
#endif