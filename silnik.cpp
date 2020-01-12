#include <iostream>
#include <cstdlib>
#include <string>
#include "silnik.h"

using namespace std;
const char * Silnik::typy_silnika[] = { "nie podano", "diesel", "benzyna", "inny" };
void Silnik::wczytaj() {
	cout << "Podaj pojemnosc, moc, typ (1 - diesel, 2 - benzyna, 3 - inny" << endl;
	cin >> pojemnosc;
	cin >> moc;
	cin >> typ;
}

void Silnik::wyswietl() {
	cout << "Pojemnosc: " << pojemnosc << "L" << endl;
	cout << "Moc: " << moc << "KM" << endl;
	cout << "Typ: " << typy_silnika[typ] << endl;
	cout << "--------------------------------------------------" << endl;
}

Silnik::Silnik(Silnik &silnik) {
	pojemnosc = silnik.pojemnosc;
	moc = silnik.moc;
	typ = silnik.typ;
}

Silnik::Silnik(double p, double m, int t) {
	pojemnosc = p;
	moc = m;
	if (t < 1 || t>3) {
		t = 0;
	}
	typ = t;
}

Silnik::~Silnik() {
	cout << "Destruktor Silnik wlaczony" << endl;
}

double Silnik::get_pojemnosc() {
	return pojemnosc;
}
double Silnik::get_moc() {
	return moc;
}
int Silnik::get_typ() {
	return typ;
}
ostream& operator<<(ostream& str, const Silnik& s) {
	if (&str == &std::cout) {
		str << "Pojemnosc: " << s.pojemnosc << "L" << endl;
		str << "Moc: " << s.moc << "KM" << endl;
		str << "Typ: " << s.typy_silnika[s.typ] << endl;
		return str << "--------------------------------------------------" << endl;
	}
	else {
		return str << s.pojemnosc << endl << s.moc << endl << s.typ << endl;
	}
}
istream& operator>> (istream& str, Silnik &s) {
	char tab[20];
	int size = sizeof(tab) / sizeof(tab[0]);
	if (&str == &std::cin) {
		cout << "Podaj pojemnosc, moc, typ (1 - diesel, 2 - benzyna, 3 - inny)" << endl;
		str >> s.pojemnosc;
		str >> s.moc;
		return str >> s.typ;
	}
	else {
		str.getline(tab, size);
		s.pojemnosc = stod(tab);
		str.getline(tab, size);
		s.moc = stod(tab);
		str.getline(tab, size);
		s.typ = stoi(tab);
		return str;
	}
}