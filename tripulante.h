#include "persona.h"

using namespace std;

#ifndef TRIPULANTE
#define TRIPULANTE

class tripulante : private persona{
	private:
		string puesto;
		int experienciaAños;
		int horasMax;
	public:
		/* gets */
		string getPuesto();
		int getExperienciaAños();
		int getHorasMax();
		/* sets */
		string setPuesto();
		int setExperienciaAños();
		int setHorasMax();
};

#endif