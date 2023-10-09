#include "aeropuerto.h"
#include <limits> 
#include <stdexcept>
#include <set>
#include <algorithm>

aeropuerto::aeropuerto(){

}

aeropuerto::aeropuerto(vector<vuelo> vuelo){
	vuelos = vuelo;
}

void aeropuerto::reservarVuelo(){
	int opcion;
	cout << "1. Vuelo Comercial" << endl;
	cout << "2. Vuelo de Carga" << endl;
	cout << "3. Helicoptero" << endl;
	cout << "4. Jet Privado" << endl;
	bool entradaValida = false;
	do{
		cin >> "Ingrese su opcion: " >> opcion;
		if(cin.fail() || opcion > 5 || opcion < 1){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cerr << "Error: Entrada inválida. Por favor, ingrese un número entero válido." << endl;
        } 
        else{
        	entradaValida = true;
        }

	}while(!entradaValida);
	for(int i = 0; i < vuelos.size(); i++){
		aeronave *tmp = vuelo[i].getAeronaveAsignada(); /* variable tipo puntero de la clase aeronave */
		if(tmp->getCapacidadPasajeros() > 0 && tmp->getCtVuelos() < 3 && vuelos[i].getTipoVuelo() == opcion){
			cout << i++ << ". " <<"Vuelo #" << tmp->numIdent << "está programado para " << tmp->fecha << "con ciudad de origen " << tmp->ciudadOrigen << "y ciudad de destino " << tmp->ciudadDestino << endl; 
		}
		else if(i == vuelos.size()){
			cout << "No hay vuelos disponibles" << endl;
		}
	}
	int numvuelo;
	entradaValida = false;
	do{
		cout << "Seleccione un vuelo" << endl;
		cin >> numvuelo;
		if(cin.fail() || opcion < 0 || opcion >= vuelos.size()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cerr << "Error: Entrada inválida. Por favor, ingrese un número entero." << endl;
        } 
        else{
        	entradaValida = true;
        }

	}while(!entradaValida);
	numvuelo--;
	tmp = vuelos[numvuelo].getAeronaveAsignada();
	int tmp2 = tmp->getCapacidadPasajeros(); /* variable de tipo entero temporal */
	tmp->setCapacidadPasajeros(tmp2--);
	if(tmp->getCapacidadPasajeros() == 0){
		tmp->setEstado(2);
		tmp2 = tmp->getCtVuelos();
		tmp->setCtVuelos(tmp2++);
	}
	pasajero personita;
	string tmp3; /* Tmp3 es una variable tipo string temporal para recibir los datos del usuario*/
	cin >> "Ingrese su cedula: " >> tmp3;
	personita.setCedula(tmp3);
	cin >> "Ingrese su nombre: " >> tmp3;
	personita.setNombre(tmp3);
	cin >> "Ingrese su fecha nacimiento: " >> tmp3;
	personita.setFechaNacimiento(tmp3);
	cin >> "Ingrese su género: " >> tmp3;
	personita.setGenero(tmp3);
	cin >> "Ingrese su dirección: " >> tmp3;
	personita.setDireccion(tmp3);
	cin >> "Ingrese su teléfono: " >> tmp3;
	personita.setTelefono(tmp3);
	cin >> "Ingrese su correo: " >> tmp3;
	personita.setCorreo(tmp3);
	cin >> "Ingrese su nacionalidad: " >> tmp3;
	personita.setNacionalidad(tmp3);
	cin >> "Ingrese su Informacion Medica: " >> tmp3;
	personita.setInfoMedica(tmp3);
	cin >> "Ingrese su cantidad de maletas: " >> tmp2;
	personita.setCntMaletas(tmp2);
}

void aeropuerto::consultarVuelo(){
	string numvuelo;
	int i = 0;
	bool flag = false;
	cin >> "Ingrese un numero de vuelo: " >> numvuelo;
	while(i < vuelos.size() && !flag){
		if(vuelos[i].getNumIdent() == numvuelo){
			flag = true;
			cout << "Numero de Vuelo: " << vuelos[i].getNum() << endl;
			cout << "Ciudad de Origen: " << vuelos[i].getCiudadOrigen() << endl;
			cout << "Ciudad de Destino: " << vuelos[i].getCiudadDestino() << endl;
			cout << "Fecha del Vuelo: " <<vuelos[i].getFecha() << endl;
		}
		i++;
	}
}

void aeropuerto::consultarPuertas(){
	for(int i = 0; i < Puertas.size(); i++){
		cout << "Puerta #" << Puertas[i].getIdentificacion() << ": ";
		if(Puertas[i].getDisponible())
			cout << "Disponible, ";
		else
			cout << "No Disponible, ";
		cout << "Ubicacion: " << Puertas[i].getUbicacion() << endl;
	}
}

void aeropuerto::añadirVuelo(){
	vuelo flight;
	int opcion, tmp; /* variable temporal tipo entero para el switch y variable auxiliar tipo entero para los atributos del avión*/
	string tmp1; /* varibale temporal tipo string */
	cin >> "Digite el tipo de vuelo: 1. Vuelo Comercial\n2. Vuelo de Carga\n3. Helicoptero\n4. Jet Privado\n" >> tmp;
	flight.setTipoVuelo(tmp);
	aeronave *tmp3; /* variable temporal tipo puntero aeronave */
	switch(opcion){
        case 1:
        	avion AvionComercial;
            cin >> "Ingrese la marca del avion: " >> tmp1;
            AvionComercial.setMarca(tmp1);

            cin >> "Ingrese el modelo del avion: " >> tmp;
            AvionComercial.setModelo(tmp);

            cin >> "Ingrese la cantidad de asientos del avion: " >> tmp;
            AvionComercial.setCapacidadPasajeros(tmp);

            cin >> "Ingrese la velocidad maxima del avion: " >> tmp;
            AvionComercial.setVelocidadMaxima(tmp);

            cin >> "Ingrese la autonomia avion: " >> tmp;
            AvionComercial.setAutonomia(tmp);

            cin >> "Ingrese ano de fabricacion del avion: " >> tmp;
            AvionComercial.setAñoFabricacion(tmp);

            AvionComercial.setEstado(1);

            AvionComercial.setCtVuelos(0);

            cin >> "Ingrese la altitud Maxima del avion: " >> tmp1;
            AvionComercial.setAltitudMax(tmp1);

            cin >> "Ingrese la cantidad de motores del avion: " >> tmp;
            AvionComercial.setCantMotores(tmp);

            tmp3 = &AvionComercial;
            break;
        case 2:
            avion AvionCarga;
            cin >> "Ingrese la marca del avion: " >> tmp1;
            AvionCarga.setMarca(tmp1);

            cin >> "Ingrese el modelo del avion: " >> tmp;
            AvionCarga.setModelo(tmp);

            cin >> "Ingrese la cantidad de asientos del avion: " >> tmp;
            AvionCarga.setCapacidadPasajeros(tmp);

            cin >> "Ingrese la velocidad maxima del avion: " >> tmp;
            AvionCarga.setVelocidadMaxima(tmp);

            cin >> "Ingrese la autonomia avion: " >> tmp;
            AvionCarga.setAutonomia(tmp);

            cin >> "Ingrese ano de fabricacion del avion: " >> tmp;
            AvionCarga.setAñoFabricacion(tmp);

            AvionCarga.setEstado(1);

            AvionCarga.setCtVuelos(0);

            cin >> "Ingrese la altitud Maxima del avion: " >> tmp1;
            AvionComercial.setAltitudMax(tmp1);

            cin >> "Ingrese la cantidad de motores del avion: " >> tmp;
            AvionComercial.setCantMotores(tmp);

            tmp3 = &AvionCarga;
            break;
        case 3:  
            helicoptero heli;

            cin >> "Ingrese la marca del helicoptero: " >> tmp1;
            heli.setMarca(tmp1);

            cin >> "Ingrese el modelo del helicoptero: " >> tmp;
            heli.setModelo(tmp);

            cin >> "Ingrese la cantidad de asientos del helicoptero: " >> tmp;
            heli.setCapacidadPasajeros(tmp);

            cin >> "Ingrese la velocidad maxima del helicoptero: " >> tmp;
            heli.setVelocidadMaxima(tmp);

            cin >> "Ingrese la autonomia helicoptero: " >> tmp;
            heli.setAutonomia(tmp);

            cin >> "Ingrese ano de fabricacion del helicoptero: " >> tmp;
            heli.setAñoFabricacion(tmp);

            heli.setEstado(1);

            heli.setCtVuelos(0);

            cin >> "Ingrese la cantidad de rotores del helicoptero: " >> tmp;
            heli.setCntRotores(tmp);

            cin >> "Ingrese la capacidad de elevacion del helicoptero: " >> tmp1;
            heli.setCapacidadElevacion(tmp1);

            cin >> "Digite el tipo de uso: 1. Rescate\n2. Turismo\n3. Transporte\n4. Medicina\n" >> tmp;
 			heli.setUso(tmp);

            tmp3 = &heli;
        case 4:
            jets jet;

            cin >> "Ingrese la marca del helicoptero: " >> tmp1;
            jet.setMarca(tmp1);

            cin >> "Ingrese el modelo del helicoptero: " >> tmp;
            jet.setModelo(tmp);

            cin >> "Ingrese la cantidad de asientos del helicoptero: " >> tmp;
            jet.setCapacidadPasajeros(tmp);

            cin >> "Ingrese la velocidad maxima del helicoptero: " >> tmp;
            jet.setVelocidadMaxima(tmp);

            cin >> "Ingrese la autonomia helicoptero: " >> tmp;
            jet.setAutonomia(tmp);

            cin >> "Ingrese ano de fabricacion del helicoptero: " >> tmp;
            jet.setAñoFabricacion(tmp);

            jet.setEstado(1);

            jet.setCtVuelos(0);

            cin >> "Ingrese el nombre del propietario del jet: " >> tmp1;
            jet.setPropietario(tmp1);

            bool flag = false;
            while(!flag){
            	cin >> "Digite el tipo de uso: 1. Bar\n2. Entretenimiento VIP\n3. Dormitorio privado\n4. Chef privado\n5. Salir\n" >> tmp;
            	set<string> servicios;
            	if(tmp == 5)
            		flag = true;
            	else if(tmp == 1)
            		servicios.insert("Bar");
            	else if(tmp == 2)
					servicios.insert("Entretenimiento VIP");
            	else if(tmp == 3)
            		servicios.insert("Dormitorio privado");
            	else if(tmp == 4)
            		servicios.insert("Chef privado");
            	else{
            		cout << "Opcion invalida" << endl;
            	}
            }
            vector<string> services(servicios.begin(), servicios.end());
            jet.setServicios(services);

            int ct;
            set<string> destinos;
            cin >> "Digite cuantos destinos frecuentes desea: " >> ct;
            for(int i = 0; i < ct; i++){
            	cin >> "Digite los destinos Frecuentes: \n" >> tmp1;
            	set.insert(tmp1);
            }
            vector<string> destino(destinos.begin(), destinos.end());
            jet.setDestinosFrec(destino);

			tmp3 = &jet;
            break;
        default:
            cout << "Opción inválida." << endl;
            break;
        flight.setAeronaveAsignada(tmp3);
    }
	cin >> "Digite el numero del vuelo: " >> tmp1;
	flight.setnumIdent(tmp1);
	cin >> "Digite la fecha del vuelo: " >> tmp1;
	flight.setFecha(tmp1);
	cin >> "Digite el numero del vuelo: " >> tmp1;
	flight.setCiudadOrigen(tmp1);
	cin >> "Digite el numero del vuelo: " >> tmp1;
	flight.setCiudadDestino(tmp1);
}