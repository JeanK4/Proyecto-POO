# Proyecto-POO - Aeropuerto 
UML - https://github.com/JeanK4/UML/blob/main/ProyectoAeropuerto.drawio

# Manual de Usuario - Sistema de Aeronaves

## Introducción

Bienvenido al Manual de Usuario del Sistema de Aeronaves. Este manual te proporcionará información detallada sobre cómo utilizar el sistema, sus características y funcionalidades. Asegúrate de seguir las instrucciones cuidadosamente para aprovechar al máximo esta aplicación.

## Requisitos del Sistema

Antes de comenzar a utilizar el Sistema de Aeronaves, asegúrate de que tu sistema cumpla con los siguientes requisitos:

- Sistema operativo compatible: Windows, macOS o Linux.

## Interfaz de Usuario

El Sistema de Aeronaves cuenta con una interfaz de usuario intuitiva que te permite navegar fácilmente por las diferentes secciones.

## Funcionalidades Principales

El sistema ofrece varias funcionalidades principales que te permiten gestionar información sobre aeronaves. A continuación, se detallan algunas de las funciones más importantes:

### 1. Registro de Aeronaves

- Descripción: Permite ingresar información detallada sobre una nueva aeronave.
- Pasos para utilizarlo:
    1. Haz clic en "Registrar Aeronave".
    2. Completa los campos obligatorios (marca, modelo, capacidad de pasajeros, etc.).
    3. Guarda la información.

### 2. Consulta de Aeronaves

- Descripción: Permite buscar y ver información sobre aeronaves registradas en el sistema.
- Pasos para utilizarlo:
    1. Accede a la sección "Consulta de Aeronaves".
    2. Utiliza los filtros de búsqueda para encontrar la aeronave deseada.
    3. Visualiza los detalles de la aeronave seleccionada.

### 3. Actualización de Datos

- Descripción: Permite modificar la información de una aeronave existente.
- Pasos para utilizarlo:
    1. Busca la aeronave que deseas actualizar.
    2. Haz clic en "Editar".
    3. Realiza los cambios necesarios en los campos correspondientes.
    4. Guarda los cambios.

## Preguntas Frecuentes

Aquí encontrarás respuestas a algunas preguntas comunes:

1. **¿Cómo puedo agregar una nueva aeronave al sistema?**
    - Para registrar una nueva aeronave, ve a la sección "Registro de Aeronaves" y sigue las instrucciones proporcionadas.

2. **¿Cómo puedo buscar una aeronave específica?**
    - Utiliza la función de "Consulta de Aeronaves" y aplica filtros para encontrar la aeronave que necesitas.


## Inicio de Sesión
Una vez en la página de inicio de sesión, siga estos pasos para acceder a su cuenta:
1. Ingrese su nombre de usuario y contraseña en los campos correspondientes.
2. Haga clic en el botón "Iniciar Sesión".
3. Si los datos son correctos, será redirigido al panel principal del sistema.

## Panel Principal
El panel principal es el centro de control del sistema de reservas de vuelos. Desde aquí, puede realizar diversas acciones, que incluyen:

### Reservar un Vuelo
1. Haga clic en la opción "Reservar Vuelo" en el menú principal.
2. Seleccione el tipo de vuelo que desea reservar (Vuelo Comercial, Vuelo de Carga, Helicóptero, Jet Privado).
3. Siga las instrucciones en pantalla para seleccionar un vuelo disponible y completar la reserva.

### Consultar Vuelo
1. Haga clic en la opción "Consultar Vuelo" en el menú principal.
2. Ingrese el número de vuelo que desea consultar.
3. Obtendrá información detallada sobre ese vuelo, incluida la aeronave asignada.

### Añadir un Vuelo
1. Haga clic en la opción "Añadir Vuelo" en el menú principal.
2. Complete los detalles del nuevo vuelo, incluida la aeronave asignada y la tripulación.
3. Haga clic en "Guardar" para añadir el vuelo al sistema.

## Cierre de Sesión
Para cerrar la sesión en el sistema, siga estos pasos:
1. Haga clic en su nombre de usuario en la esquina superior derecha.
2. Seleccione la opción "Cerrar Sesión" en el menú desplegable.
3. Se le redirigirá a la página de inicio de sesión.


## Clase persona
La clase persona representa a una persona con los siguientes atributos:
- cedula: Identificación de la persona.
- nombre: Nombre de la persona.
- fechaNacimiento`: Fecha de nacimiento de la persona.
- genero: Género de la persona.
- direccion: Dirección de la persona.
- telefono: Número de teléfono de la persona.
- correo: Dirección de correo electrónico de la persona.

### Métodos
#### Constructor
- persona(): Constructor por defecto.

- persona(string Ced, string Nom, string FechNaci, string gender, string address, string telef, string mail): Constructor que permite inicializar todos los atributos de la persona.

#### Métodos "get"
- string getCedula(): Devuelve la cédula de la persona.
- string getNombre(): Devuelve el nombre de la persona.
- string getFechaNacimiento(): Devuelve la fecha de nacimiento de la persona.
- string getGenero(): Devuelve el género de la persona.
- string getDireccion(): Devuelve la dirección de la persona.
- string getTelefono(): Devuelve el número de teléfono de la persona.
- string getCorreo(): Devuelve la dirección de correo electrónico de la persona.

#### Métodos "set"
- void setCedula(string Ced): Establece la cédula de la persona.
- void setNombre(string Nom): Establece el nombre de la persona.
- void setFechaNacimiento(string FechNaci): Establece la fecha de nacimiento de la persona.
- void setGenero(string gender): Establece el género de la persona.
- void setDireccion(string address): Establece la dirección de la persona.
- void setTelefono(string telef): Establece el número de teléfono de la persona.
- void setCorreo(string mail): Establece la dirección de correo electrónico de la persona.

## Clase pasajero
La clase pasajero hereda de la clase persona e incluye atributos adicionales:
- nacionalidad: Nacionalidad del pasajero.
- cntMaletas: Cantidad de maletas del pasajero.
- infoMedica: Información médica del pasajero.


#### Métodos "get"
- string getNacionalidad(): Devuelve la nacionalidad del pasajero.
- int getCntMaletas(): Devuelve la cantidad de maletas del pasajero.
- string getInfoMedica(): Devuelve la información médica del pasajero.

#### Métodos "set"
- void setNacionalidad(string Nacionalidad): Establece la nacionalidad del pasajero.
- void setCntMaletas(int ctMaletas): Establece la cantidad de maletas del pasajero.
- void setInfoMedica(string InfMed): Establece la información médica del pasajero.

## Clase tripulante
La clase tripulante hereda de la clase persona e incluye atributos adicionales:
- puesto: Puesto ocupado por el tripulante.
- experienciaAnos: Experiencia en años del tripulante.
- horasMax: Horas máximas de trabajo del tripulante.

### Métodos
#### Constructor
- tripulante(string Ced, tring Nom, string FechNaci, string gender, string address, string telef, string mail, string puest, int Xp, int HM): Constructor que permite inicializar todos los atributos del tripulante y de la persona a la que pertenece.

#### Métodos "get"
- string getPuesto(): Devuelve el puesto ocupado por el tripulante.
- int getExperienciaAnos(): Devuelve la experiencia en años del tripulante.
- int getHorasMax(): Devuelve las horas máximas de trabajo del tripulante.

#### Métodos "set"
- void setPuesto(string puesto): Establece el puesto ocupado por el tripulante.
- void setExperienciaAnos(int Xp): Establece la experiencia en años del tripulante.
- void setHorasMax(int HM): Establece las horas máximas de trabajo del tripulante.

## Clase vuelo
La clase vuelo tiene los siguientes atributos:

- hora: Hora del vuelo.
- fecha: Fecha del vuelo.
- tipoVuelo: Tipo de vuelo.
- altitud: Altitud del vuelo.
- idPuerta: Identificación de la puerta de embarque.
- numIdent: Número de identificación del vuelo.
- ciudadOrigen: Ciudad de origen del vuelo.
- ciudadDestino: Ciudad de destino del vuelo.
- aeronaveAsignada: Puntero a la aeronave asignada al vuelo.
- personasAbordo: Vector que almacena pasajeros a bordo.
- tripulantesAbordo: Vector que almacena tripulantes a bordo.

### Métodos
#### Constructor
- vuelo(): Constructor por defecto que inicializa algunos atributos y genera una altitud aleatoria para el vuelo.

#### Métodos "get"
- string getNumIdent(): Devuelve el número de identificación del vuelo.
- int getAltitud(): Devuelve la altitud del vuelo.
- string getFecha(): Devuelve la fecha del vuelo.
- string getHora(): Devuelve la hora del vuelo.
- string getCiudadOrigen(): Devuelve la ciudad de origen del vuelo.
- string getCiudadDestino(): Devuelve la ciudad de destino del vuelo.
- vector<pasajero> getPersonasAbordo(): Devuelve un vector con los pasajeros a bordo.
- aeronave* getAeronaveAsignada(): Devuelve un puntero a la aeronave asignada al vuelo.
- int getTipoVuelo(): Devuelve el tipo de vuelo.
- string getIdPuerta(): Devuelve la identificación de la puerta de embarque.
- vector<tripulante> getTripulantesAbordo(): Devuelve un vector con los tripulantes a bordo.

#### Métodos "set"
- void setNumIdent(string NumID): Establece el número de identificación del vuelo.
- void setFecha(string Fecha): Establece la fecha del vuelo.
- void setHora(string hour): Establece la hora del vuelo.
- void setCiudadOrigen(string COrigen): Establece la ciudad de origen del vuelo.
- void setCiudadDestino(string CDestino): Establece la ciudad de destino del vuelo.
- void addPersonasAbordo(pasajero p): Agrega un pasajero a bordo del vuelo.
- void setAeronaveAsignada(aeronave *n): Establece la aeronave asignada al vuelo.
- void addTripulantesAbordo(tripulante t): Agrega un tripulante a bordo del vuelo.
- void setTipoVuelo(int x): Establece el tipo de vuelo.
- void setIdPuerta(string identificacion): Establece la identificación de la puerta de embarque.

## Clase torreControl
La clase torreControl tiene los siguientes atributos y métodos:

### Atributos
- instance: Instancia única de la clase torreControl.
- Puertas: Vector que almacena objetos de la clase puertaembarque.

### Métodos
- static torreControl* getInstance(): Obtiene la instancia única de la clase torreControl.
- void asignarPuerta(): Asigna una puerta de embarque a un vuelo disponible.
- void iniciarVuelo(string numIdent): Inicia un vuelo previamente asignado a una puerta de embarque.
- void addPuerta(puertaembarque puerta): Agrega una puerta de embarque al vector de puertas disponibles.
- void finalizarVuelo(string numIdent): Finaliza un vuelo y libera la puerta de embarque.
- void solicitarAltitud(string numIdent): Solicita la altitud de un vuelo en curso.
- void consultarPuertas(): Muestra el estado de las puertas de embarque disponibles.


## Clase usuario
La clase usuario tiene los siguientes atributos y métodos:

### Atributos
- nickname: Nombre de usuario (nickname).
- password: Contraseña del usuario.

### Métodos
- usuario(): Constructor por defecto.
- void setNickname(string name): Establece el nombre de usuario (nickname).
- void setPassword(string pass): Establece la contraseña del usuario.
- string getNickname(): Devuelve el nombre de usuario (nickname).
- string getPassword(): Devuelve la contraseña del usuario.


## Clase puertaembarque
La clase puertaembarque tiene los siguientes atributos y métodos:

### Atributos
- disponible: Indica si la puerta de embarque está disponible o no.
- identificacion: Número de identificación de la puerta de embarque.
- ubicacion: Ubicación de la puerta de embarque en el aeropuerto.
- hora: Hora de asignación de la puerta de embarque.
- vueloAsignado: Puntero al vuelo asignado a la puerta de embarque.
- historial: Vector que almacena el historial de vuelos asignados a la puerta de embarque.

### Métodos
- puertaembarque(): Constructor por defecto.
- puertaembarque(string id, string ubi): Constructor que inicializa la identificación y ubicación de la puerta de embarque.
- void addHistorial(vuelo fly): Agrega un vuelo al historial de vuelos asignados.
- bool getDisponible(): Devuelve si la puerta de embarque está disponible o no.
- string getIdentificacion(): Devuelve la identificación de la puerta de embarque.
- string getUbicacion(): Devuelve la ubicación de la puerta de embarque.
- string getHora(): Devuelve la hora de asignación de la puerta de embarque.
- vuelo* getVuelo(): Devuelve un puntero al vuelo asignado a la puerta de embarque.
- vector<vuelo> getHistorial(): Devuelve el historial de vuelos asignados.
- void setDisponible(bool estado): Establece si la puerta de embarque está disponible o no.
- void setIdentificacion(string ID): Establece la identificación de la puerta de embarque.
- void setUbicacion(string Ubicacion): Establece la ubicación de la puerta de embarque.
- void setHora(string Hora): Establece la hora de asignación de la puerta de embarque.
- void setVuelo(vuelo* fly): Establece el vuelo asignado a la puerta de embarque.
