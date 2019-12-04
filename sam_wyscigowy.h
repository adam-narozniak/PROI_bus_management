#include <iostream>
#include "Bak.h"
#include "silnik.h"
#include "virtualna.h"
#include "samochod.h"
#ifndef Sam_wyscigowy_H
#define Sam_wyscigowy_H
class Sam_wyscigowy : public Samochod {
private:
	string gr_krwi;
public:
	Sam_wyscigowy(string = "BRAK", string = "Mustang", double = 2.5, double = 321, int = 2, double = 57, double = 60, string = "0 Rh-");
	void wyswietl();
	void zapisz(string = "outputw.txt");
	void odczytaj(string = "outputw.txt");
	friend ostream& operator<<(ostream&, const Sam_wyscigowy &);
	friend istream& operator>> (istream& str, Sam_wyscigowy &w);
};
#endif