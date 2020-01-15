#include <iostream>
#include "Bak.h"
#include "silnik.h"
#include "virtualna.h"
#include "samochod.h"
#ifndef Sam_wyscigowy_H
#define Sam_wyscigowy_H
class Sam_wyscigowy : public Samochod {
private:
	string gr_krwi;
public:
	Sam_wyscigowy(string = "BRAK", string = "Mustang", double = 2.5, double = 321, int = 2, double = 57, double = 60, string = "0 Rh-");
	~Sam_wyscigowy();
	Sam_wyscigowy & operator=(const Sam_wyscigowy&);
	void wyswietl();
	void zapisz(string = "outputw.txt");
	void odczytaj(string = "outputw.txt");
	friend ostream& operator<<(ostream&, const Sam_wyscigowy &);
	friend istream& operator>> (istream& str, Sam_wyscigowy &w);
	/*string get_nr_rej();
	Silnik * get_silnik();
	Bak * get_bak();
	string get_marka();*/
};
#endif