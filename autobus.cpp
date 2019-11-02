#include <iostream>
#include "autobus.h"
#include <cstdlib>
#include <string>

using namespace std;
void Autobus::wczytaj() {
	cout << "Podaj nr rejestracyjny oraz marke" << endl;
	cin >> nr_rej;
	cin >> marka;
}

void Autobus::wyswietl() {
	cout << endl;
	cout << "AUTOBUS" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "NR rejestracyjny: " << nr_rej << endl;
	cout << "Marka: " << marka << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Silnik: " << endl;
	silnik->wyswietl();

	cout << "Bak: " << endl;
	bak->wyswietl();

	cout << "Kierowca: " << endl;
	if (kierowca == NULL) {
		cout << "Kierowca nie jest przypisany do autobusu" << endl;
		cout << "--------------------------------------------------" << endl;
	}
	else {
		kierowca->wyswietl();
	}
	cout << "Miejsca: " << endl;
	miejsca->wyswietl();

	cout << "Pasazerowie: " << endl;
	if (pasazerowie == NULL) {
		cout << "Brak przypisanych pasazerow" << endl;
		cout << "--------------------------------------------------" << endl;
	}
	else {
		pasazerowie->wyswietl();
	}
	cout << endl;
}

Autobus::Autobus(string r, string m, double p, double mo, int t, double s, double po, int m1, int m2, int m3, Kierowca * k, Pasazerowie * pa){// , int p1, int p2, int p3){
	nr_rej = r;
	marka = m;
	silnik = new Silnik(p, mo, t);
	bak = new Bak(s, po);
	kierowca = k;
	miejsca = new Miejsca(m1, m2, m3);
	pasazerowie = pa;//new Pasazerowie;// (p1, p2, p3);
	
}

Autobus::~Autobus() {
	delete silnik;
	delete bak;
	if (kierowca != NULL) {
		delete kierowca;
	}
	delete miejsca;
	if(pasazerowie != NULL) {
		delete pasazerowie;
	}
	cout << "Destruktor AUTOBUS wlaczony" << endl;
}

Autobus::Autobus(const Autobus &autobus) {
	nr_rej = autobus.nr_rej;
	marka = autobus.marka;
	silnik = new Silnik(autobus.silnik->get_pojemnosc(), autobus.silnik->get_moc(), autobus.silnik->get_typ());
	bak = new Bak(autobus.bak->get_stan(), autobus.bak->get_pojemnosc());
	//kierowca = NULL;
	if (autobus.kierowca == NULL) {
		kierowca = NULL;
	}
	else {
		kierowca = new Kierowca(autobus.kierowca->get_imie(), autobus.kierowca->get_nazwisko(), autobus.kierowca->get_id());
	}
	miejsca = new Miejsca(autobus.miejsca->get_miejsca_normalne(), autobus.miejsca->get_miejsca_stojace(), autobus.miejsca->get_miejsca_rowery());
	//pasazerowie = new Pasazerowie(autobus.pasazerowie->get_n_pasazerow(), autobus.pasazerowie->get_n_z_biletami(), autobus.pasazerowie->get_n_rowerow());
	if (autobus.pasazerowie == NULL) {
		pasazerowie = NULL;
	}
	else {
		pasazerowie = new Pasazerowie(autobus.pasazerowie->get_n_pasazerow(), autobus.pasazerowie->get_n_z_biletami(), autobus.pasazerowie->get_n_rowerow());
	}

}

Kierowca * Autobus::stworz_kierowce(string im, string n, int i) {
	Kierowca * k = new Kierowca(im, n, i);
	//kierowca = k;
	return k;
}
Pasazerowie * Autobus::stworz_pasazerow(int n, int b, int r) {
	if (n > (miejsca->get_miejsca_normalne() + miejsca->get_miejsca_stojace()) || r > miejsca->get_miejsca_rowery()) {
		n = miejsca->get_miejsca_normalne() + miejsca->get_miejsca_stojace();
		b = n;
		r = miejsca->get_miejsca_rowery();
	}
	Pasazerowie * p = new Pasazerowie(n, b, r);
	return p;
}

void Autobus::przypisz_kierowce(Kierowca *k) {
	if (k != NULL && kierowca == NULL) {
		//delete kierowca;
		kierowca = k;
		cout << "Kierowca poprawnie przypisany" << endl;
		kierowca->wyswietl();
	}
	else if (kierowca != NULL){
		cout << "Autobus ma obecnie kierowce" << endl;
	}
	else {
		cout << "Blad przypisania" << endl;
	}

}
void Autobus::przypisz_pasazerow(Pasazerowie *p) {
	if (kierowca == NULL) {
		cout << "Aby dodac pasazerow najpierw dodaj kierowce" << endl;
		return;
	}
	if (p != NULL && pasazerowie == NULL) {
		//delete pasazerowie;
		pasazerowie = p;
		cout << "pasazerowie poprawnie przypisany" << endl;
		pasazerowie->wyswietl();
	}
	else if (pasazerowie != NULL) {
		cout << "Autobus ma obecnie pasazerow" << endl;
	}
	else {
		cout << "Blad przypisania, podaj wskaznik rozny od NULL" << endl;
	}

}
void Autobus::dodaj_pasazerow(int a, int b, int c) {
	if (kierowca == NULL) {
		cout << "Aby dodac pasazerow najpierw dodaj kierowce" << endl;
		return;
	}
	Pasazerowie * p = stworz_pasazerow(a, b, c);
	if (p != NULL && pasazerowie == NULL) {
		pasazerowie = p;
		cout << "Pasazerowie poprawnie przypisany" << endl;
		pasazerowie->wyswietl();
	}
	else if (p != NULL && pasazerowie != NULL) {
		delete pasazerowie;
		pasazerowie = p;
		cout << "Pasazerowie poprawnie przypisany, starzy usunieci" << endl;
		pasazerowie->wyswietl();
	}
	else {
		cout << "Blad przypisania" << endl;

	}
}
void Autobus::dodaj_kierowce(string i, string n, int i_) {
	
	Kierowca * k = stworz_kierowce(i, n, i_);
	if (k == NULL ) {
		kierowca = k;
		cout << "Kierowca poprawnie przypisany" << endl;
		kierowca->wyswietl();
	}
	else if (k != NULL) {
		delete kierowca;
		kierowca = k;
		cout << "Kierowca dodany poprawnie, stary usuniety" << endl;
		kierowca->wyswietl();
	}
	else {
		cout << "Blad przypisania" << endl;

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

//gety
string Autobus::get_nr_rej() {
	return nr_rej;
}
string  Autobus::get_marka() {
	return marka;
}
Silnik * Autobus::get_silnik() {
	return silnik;
}
Bak * Autobus::get_bak() {
	return bak;
}
Kierowca * Autobus::get_kierowca() {
	return kierowca;
}
Miejsca * Autobus::get_miejsca() {
	return miejsca;
}
Pasazerowie * Autobus::get_pasazerowie() {
	return pasazerowie;
}



//OPERATORY

bool Autobus::operator > (const Autobus &a) const{
	if (this->silnik->get_moc() > a.silnik->get_moc()) {
		return true;
	}
	else {
		return false;
	}
}
bool Autobus::operator < (const Autobus &a) const {
	if (this->silnik->get_moc() < a.silnik->get_moc()) {
		return true;
	}
	else {
		return false;
	}
}

Autobus Autobus::operator !() {
	if (this->pasazerowie == NULL & this->kierowca == NULL) {
		return Autobus(this->nr_rej, this->marka, this->silnik->get_pojemnosc(), this->silnik->get_moc(), this->silnik->get_typ(), this->bak->get_pojemnosc(),
			this->bak->get_pojemnosc(), this->miejsca->get_miejsca_normalne(), this->miejsca->get_miejsca_stojace(), this->miejsca->get_miejsca_rowery(),
			NULL, NULL);
	}
	else if (this->pasazerowie == NULL) {
		Kierowca * k = new Kierowca(this->kierowca->get_imie(), this->kierowca->get_nazwisko(), this->kierowca->get_id());
		return Autobus(this->nr_rej, this->marka, this->silnik->get_pojemnosc(), this->silnik->get_moc(), this->silnik->get_typ(), this->bak->get_pojemnosc(),
			this->bak->get_pojemnosc(), this->miejsca->get_miejsca_normalne(), this->miejsca->get_miejsca_stojace(), this->miejsca->get_miejsca_rowery(),
			k, NULL);
	}
	else if (this->kierowca == NULL) {
		Pasazerowie * p = new Pasazerowie(this->pasazerowie->get_n_pasazerow(), this->pasazerowie->get_n_z_biletami(), this->pasazerowie->get_n_rowerow());
		Kierowca * k = new Kierowca(this->kierowca->get_imie(), this->kierowca->get_nazwisko(), this->kierowca->get_id());
		return Autobus(this->nr_rej, this->marka, this->silnik->get_pojemnosc(), this->silnik->get_moc(), this->silnik->get_typ(), this->bak->get_pojemnosc(),
			this->bak->get_pojemnosc(), this->miejsca->get_miejsca_normalne(), this->miejsca->get_miejsca_stojace(), this->miejsca->get_miejsca_rowery(),
			NULL, p);
	}
	else {
		Pasazerowie * p = new Pasazerowie(this->pasazerowie->get_n_pasazerow(), this->pasazerowie->get_n_z_biletami(), this->pasazerowie->get_n_rowerow());
		Kierowca * k = new Kierowca(this->kierowca->get_imie(), this->kierowca->get_nazwisko(), this->kierowca->get_id());
		return Autobus(this->nr_rej, this->marka, this->silnik->get_pojemnosc(), this->silnik->get_moc(), this->silnik->get_typ(), this->bak->get_pojemnosc(),
			this->bak->get_pojemnosc(), this->miejsca->get_miejsca_normalne(), this->miejsca->get_miejsca_stojace(), this->miejsca->get_miejsca_rowery(),
			k, p);
	}
	
}
Autobus & Autobus::operator =(const Autobus &) {
	return *this;
}

Autobus Autobus::operator -() {
	if (this->pasazerowie = NULL) {
		cout << "Pasazerowie nie moga wyjsc z autobusu, poniewaz Pasazerowie nie zostali przypisani do autobusu, zwracam autobus o wart domyslnych" << endl;
		Autobus a;
		return a;
		/*(this->nr_rej, this->marka, this->silnik->get_pojemnosc(), this->silnik->get_moc(), this->silnik->get_typ(), this->bak->get_pojemnosc(),
			this->bak->get_pojemnosc(), this->miejsca->get_miejsca_normalne(), this->miejsca->get_miejsca_stojace(), this->miejsca->get_miejsca_rowery(),
			this->kierowca, this->pasazerowie);*/
	}
	else if (kierowca ==NULL){
		Pasazerowie * p = new Pasazerowie(0, 0, 0);
		
		return Autobus(this->nr_rej, this->marka, this->silnik->get_pojemnosc(), this->silnik->get_moc(), this->silnik->get_typ(), this->bak->get_pojemnosc(),
			this->bak->get_pojemnosc(), this->miejsca->get_miejsca_normalne(), this->miejsca->get_miejsca_stojace(), this->miejsca->get_miejsca_rowery(),
			NULL, p);
	}
	else {
		Pasazerowie * p = new Pasazerowie(0, 0, 0);
		Kierowca * k = new Kierowca(this->kierowca->get_imie(), this->kierowca->get_nazwisko(), this->kierowca->get_id());
		return Autobus(this->nr_rej, this->marka, this->silnik->get_pojemnosc(), this->silnik->get_moc(), this->silnik->get_typ(), this->bak->get_pojemnosc(),
			this->bak->get_pojemnosc(), this->miejsca->get_miejsca_normalne(), this->miejsca->get_miejsca_stojace(), this->miejsca->get_miejsca_rowery(),
			k, p);
	}
}
Autobus & Autobus::operator --() {
	if (pasazerowie != NULL) {
		if (pasazerowie->get_n_rowerow() - 1 >= 0) {
			Pasazerowie * p = new Pasazerowie(this->pasazerowie->get_n_pasazerow(), this->pasazerowie->get_n_z_biletami(), this->pasazerowie->get_n_rowerow()-1);
			delete this->pasazerowie;
			this->pasazerowie = p;
			return *this;
		}
	}
	else {
		cout << "Stworz najpierw pasazerow" << endl;
		return *this;
	}
	
}
Autobus & Autobus::operator ++() {
	if (pasazerowie != NULL) {
		if (pasazerowie->get_n_rowerow() + 1>= miejsca->get_miejsca_rowery()) {
			Pasazerowie * p = new Pasazerowie(this->pasazerowie->get_n_pasazerow(), this->pasazerowie->get_n_z_biletami(), this->pasazerowie->get_n_rowerow() + 1);
			delete this->pasazerowie;
			this->pasazerowie = p;
			return *this;
		}
	}
	else {
		cout << "Stworz najpierw pasazerow" << endl;
		return *this;
	}

}
