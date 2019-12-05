#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "kierowca.h"

using namespace std;
void Kierowca::wczytaj() {
	cin >> *this;
}

void Kierowca::wyswietl() {
	cout << "Imie: " << imie<< endl;
	cout << "Nazwisko: " << nazwisko << endl;
	cout << "Id: " <<setw(4)<<setfill('0')<< id << endl;
	cout << "--------------------------------------------------" << endl;
}
ostream& operator<<(ostream& str, const Kierowca& k) {
	if (&k == NULL) {
		return str << "NULL" << endl;
	}
	if (&str == &std::cout) {
		str << "Imie: " << k.imie << endl;
		str << "Nazwisko: " << k.nazwisko << endl;
		str << "Id: " << setw(4) << setfill('0') << k.id << endl;
		return str << "--------------------------------------------------" << endl;
	}
	else {
		str << k.imie << endl;
		str << k.nazwisko << endl;
		return str << k.id << endl;
	}
}
istream& operator>> (istream& str, Kierowca &k) {
	char tab[20];
	int size = sizeof(tab) / sizeof(tab[0]);
	if (&str == &std::cin) {
		cout << "Podaj imie, nazwisko oraz id kierowcy" << endl;
		str >> k.imie;
		str >> k.nazwisko;
		return str >> k.id;
	}
	else {
		str.getline(tab, size);
		if (!strcmp(tab, "NULL")) {
			k.~Kierowca();
			return str;
		}
		k.imie = tab;
		str.getline(tab, size);
		k.nazwisko = tab;
		str.getline(tab, size);
		k.id = stoi(tab);
		return str;
	}
}

Kierowca::Kierowca(string im, string n, int i) {
	imie = im;
	nazwisko = n;
	id = i;
}

Kierowca::Kierowca(Kierowca &kierowca) {
	imie = kierowca.imie;
	nazwisko = kierowca.nazwisko;
	id = kierowca.id;
}

Kierowca::~Kierowca() {
	cout << "Destruktor Kierowca wlaczony" << endl;

}
string Kierowca::get_imie() {
	return imie;
}
string Kierowca:: get_nazwisko(){
	return nazwisko;
}
int Kierowca:: get_id() {
	return id;
}