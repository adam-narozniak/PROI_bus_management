#include <iostream>
#include "sam_wyscigowy.h"
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
Sam_wyscigowy::Sam_wyscigowy(string r, string m, double p, double mo, int t, double s, double po, string g) :
	Samochod(r, m, p, mo, t, s, po), gr_krwi(g)
{}
void Sam_wyscigowy::zapisz(string s) {
	ofstream plik(s);
	plik << *this << endl;
	plik.close();
}
void Sam_wyscigowy::wyswietl() {
	this->Samochod::wyswietl();
	cout << "Grupa krwii: " << gr_krwi << endl;
	cout << "--------------------------------------------------" << endl;
}
ostream& operator<<(ostream& str, const Sam_wyscigowy & w) {
	if (&str == &std::cout) {
		str << "SAM_WYSCIGOWY" << endl;
		str << (Samochod)w;
		str << "Grupa krwii: " << w.gr_krwi << endl;
		return str << "--------------------------------------------------" << endl;
	}
	else {
		str << "SAM_WYSCIGOWY" << endl;
		str << (Samochod)w;
		return str << w.gr_krwi << endl;
	}
}