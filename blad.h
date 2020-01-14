#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>
#include <sstream> 

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
#ifndef Blad_H
#define Blad_H
using namespace std;
struct Blad {
	virtual string opis() = 0;

};
#endif