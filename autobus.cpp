#include <iostream>
#include "autobus.h"
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

void Autobus::wczytaj() {
	cout << "Podaj nr rejestracyjny oraz marke" << endl;
	cin >> nr_rej;
	cin >> marka;
}

void Autobus::wyswietl() {
	//funkcja do wywietlenie wszytkich danych
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
ostream& operator<<(ostream& str, const Autobus& a) {
	if (&str == &std::cout) {
		str << "AUTOBUS" << endl;
		str << "--------------------------------------------------" << endl;
		str << "NR rejestracyjny: " << a.nr_rej << endl;
		str << "Marka: " << a.marka << endl;
		str << "--------------------------------------------------" << endl;
		str << "Silnik: " << endl;
		str << *(a.silnik);
		str << "Bak: " << endl;
		str << *(a.bak);
		str << "Kierowca: " << endl;
		if (a.kierowca == NULL) {
			str << "Kierowca nie jest przypisany do autobusu" << endl;
			str << "--------------------------------------------------" << endl;
		}
		else {
			str << *(a.kierowca);
		}
		str << "Miejsca: " << endl;
		str << *(a.miejsca);

		str << "Pasazerowie: " << endl;
		if (a.pasazerowie == NULL) {
			str << "Brak przypisanych pasazerow" << endl;
			str << "--------------------------------------------------" << endl;
		}
		else {
			str << *(a.pasazerowie);
		}
		return str << endl;
	}
	else {
		str << "AUTOBUS" << endl;
		str << a.nr_rej << endl;
		str << a.marka << endl;
		str << *(a.silnik);
		str << *(a.bak);
		if (a.kierowca == NULL) {
			str << "NULL" << endl;
		}
		else {
			str << *(a.kierowca);
		}
		str << *(a.miejsca);
		if (a.pasazerowie == NULL) {
			str << "NULL" << endl;
		}
		else {
			str << *(a.pasazerowie);
		}
		return str << endl;
	}
}
void Autobus::zapisz(string s) {
	ofstream plik(s);
	plik << *this << endl;
	plik.close();
}


void Autobus::jedz() {//kierowca musi byc rozny od NULL
	if (kierowca == NULL) {
		cout << "Funkcja jedz nie jest mozliwa, dodaj napierw kierowce" << endl;
	}
	else {
		double delta = silnik->get_pojemnosc()*2.2;
		if (delta > bak->get_stan()) {
			cout << "Najpierw zatankuj, za malo paliwa w baku" << endl;
		}
		else {
			bak->zmien_stan(bak->get_stan() - delta);
		}
	}
}
void Autobus::kanar() {
	if (pasazerowie == NULL) {
		cout << "Operacja nie jest mozliwa, najpierw dodaj pasazerow" << endl;
	}
	else {
		int z_biletami = this->pasazerowie->get_n_z_biletami();
		this->edytuj_pasazerow(z_biletami, z_biletami, this->pasazerowie->get_n_rowerow());
	}
}
void Autobus::przerejestruj(const string rej) {
	this->nr_rej = rej;
}


Autobus::Autobus(string r, string m, double p, double mo, int t, double s, double po, int m1, int m2, int m3, Kierowca * k, Pasazerowie * pa) {// , int p1, int p2, int p3){
	//konstruktor, gdzie silnik, bak oraz miejsca tworzone automotycznie, a bak i pasazerowie dynamicznie
	nr_rej = r;
	marka = m;
	silnik = new Silnik(p, mo, t);
	bak = new Bak(s, po);
	kierowca = k;
	miejsca = new Miejsca(m1, m2, m3);
	pasazerowie = pa;

}

Autobus::~Autobus() {
	//desturktor
	delete silnik;
	delete bak;
	if (kierowca != NULL) {
		delete kierowca;
	}
	delete miejsca;
	if (pasazerowie != NULL) {
		delete pasazerowie;
	}
	cout << "Destruktor AUTOBUS wlaczony" << endl;
}

Autobus::Autobus(const Autobus &autobus) {
	//destruktor elementy dynamiczne specjalnie rozpatrzone
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
Pasazerowie * Autobus::stworz_pasazerow(int a, int b, int r) {
	//funkcja do tworzenia pasazerow, ktora sprawdza jak miejsca na to pozwalaja

	int dostepne_miejsca = this->miejsca->get_miejsca_normalne() + this->miejsca->get_miejsca_stojace();
	bool pa = (a <= dostepne_miejsca);
	int r_mozliwe = this->miejsca->get_miejsca_rowery();
	bool ro = (r <= r_mozliwe);
	Pasazerowie * p;
	if (pa && ro) {
		p = new Pasazerowie(a, b, r);
	}
	else if (pa && ~ro) {
		p = new Pasazerowie(a, b, r_mozliwe);
	}
	else if (~pa && ro) {
		p = new Pasazerowie(dostepne_miejsca, dostepne_miejsca, r);
	}
	else {
		p = new Pasazerowie(dostepne_miejsca, dostepne_miejsca, r_mozliwe);
	}
	return p;
}

void Autobus::przypisz_kierowce(Kierowca *k) {
	if (k != NULL && kierowca == NULL) {
		//delete kierowca;
		kierowca = k;
		cout << "Kierowca poprawnie przypisany" << endl;
		kierowca->wyswietl();
	}
	else if (kierowca != NULL) {
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
void Autobus::dodaj_pasazerow(int a, int b, int r) {
	if (kierowca == NULL) {
		cout << "Aby dodac pasazerow najpierw dodaj kierowce" << endl;
		return;
	}

	Pasazerowie * p = stworz_pasazerow(a, b, r);
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

void Autobus::edytuj_pasazerow(int a, int b, int r) {//specjalnie pod przesiadki
	if (this->pasazerowie == NULL) {
		cout << "Metoda edytuj pasazerow uzyta nieprawaidlowo - pasazerowie == NULL" << endl;
		return;
	}
	int dostepne_miejsca = this->miejsca->get_miejsca_normalne() + this->miejsca->get_miejsca_stojace();
	bool pa = (a <= dostepne_miejsca);
	int r_mozliwe = this->miejsca->get_miejsca_rowery();
	bool ro = (r <= r_mozliwe);
	if (pa && ro) {
		this->pasazerowie->edytuj(a, b, r);
	}
	else if (pa && ~ro) {
		this->pasazerowie->edytuj(a, b, r_mozliwe);
	}
	else if (~pa && ro) {
		this->pasazerowie->edytuj(dostepne_miejsca, dostepne_miejsca, r);
	}
	else {
		this->pasazerowie->edytuj(dostepne_miejsca, dostepne_miejsca, r_mozliwe);
	}
}
void Autobus::dodaj_kierowce(string i, string n, int i_) {
	//funcja tworzy instancje kierowca a nastepnie dodaje ja do instacji autobus, jesli natomiast kierowca instal - zostaje usuniety, a nowy przypisany
	Kierowca * k = stworz_kierowce(i, n, i_);
	if (this->kierowca == NULL) {
		kierowca = k;
		cout << "Kierowca poprawnie przypisany" << endl;
		kierowca->wyswietl();
	}
	else if (this->kierowca != NULL) {
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
	if (ile < bak->get_stan()) {
		cout << "Takowanie tylko do wiekszego stanu niz obeczny" << endl;
	}
	bak->zmien_stan(ile);
	//return *this;
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

bool Autobus::operator > (const Autobus &a) const {
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

Autobus & Autobus::operator !() {
	/*Autobus * p = new Autobus(*this);
	p->tankuj(this->bak->get_pojemnosc());
	return *p;*/
	this->tankuj(this->bak->get_pojemnosc());
	return *this;

}
Autobus & Autobus::operator =(const Autobus &p) {
	nr_rej = p.nr_rej;
	marka = p.marka;
	silnik = p.silnik;
	bak = p.bak;
	kierowca = p.kierowca;
	miejsca = p.miejsca;
	pasazerowie = p.pasazerowie;
	return *this;
}

Autobus & Autobus::operator -() {
	if (this->pasazerowie == NULL) {
		cout << "Pasazerowie nie moga wyjsc z autobusu, poniewaz Pasazerowie nie zostali przypisani do autobusu" << endl;
		return *this;

	}
	else {
		this->edytuj_pasazerow(0, 0, 0);
		return *this;
	}

}
Autobus & Autobus::operator --() {
	if (pasazerowie != NULL) {
		if (pasazerowie->get_n_rowerow() - 1 >= 0) {
			edytuj_pasazerow(this->pasazerowie->get_n_pasazerow(), this->pasazerowie->get_n_z_biletami(), this->pasazerowie->get_n_rowerow() - 1);
		}
		return *this;
	}
	else {
		cout << "Stworz najpierw pasazerow" << endl;
		return *this;
	}

}
Autobus & Autobus::operator ++() {
	if (pasazerowie != NULL) {
		if (pasazerowie->get_n_rowerow() + 1 <= miejsca->get_miejsca_rowery()) {
			edytuj_pasazerow(this->pasazerowie->get_n_pasazerow(), this->pasazerowie->get_n_z_biletami(), this->pasazerowie->get_n_rowerow() + 1);
		}
		return *this;
	}
	else {
		cout << "Stworz najpierw pasazerow" << endl;
		return *this;
	}

}



void  Autobus::operator <<(Autobus &p) {//przesiadka z p do this: wychodza z p, wchodza do this
	if (p.pasazerowie == NULL) {
		cout << "Operacja niemozliwa, dodaj napierw pasazerow, Obecnie nikt nie moze przejsc poniewaz nie ma pasazerow w autobusie z ktorego mieliby przejsc" << endl;
	}
	else if (this->pasazerowie == NULL) {
		if (this->kierowca == NULL) {
			cout << "Najpierw dodaj kierowce" << endl;
			return;
		}
		Pasazerowie * p_new = stworz_pasazerow(p.pasazerowie->get_n_pasazerow(), p.pasazerowie->get_n_z_biletami(), p.pasazerowie->get_n_rowerow());
		this->pasazerowie = p_new;
		p.edytuj_pasazerow(p.pasazerowie->get_n_pasazerow() - this->pasazerowie->get_n_pasazerow(), p.pasazerowie->get_n_z_biletami() - this->pasazerowie->get_n_z_biletami(),
			p.pasazerowie->get_n_rowerow() - this->pasazerowie->get_n_rowerow());

	}
	else {
		int a0, b0, r0;
		a0 = this->pasazerowie->get_n_pasazerow();
		b0 = this->pasazerowie->get_n_z_biletami();
		r0 = this->pasazerowie->get_n_rowerow();

		this->edytuj_pasazerow(p.pasazerowie->get_n_pasazerow(), p.pasazerowie->get_n_z_biletami(), p.pasazerowie->get_n_rowerow());
		p.edytuj_pasazerow(p.pasazerowie->get_n_pasazerow() - this->pasazerowie->get_n_pasazerow() + a0, p.pasazerowie->get_n_z_biletami() - this->pasazerowie->get_n_z_biletami() + b0,
			p.pasazerowie->get_n_rowerow() - this->pasazerowie->get_n_rowerow() + r0);
	}
}

