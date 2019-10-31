#include <iostream>
#include <cstdlib>
#include <string>
#include "miejsca.h"

using namespace std;
void Miejsca::wczytaj() {
	cout << "Podaj liczbe miejsc normalnych, miejsca_niepelnosprawni, miejsca_stoj¹ce" << endl;
	cin >> miejsca_normalne;
	cin >> miejsca_stojace;
	cin >> miejsca_rowery;
	//cin >> miejsca_niepelnosprawni;
	
}

void Miejsca::wyswietl() {
	cout << "miejsca_normalne: " << miejsca_normalne << endl;
	cout << "miejsca_stojace: " << miejsca_stojace << endl;
	cout << "miejsca_rowery: " << miejsca_rowery << endl;
	//cout << "miejsca_niepelnosprawni: " << miejsca_niepelnosprawni << endl;

}

Miejsca::Miejsca(int n, int s, int r){
	//, int np) {
	miejsca_normalne = n;
	miejsca_stojace = s;
	miejsca_rowery = r;
	//miejsca_niepelnosprawni = np;

}

Miejsca::~Miejsca() {
	cout << "Destruktor Miejsca wlaczony" << endl;

}
int Miejsca::get_miejsca_normalne() {
	return miejsca_normalne;
}
int Miejsca::get_miejsca_stojace() {
	return miejsca_stojace;
}
int Miejsca::get_miejsca_rowery(){
	return miejsca_rowery;
}