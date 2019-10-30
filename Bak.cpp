#include <iostream>
#include <cstdlib>
#include <string>
#include "bak.h"

using namespace std;
void Bak::wczytaj() {
	cout << "Podaj pojemnosc oraz poziom zatankowania baku" << endl;
	cin >> pojemnosc;
	cin >> stan;
}

void Bak::wyswietl() {
	cout << "Pojemnosc: " << pojemnosc << endl;
	cout << "Stan obecny(ilosc paliwa w baku): " << stan<< endl;
}

Bak::Bak(double poj, double stn) {
	pojemnosc = poj;
	stan = stn;
}

Bak::~Bak() {
	cout << "Destruktor Bak wlaczony" << endl;

}