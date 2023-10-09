#include "vuelo.h"
#include "TorreControl.h"

using namespace std;

#ifndef AEROPUERTO
#define AEROPUERTO

class aeropuerto{
	private:
		vector<vuelo> vuelos;
	public:
		aeropuerto();
		aeropuerto(vector<vuelo> vuelo);
		void reservarVuelo();
		void consultarVuelo();
		void añadirVuelo();
		void consultarPuertas();
};

#endif