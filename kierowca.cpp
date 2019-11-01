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
	cout << "--------------------------------------------------" << endl;
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