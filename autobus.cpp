#include <iostream>
#include "autobus.h"
#include <cstdlib>
#include <string>

using namespace std;
void Autobus::wczytaj() {
	cout << "Podaj nr rejestracyjny, marke oraz liczbe miejsc" << endl;
	cin >> nr_rej;
	cin >> marka;
	cin >> liczba_miejsc;
}

void Autobus::wyswietl() {
	cout << "NR rejestracyjny: " <<nr_rej<< endl;
	cout << "Marka: " << marka<< endl;
	cout << "Liczba miejsc: " << liczba_miejsc << endl;

}

Autobus::Autobus(string r, string m, int l) {
	nr_rej = r;
	marka = m;
	liczba_miejsc = l;
}

Autobus::~Autobus() {
	cout << "Destruktor wlaczony" << endl;

}