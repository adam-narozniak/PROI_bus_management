#include <iostream>
#include <cstdlib>
#include <string>
#include "kierowca.h"

using namespace std;
void Kierowca::wczytaj() {
	cout << "Podaj imie, nazwisko oraz id kierowcy" << endl;
	cin >> imie;
	cin >> nazwisko;
	cin >> id;
}

void Kierowca::wyswietl() {
	cout << "Imie: " << imie<< endl;
	cout << "Nazwisko: " << nazwisko << endl;
	cout << "Id: " << id << endl;

}

Kierowca::Kierowca(string im, string n, int i) {
	imie = im;
	nazwisko = n;
	id = i;
}

Kierowca::~Kierowca() {
	cout << "Destruktor Kierowca wlaczony" << endl;

}