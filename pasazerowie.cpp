#include <iostream>
#include <cstdlib>
#include <string>
#include "pasazerowie.h"

using namespace std;
void Pasazerowie::wczytaj() {
	cin >> *this;
}

void Pasazerowie::wyswietl() {
	cout << "Pasazerowie: " <<n_pasazerow << endl;
	cout << "Pasazerowie z biletami: " << n_z_biletami<< endl;
	cout << "Rowery: " << n_rowerow << endl;
	cout << "--------------------------------------------------" << endl;

}
ostream& operator<<(ostream& str, const Pasazerowie& p) {
	if (&p == NULL) {
		return str << "NULL" << endl;
}
	if (&str == &std::cout) {
		str << "Pasazerowie: " << p.n_pasazerow << endl;
		str << "Pasazerowie z biletami: " << p.n_z_biletami << endl;
		str << "Rowery: " << p.n_rowerow << endl;
		return str << "--------------------------------------------------" << endl;
	}
	else {
		str << p.n_pasazerow << endl;
		str << p.n_z_biletami << endl;
		return str << p.n_rowerow << endl;
	}
}
istream& operator>> (istream& str, Pasazerowie &p) {
	char tab[20];
	int size = sizeof(tab) / sizeof(tab[0]);
	if (&str == &std::cin) {
		cout << "Podaj liczbe pasazerow, pasazerow z biletami oraz liczbe rowerow" << endl;
		str >> p.n_pasazerow;
		str >> p.n_z_biletami;
		return str >> p.n_rowerow;
	}
	else {
		str.getline(tab, size);
		if (!strcmp(tab, "NULL")) {
			p.~Pasazerowie();
			return str;
		}
		p.n_pasazerow= stoi(tab);
		str.getline(tab, size);
		p.n_z_biletami = atoi(tab);
		str.getline(tab, size);
		p.n_rowerow = stoi(tab);
		return str;
	}
}

Pasazerowie::Pasazerowie(int n, int b, int r) {
	n_pasazerow = n;
	if (b > n) {
		n_z_biletami = n;
	}
	else {
		n_z_biletami = b;
	}
	n_rowerow= r;
}
void Pasazerowie::edytuj(int n, int b, int r) {
	n_pasazerow = n;
	if (b > n) {
		n_z_biletami = n;
	}
	else {
		n_z_biletami = b;
	}
	n_rowerow = r;
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