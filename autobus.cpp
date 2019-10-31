#include <iostream>
#include "autobus.h"
#include <cstdlib>
#include <string>

using namespace std;
void Autobus::wczytaj() {
	cout << "Podaj nr rejestracyjny, marke oraz liczbe miejsc" << endl;
	cin >> nr_rej;
	cin >> marka;
}

void Autobus::wyswietl() {
	cout << "**************************************************" << endl;
	cout << "**************************************************" << endl;
	cout << "AUTOBUS" << endl;
	cout << "NR rejestracyjny: " <<nr_rej<< endl;
	cout << "Marka: " << marka<< endl;
	cout << "--------------------------------------------------" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Silnik: " << endl;
	silnik->wyswietl();
	cout << "Bak: " << endl;
	bak->wyswietl();
	cout << "--------------------------------------------------" << endl;
	cout << "Kierowca: " << endl;
	if (kierowca != NULL) {
		kierowca->wyswietl();

	}
	else {
		cout << "Kierowca nie jest przypisany do autobusu" << endl;
	}

	cout << "--------------------------------------------------" << endl;
	//cout << "Liczba miejsc: " << liczba_miejsc << endl;
	/*
	
	
	cout << "Pasazerowie: " << endl;
	pasazerowie->wyswietl();
	cout << "--------------------------------------------------" << endl;
	cout << "Miejsca: " << endl;
	miejsca->wyswietl();*/
	cout << "**************************************************" << endl;
	cout << "**************************************************" << endl;

}

Autobus::Autobus(string r, string m, double p, double mo, int t, double s, double po){//, int m1, int m2, int m3, int p1, int p2, int p3){
	nr_rej = r;
	marka = m;
	silnik = new Silnik(p, mo, t);
	bak = new Bak;// (s, po);
	kierowca = 0;
	/*miejsca = new Miejsca;// (m1, m2, m3);
	pasazerowie = new Pasazerowie;// (p1, p2, p3);
	*/
}

Autobus::~Autobus() {
	delete silnik;
	delete bak;
	if (kierowca != NULL) {
		delete kierowca;
	}
	/*delete pasazerowie;
	delete miejsca;
*/
	cout << "Destruktor AUTOBUS wlaczony" << endl;

}

Autobus::Autobus(const Autobus &autobus) {
	nr_rej = autobus.nr_rej;
	marka = autobus.marka;
	silnik = new Silnik(autobus.silnik->get_pojemnosc(), autobus.silnik->get_moc(), autobus.silnik->get_typ());
	bak = new Bak(autobus.bak->get_stan(), autobus.bak->get_pojemnosc());
	if (kierowca == NULL) {
		kierowca = 0;
	}
	else {
		kierowca = new Kierowca(autobus.kierowca->get_imie(), autobus.kierowca->get_nazwisko(), autobus.kierowca->get_id());
	}
	/*miejsca = new Miejsca(autobus.miejsca->get_miejsca_normalne(), autobus.miejsca->get_miejsca_stojace(), autobus.miejsca->get_miejsca_rowery());
	
	pasazerowie = new Pasazerowie(autobus.pasazerowie->get_n_pasazerow(), autobus.pasazerowie->get_n_z_biletami(), autobus.pasazerowie->get_n_rowerow());
	*/
	
}

Kierowca * Autobus::stworz_kierowce(string im, string n, int i) {
	Kierowca * k = new Kierowca(im, n, i);
	kierowca = k;
	return k;
}

void Autobus::przypisz_kierowce(Kierowca *k) {
	if (k != NULL) {
		kierowca = k;
		cout << "Kierowca poprawnie przypisany" << endl;
		kierowca->wyswietl();
	}
	else {
		cout << "Autobus nie ma obecnie kierowcy" << endl;
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