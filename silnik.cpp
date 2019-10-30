#include <iostream>
#include <cstdlib>
#include <string>
#include "silnik.h"

using namespace std;
void Silnik::wczytaj() {
	cout << "Podaj pojemnosc, moc, typ" << endl;
	cin >> pojemnosc;
	cin >> moc;
	cin >> typ;
}

void Silnik::wyswietl() {
	cout << "Pojemnosc: " << pojemnosc << "L"<< endl;
	cout << "Moc: " << moc<<"KM"<< endl;
	cout << "Typ: " << typ << endl;

}

Silnik::Silnik(double p, double m, int t) {
	pojemnosc = p;
	moc = m;
	typ = t;
}

Silnik::~Silnik() {
	cout << "Destruktor Silnik wlaczony" << endl;

}