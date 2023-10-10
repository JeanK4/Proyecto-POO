#include "aeropuerto.h"
#include <iostream>
#include <string>
#include "TorreControl.h"
#include <windows.h>
#include "usuario.h"

using namespace std;

/* Variables y objetos globales */
aeropuerto elDorado;
torreControl* torreControl::instance = nullptr;


int main(){
	/* Creacion gates aeropuerto */
	torreControl* Tower = torreControl::getInstance();
	puertaembarque Gate1("01","Ala norte");
	Tower->addPuerta(Gate1);
	puertaembarque Gate2("02","Ala este");
	Tower->addPuerta(Gate2);
	puertaembarque Gate3("03","Ala sur");
	Tower->addPuerta(Gate3);
	puertaembarque Gate4("04","Ala oeste");
	Tower->addPuerta(Gate4);

 	/* MENU */
	cout << "----------------------------------------" << endl;
	cout << "  Bienvenido al sistema del Aeropuerto" << endl; 
	cout << "----------------------------------------" << endl;
	cout << endl;
	int opcion1;
	cout << "Elija su opcion: " << endl << endl;
	cout << "1. Crear usuario\n2. Ingresar usuario\n3. Salir\n" << endl;
	cin >> opcion1;
	string np;
	usuario* user = new usuario();
 	while(opcion1 != 3){
 		
 		if(opcion1 == 1){
 			cout << "Digite el nickname para su usuario: " << endl;
 			cin >> np;
			user->setNickname(np);
 			cout << "Digite la contrasena para su usuario: " << endl;
 			cin >> np;
 			user->setPassword(np);
 		}
 		else if(opcion1 == 2){
 			cout << "Login: ";
 			cin >> np;
 			if(user->getNickname() == np){
 				cout << "Password: ";
 				cin >> np;
 				if(user->getPassword() != np)
 					cout << "Contraseña incorrecta" << endl;
 				else{
 					Sleep(2000);
 					system("cls");
 					int opcion;
					int opcion2;
					cout << "Elija su opcion: " << endl << endl;
					cout << "--------------------" << endl;
					cout << "1. Reservar Vuelo\n--------------------\n2. Agregar Vuelo\n--------------------\n3. Consultar Vuelo\n--------------------\n4. Torre de Control\n--------------------\n5. Salir\n--------------------\n\n" << endl;
					cout << "Digite su opcion -> ";
					cin  >> opcion;
					system("cls");
					while(opcion != 5){
						switch(opcion){
						case 1:
							elDorado.reservarVuelo();
							cout << endl << "Vuelo reservado con exito" << endl;
							Sleep(2000);
							system("cls");
							break;
						case 2:
							elDorado.anadirVuelo();
							cout << endl << "Vuelo agregado con exito" << endl;
							Sleep(2000);
							system("cls");
							break;
						case 3:
							elDorado.consultarVuelo();
							break;
						case 4:
							cout << "Que desea realizar: " << endl;
							cout << "1. Pedir altitud a Areonave en vuelo\n2. Consultar puertas de embarque\n3. Asignar puertas\n4. Iniciar vuelo\n5. Finalizar vuelo\n6. Salir" << endl;
							cin >> opcion2;
							system("cls");
							while(opcion2 != 6){
								string nId;
								if(opcion2 == 1){
									cout << "Ingrese el numero de identificacion del vuelo: ";
									cin >> nId;
									Tower->solicitarAltitud(nId);
								}
								else if(opcion2 == 2)
									Tower->consultarPuertas();
								else if(opcion2 == 3)
									Tower->asignarPuerta();
								else if(opcion2 == 4){
									cout << "Ingrese el numero de identificacion del vuelo a inicializar: ";
									cin >> nId;
									Tower->iniciarVuelo(nId);
								}
								else if(opcion2 == 5){
									cout << "Ingrese el numero de identificacion del vuelo a finalizar: ";
									cin >> nId;
									Tower->finalizarVuelo(nId);
								}
								else
									cout << "Opcion invalida" << endl;

								cout << "Que desea realizar: " << endl;
								cout << "1. Pedir altitud a Areonaves en vuelo\n2. Consultar puertas de embarque\n3. Asignar puertas\n4. Iniciar vuelo\n5. Finalizar vuelo\n6. Salir" << endl;
								cin >> opcion2;
								system("cls");
							}
							break;
						default:
							cout << "Opcion invalida" << endl;
							break;
							
						}
						cout << "Elija su opcion: " << endl << endl;
						cout << "--------------------" << endl;
						cout << "1. Reservar Vuelo\n--------------------\n2. Agregar Vuelo\n--------------------\n3. Consultar Vuelo\n--------------------\n4. Torre de Control\n--------------------\n5. Salir\n--------------------\n\n" << endl;
						cout << "Digite su opcion -> ";
						cin  >> opcion;
						system("cls");
					}
				}
 			}
 			else
 				cout << "Usuario incorrecto" << endl;
		}
	else
		cout << "Opcion invalida" << endl;
	cout << "Elija su opcion: " << endl << endl;
	cout << "1. Crear usuario\n2. Ingresar usuario\n3. Salir\n" << endl;
	cin >> opcion1;
	}
return 0;
}