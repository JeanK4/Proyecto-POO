#include "pasajeros.h"
#include "aeronave.h"
#include "tripulantes.h"

using namespace std;

#ifndef VUELO
#define VUELO

class vuelo{
	private:
		int tipoVuelo;
		string numIdent;
		string fecha;
		string ciudadOrigen;
		string ciudadDestino;
		vector<pasajero> personasAbordo;
		aeronave *aeronaveAsignada;
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
		int getTipoVuelo();
		vector<tripulante> getTripulantesAbordo();
		/* sets */
		void setNumIdent(string NumID);
		void setFecha(string Fecha);
		void setCiudadOrigen(string COrigen);
		void setCiudadDestino(string CDestino);
		void addPersonasAbordo(pasajero p);
		void setAeronaveAsignada(aeronave *n);
		void addTripulantesAbordo(tripulante t);
		void setTipoVuelo(int x);
};

#endif