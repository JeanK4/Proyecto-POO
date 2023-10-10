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
		tripulante(std::string Ced, std::string Nom, std::string FechNaci, std::string gender, std::string address, std::string telef, std::string mail,std::string puest, int Xp, int HM);
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