#include <iostream>
#include "samochod.h"
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
Samochod::Samochod(string r, string m, double p, double mo, int t, double s, double po) :
	nr_rej(r), marka(m), silnik(new Silnik(p, mo, t)), bak(new Bak(s, po)) {
}
void Samochod::wyswietl() {
	cout << "SAMOCHOD" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "NR rejestracyjny: " << nr_rej << endl;
	cout << "Marka: " << marka << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Silnik: " << endl;
	silnik->wyswietl();
	cout << "Bak: " << endl;
	bak->wyswietl();
	
}
ostream& operator<< (ostream& str, const Samochod &s) {
	if (&str == &std::cout) {
		str << "SAMOCHOD" << endl;
		str << "--------------------------------------------------" << endl;
		str << "NR rejestracyjny: " << s.nr_rej << endl;
		str << "Marka: " << s.marka << endl;
		str << "--------------------------------------------------" << endl;
		str << "Silnik: " << endl;
		str << *(s.silnik);
		str << "Bak: " << endl;
		return str << *(s.bak);
	}
	else {
		str << "SAMOCHOD" << endl;
		str << s.nr_rej << endl << s.marka << endl << *(s.silnik) << *(s.bak);
	}
}
void Samochod::zapisz(string s) {
	ofstream plik(s);
	plik << *this << endl;
	plik.close();
}

void Samochod::jedz() {
	double delta = silnik->get_pojemnosc()*silnik->get_moc()/100;
	if (delta > bak->get_stan()) {
		cout << "Najpierw zatankuj, za malo paliwa w baku" << endl;
	}
	else {
		bak->zmien_stan(bak->get_stan() - delta);
	}
}