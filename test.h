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
void menu_autobus(Autobus &);
void menu_samochod(Samochod &);
void menu_sam_wys(Sam_wyscigowy&);
void tablica_pojazd();
void vector_iterator_sort();
void vector_find();
template <typename P>
struct Komp {
	enum Sposoby {
		wg_rejestracji,
		wg_pojemnosci,
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
		return (a1.get_nr_rej().compare(a2.get_nr_rej())) > 0;

	case wg_pojemnosci:
		return (a1.get_silnik()->get_pojemnosc()) > (a2.get_silnik()->get_pojemnosc());

		return 0;
	}
}
template <typename P1, typename P2>
bool czy_rejestracja(const P1 &p1, const P2 &p2) {
	return !((p1.get_nr_rejestracji().compare(p2)) == 0);
}
#endif
