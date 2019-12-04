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
	/*Samochod s;
	cout << s << endl;
	s.zapisz();*/
	/*ofstream plik("output.txt");
	plik << s << endl;
	plik.close();*/
	Autobus a1;
	cout << a1 << endl;
	a1.zapisz();


}