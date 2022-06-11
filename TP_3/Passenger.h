/*
* Passenger.h
*/

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	int estadoVuelo;
}Passenger;

/// @brief Funcion contructora de pasajeros sin parametros.
/// @return Retorna un puntero a la direccion de memoria dinamica con espacio suficiente para guardar un pasajero.
Passenger* Passenger_new();

/// @brief Funcion contructora de pasajeros con parametros. Recibe los datos del pasajero por parametro en formato char[] y los carga utilizando setters.
/// @param idStr ID del pasajero en formato char[].
/// @param nombreStr Nombre del pasajero en formato char[].
/// @param apellidoStr Apellido del pasajero en formato char[].
/// @param precioStr Precio de vuelo en formato char[].
/// @param tipoPasajeroStr Tipo de pasajero en formato char[].
/// @param codigoVueloStr Codigo de vuelo en formato char[].
/// @param estadoVueloStr Estado de vuelo en formato char[].
/// @return Retorna un puntero al pasajero creado en memoria dinamica, NULL en caso de error.
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr);

/// @brief Destructor del pasajero, libera la memoria de un Pasajero.
/// @param this Puntero al pasajero que destruira.
void Passenger_delete(Passenger* this);

/// @brief Funcion Setter de ID del pasajero.
/// @param this Puntero al pasajero.
/// @param id el ID que se le asignara.
/// @return Retorna 0 si pudo asignar el dato y -1 en caso de error.
int Passenger_setId(Passenger* this, int id);

/// @brief Funcion Getter de ID del pasajero.
/// @param this Puntero al pasajero.
/// @param id puntero a la variable donde guardara el Id obtenido.
/// @return Retorna 0 si pudo obtener el dato y -1 en caso de error.
int Passenger_getId(Passenger* this, int* id);

/// @brief Funcion Setter del nombre del pasajero.
/// @param this Puntero al pasajero.
/// @param nombre Es el Nombre que le asignara.
/// @return Retorna 0 si pudo asignar el dato y -1 en caso de error.
int Passenger_setNombre(Passenger* this, char* nombre);

/// @brief Funcion Getter del nombre del pasajero.
/// @param this Puntero al pasajero.
/// @param nombre Puntero a la variable donde guardara el nombre obtenido.
/// @return Retorna 0 si pudo obtener el dato y -1 en caso de error.
int Passenger_getNombre(Passenger* this, char* nombre);

/// @brief Funcion Setter del apellido del pasajero.
/// @param this Puntero al pasajero.
/// @param apellido Es el apellido que le asignara.
/// @return Retorna 0 si pudo asignar el dato y -1 en caso de error.
int Passenger_setApellido(Passenger* this, char* apellido);

/// @brief Funcion Getter del apellido del pasajero.
/// @param this Puntero al pasajero.
/// @param apellido Puntero a la variable donde guardara el apellido obtenido.
/// @return Retorna 0 si pudo obtener el dato y -1 en caso de error.
int Passenger_getApellido(Passenger* this, char* apellido);

/// @brief Funcion Setter del Codigo de Vuelo.
/// @param this Puntero al pasajero.
/// @param codigoVuelo El codigo que le asignara al pasajero.
/// @return Retorna 0 si pudo asignar el dato y -1 en caso de error.
int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);

/// @brief Funcion Getter del Codigo de Vuelo
/// @param this Puntero al pasajero.
/// @param codigoVuelo Puntero a la variable donde guardara el codigo de vuelo obtenido.
/// @return Retorna 0 si pudo obtener el dato y -1 en caso de error.
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

/// @brief Funcion Setter del Tipo de Pasajero.
/// @param this Puntero al pasajero.
/// @param tipoPasajero El dato del tipo de pasajero que le asignara.
/// @return Retorna 0 si pudo asignar el dato y -1 en caso de error.
int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);

/// @brief Funcion Getter del Tipo de Pasajero
/// @param this Puntero al pasajero.
/// @param tipoPasajero Puntero a la variable donde guardara el dato obtenido.
/// @return Retorna 0 si pudo obtener el dato y -1 en caso de error.
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);

/// @brief Funcion Setter del Precio.
/// @param this Puntero al pasajero.
/// @param precio El precio que le asignara.
/// @return Retorna 0 si pudo asignar el dato y -1 en caso de error.
int Passenger_setPrecio(Passenger* this, float precio);

/// @brief Funcion Getter del Precio.
/// @param this Puntero al pasajero.
/// @param precio Puntero a la variable donde guardara el precio obtenido.
/// @return Retorna 0 si pudo obtener el dato y -1 en caso de error.
int Passenger_getPrecio(Passenger* this, float* precio);

/// @brief Funcion Setter del Estado de Vuelo.
/// @param this Puntero al pasajero.
/// @param estadoVuelo Es el estado de vuelo que le asignara al pasajero.
/// @return Retorna 0 si pudo asignar el dato y -1 en caso de error.
int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);

/// @brief Funcion Getter del Estado de Vuelo.
/// @param this Puntero al pasajero.
/// @param estadoVuelo Puntero a la variable donde guardara el estado de vuelo obtenido.
/// @return Retorna 0 si pudo obtener el dato y -1 en caso de error.
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);

/// @brief Imprime UN pasajero por consola.
/// @param unPasajero Puntero al pasajero a imprimir.
void Passenger_printOne(Passenger* unPasajero);

/// @brief Funcion simple que transforma el tipo de pasajero del formato char[] a un entero.
/// @param tipoStr Puntero al tipo de pasajero.
/// @return Retorna 1 si es "FirstClass", 2 si es "ExecutiveClass", 3 si es "EconomyClass" y -1 en caso de error.
int tipoPasajero_Str(char* tipoStr);

/// @brief Funcion simple que transforma el tipo de pasajero del formato int a un char[].
/// @param tipo Tipo de pasajero en formato Int.
/// @param tipoStr Puntero a la variable donde guardara el resultado.
/// @return Retorna 0 en caso de exito y -1 si se produjo un error.
int tipoPasajero_Int(int tipo, char* tipoStr);

/// @brief Funcion simple que transforma el estado de vuelo del formato char[] a un entero.
/// @param estadoVuelo Puntero al estado de vuelo de un pasajero.
/// @return Retorna 1 si el estado es "En Horario", 2 si es "Aterrizado", 3 si es "En Vuelo", 4 si es "Demorado", 0 si no se encontraron coincidencias y -1 en caso de error.
int estadoVuelo_Str(char* estadoVuelo);

/// @brief Funcion simple que transforma el estado de vuelo de formato Int a char[].
/// @param estadoVueloInt Estado de vuelo con tipo entero.
/// @param estadoVueloStr Puntero a la variable donde guardara el resultado.
/// @return Retorna 0 en caso de exito y -1 si se produjo un error.
int estadoVuelo_Int(int estadoVueloInt, char* estadoVueloStr);

/// @brief Pide datos (del tipo char[]) al usuario para realizar una alta de pasajero.
/// @param nombre Puntero a la variable donde guardara el nombre del pasajero.
/// @param apellido Puntero a la variable donde guardara el apellido del pasajero.
/// @param precio Puntero a la variable donde guardara el precio.
/// @param tipoPasajero Puntero a la variable donde guardara el tipo de pasajero.
/// @param codigoVuelo Puntero a la variable donde guardara el codigo de vuelo.
/// @param estadoVuelo Puntero a la variable donde guardara el estado de vuelo.
/// @return Retorna 0 en caso de exito y -1 si se produjo un error.
int altaPasajero(char* nombre, char* apellido, char* precio, char* tipoPasajero, char* codigoVuelo, char* estadoVuelo);

/// @brief Realiza la baja logica de un pasajero, guardando los datos en un archivo.
/// @param unPasajero Puntero al pasajero que se dara de baja.
/// @return Retorna 0 en caso de haber realizado la baja con exito y -1 en caso de error.
int baja_logica(Passenger* unPasajero);

/// @brief Compara dos pasajeros mediante sus IDs.
/// @param pPassengerOne Puntero al primer pasajero.
/// @param pPassengerTwo Puntero al segundo pasajero.
/// @return Retorna 1 si el primero es menor que el segundo, 0 si son iguales y -1 en caso de error.
int ordenar_id(void* pPassengerOne, void* pPassengerTwo);

/// @brief Compara dos pasajeros mediante sus Nombres.
/// @param pPassengerOne Puntero al primer pasajero.
/// @param pPassengerTwo Puntero al segundo pasajero.
/// @return Retorna 1 si el primero es menor que el segundo, 0 si son iguales y -1 en caso de error.
int ordenar_nombre(void* pPassengerOne, void* pPassengerTwo);

/// @brief Compara dos pasajeros mediante sus Apellidos.
/// @param pPassengerOne Puntero al primer pasajero.
/// @param pPassengerTwo Puntero al segundo pasajero.
/// @return Retorna 1 si el primero es menor que el segundo, 0 si son iguales y -1 en caso de error.
int ordenar_apellido(void* pPassengerOne, void* pPassengerTwo);

/// @brief Compara dos pasajeros mediante sus precios.
/// @param pPassengerOne Puntero al primer pasajero.
/// @param pPassengerTwo Puntero al segundo pasajero.
/// @return Retorna 1 si el primero es menor que el segundo, 0 si son iguales y -1 en caso de error.
int ordenar_precio(void* pPassengerOne, void* pPassengerTwo);

/// @brief Compara dos pasajeros mediante sus estados de vuelo.
/// @param pPassengerOne Puntero al primer pasajero.
/// @param pPassengerTwo Puntero al segundo pasajero.
/// @return Retorna 1 si el primero es menor que el segundo, 0 si son iguales y -1 en caso de error.
int ordenar_estado(void* pPassengerOne, void* pPassengerTwo);

/// @brief Controla el archivo de de los IDs
/// @param idString Puntero donde guardara el ultimo ID en formato "char[]".
/// @return Si logro leer y escribir el id retornara 1, de lo contrario retornara 0, y en caso de error retornara -1.
int alta_id(char* idString);

#endif /* PASSENGER_H_ */
