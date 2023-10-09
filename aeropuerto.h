#include "vuelo.h"

using namespace std;

#ifndef AEROPUERTO
#define AEROPUERTO

class aeropuerto{
	private:
		static vector<vuelo> vuelos;
	public:
		aeropuerto();
		aeropuerto(vector<vuelo> vuelo);
		void reservarVuelo();
		void consultarVuelo();
		void anadirVuelo();
		static vector<vuelo>& getVuelos();
};

#endif