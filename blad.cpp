#include "blad.h"


class Ujemna : public Blad {
	double x;
public:
	Ujemna(double x) : x(x) { }
	string opis() {
		ostringstream strum;
		strum << "Ujemny poziom: x = " << x;
		return strum.str();
	}
};

class PozaZakresem : public Blad {
	double x, max;
public:
	PozaZakresem(double x, double ma)
		: x(x), max(ma)
	{ }
	string opis() {
		ostringstream strum;
		strum << "Argument x = " << x << "\n    "
			<< "    poza zakresem [" << ","
			<< max << "]";
		return strum.str();

	}

};