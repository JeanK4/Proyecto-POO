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
		void setDisponible(bool estado);
		void setIdentificacion(string ID);
		void setUbicacion(string Ubicacion);
		void setHora(string Hora);
		void setHistorial(vector<vuelo> historial);
};

#endif