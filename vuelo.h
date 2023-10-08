#include "pasajeros.h"
#include "aeronave.h"
#include "tripulantes.h"

using namespace std;

#ifndef VUELO
#define VUELO

class vuelo{
	private:
		string numIdent;
		string fecha;
		string ciudadOrigen;
		string ciudadDestino;
		vector<pasajero> personasAbordo;
		aeronave aeronaveAsignada;
		vector<tripulante> tripulantesAbordo;
	public: 
		vuelo();
		/* gets */
		string getNumIdent();
		string getFecha();
		string getCiudadOrigen();
		string getCiudadDestino();
		vector<pasajero> getPersonasAbordo();
		aeronave getAeronaveAsignada();
		vector<tripulante> getTripulantesAbordo();
		/* sets */
		string setNumIdent();
		string setFecha();
		string setCiudadOrigen();
		string setCiudadDestino();
		vector<pasajero> setPersonasAbordo();
		aeronave setAeronaveAsignada();
		vector<tripulante> setTripulantesAbordo();
};

#endif