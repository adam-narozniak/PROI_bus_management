#include <iostream>
using namespace std;
#ifndef Pasazerowie_H
#define Pasazerowie_H
class Pasazerowie {

	int n_pasazerow;
	int n_z_biletami;
	int n_rowerow;;
public:
	Pasazerowie(int = 30, int = 24, int = 2);
	~Pasazerowie();
	void wczytaj();
	void wyswietl();
	void edytuj(int = 30, int = 24, int = 2);

	int get_n_pasazerow();
	int get_n_z_biletami();
	int get_n_rowerow();
};
#endif