#include <iostream>
#include "samochod.h"
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
Samochod::Samochod(string r, string m, double p, double mo, int t, double s, double po) :
	nr_rej(r), marka(m), silnik(new Silnik(p, mo, t)), bak(new Bak(s, po)) {
}
Samochod::Samochod(const Samochod& s) {
	nr_rej = s.nr_rej;
	marka = s.marka;
	silnik = new Silnik(*(s.silnik));
	bak = new Bak(*(s.bak));
}
Samochod & Samochod::operator=(const Samochod &s) {
	if (this == &s) return *this;
	nr_rej = s.nr_rej;
	marka = s.marka;
	delete silnik;
	silnik = new Silnik(*(s.silnik));
	delete bak;
	bak = new Bak(*(s.bak));
	return *this;
}
void Samochod::wyswietl() {
	cout << *this;
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
		cout << "Podaj nr rejestracyjny oraz marke" << endl;
		cin.getline(tab, size);
		s.nr_rej = tab;
		str >> s.marka;
		str >> *(s.silnik);
		return str >> *(s.bak);
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

void Samochod::przerejestruj(const string rej) {
	this->nr_rej = rej;
}

void Samochod::tankuj(double ile) {
	if (ile < bak->get_stan()) {
		cout << "Takowanie tylko do wiekszego stanu niz obeczny" << endl;
	}
	bak->zmien_stan(ile);
}
Samochod::~Samochod() {
	delete silnik;
	delete bak;
	cout << "Destruktor SAMOCHOD wlaczony" << endl;
}

string Samochod::get_nr_rej() {
	return nr_rej;
}

Silnik * Samochod::get_silnik() {
	return silnik;
}