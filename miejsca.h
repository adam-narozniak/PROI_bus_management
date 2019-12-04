#include <iostream>
using namespace std;
#ifndef Miejsca_H
#define Miejsca_H
class Miejsca {
private:
	int miejsca_normalne;
	int miejsca_stojace;
	int miejsca_rowery;
public:
	Miejsca(int = 40, int = 90, int = 5);
	~Miejsca();
	void wczytaj();
	void wyswietl();
	int get_miejsca_normalne();
	int get_miejsca_stojace();
	int get_miejsca_rowery();
	friend ostream& operator<<(ostream&, const Miejsca&);

};
#endif