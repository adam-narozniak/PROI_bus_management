#include <iostream>
#include "kierowca.h"
#include "miejsca.h"
#include "Bak.h"
#include "silnik.h"
#include "pasazerowie.h"
#include "virtualna.h"

#ifndef Autobus_H
#define Autobus_H
using namespace std;
class Autobus: public Pojazd {

protected:
	string nr_rej;
	string marka;
	Silnik *silnik;
	Bak *bak;
private:
	Kierowca *kierowca;
	Miejsca *miejsca;
	Pasazerowie *pasazerowie;
	
public:
	//gety
	string get_nr_rej();
	string get_marka();
	Silnik *get_silnik();
	Bak *get_bak();
	Kierowca *get_kierowca();
	Miejsca *get_miejsca();
	Pasazerowie *get_pasazerowie();
	//dla Autobusu
	Autobus(string = "BRAK", string = "BMW", double = 2.2, double = 190, int = 1, double = 40, double = 60, 
		int = 40, int = 90, int = 5, Kierowca * = NULL, Pasazerowie * = NULL);
	~Autobus();
	Autobus(const Autobus &);
	void wczytaj();
	void wyswietl();
	Autobus & operator =(const Autobus &);
	bool operator ==(const Autobus &) const ;
	bool operator ==(const char*) const;
	void jedz();
	void kanar();
	void przerejestruj(const string ="");
	//dla kierowcy
	void dodaj_kierowce(string = "Jan", string = "Nowak", int = 0001);
	Kierowca* stworz_kierowce(string = "Jan", string = "Nowak", int = 0001);
	void przypisz_kierowce(Kierowca * = NULL);
	Kierowca * zamien_kierowce(Kierowca * = NULL);
	//dla pasazerow
	void edytuj_pasazerow(int = 30, int = 24, int = 2);
	Pasazerowie *stworz_pasazerow(int = 30, int = 80, int = 2);
	void przypisz_pasazerow(Pasazerowie * = NULL);
	void dodaj_pasazerow(int = 30, int =24, int =2);
	Autobus & operator --();
	Autobus & operator ++();
	//dla baku
	void tankuj(double = 60.0);
	Autobus & operator !();
	//dla silnika
	bool operator > (const Autobus &) const;
	bool operator < (const Autobus &) const;
	Autobus & operator -();
	void operator <<(Autobus &);
	friend ostream& operator<<(ostream&, const Autobus&);
	friend istream& operator>>(istream&, Autobus&);
	void zapisz(string = "outputa.txt");
	void odczytaj(string = "outputa.txt");

};
#endif
