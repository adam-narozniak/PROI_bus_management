#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "bak.h"

using namespace std;
void Bak::wczytaj() {
	
}

void Bak::wyswietl() {
	cout << "Stan obecny(ilosc paliwa w baku): "<<setprecision(2)<<fixed << stan << endl;
	cout << "Pojemnosc: " << setprecision(2)<<fixed<< pojemnosc << endl;
	cout << "--------------------------------------------------" << endl;
}

Bak::Bak(double stn, double poj) {
	if (stn <= poj) {//zabezpieczenie przed podaniem stanu wiekszego od pojemnosi - nastepuje tankowanie do pelna
		stan = stn;
	}
	else {
		stan = poj;
	}
	pojemnosc = poj;
}
Bak::Bak(const Bak &bak) {
	stan = bak.stan;
	pojemnosc = bak.pojemnosc;
}

Bak::~Bak() {
	cout << "Destruktor Bak wlaczony" << endl;
}

void Bak::zmien_stan(double stn) {
	try {
		if (stn < 0) throw "ujemne tankowanie";
	}
	catch(const char *){
		cout << "Tankujesz ujemnie, poziom paliwa zostanie niezmieniony" ;
		return;
	}
	try {
		if (stn < stan) throw "Tankowanie do stanu mniejszego niz obecy jest niemozliwe";
	}
	catch (const char*) {
		return;
	}
	try {
		if (stn > pojemnosc) throw "tankowanie poza dozowlony poziom";
	}
	catch(const char*){
		stan = pojemnosc;
		return;
	}
	stan = stn;
}

double Bak::get_pojemnosc() {
	return pojemnosc;
}
double Bak::get_stan() {
	return stan;
}

ostream& operator<<(ostream& str, const Bak& b) {
	if (&str == &std::cout) {
		str << "Stan obecny(ilosc paliwa w baku): " << setprecision(2) << fixed << b.stan << endl;
		str << "Pojemnosc: " << setprecision(2) << fixed << b.pojemnosc << endl;
		return str << "--------------------------------------------------" << endl;
	}
	else {
		str << b.stan << endl;
		return str << b.pojemnosc << endl;
	}
}
istream& operator>> (istream& str, Bak &b ){
	char tab[20];
	int size = sizeof(tab) / sizeof(tab[0]);
	if (&str == &std::cin) {
		cout << "Podaj pojemnosc oraz poziom zatankowania baku" << endl;
		str >> b.pojemnosc;
		double temp;
		str >> temp;
		
		if (temp <= b.pojemnosc) {//zabezpieczenie przed podaniem stanu wiekszego od pojemnosi - nastepuje tankowanie do pelna
			temp;
		}
		else {
			temp = b.pojemnosc;
		}
		b.stan = temp;
		return str;
	}
	else {
		str.getline(tab, size);
		b.stan = stod(tab);
		str.getline(tab, size);
		b.pojemnosc = stod(tab);
		return str;
	}
}

