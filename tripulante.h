#include "persona.h"

using namespace std;

#ifndef TRIPULANTE
#define TRIPULANTE

class tripulante : public persona{
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
		void setPuesto(string puesto);
		void setExperienciaAños(int Xp);
		void setHorasMax(int HM);
};

#endif