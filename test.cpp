#include "test.h"
void menu() {
	int a;
	do {
		cout << "Wcisnij:" << endl << "1 aby stworzyc obiekt klasy autobus" << endl << "2 aby stworzyc obiekt klasy samochod" << endl
			<< "3 aby stworzyc obiekt klasy Sam_wyscigowy" << endl << "4 aby uzywac vektorow" << endl << "5 aby wyjsc" << endl;
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
		else if (a == 4) {
			do {
				cout << "1 - autobusow" << endl << "2 - samochodow" << endl << "3 - samochodow wyscigowych" << endl << "4 - wyjscie" << endl;
				cin >> a;
				if (a == 1) {
					baza_autobus();
				}
				else if (a == 2) {
					baza_samochod();
				}
				else if (a == 3) {
					baza_sam_wyscigowy();
				}
				else {
					break;
				}
			} while (1);
		}
		else {
			break;
		}

	} while (1);
}
void baza_autobus() {
	Autobus a1("aWW0001", "Mercedes", 2.4, 180, 1, 80, 100, 30, 50, 3);
	Autobus a2("bwk3465", "bmw", 2.2, 200, 2, 32, 40);
	Autobus a3("cwk3465", "bmw", 2.72, 287, 2, 37.3, 50);
	vector<Autobus> aut;
	aut.push_back(a3);
	aut.push_back(a1);
	aut.push_back(a2);
	tekst_menu(aut);
}
void baza_samochod() {
	Samochod s1("aWOK 2343", "porshe", 1.2, 130, 1, 34, 60);
	Samochod s2("bLWK 2343", "bmw", 1.8, 172, 2, 20, 70);
	Samochod s3("cWWK 2SD3", "audi", 2.2, 230, 1, 54, 60);
	vector<Samochod> sam;
	sam.push_back(s1);
	sam.push_back(s2);
	sam.push_back(s3);
	tekst_menu(sam);
}
void baza_sam_wyscigowy() {
	Sam_wyscigowy s1("aWOA 2343", "volvo", 1.2, 130, 1, 34, 60,"A Rh+");
	Sam_wyscigowy s2("bGD 2343", "bmw", 1.8, 172, 2, 20, 70);
	Sam_wyscigowy s3("cPA 2SD3", "audi", 2.2, 230, 1, 54, 60, "AB Rh-");
	vector<Sam_wyscigowy> sam;
	sam.push_back(s1);
	sam.push_back(s2);
	sam.push_back(s3);
	tekst_menu(sam);
}
template <class T>
void tekst_menu(vector<T> &v) {
	typedef vector<T>::iterator IT;
	do {
		cout << "1-dodaj" << endl << "2-sortuj" << endl << "3-znajdz" << endl << "4-max" << endl << "5-min" << endl << "6 wyswietl" << endl
			<< "7 wyjscie" << endl;
		int a;
		cin >> a;
		if (a == 1) {
			getchar();
			T t1;
			cin >> t1;
			v.push_back(t1);
		}
		else if (a == 2) {
			cout << "Podaj tryb sortowania" << endl << "1-wg_rejestracji, 2-wg_pojemnosci, 3-wg_mocy, 4-wg_paliwa" << endl;
			cin >> a;
			switch (a) {
			case 1:
				sort(v.begin(), v.end(), Komp<T>(Komp<T>::wg_rejestracji));
				break;
			case 2:
				sort(v.begin(), v.end(), Komp<T>(Komp<T>::wg_pojemnosci));
				break;
			case 3:
				sort(v.begin(), v.end(), Komp<T>(Komp<T>::wg_mocy));
				break;
			case 4:
				sort(v.begin(), v.end(), Komp<T>(Komp<T>::wg_paliwa));
				break;
			default:
				break;
			}
		}
		else if (a == 3) {
			cout << "Podaj tryb znajdywania:" << endl << "1- wg_marki, 2-wg_min_pojemnosci, 3-wg_min_mocy, 4-wg_min_paliwa" << endl;
			cin >> a;
			cout << "Podaj interesujacy Cie parametr" << endl;
			string s;
			cin >> s;

			IT it;
			switch (a) {
			case 1:
				it = find_if(v.begin(), v.end(), Komp2<T>(Komp2<T>::wg_marki, s));
				break;
			case 2:
				it = find_if(v.begin(), v.end(), Komp2<T>(Komp2<T>::wg_min_pojemnosci, s));
				break;
			case 3:
				it = find_if(v.begin(), v.end(), Komp2<T>(Komp2<T>::wg_min_mocy, s));
				break;
			case 4:
				it = find_if(v.begin(), v.end(), Komp2<T>(Komp2<T>::wg_min_paliwa, s));
				break;
			default:
				break;
			}
			if (a > 0 && a < 5) {
				if (it == v.end()) {
					cout << "Nie znaleziono szukanego pojazdu" << endl;
				}
				else {
					cout << "Twoj obiekt to " << *it << endl;
				}
			}

		}
		else if (a == 4) {
			cout << "Podaj tryb porownan" << endl << "1-wg_rejestracji, 2-wg_pojemnosci, 3-wg_mocy, 4-wg_paliwa" << endl;
			cin >> a;
			IT it;
			switch (a) {
			case 1:
				it = max_element(v.begin(), v.end(), Komp<T>(Komp<T>::wg_rejestracji));
				break;
			case 2:
				it = max_element(v.begin(), v.end(), Komp<T>(Komp<T>::wg_pojemnosci));
				break;
			case 3:
				it = max_element(v.begin(), v.end(), Komp<T>(Komp<T>::wg_mocy));
				break;
			case 4:
				it = max_element(v.begin(), v.end(), Komp<T>(Komp<T>::wg_paliwa));
				break;
			default:
				break;
			}
			if (a > 0 && a < 5) {
				cout << "Maxymalny element to: " << endl << *it << endl;
			}

		}
		else if (a == 5) {
			cout << "Podaj tryb porownan" << endl << "1-wg_rejestracji, 2-wg_pojemnosci, 3-wg_mocy, 4-wg_paliwa" << endl;
			cin >> a;
			IT it;
			switch (a) {
			case 1:
				it = min_element(v.begin(), v.end(), Komp<T>(Komp<T>::wg_rejestracji));
				break;
			case 2:
				it = min_element(v.begin(), v.end(), Komp<T>(Komp<T>::wg_pojemnosci));
				break;
			case 3:
				it = min_element(v.begin(), v.end(), Komp<T>(Komp<T>::wg_mocy));
				break;
			case 4:
				it = min_element(v.begin(), v.end(), Komp<T>(Komp<T>::wg_paliwa));
				break;
			default:
				break;
			}
			if (a > 0 && a < 5) {
				cout << "Minimalny element to: " << endl << *it << endl;
			}
		}
		else if (a == 6) {
		copy(v.begin(), v.end(), ostream_iterator<T>(cout, ""));
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
	copy(aut.begin(), aut.end(), ostream_iterator<Autobus>(cout, ""));

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
		cout << "Twoj obiekt to " << endl << *it << endl;
	}

}
void vector_find_if() {
	Autobus a1("aWW0001", "Mercedes", 2.4, 180, 1, 80, 100, 30, 50, 3);
	Autobus a2("bwk3465", "bmw", 2.2, 200, 2);
	Autobus a3("cwk3465", "bmw", 2.72, 287, 2);
	vector<Autobus> aut;
	aut.push_back(a3);
	aut.push_back(a1);
	aut.push_back(a2);
	typedef vector<Autobus>::iterator IT;
	IT it;
	it = find_if(aut.begin(), aut.end(), Komp2<Autobus>(Komp2<Autobus>::wg_marki, "bmw"));
	if (it == aut.end()) {
		cout << "Nie znaleziono szukanego autobusu" << endl;
	}
	else {
		cout << "Twoj obiekt to " << *it << endl;
	}

}
void find_max_elem() {
	Autobus a1("aWW0001", "Mercedes", 2.4, 180, 1, 80, 100, 30, 50, 3);
	Autobus a2("bwk3465", "bmw", 2.2, 200, 2);
	Autobus a3("cwk3465", "bmw", 2.72, 287, 2);
	vector<Autobus> aut;
	aut.push_back(a3);
	aut.push_back(a1);
	aut.push_back(a2);
	typedef vector<Autobus>::iterator IT;
	IT it;
	it = max_element(aut.begin(), aut.end(), Komp<Autobus>(Komp<Autobus>::wg_mocy));
	cout << *it;

}