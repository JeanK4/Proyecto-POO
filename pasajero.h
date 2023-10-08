#include "persona.h"

using namespace std;

#ifndef PASAJERO
#define PASAJERO

class pasajero : private persona{
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
		string setNacionalidad();
		int setCntMaletas();
		string setInfoMedica();
};

#endif