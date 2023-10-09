#include "persona.h"

using namespace std;

#ifndef PASAJERO
#define PASAJERO

class pasajero : public persona{
	private:
		string nacionalidad;
		int cntMaletas;
		string infoMedica;
	public:
		/* gets */
		string getNacionalidad();
		int getCntMaletas();
		string getInfoMedica();
		/* sets */
		void setNacionalidad(string Nacionalidad);
		void setCntMaletas(int ctMaletas);
		void setInfoMedica(string InfMed);
};

#endif