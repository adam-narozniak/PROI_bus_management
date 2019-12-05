#include <iostream>
#include <iomanip>
#include <string>
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
void clear();
#endif
