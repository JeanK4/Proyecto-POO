#include "persona.h"

using namespace std;

#ifndef TRIPULANTE
#define TRIPULANTE

class tripulante : public persona{
	private:
		string puesto;
		int experienciaAnos;
		int horasMax;
	public:
		/* gets */
		string getPuesto();
		int getExperienciaAnos();
		int getHorasMax();
		/* sets */
		void setPuesto(string puesto);
		void setExperienciaAnos(int Xp);
		void setHorasMax(int HM);
};

#endif