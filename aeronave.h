#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef AERONAVE
#define AERONAVE

class aeronave{
	private:
		/************
		* ATRIBUTOS *
		************/
		string marca;
		int modelo;
		int capacidadPasajeros;
		int velocidadMaxima;
		int autonomia;
		int añoFabricacion;
		int estado;
	public:
		aeronave();
		/* gets */
		string getMarca();
		int getModelo();
		int getCapacidadPasajeros();
		int getVelocidadMaxima();
		int getAutonomia();
		int getAñoFabricacion();
		int getEstado();
		/* sets */
		void setMarca(string Marca);
		void setModelo(int model);
		void setCapacidadPasajeros(int capPasajeros);
		void setVelocidadMaxima(int velM);
		void setAutonomia(int autonomia);
		void setAñoFabricacion(int yF);
		void setEstado(int S);
};

class avion : private aeronave{
	private:
		string altitudMax;
		int cantMotores;
		int categoria;
	public:
		avion();
		avion(string marca, int model, int capacidadP, int velocidadM, int autonomia, int añoF, int est, string altM, int cntM, int categ);
		/* gets */
		string getAltitudMax();
		int getCantMotores();
		int getCategoria();
		
		/* sets */
		void setAltitudMax(string AltM);
		void setCantMotores(int ctM);
		void setCategoria(int Categ);
		
};

class helicoptero : private aeronave{
	private:
		int cntRotores;
		string capacidadElevacion;
		int uso;
	public:
		helicoptero();
		helicoptero(string marca, int model, int capacidadP, int velocidadM, int autonomia, int añoF, int est, int cntR, string capE, int uso);
		/* gets */
		int getCntRotores();
		string getCapacidadElevacion();
		int getUso();

		/* sets */
		void setCntRotores(int rotores);
		void setCapacidadElevacion(string capElev);
		void setUso(int uso);
};

class jets : private aeronave{
	private:
		string propietario;
		vector<string> servicios;
		vector<string> destinosFrec;
	public:
		jets();
		jets(string marca, int model, int capacidadP, int velocidadM, int autonomia, int añoF, int est, string propietario, vector<string> services ,vector<string> destinosFrec);
		/* gets */
		string getPropietario();
		vector<string> getServicios();
		vector<string> getDestinosFrec();
		/* sets */
		void setPropietario(string p);
		void setServicios(vector<string> s);
		void setDestinosFrec(vector<string> d);
};

#endif