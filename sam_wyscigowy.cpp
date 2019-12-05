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
void Sam_wyscigowy::odczytaj(string s) {
	ifstream plik(s);
	if (!plik.is_open()) {
		cout << "Bledna nazwa pliku" << endl;
		return;
	}
	plik >> *this;
	plik.close();
}
void Sam_wyscigowy::wyswietl() {
	/*cout << "SAM_WYSCIGOWY" << endl;
	this->Samochod::wyswietl();
	cout << "Grupa krwii: " << gr_krwi << endl;
	cout << "--------------------------------------------------" << endl;*/
	cout << (*this);
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
istream& operator>> (istream& str, Sam_wyscigowy &w) {
	char tab[20];
	int size = sizeof(tab) / sizeof(tab[0]);
	if (&str == &std::cin) {
		1;
	}
	else {
		str.getline(tab, size);
		if (strcmp(tab, "SAM_WYSCIGOWY")) {
			cout << "Plik nie zawiera danych ktore chcesz wczytac" << endl;
			return str;
		}
		else {
			str >> static_cast<Samochod &>(w);
			str.getline(tab, size);
			w.gr_krwi = tab;
		}


	}
}