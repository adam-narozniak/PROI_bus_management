#include <iostream>
using namespace std;
#ifndef Miejsca_H
#define Miejsca_H
class Miejsca {

	int miejsca_normalne;
	int miejsca_stojace;
	int miejsca_rowery;
	//int miejsca_niepelnosprawni;
public:
	Miejsca(int = 30, int = 80, int = 2);// , int = 0);
	~Miejsca();
	void wczytaj();
	void wyswietl();
	int get_miejsca_normalne();
	int get_miejsca_stojace();
	int get_miejsca_rowery();
};
#endif