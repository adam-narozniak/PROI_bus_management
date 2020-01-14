#include "test.h"
void menu() {
	int a;
	do {
		cout << "Wcisnij:" << endl << "1 aby stworzyc obiekt klasy autobus" << endl << "2 aby stworzyc obiekt klasy samochod" << endl
			<< "3 aby stworzyc obiekt klasy Sam_wyscigowy" << endl << "4 aby wyjsc" << endl;
		cin >> a;
		if (a == 1) {
			Autobus aut;
			menu_autobus(aut);
		}
		else if (a == 2) {
			Samochod s;
			menu_samochod(s);
		}
		else if (a == 3) {
			Sam_wyscigowy w;
			menu_sam_wys(w);
		}
		else {
			break;
		}

	} while (1);
}
void menu_autobus(Autobus &aut) {
	int a;
	string s;
	do {
		cout << "Wcisnij:" << endl << "0 aby utworzyc Autobus" << endl << "1 aby odczytac z pliku" << endl << "2 aby zapisac do pliku" << endl
			<< "3 aby jechac" << endl << "4 aby tankowac" << endl << "5 aby wyswietlic" << endl;
		cin >> a;
		if (a == 0) {
			getchar();
			cin >> aut;
			cout << aut;
			getchar();
		}
		else if (a == 1) {
			cout << "Podaj nazwe pliku: " << endl;
			cin >> s;
			aut.odczytaj(s);
		}
		else if (a == 2) {
			cout << "Podaj nazwe pliku: " << endl;
			cin >> s;
			aut.zapisz(s);
		}
		else if (a == 3) {
			aut.jedz();
			cout << aut;

		}
		else if (a == 4) {
			cout << "Ile chcesz zatankowac?" << endl;
			cin >> s;
			aut.tankuj(stod(s));
		}
		else if (a == 5) {
			cout << aut;
			getchar();
		}
		else {
			break;
		}

	} while (1);
}
void menu_samochod(Samochod &sam) {
	int a;
	string s;
	do {
		cout << "Wcisnij:" << endl << "0 aby utworzyc samochod" << endl << "1 aby odczytac z pliku" << endl << "2 aby zapisac do pliku" << endl
			<< "3 aby jechac" << endl << "4 aby tankowac" << endl;
		cin >> a;
		if (a == 0) {
			getchar();
			cin >> sam;
			cout << sam;
			getchar();
		}
		else if (a == 1) {
			cout << "Podaj nazwe pliku: " << endl;
			cin >> s;
			sam.odczytaj(s);
		}
		else if (a == 2) {
			cout << "Podaj nazwe pliku: " << endl;
			cin >> s;
			sam.zapisz(s);
		}
		else if (a == 3) {
			sam.jedz();
			cout << s;

		}
		else if (a == 4) {
			cout << "Ile chcesz zatankowac?" << endl;
			cin >> s;
			sam.tankuj(stod(s));
		}
		else {
			break;
		}

	} while (1);
}
void menu_sam_wys(Sam_wyscigowy &w) {
	int a;
	string s;
	do {
		cout << "Wcisnij:" << endl << "1 aby odczytac z pliku" << endl << "2 aby zapisac do pliku" << endl
			<< "3 aby jechac" << endl << "4 aby tankowac" << endl;
		cin >> a;
		if (a == 0) {
			getchar();
			cin >> w;
			cout << w;
			getchar();

		}
		else if (a == 1) {
			cout << "Podaj nazwe pliku: " << endl;
			cin >> s;
			w.odczytaj(s);
		}
		else if (a == 2) {
			cout << "Podaj nazwe pliku: " << endl;
			cin >> s;
			w.zapisz(s);
		}
		else if (a == 3) {
			w.jedz();
			cout << w;

		}
		else if (a == 4) {
			cout << "Ile chcesz zatankowac?" << endl;
			cin >> s;
			w.tankuj(stod(s));
		}
		else {
			break;
		}

	} while (1);
}

void test() {
	char stop;
	cout << "Funkcja testujaca" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Tworze podstawowa klase Autobus" << endl;
	cout << "--------------------------------------------------" << endl;
	Autobus a1("WW0000", "BMW", 2.2, 190, 1, 80, 100, 30, 50, 3);
	a1.wyswietl();
	//kierowca
	a1.dodaj_kierowce();
	cout << "KOPIA" << endl;
	Autobus a2(a1);
	cout << "AUTOBUS 2" << endl;
	cout << "AUTOBUS 2 - JEDZ" << endl;
	a2.jedz();
	a2.wyswietl();
	cout << "--------------------------------------------------" << endl;
	cout << "TANKOWANIE KOPII" << endl;
	a2.tankuj(90);
	cout << "PASAZEROWIE W A2" << endl;
	a2.dodaj_pasazerow(30, 24, 1);
	a2.wyswietl();
	cout << "KANAR - wywolanie funkcji" << endl;
	a2.kanar();
	a2.wyswietl();
	{
		cout << "LOKALNIE" << endl;
		Autobus a3("WW0001", "Mercedes", 2.4, 180, 1, 80, 100, 30, 50, 3);
		a3.wyswietl();
	}
	cin >> stop;
	cout << "DYNAMICZNIE" << endl;
	Autobus * pa;
	pa = new Autobus("WW 0932");
	pa->wyswietl();
	cout << "Dodaj kierowce, przerejestruj, dodaj pasazerow, tankuj" << endl;
	pa->dodaj_kierowce("Kamil", "Stok", 2);
	pa->dodaj_pasazerow();
	pa->tankuj(100);
	pa->przerejestruj("WW 8734");
	pa->wyswietl();
	test_edycji_pasazerow();
	test_podklas();

}

void test_porownania_mocy() {
	cout << "TEST POROWNANIA MOCY" << endl;
	Autobus a1("ww0012", "mercedes", 2.2, 190, 1);
	Autobus a2("wk3465", "bmw", 2.2, 200, 2);
	bool test;
	test = a1 < a2;
	cout << test << endl;
}

void test_tankowania_do_pelna() {
	Autobus a1("ww0012", "mercedes", 2.2, 190, 1, 10, 60);
	a1.wyswietl();
	!a1;
	a1.wyswietl();
}

void test_edycji_pasazerow() { // obecnie nie mozliwa w uzyciu, metoda prywatna, aby nie podmienic zle
	Autobus a1("wwl", "lada", 2.5, 190, 1, 41, 62, 32, 87, 3);
	a1.dodaj_kierowce();
	a1.dodaj_pasazerow(50, 23, 2);
	a1.wyswietl();
	a1.edytuj_pasazerow(200, 150, 5);
	a1.wyswietl();
}

void test_konsturkora_kopiujacego() {
	cout << "KONSTRUKTOR KOPIUJACY kopia 1 w 2" << endl;
	Autobus a1("ww0012", "mercedes", 2.2, 190, 1, 10, 60);
	a1.dodaj_kierowce();
	cout << "Przed zmianami 1" << endl;
	a1.wyswietl();
	Autobus a2(a1);
	cout << "TANKOWANIE KOPII + dodanie pasazerow - autobus 2" << endl;
	a2.tankuj(50);
	a2.dodaj_pasazerow();
	cout << "Po zmianach 1" << endl;
	a1.wyswietl();
	cout << "Po zmianach 2" << endl;
	a2.wyswietl();
}

void test_podklas() {
	cout << endl;
	Silnik silnik01(1.9, 130, 1);
	silnik01.wyswietl();

	Bak bak01(34, 60);
	bak01.wyswietl();

	Kierowca k("Jan", "Nowak", 01234);
	k.wyswietl();

	Miejsca miejsca01;
	miejsca01.wyswietl();

	Pasazerowie pas01(10, 12, 3);
	pas01.wyswietl();
	cout << endl;
}
void test_dodawania_rowerow() {
	Autobus a1;
	cout << "Proba przypisania bez kierowcy" << endl;
	++a1;
	a1.dodaj_kierowce("Janek", "Nowak", 12345);
	a1.dodaj_pasazerow(30, 24, 2);
	a1.wyswietl();
	cout << "DODANIE ROWERU" << endl;
	++a1;
	a1.wyswietl();
	cout << "ODJECIE ROWERU" << endl;
	--a1;
	a1.wyswietl();

}
void test_przesiadki() {
	Autobus a1, a2("wwl", "lada", 2.5, 190, 1, 41, 62, 32, 87, 3);
	a1.dodaj_kierowce();
	a2.dodaj_kierowce("Janek", "Nowak", 12345);
	a2.dodaj_pasazerow(120, 23, 2);
	a1.wyswietl();
	a2.wyswietl();
	a1 << a2;
	a1.wyswietl();
	a2.wyswietl();

}

void test_wysiadki() {
	Autobus a1("WW0000", "BMW", 2.2, 190, 1, 80, 100, 30, 50, 3);
	a1.dodaj_kierowce();
	a1.dodaj_pasazerow();
	a1.wyswietl();
	Autobus a2 = -a1;
	a2.wyswietl();
}
void test_operatorow() {

	test_porownania_mocy();
	test_tankowania_do_pelna();
	test_dodawania_rowerow();
	test_przesiadki();
	test_wysiadki();
}

void tablica_pojazd() {
	Pojazd * p[3];
	Autobus a1;
	a1.dodaj_kierowce("Janek", "Nowak", 12345);
	//a1.zapisz();
	p[0] = &a1;
	Samochod s1("WWK 2343", "Porshe", 1.2, 130, 1, 34, 60);
	//s1.zapisz();
	p[1] = &s1;
	Sam_wyscigowy w1("WK 00123", "Audi", 1.23, 130, 1, 20, 34);
	//w1.zapisz();
	p[2] = &w1;
	for (int i = 0; i < 3; i++) {
		1;
	}

}
void vector_iterator_sort() {
	Autobus a1("aWW0001", "Mercedes", 2.4, 180, 1, 80, 100, 30, 50, 3);
	Autobus a2("bwk3465", "bmw", 2.2, 200, 2);
	Autobus a3("cwk3465", "bmw", 2.72, 287, 2);
	vector<Autobus> aut;
	aut.push_back(a3);
	aut.push_back(a1);
	aut.push_back(a2);
	typedef vector<Autobus>::iterator IT;
	IT begin = aut.begin();
	sort(aut.begin(), aut.end(), Komp<Autobus>(Komp<Autobus>::wg_rejestracji));
	copy(aut.begin(), aut.end(), ostream_iterator<Autobus>(cout, " "));

}
void iterator() {
	Autobus a1("aWW0001", "Mercedes", 2.4, 180, 1, 80, 100, 30, 50, 3);
	Autobus a2("bwk3465", "bmw", 2.2, 200, 2);
	Autobus a3("cwk3465", "bmw", 2.72, 287, 2);
	vector<Autobus> aut;
	aut.push_back(a3);
	aut.push_back(a1);
	aut.push_back(a2);
	typedef vector<Autobus>::iterator IT;
	IT begin = aut.begin();
	sort(aut.begin(), aut.end(), Komp<Autobus>(Komp<Autobus>::wg_rejestracji));
	cout << *begin << endl;
	begin++;
	cout << *begin << endl;
}
void wyjatki() {
	Autobus a1("aWW0001", "Mercedes", 2.4, 180, 1, 80, 100, 30, 50, 3);
	a1.tankuj(-2);
}
void vector_find() {
	Autobus a1("aWW0001", "Mercedes", 2.4, 180, 1, 80, 100, 30, 50, 3);
	Autobus a2("bwk3465", "bmw", 2.2, 200, 2);
	Autobus a3("cwk3465", "bmw", 2.72, 287, 2);
	vector<Autobus> aut;
	aut.push_back(a3);
	aut.push_back(a1);
	aut.push_back(a2);
	typedef vector<Autobus>::iterator IT;
	IT it;
	it = find(aut.begin(), aut.end(), "aWW0001");
	if (it == aut.end()) {
		cout << "Nie znaleziono autobusu o tym numerze rejestracyjnym" << endl;
	}
	else {
		cout <<"Twoj obiekt to "<<*it << endl;
	}

}
/*void vector_find_if() {
	Autobus a1("aWW0001", "Mercedes", 2.4, 180, 1, 80, 100, 30, 50, 3);
	Autobus a2("bwk3465", "bmw", 2.2, 200, 2);
	Autobus a3("cwk3465", "bmw", 2.72, 287, 2);
	vector<Autobus> aut;
	aut.push_back(a3);
	aut.push_back(a1);
	aut.push_back(a2);
	typedef vector<Autobus>::iterator IT;
	IT it;
	it = find_if(aut.begin(), aut.end(), Komp<Autobus>(Komp<Autobus>::find_wg_marki));
	if (it == aut.end()) {
		cout << "Nie znaleziono autobusu o tym numerze rejestracyjnym" << endl;
	}
	else {
		cout << "Twoj obiekt to " << *it << endl;
	}

}*/
void czy_jest_rej() {
	1;
}