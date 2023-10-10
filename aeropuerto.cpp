#include "aeropuerto.h"
#include <limits> 
#include <stdexcept>
#include <set>
#include <algorithm>
#include "tripulante.h"

aeropuerto::aeropuerto(){

}
vector<vuelo> aeropuerto::vuelos;

vector<vuelo>& aeropuerto::getVuelos() {
    return vuelos;
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
		cout << "Ingrese su opcion: ";
		cin >> opcion;
		if(cin.fail() && opcion > 5 && opcion < 1){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cerr << "Error: Entrada inválida. Por favor, ingrese un número entero válido." << endl;
        } 
        else{
        	entradaValida = true;
        }

	}while(!entradaValida);
	if(vuelos.size() != 0){
		bool permiso = true;
		int x;
		for(int i = 0; i < vuelos.size(); i++){
			if(vuelos[i].getAeronaveAsignada()->getCapacidadPasajeros() > 0 && vuelos[i].getAeronaveAsignada()->getCtVuelos() < 3 && vuelos[i].getTipoVuelo() == opcion){
				x = i+1;
				permiso = false;
				cout << x << ". " <<"Vuelo #" << vuelos[i].getNumIdent() << " esta programado para la fecha " << vuelos[i].getFecha() << " con ciudad de origen " << vuelos[i].getCiudadOrigen() << " y ciudad de destino " << vuelos[i].getCiudadDestino() << endl; 
			}
			else if(i = vuelos.size()-1 && permiso)
				cout << "No hay vuelos libres" << endl;
		}
		if(!permiso){
			int numvuelo;
			entradaValida = false;
			do{
				cout << "Seleccione un vuelo -> ";
				cin >> numvuelo;
				if(cin.fail()){
		            cin.clear();
		            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		            cerr << "Error: Entrada invalida. Por favor, ingrese un número entero." << endl;
		        } 
		        else
		        	entradaValida = true;
			}while(!entradaValida);
			numvuelo--;
			aeronave* tmp = vuelos[numvuelo].getAeronaveAsignada();
			int tmp2 = tmp->getCapacidadPasajeros() - 1; /* variable de tipo entero temporal */
			tmp->setCapacidadPasajeros(tmp2);
			if(tmp->getCapacidadPasajeros() == 0){
				tmp->setEstado(2);

				tmp2 = tmp->getCtVuelos() + 1;
				tmp->setCtVuelos(tmp2);
			}
			pasajero usuario;
			string tmp3; /* Tmp3 es una variable tipo string temporal para recibir los datos del usuario*/
			cout << "Ingrese su cedula: "; 
			cin >> tmp3;
			cout << endl;
			usuario.setCedula(tmp3);
			cout << "Ingrese su nombre: ";
			cin >> tmp3;
			cout << endl;
			usuario.setNombre(tmp3);
			cout << "Ingrese su fecha nacimiento: ";
			cin >> tmp3;
			cout << endl;
			usuario.setFechaNacimiento(tmp3);
			cout << "Ingrese su genero: ";
			cin >> tmp3;
			cout << endl;
			usuario.setGenero(tmp3);
			cout << "Ingrese su direccion: ";
			cin >> tmp3;
			cout << endl;
			usuario.setDireccion(tmp3);
			cout << "Ingrese su telefono: ";
			cin >> tmp3;
			cout << endl;
			usuario.setTelefono(tmp3);
			cout << "Ingrese su correo: ";
			cin >> tmp3;
			cout << endl;
			usuario.setCorreo(tmp3);
			cout << "Ingrese su nacionalidad: ";
			cin >> tmp3;
			cout << endl;
			usuario.setNacionalidad(tmp3);
			cout << "Ingrese su Informacion Medica: ";
			cin >> tmp3;
			cout << endl;
			usuario.setInfoMedica(tmp3);
			cout << "Ingrese su cantidad de maletas: ";
			cin >> tmp2;
			cout << endl;
			usuario.setCntMaletas(tmp2);
		}
	}
	else
		cout << "No hay vuelos disponibles" << endl;
	
}

void aeropuerto::consultarVuelo(){
	string numvuelo;
	int i = 0;
	bool flag = false;
	cout << "Ingrese un numero de vuelo: ";
	cin  >> numvuelo;
	cout << endl;
	while(i < vuelos.size() && !flag){
		if(vuelos[i].getNumIdent() == numvuelo){
			flag = true;
			cout << "Numero de Vuelo: " << vuelos[i].getNumIdent() << endl;
			cout << "Ciudad de Origen: " << vuelos[i].getCiudadOrigen() << endl;
			cout << "Ciudad de Destino: " << vuelos[i].getCiudadDestino() << endl;
			cout << "Fecha del Vuelo: " << vuelos[i].getFecha() << endl;
			cout << "Marca Aeronave: " << vuelos[i].getAeronaveAsignada()->getMarca() << endl;
			cout << "Modelo Aeronave: " << vuelos[i].getAeronaveAsignada()->getModelo() << endl << endl;
		}
		i++;
	}
}
	    
void aeropuerto::anadirVuelo(){
	vuelo flight;
	int opcion, tmp; /* variable temporal tipo entero para el switch y variable auxiliar tipo entero para los atributos del avión*/
	string tmp1; /* varibale temporal tipo string */
	cout << "Digite el tipo de vuelo: \n1. Vuelo Comercial\n2. Vuelo de Carga\n3. Helicoptero\n4. Jet Privado\n";
	cin >> opcion;
	flight.setTipoVuelo(opcion);
	int x = 0;
	aeronave* tmp3 = nullptr;
	if(vuelos.size() == 0){
		switch(opcion){
		    case 1: {
	            avion* AvionComercial = new avion(); 

	            cout << "Ingrese la marca del avion(texto): ";
	            cin >> tmp1;
	            AvionComercial->setMarca(tmp1);

	            cout << "Ingrese el modelo del avion(numero): ";
	            cin >> tmp;
	            AvionComercial->setModelo(tmp);

	            cout << "Ingrese la cantidad de asientos del avion: ";
	            cin >> tmp;
	            AvionComercial->setCapacidadPasajeros(tmp);

	            cout << "Ingrese la velocidad maxima del avion(numero): ";
	            cin >> tmp;
	            AvionComercial->setVelocidadMaxima(tmp);

	            cout << "Ingrese la autonomia avion(numero): ";
	            cin >> tmp;
	            AvionComercial->setAutonomia(tmp);

	            cout << "Ingrese ano de fabricacion del avion(numero): ";
	            cin >> tmp;
	            AvionComercial->setAnoFabricacion(tmp);

	            AvionComercial->setEstado(1);

	            AvionComercial->setCtVuelos(x);

	            cout << "Ingrese la altitud Maxima del avion(numero): ";
	            cin >> tmp1;
	            AvionComercial->setAltitudMax(tmp1);

	            cout << "Ingrese la cantidad de motores del avion(numero): ";
	            cin >> tmp;
	            AvionComercial->setCantMotores(tmp);

	            tmp3 = AvionComercial; 

	            break;
	        }
			case 2: {
			    avion *AvionCarga = new avion();

			    cout << "Ingrese la marca del avion(texto): ";
			    cin >> tmp1;
			    AvionCarga->setMarca(tmp1);

			    cout << "Ingrese el modelo del avion(numero): ";
			    cin >> tmp;
			    AvionCarga->setModelo(tmp);

			    cout << "Ingrese la cantidad de asientos del avion: ";
			    cin >> tmp;
			    AvionCarga->setCapacidadPasajeros(tmp);

			    cout << "Ingrese la velocidad maxima del avion(numero): ";
			    cin >> tmp;
			    AvionCarga->setVelocidadMaxima(tmp);

			    cout << "Ingrese la autonomia avion(numero): ";
			    cin >> tmp;
			    AvionCarga->setAutonomia(tmp);

			    cout << "Ingrese ano de fabricacion del avion(numero): ";
			    cin >> tmp;
			    AvionCarga->setAnoFabricacion(tmp);

			    AvionCarga->setEstado(1);

			    AvionCarga->setCtVuelos(x);

			    cout << "Ingrese la altitud Maxima del avion(numero): ";
			    cin >> tmp1;
			    AvionCarga->setAltitudMax(tmp1);

			    cout << "Ingrese la cantidad de motores del avion(numero): ";
			    cin >> tmp;
			    AvionCarga->setCantMotores(tmp);

			    tmp3 = AvionCarga;

			    break;
			}
	        case 3: {
			    helicoptero *heli = new helicoptero();

			    cout << "Ingrese la marca del helicoptero(texto): ";
			    cin >> tmp1;
			    heli->setMarca(tmp1);

			    cout << "Ingrese el modelo del helicoptero(numero): ";
			    cin >> tmp;
			    heli->setModelo(tmp);

			    cout << "Ingrese la cantidad de asientos del helicoptero: ";
			    cin >> tmp;
			    heli->setCapacidadPasajeros(tmp);

			    cout << "Ingrese la velocidad maxima del helicoptero(numero): ";
			    cin >> tmp;
			    heli->setVelocidadMaxima(tmp);

			    cout << "Ingrese la autonomia helicoptero(numero): ";
			    cin >> tmp;
			    heli->setAutonomia(tmp);

			    cout << "Ingrese ano de fabricacion del helicoptero(numero): ";
			    cin >> tmp;
			    heli->setAnoFabricacion(tmp);

			    heli->setEstado(1);

			    heli->setCtVuelos(x);

			    cout << "Ingrese la cantidad de rotores del helicoptero(numero): ";
			    cin >> tmp;
			    heli->setCntRotores(tmp);

			    cout << "Ingrese la capacidad de elevacion del helicoptero(numero): ";
			    cin >> tmp1;
			    heli->setCapacidadElevacion(tmp1);

			    cout << "Digite el tipo de uso: 1. Rescate\n2. Turismo\n3. Transporte\n4. Medicina\n";
			    cin >> tmp;
			    heli->setUso(tmp);

			    tmp3 = heli;

			    break;
			}
	        case 4: {
			    jets *jet = new jets(); // Crear un objeto jets en el heap usando new

			    cout << "Ingrese la marca del jet(texto): ";
			    cin >> tmp1;
			    jet->setMarca(tmp1);

			    cout << "Ingrese el modelo del jet(numero): ";
			    cin >> tmp;
			    jet->setModelo(tmp);

			    cout << "Ingrese la cantidad de asientos del jet: ";
			    cin >> tmp;
			    jet->setCapacidadPasajeros(tmp);

			    cout << "Ingrese la velocidad maxima del jet(numero): ";
			    cin >> tmp;
			    jet->setVelocidadMaxima(tmp);

			    cout << "Ingrese la autonomia del jet(numero): ";
			    cin >> tmp;
			    jet->setAutonomia(tmp);

			    cout << "Ingrese el ano de fabricacion del jet(numero): ";
			    cin >> tmp;
			    jet->setAnoFabricacion(tmp);

			    jet->setEstado(1);

			    jet->setCtVuelos(x);

			    cout << "Ingrese el nombre del propietario del jet(texto): ";
			    cin >> tmp1;
			    jet->setPropietario(tmp1);

			    set<string> servicios;
			    bool flag = false;
			    while (!flag) {
			        cout << "Digite el tipo de uso: 1. Bar\n2. Entretenimiento VIP\n3. Dormitorio privado\n4. Chef privado\n5. Salir\n";
			        cin >> tmp;
			        if (tmp == 5)
			            flag = true;
			        else if (tmp == 1)
			            servicios.insert("Bar");
			        else if (tmp == 2)
			            servicios.insert("Entretenimiento VIP");
			        else if (tmp == 3)
			            servicios.insert("Dormitorio privado");
			        else if (tmp == 4)
			            servicios.insert("Chef privado");
			        else {
			            cout << "Opcion invalida" << endl;
			        }
			    }
		    vector<string> services(servicios.begin(), servicios.end());
		    jet->setServicios(services);

		    int ct;
		    set<string> destinos;
		    cout << "Digite cuantos destinos frecuentes desea(numero): ";
		    cin >> ct;
		    for (int i = 0; i < ct; i++) {
		        cout << "Digite los destinos Frecuentes(texto): ";
		        cin >> tmp1;
		        destinos.insert(tmp1);
		    }

		    vector<string> destino(destinos.begin(), destinos.end());
		    jet->setDestinosFrec(destino);

		    tmp3 = jet; // Asignar el puntero al objeto creado en el heap

		    break;
		}
        default:
            cout << "Opcion invalida." << endl;
            break;
        }
    }
    else{
    	bool naveAsignada = false;
	    auto it = vuelos.begin();
	    while(!naveAsignada && it != vuelos.end()){
	        if (opcion == it->getTipoVuelo() && it->getAeronaveAsignada()->getCtVuelos() < 3) {
	            flight.setAeronaveAsignada(it->getAeronaveAsignada());
	            int z = it->getAeronaveAsignada()->getCtVuelos();
	            it->getAeronaveAsignada()->setCtVuelos(z);
	            naveAsignada = true;
	        }
	        ++it;
	    }
	    if(!naveAsignada) {
	        cout << "No hay naves disponibles con menos de 3 vuelos del tipo seleccionado, por favor, crea una nueva nave." << endl;
	        if(opcion == 1){
	            avion *AvionComercial = new avion(); 

	            cout << "Ingrese la marca del avion(texto): ";
	            cin >> tmp1;
	            AvionComercial->setMarca(tmp1);

	            cout << "Ingrese el modelo del avion(numero): ";
	            cin >> tmp;
	            AvionComercial->setModelo(tmp);

	            cout << "Ingrese la cantidad de asientos del avion: ";
	            cin >> tmp;
	            AvionComercial->setCapacidadPasajeros(tmp);

	            cout << "Ingrese la velocidad maxima del avion(numero): ";
	            cin >> tmp;
	            AvionComercial->setVelocidadMaxima(tmp);

	            cout << "Ingrese la autonomia avion(numero): ";
	            cin >> tmp;
	            AvionComercial->setAutonomia(tmp);

	            cout << "Ingrese ano de fabricacion del avion(numero): ";
	            cin >> tmp;
	            AvionComercial->setAnoFabricacion(tmp);

	            AvionComercial->setEstado(1);

	            AvionComercial->setCtVuelos(x);

	            cout << "Ingrese la altitud Maxima del avion(numero): ";
	            cin >> tmp1;
	            AvionComercial->setAltitudMax(tmp1);

	            cout << "Ingrese la cantidad de motores del avion(numero): ";
	            cin >> tmp;
	            AvionComercial->setCantMotores(tmp);

	            tmp3 = AvionComercial; 

		    }
			else if(opcion == 2){
			    avion *AvionCarga = new avion();

			    cout << "Ingrese la marca del avion(texto): ";
			    cin >> tmp1;
			    AvionCarga->setMarca(tmp1);

			    cout << "Ingrese el modelo del avion(numero): ";
			    cin >> tmp;
			    AvionCarga->setModelo(tmp);

			    cout << "Ingrese la cantidad de asientos del avion: ";
			    cin >> tmp;
			    AvionCarga->setCapacidadPasajeros(tmp);

			    cout << "Ingrese la velocidad maxima del avion(numero): ";
			    cin >> tmp;
			    AvionCarga->setVelocidadMaxima(tmp);

			    cout << "Ingrese la autonomia avion(numero): ";
			    cin >> tmp;
			    AvionCarga->setAutonomia(tmp);

			    cout << "Ingrese ano de fabricacion del avion(numero): ";
			    cin >> tmp;
			    AvionCarga->setAnoFabricacion(tmp);

			    AvionCarga->setEstado(1);

			    AvionCarga->setCtVuelos(x);

			    cout << "Ingrese la altitud Maxima del avion(numero): ";
			    cin >> tmp1;
			    AvionCarga->setAltitudMax(tmp1);

			    cout << "Ingrese la cantidad de motores del avion(numero): ";
			    cin >> tmp;
			    AvionCarga->setCantMotores(tmp);

			    tmp3 = AvionCarga;

			}
	        else if(opcion == 3){
			    helicoptero *heli = new helicoptero();

			    cout << "Ingrese la marca del helicoptero(texto): ";
			    cin >> tmp1;
			    heli->setMarca(tmp1);

			    cout << "Ingrese el modelo del helicoptero(numero): ";
			    cin >> tmp;
			    heli->setModelo(tmp);

			    cout << "Ingrese la cantidad de asientos del helicoptero: ";
			    cin >> tmp;
			    heli->setCapacidadPasajeros(tmp);

			    cout << "Ingrese la velocidad maxima del helicoptero(numero): ";
			    cin >> tmp;
			    heli->setVelocidadMaxima(tmp);

			    cout << "Ingrese la autonomia helicoptero(numero): ";
			    cin >> tmp;
			    heli->setAutonomia(tmp);

			    cout << "Ingrese ano de fabricacion del helicoptero(numero): ";
			    cin >> tmp;
			    heli->setAnoFabricacion(tmp);

			    heli->setEstado(1);

			    heli->setCtVuelos(x);

			    cout << "Ingrese la cantidad de rotores del helicoptero(numero): ";
			    cin >> tmp;
			    heli->setCntRotores(tmp);

			    cout << "Ingrese la capacidad de elevacion del helicoptero(numero): ";
			    cin >> tmp1;
			    heli->setCapacidadElevacion(tmp1);

			    cout << "Digite el tipo de uso: 1. Rescate\n2. Turismo\n3. Transporte\n4. Medicina\n";
			    cin >> tmp;
			    heli->setUso(tmp);

			    tmp3 = heli;

			}
	        else if(opcion == 4){
			    jets *jet = new jets(); // Crear un objeto jets en el heap usando new

			    cout << "Ingrese la marca del jet(texto): ";
			    cin >> tmp1;
			    jet->setMarca(tmp1);

			    cout << "Ingrese el modelo del jet(numero): ";
			    cin >> tmp;
			    jet->setModelo(tmp);

			    cout << "Ingrese la cantidad de asientos del jet: ";
			    cin >> tmp;
			    jet->setCapacidadPasajeros(tmp);

			    cout << "Ingrese la velocidad maxima del jet(numero): ";
			    cin >> tmp;
			    jet->setVelocidadMaxima(tmp);

			    cout << "Ingrese la autonomia del jet(numero): ";
			    cin >> tmp;
			    jet->setAutonomia(tmp);

			    cout << "Ingrese el ano de fabricacion del jet(numero): ";
			    cin >> tmp;
			    jet->setAnoFabricacion(tmp);

			    jet->setEstado(1);

			    jet->setCtVuelos(x);

			    cout << "Ingrese el nombre del propietario del jet(texto): ";
			    cin >> tmp1;
			    jet->setPropietario(tmp1);

			    set<string> servicios;
			    bool flag = false;
			    while (!flag) {
			        cout << "Digite el tipo de uso: 1. Bar\n2. Entretenimiento VIP\n3. Dormitorio privado\n4. Chef privado\n5. Salir\n";
			        cin >> tmp;
			        if (tmp == 5)
			            flag = true;
			        else if (tmp == 1)
			            servicios.insert("Bar");
			        else if (tmp == 2)
			            servicios.insert("Entretenimiento VIP");
			        else if (tmp == 3)
			            servicios.insert("Dormitorio privado");
			        else if (tmp == 4)
			            servicios.insert("Chef privado");
			        else {
			            cout << "Opcion invalida" << endl;
			        }
			    }

		    vector<string> services(servicios.begin(), servicios.end());
		    jet->setServicios(services);

		    int ct;
		    set<string> destinos;
		    cout << "Digite cuantos destinos frecuentes desea(numero): ";
		    cin >> ct;
		    for (int i = 0; i < ct; i++) {
		        cout << "Digite los destinos Frecuentes(texto): ";
		        cin >> tmp1;
		        destinos.insert(tmp1);
		    }

		    vector<string> destino(destinos.begin(), destinos.end());
		    jet->setDestinosFrec(destino);

		    tmp3 = jet;
		}
	    else
	        cout << "Opcion invalida." << endl;
    	}
	}
    /* Creacion Tripulacion */
    tripulante capitan("12345", "Juan", "01/01/1980", "Masculino", "Calle 123", "123456789", "juan@gmail.com", "Capitan", 10, 1000);
	tripulante azafata("67890", "María", "05/12/1992", "Femenino", "Avenida Principal", "987654321", "maria@outlook.com", "Azafata", 5, 800);
	tripulante copiloto("6789", "Carlos", "02/05/1985", "Masculino", "Calle Principal 456", "987654321", "carlos@yahoo.es", "Copiloto", 8, 900);
	tripulante auxiliarDeVuelo("5678", "Laura", "15/09/1990", "Femenino", "Avenida Secundaria 789", "123456789", "laura@gmail.com", "Auxiliar de Vuelo", 6, 850);
    flight.addTripulantesAbordo(capitan);
    flight.addTripulantesAbordo(azafata);
    flight.addTripulantesAbordo(copiloto);
    flight.addTripulantesAbordo(auxiliarDeVuelo);
    flight.setAeronaveAsignada(tmp3);
	cout << "Digite el numero del vuelo: ";
	cin >> tmp1;
	flight.setNumIdent(tmp1);

	cout << "Digite la fecha del vuelo(numero): ";
	cin >> tmp1;
	flight.setFecha(tmp1);

	cout << "Digite la ciudad de origen del vuelo(texto): ";
	cin >> tmp1;
	flight.setCiudadOrigen(tmp1);

	cout << "Digite la ciudad de destino del vuelo(texto): ";
	cin >> tmp1;
	flight.setCiudadDestino(tmp1);
	vuelos.push_back(flight);
}