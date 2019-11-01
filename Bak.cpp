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
	cout << "--------------------------------------------------" << endl;
}

Bak::Bak(double stn, double poj) {
	stan = stn;
	pojemnosc = poj;
}

Bak::~Bak() {
	cout << "Destruktor Bak wlaczony" << endl;
}

void Bak::zmien_stan(double stn) {
	if (stn < pojemnosc) {
		stan = stn;
	}
	else {
		stan = pojemnosc;
	}
}

double Bak::get_pojemnosc() {
	return pojemnosc;
}
double Bak::get_stan() {
	return stan;
}
