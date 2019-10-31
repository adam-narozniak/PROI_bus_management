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
	cout << "Stan obecny(ilosc paliwa w baku): " << stan << endl;
	cout << "Pojemnosc: " << pojemnosc << endl;
}

Bak::Bak(double stn, double poj) {
	pojemnosc = poj;
	stan = stn;
}

Bak::~Bak() {
	cout << "Destruktor Bak wlaczony" << endl;

}

void Bak::zmien_stan(double stn) {
	if (stn > 60) {
		stan = stn;
	}
	else {
		stan = stn;
	}
}