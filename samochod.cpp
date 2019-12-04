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
		return str << s.nr_rej << endl << s.marka << endl << *(s.silnik) << *(s.bak);
	}
}
void Samochod::zapisz(string s) {
	ofstream plik(s);
	plik << *this << endl;
	plik.close();
}
void Samochod::odczytaj(string s) {
	ifstream plik(s);
	if (!plik.is_open()) {
		cout << "Bledna nazwa pliku" << endl;
		return;
	}
	plik >> *this;
	plik.close();
}

istream& operator>> (istream& str,  Samochod &s) {
	char tab[20];
	int size = sizeof(tab) / sizeof(tab[0]);
	if (&str == &std::cin) {
		1;
		cout << "Dziala" << endl;
	}
	else {
		str.getline(tab, size);
		if (strcmp(tab, "SAMOCHOD")) {
			cout << "Plik nie zawiera danych ktore chcesz wczytac" << endl;
			return str;
		}
		else {
			str.getline(tab, size);
			s.nr_rej = tab;
			str.getline(tab, size);
			s.marka = tab;
			str >> *(s.silnik);
			return str >> *(s.bak);
		}


	}
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