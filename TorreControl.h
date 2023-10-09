#include "PuertaEmbarque.h"

#ifndef TORRECONTROL
#define TORRECONTROL

using namespace std;

class torreControl{
	private:
		static torreControl* instance;
		torreControl();
		vector<puertaembarque> Puertas;
	public:
		static torreControl* getInstance();
		/* get */
		vector<puertaembarque> getPuertas();
		/* set */
		void setPuertas(vector<puertaembarque> puertas);
		
};

#endif