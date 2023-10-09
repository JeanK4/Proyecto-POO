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
		vuelo* vueloAsignado;
		vector<vuelo> historial;
	public:
		puertaembarque();
		puertaembarque(string id, string ubi);
		void addHistorial(vuelo fly);
		/* gets */
		bool getDisponible();
		string getIdentificacion();
		string getUbicacion();
		string getHora();
		vuelo* getVuelo();
		vector<vuelo> getHistorial();
		/* sets */
		void setDisponible(bool estado);
		void setIdentificacion(string ID);
		void setUbicacion(string Ubicacion);
		void setHora(string Hora);
		void setVuelo(vuelo* fly);
		
};

#endif