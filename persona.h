#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef PERSONA
#define PERSONA

class persona{
	private:
		string cedula;
		string nombre;
		string fechaNacimiento;
		string genero;
		string direccion;
		string telefono;
		string correo;
	public:
		/* gets */
		string getCedula();
		string getNombre();
		string getFechaNacimiento();
		string getGenero();
		string getDireccion();
		string getTelefono();
		string getCorreo();
		/* sets */
		void setCedula(string Ced);
		void setNombre(string Nom);
		void setFechaNacimiento(string FechNaci);
		void setGenero(string gender);
		void setDireccion(string address);
		void setTelefono(string telef);
		void setCorreo(string mail);
};

#endif