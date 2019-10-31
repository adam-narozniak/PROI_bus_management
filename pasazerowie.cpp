#include <iostream>
#include <cstdlib>
#include <string>
#include "pasazerowie.h"

using namespace std;
void Pasazerowie::wczytaj() {
	cout << "Podaj liczbe miejsc normalnych, Pasazerowie_niepelnosprawni, Pasazerowie_stoj¹ce" << endl;
	cin >> n_pasazerow;
	cin >> n_z_biletami;
	cin >> n_rowerow;
	//cin >> Pasazerowie_niepelnosprawni;

}

void Pasazerowie::wyswietl() {
	cout << "Pasazerowie: " <<n_pasazerow << endl;
	cout << "Pasazerowie z biletami: " << n_z_biletami<< endl;
	cout << "Rowery: " << n_rowerow << endl;
	//cout << "Pasazerowie_niepelnosprawni: " << Pasazerowie_niepelnosprawni << endl;

}

Pasazerowie::Pasazerowie(int n, int b, int r) {
	n_pasazerow = n;
	n_z_biletami= b;
	n_rowerow= r;
	//Pasazerowie_niepelnosprawni = np;

}

Pasazerowie::~Pasazerowie() {
	cout << "Destruktor Pasazerowie wlaczony" << endl;

}

int Pasazerowie::get_n_pasazerow() {
	return n_pasazerow;
}
int Pasazerowie::get_n_z_biletami() {
	return n_z_biletami;
}
int Pasazerowie::get_n_rowerow() {
	return n_rowerow;
}