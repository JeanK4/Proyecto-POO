#include "aeropuerto.h"
#include <limits> 
#include <stdexcept>
#include <set>
#include <algorithm>

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
	for(int i = 0; i < vuelos.size(); i++){
		cout << opcion << endl;
		aeronave* tmp = vuelos[i].getAeronaveAsignada(); /* variable tipo puntero de la clase aeronave */
		cout << tmp->getCtVuelos() << endl;
		if(tmp->getCapacidadPasajeros() > 0 && tmp->getCtVuelos() < 3 && vuelos[i].getTipoVuelo() == opcion){
			cout << ++i << ". " <<"Vuelo #" << vuelos[i].getNumIdent() << " esta programado para la fecha " << vuelos[i].getFecha() << "con ciudad de origen " << vuelos[i].getCiudadOrigen() << " y ciudad de destino " << vuelos[i].getCiudadDestino() << endl; 
		}
		else if(i == vuelos.size() || vuelos.size() == 0){
			cout << "No hay vuelos disponibles" << endl;
		}
	}
	int numvuelo;
	entradaValida = false;
	do{
		cout << "Seleccione un vuelo" << endl;
		cin >> numvuelo;
		if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cerr << "Error: Entrada inválida. Por favor, ingrese un número entero." << endl;
        } 
        else{
        	entradaValida = true;
        }

	}while(!entradaValida);
	numvuelo--;
	aeronave* tmp = vuelos[numvuelo].getAeronaveAsignada();
	int tmp2 = tmp->getCapacidadPasajeros(); /* variable de tipo entero temporal */
	tmp->setCapacidadPasajeros(tmp2--);
	if(tmp->getCapacidadPasajeros() == 0){
		cout << "entra" << endl;
		tmp->setEstado(2);
		tmp2 = tmp->getCtVuelos() + 1;
		tmp->setCtVuelos(tmp2);
	}
	pasajero personita;
	string tmp3; /* Tmp3 es una variable tipo string temporal para recibir los datos del usuario*/
	cout << "Ingrese su cedula: "; 
	cin >> tmp3;
	cout << endl;
	personita.setCedula(tmp3);
	cout << "Ingrese su nombre: ";
	cin >> tmp3;
	cout << endl;
	personita.setNombre(tmp3);
	cout << "Ingrese su fecha nacimiento: ";
	cin >> tmp3;
	cout << endl;
	personita.setFechaNacimiento(tmp3);
	cout << "Ingrese su género: ";
	cin >> tmp3;
	cout << endl;
	personita.setGenero(tmp3);
	cout << "Ingrese su dirección: ";
	cin >> tmp3;
	cout << endl;
	personita.setDireccion(tmp3);
	cout << "Ingrese su teléfono: ";
	cin >> tmp3;
	cout << endl;
	personita.setTelefono(tmp3);
	cout << "Ingrese su correo: ";
	cin >> tmp3;
	cout << endl;
	personita.setCorreo(tmp3);
	cout << "Ingrese su nacionalidad: ";
	cin >> tmp3;
	cout << endl;
	personita.setNacionalidad(tmp3);
	cout << "Ingrese su Informacion Medica: ";
	cin >> tmp3;
	cout << endl;
	personita.setInfoMedica(tmp3);
	cout << "Ingrese su cantidad de maletas: ";
	cin >> tmp2;
	cout << endl;
	personita.setCntMaletas(tmp2);
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
			cout << "Fecha del Vuelo: " <<vuelos[i].getFecha() << endl;
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
	cout << endl;
	flight.setTipoVuelo(opcion);
	aeronave *tmp3; /* variable temporal tipo puntero aeronave */
	switch(opcion){
	    case 1: {
		    avion AvionComercial;
		    cout << "Ingrese la marca del avion: ";
		    cin >> tmp1;
		    AvionComercial.setMarca(tmp1);

		    cout << "Ingrese el modelo del avion: ";
		    cin >> tmp;
		    AvionComercial.setModelo(tmp);

		    cout << "Ingrese la cantidad de asientos del avion: ";
		    cin >> tmp;
		    AvionComercial.setCapacidadPasajeros(tmp);

		    cout << "Ingrese la velocidad maxima del avion: ";
		    cin >> tmp;
		    AvionComercial.setVelocidadMaxima(tmp);

		    cout << "Ingrese la autonomia avion: ";
		    cin >> tmp;
		    AvionComercial.setAutonomia(tmp);

		    cout << "Ingrese ano de fabricacion del avion: ";
		    cin >> tmp;
		    AvionComercial.setAnoFabricacion(tmp);

		    AvionComercial.setEstado(1);

		    AvionComercial.setCtVuelos(0);

		    cout << "Ingrese la altitud Maxima del avion: ";
		    cin >> tmp1;
		    AvionComercial.setAltitudMax(tmp1);

		    cout << "Ingrese la cantidad de motores del avion: ";
		    cin >> tmp;
		    AvionComercial.setCantMotores(tmp);

		    tmp3 = &AvionComercial;

		    break;
		}
        case 2:{
		    avion AvionCarga;

		    cout << "Ingrese la marca del avion: ";
		    cin >> tmp1;
		    AvionCarga.setMarca(tmp1);

		    cout << "Ingrese el modelo del avion: ";
		    cin >> tmp;
		    AvionCarga.setModelo(tmp);

		    cout << "Ingrese la cantidad de asientos del avion: ";
		    cin >> tmp;
		    AvionCarga.setCapacidadPasajeros(tmp);

		    cout << "Ingrese la velocidad maxima del avion: ";
		    cin >> tmp;
		    AvionCarga.setVelocidadMaxima(tmp);

		    cout << "Ingrese la autonomia avion: ";
		    cin >> tmp;
		    AvionCarga.setAutonomia(tmp);

		    cout << "Ingrese ano de fabricacion del avion: ";
		    cin >> tmp;
		    AvionCarga.setAnoFabricacion(tmp);

		    AvionCarga.setEstado(1);

		    AvionCarga.setCtVuelos(0);

		    

		    cout << "Ingrese la altitud Maxima del avion: ";
		    cin >> tmp1;
		    AvionCarga.setAltitudMax(tmp1);

		    cout << "Ingrese la cantidad de motores del avion: ";
		    cin >> tmp;
		    AvionCarga.setCantMotores(tmp);

		    tmp3 = &AvionCarga;

		    break;
		}
        case 3:{
		    helicoptero heli;

		    cout << "Ingrese la marca del helicoptero: ";
		    cin >> tmp1;
		    heli.setMarca(tmp1);

		    cout << "Ingrese el modelo del helicoptero: ";
		    cin >> tmp;
		    heli.setModelo(tmp);

		    cout << "Ingrese la cantidad de asientos del helicoptero: ";
		    cin >> tmp;
		    heli.setCapacidadPasajeros(tmp);

		    cout << "Ingrese la velocidad maxima del helicoptero: ";
		    cin >> tmp;
		    heli.setVelocidadMaxima(tmp);

		    cout << "Ingrese la autonomia helicoptero: ";
		    cin >> tmp;
		    heli.setAutonomia(tmp);

		    cout << "Ingrese ano de fabricacion del helicoptero: ";
		    cin >> tmp;
		    heli.setAnoFabricacion(tmp);

		    heli.setEstado(1);

		    heli.setCtVuelos(0);

		    cout << "Ingrese la cantidad de rotores del helicoptero: ";
		    cin >> tmp;
		    heli.setCntRotores(tmp);

		    cout << "Ingrese la capacidad de elevacion del helicoptero: ";
		    cin >> tmp1;
		    heli.setCapacidadElevacion(tmp1);

		    cout << "Digite el tipo de uso: 1. Rescate\n2. Turismo\n3. Transporte\n4. Medicina\n";
		    cin >> tmp;
		    heli.setUso(tmp);

		    tmp3 = &heli;

		    break;
		}
        case 4:{
		    jets jet;

		    cout << "Ingrese la marca del jet: ";
		    cin >> tmp1;
		    jet.setMarca(tmp1);

		    cout << "Ingrese el modelo del jet: ";
		    cin >> tmp;
		    jet.setModelo(tmp);

		    cout << "Ingrese la cantidad de asientos del jet: ";
		    cin >> tmp;
		    jet.setCapacidadPasajeros(tmp);

		    cout << "Ingrese la velocidad maxima del jet: ";
		    cin >> tmp;
		    jet.setVelocidadMaxima(tmp);

		    cout << "Ingrese la autonomia del jet: ";
		    cin >> tmp;
		    jet.setAutonomia(tmp);

		    cout << "Ingrese el ano de fabricacion del jet: ";
		    cin >> tmp;
		    jet.setAnoFabricacion(tmp);

		    jet.setEstado(1);

		    jet.setCtVuelos(0);

		    cout << "Ingrese el nombre del propietario del jet: ";
		    cin >> tmp1;
		    jet.setPropietario(tmp1);
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
		    jet.setServicios(services);

		    int ct;
		    set<string> destinos;
		    cout << "Digite cuantos destinos frecuentes desea: ";
		    cin >> ct;
		    for (int i = 0; i < ct; i++) {
		        cout << "Digite los destinos Frecuentes: ";
		        cin >> tmp1;
		        destinos.insert(tmp1);
		    }
		    vector<string> destino(destinos.begin(), destinos.end());
		    jet.setDestinosFrec(destino);

		    tmp3 = &jet;

		    break;
		}
        default:
            cout << "Opcion invalida." << endl;
            break;
        flight.setAeronaveAsignada(tmp3);
    }
	cout << "Digite el numero del vuelo: ";
	cin >> tmp1;
	flight.setNumIdent(tmp1);

	cout << "Digite la fecha del vuelo: ";
	cin >> tmp1;
	flight.setFecha(tmp1);

	cout << "Digite la ciudad de origen del vuelo: ";
	cin >> tmp1;
	flight.setCiudadOrigen(tmp1);

	cout << "Digite la ciudad de destino del vuelo: ";
	cin >> tmp1;
	flight.setCiudadDestino(tmp1);
	vuelos.push_back(flight);
}