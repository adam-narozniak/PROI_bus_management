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
	cout << "--------------------------------------------------" << endl;
	cout << "Silnik to: " << endl;
	silnik->wyswietl();
	cout << "--------------------------------------------------" << endl;
	cout<< "Bak to: " << endl;
	bak->wyswietl();
	cout << "--------------------------------------------------" << endl;

}

Autobus::Autobus(string r, string m, int l, double p, double mo, int t){
	nr_rej = r;
	marka = m;
	liczba_miejsc = l;
	silnik = new Silnik(p, mo, t);
	bak = new Bak();
}

Autobus::~Autobus() {
	cout << "Destruktor wlaczony" << endl;

}

Autobus::Autobus(const Autobus &autobus) {
	nr_rej = autobus.nr_rej;
	marka = autobus.marka;
	liczba_miejsc = autobus.liczba_miejsc;
}

Kierowca * Autobus::stworz_kierowce(string im, string n, int i) {
	Kierowca * k = new Kierowca(im, n, i);
	return k;
}

bool Autobus::przypisz_kierowce(Kierowca *k) {
	if (k != NULL) {
		kierowca = k;
		cout << "Kierowca poprawnie przypisany" << endl;
		return 1;
	}
	else {
		cout << "Autobus nie ma obecnie kierowcy" << endl;
		return 0;
	}

}
Kierowca * Autobus::zamien_kierowce(Kierowca *k) {
	Kierowca * temp = kierowca;
	kierowca = k;
	return temp;
}

void Autobus::tankuj(double ile) {
	bak->zmien_stan(ile);
}