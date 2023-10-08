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
		string setCedula();
		string setNombre();
		string setFechaNacimiento();
		string setGenero();
		string setDireccion();
		string setTelefono();
		string setCorreo();
};

#endif