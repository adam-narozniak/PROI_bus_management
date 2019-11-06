#include <iostream>
#include <iomanip>
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
	cout << "Stan obecny(ilosc paliwa w baku): "<<setprecision(2)<<fixed << stan << endl;
	cout << "Pojemnosc: " << setprecision(2)<<fixed<< pojemnosc << endl;
	cout << "--------------------------------------------------" << endl;
}

Bak::Bak(double stn, double poj) {
	if (stn <= poj) {
		stan = stn;
	}
	else {
		stan = poj;
	}
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
