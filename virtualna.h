#include <iostream>

#ifndef Virtualna_H
#define Virtualna_H
using namespace std;

class Pojazd {
protected:
	
public:
	//virtual friend ostream& operator<<(ostream&, const Pojazd&) = 0;

	virtual void wyswietl() = 0;
	virtual void jedz() = 0;
	//virtual void zapisz() = 0;
	//virtual void odczytaj() = 0;
	/*virtual void tankuj(double = 60.0) = 0;
	
	virtual void przerejestruj(const string = "new") = 0;*/
};

//ostream& operator<<(ostream&, const Pojazd&) = 0;


#endif