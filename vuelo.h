#include "pasajero.h"
#include "aeronave.h"
#include "tripulante.h"

using namespace std;

#ifndef VUELO
#define VUELO

class vuelo{
	private:
		int tipoVuelo;
		string numIdent;
		string fecha;
		string hora;
		string idPuerta;
		string ciudadOrigen;
		string ciudadDestino;
		aeronave *aeronaveAsignada;
		vector<pasajero> personasAbordo;
		vector<tripulante> tripulantesAbordo;
	public:
		vuelo();
		void recibirMensaje();
		void enviarAltitud();
		/* gets */
		string getNumIdent();
		string getFecha();
		string getHora();
		string getCiudadOrigen();
		string getCiudadDestino();
		vector<pasajero> getPersonasAbordo();
		aeronave* getAeronaveAsignada();
		int getTipoVuelo();
		string getIdPuerta();
		vector<tripulante> getTripulantesAbordo();
		/* sets */
		void setNumIdent(string NumID);
		void setFecha(string Fecha);
		void setHora(string hour);
		void setCiudadOrigen(string COrigen);
		void setCiudadDestino(string CDestino);
		void addPersonasAbordo(pasajero p);
		void setAeronaveAsignada(aeronave *n);
		void addTripulantesAbordo(tripulante t);
		void setTipoVuelo(int x);
		void setIdPuerta(string identificacion);
};

#endif