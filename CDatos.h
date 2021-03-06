#pragma once
#include <iostream>
#include <functional>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <list>
#include "CDatos.h"
#include <vector>

using namespace System;
using namespace std;

template<class G>
class Datos {
private:
	G dato;
	int indice;

public:
	Datos() {}

	Datos(G g) {
		dato = g;
	}

	G GetDato() { return dato; }
	void Set_Dato(G a) { dato = a; }
	int get_indice() { return indice; }
	void Set_Indice(int a) { indice = a; }
};

