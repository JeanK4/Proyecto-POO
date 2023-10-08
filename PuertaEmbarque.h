#include "vuelo.h"
#include <iostream>

#ifndef PUERTAEMBARQUE
#define PUERTAEMBARQUE

using namespace std;

class puertaembarque{
	private:
		bool disponible;
		string identificacion;
		string ubicacion;
		string hora;
		vector<vuelo> historial;
	public:
		puertaembarque();
		/* gets */
		bool getDisponible();
		string getIdentificacion();
		string getUbicacion();
		string getHora();
		vector<vuelo> getHistorial();
		/* sets */
		bool setDisponible();
		string setIdentificacion();
		string setUbicacion();
		string setHora();
		vector<vuelo> setHistorial();
};

#endif