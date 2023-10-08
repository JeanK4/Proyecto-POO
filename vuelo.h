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
		void setNumIdent(string NumID);
		void setFecha(string Fecha);
		void setCiudadOrigen(string COrigen);
		void setCiudadDestino(string CDestino);
		void setPersonasAbordo(vector<pasajero> p);
		void setAeronaveAsignada(aeronave n);
		void setTripulantesAbordo(vector<tripulante> t);
};

#endif