#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "autobus.h"
#include "kierowca.h"
#include "bak.h"
#include "silnik.h"
#include "miejsca.h"
#include "pasazerowie.h"
#include "test.h"
#include "samochod.h"
#include "virtualna.h"
#include "sam_wyscigowy.h"
using namespace std;

int main(void) {
#ifdef _DEBUG
	//test_operatorow();
	//test();
#endif
	tablica_pojazd();
	Sam_wyscigowy w("WK 00123", "Audi", 1.23, 130, 1, 20, 34);
	w.wyswietl();
	//menu();
	/*
	ofstream plik1("outputw.txt");
	plik1 << s << endl;
	plik1.close();
	ifstream plik("outputs.txt");
	Samochod s1;
	plik >> s1;
	plik.close();
	cout << s1 << endl;*/
	/*Autobus a1("WWA 9324", "Mercedes", 2.34, 100, 1, 34, 80, 34, 80, 6);
	a1.dodaj_kierowce("Jack", "Sparrow", 23);
	a1.zapisz();*/
	
}