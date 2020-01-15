#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include "autobus.h"
#include "kierowca.h"
#include "bak.h"
#include "silnik.h"
#include "miejsca.h"
#include "pasazerowie.h"
#include "samochod.h"
#include "sam_wyscigowy.h"
#include <stdlib.h>
#ifndef Test_H
#define Test_H
void test();
void test_porownania_mocy();
void test_tankowania_do_pelna();
void test_edycji_pasazerow();
void test_konsturkora_kopiujacego();
void test_podklas();
void test_wysiadki();
void test_operatorow();
void test_dodawania_rowerow();
void test_przesiadki();
void menu();
void baza_autobus();
void baza_samochod();
void baza_sam_wyscigowy();
template <class T>
void tekst_menu(vector<T> &);
void menu_autobus(Autobus &);
void menu_samochod(Samochod &);
void menu_sam_wys(Sam_wyscigowy&);
void tablica_pojazd();
void vector_iterator_sort();
void vector_find();
void vector_find_if();
void find_max_elem();
template <typename P>
struct Komp {
	enum Sposoby {
		wg_rejestracji,
		wg_pojemnosci,
		wg_mocy,
		wg_paliwa,
	};
	Komp(Sposoby s) :sposob(s) {};
	int operator()(P& a1, P& a2);
private:
	Sposoby sposob;
};
template <typename P>
int Komp<P>::operator() (P& a1, P& a2) {
	switch (sposob) {
	case wg_rejestracji:
		return (a1.get_nr_rej().compare(a2.get_nr_rej())) < 0;

	case wg_pojemnosci:
		return (a1.get_silnik()->get_pojemnosc()) < (a2.get_silnik()->get_pojemnosc());

	case wg_mocy:
		return (a1.get_silnik()->get_moc()) < (a2.get_silnik()->get_moc());

	case wg_paliwa:
		return (a1.get_bak()->get_stan()) < (a2.get_bak()->get_stan());


	}
	return 0;
}
template <typename P1, typename P2>
bool czy_rejestracja(const P1 &p1, const P2 &p2) {
	return !((p1.get_nr_rejestracji().compare(p2)) == 0);
}
template <typename P>
struct Komp2 {
	enum Sposoby2 {
		wg_marki,
		wg_min_pojemnosci,
		wg_min_mocy,
		wg_min_paliwa,
	};
	Komp2(Sposoby2 s, string st="") :sposob(s), str(st) {};
	int operator()(P& a1);
private:
	Sposoby2 sposob;
	string str;
};
template <typename P>
int Komp2<P>::operator() (P& a1) {
	switch (sposob) {
	case wg_marki:
		return (a1.get_marka().compare(str) == 0);

	case wg_min_pojemnosci:
		return (a1.get_silnik()->get_pojemnosc()) < stod(str);

	case wg_min_mocy:
		return (a1.get_silnik()->get_moc()) < stod(str);

	case wg_min_paliwa:
		return (a1.get_bak()->get_stan()) < stod(str);
	}
	return 0;
}
#endif