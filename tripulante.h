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
		tripulante(string Ced, string Nom, string FechNaci, string gender, string address, string telef, string mail,string puest, int Xp, int HM);
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