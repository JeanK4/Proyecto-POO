#include "vuelo.h"

using namespace std;

#ifndef AEROPUERTO
#define AEROPUERTO

class aeropuerto{
	private:
		vector<vuelo> vuelos;
	public:
		aeropuerto();
		aeropuerto(vector<vuelo> vuelos);
		void reservarVuelo();
		void consultarVuelo();
		void añadirVuelo();
};

#endif