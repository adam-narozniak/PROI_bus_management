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
#endif
	//test();
	/*Pojazd * p1 = new Autobus();
	//p1->tankuj();
	p1->wyswietl();
	Pojazd * p2 = new Samochod();
	p2->wyswietl();
	Pojazd * p3 = new Sam_wyscigowy();
	p3->wyswietl();*/
	/*Autobus a1;
	a1.dodaj_kierowce();
	a1.dodaj_pasazerow();
	cout << a1;*/
	/*
	cout << s << endl;
	s.zapisz();*/
	/*Sam_wyscigowy s("WK 00123", "Audi", 1.23, 130, 1, 20, 34);
	ofstream plik1("output.txt");
	plik1 << s << endl;
	plik1.close();
	
	ifstream plik("output.txt");
	Samochod s1;
	plik >> s1;
	plik.close();
	cout << s1 << endl;*/
	/*Autobus a1("WWA 9324", "Mercedes", 2.34, 100,1, 34,80,34,80,6);
	a1.dodaj_kierowce("Jack", "Sparrow",23);
	a1.zapisz();
	Autobus a2;
	a2.dodaj_kierowce();
	ifstream plik("output.txt");
	plik >> a2;
	plik.close();
	cout << a1;
	Pojazd *p[2];
	p[0] = &a1;
	p[1] = &a2;
	p[0]->zapisz("outputa.txt");*/



}