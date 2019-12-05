#include <iostream>
#include <cstdlib>
#include <string>
#include "miejsca.h"

using namespace std;
void Miejsca::wczytaj() {
	cin >> *this;
}

void Miejsca::wyswietl() {
	cout << "Miejsca_normalne: " << miejsca_normalne << endl;
	cout << "Miejsca_stojace: " << miejsca_stojace << endl;
	cout << "Miejsca_rowery: " << miejsca_rowery << endl;
	cout << "--------------------------------------------------" << endl;
}
ostream& operator<<(ostream& str, const Miejsca& m) {
	if (&m == NULL) {
		str << NULL << endl;
	}
	if (&str == &std::cout) {
		str << "Miejsca_normalne: " << m.miejsca_normalne << endl;
		str << "Miejsca_stojace: " << m.miejsca_stojace << endl;
		str << "Miejsca_rowery: " << m.miejsca_rowery << endl;
		return str << "--------------------------------------------------" << endl;
	}
	else {
		str << m.miejsca_normalne << endl;
		str << m.miejsca_stojace << endl;
		return str << m.miejsca_rowery << endl;
	}
}
istream& operator>> (istream& str, Miejsca &m) {
	char tab[20];
	int size = sizeof(tab) / sizeof(tab[0]);
	if (&str == &std::cin) {
		cout << "Podaj liczbe miejsc normalnych, miejsca_niepelnosprawni, miejsca_stojace" << endl;
		str >> m.miejsca_normalne;
		str >> m.miejsca_stojace;
		return str >> m.miejsca_rowery;
	}
	else {
		str.getline(tab, size);
		if (!strcmp(tab, "NULL")) {
			return str;
		}
		m.miejsca_normalne = stoi(tab);
		str.getline(tab, size);
		m.miejsca_stojace = atoi(tab);
		str.getline(tab, size);
		m.miejsca_rowery = stoi(tab);
		return str;
	}
}

Miejsca::Miejsca(int n, int s, int r){
	miejsca_normalne = n;
	miejsca_stojace = s;
	miejsca_rowery = r;
}

Miejsca::~Miejsca() {
	cout << "Destruktor Miejsca wlaczony" << endl;

}
int Miejsca::get_miejsca_normalne() {
	return miejsca_normalne;
}
int Miejsca::get_miejsca_stojace() {
	return miejsca_stojace;
}
int Miejsca::get_miejsca_rowery(){
	return miejsca_rowery;
}