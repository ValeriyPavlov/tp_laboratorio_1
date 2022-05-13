#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	char flycode[10];
	int statusFlight;
}eFlight;

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flycode[10];
    int typePassenger;
    int isEmpty;
}Passenger;


/// @brief To indicate that all positions in the array are empty, this function put the flag (isEmpty) in TRUE in all positions of the array.
/// @param list Pointer to array of passengers.
/// @param len Array length.
/// @return Return -1 if error (invalid length or NULL pointer), - 0 if Ok.
int initPassengers(Passenger* list, int len);

/// @brief Checks if there is any empty indexes of the array and if so, returns the first empty index.
/// @param list Pointer to array of passengers.
/// @param len Array length.
/// @return Return -1 if (invalid length or NULL pointer or without free space), or the first empty array index.
int findEmptyPassenger(Passenger* list, int len);

/// @brief Add in a existing list of passengers the values received as parameters in the first empty position.
/// @param list Pointer to array of passengers.
/// @param len Array length.
/// @param id Unique ID of the passenger.
/// @param name First name of the passenger.
/// @param lastName Lastname of the passenger.
/// @param price Price of the flight.
/// @param typePassenger Passenger type.
/// @param flycode Flycode of the flight.
/// @return Return -1 if error (invalid length or NULL pointer or without free space), - 0 if Ok.
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]);

/// @brief Find one passenger by ID and returns the index position in array.
/// @param list Pointer to array of passengers.
/// @param len Array length.
/// @param id ID of the passenger to find.
/// @return Returns the index position of the passenger or -1 if error (invalid length or NULL pointer or passenger not found).
int findPassengerById(Passenger* list, int len, int id);

/// @brief Remove a passenger by ID.
/// @param list Pointer to array of passengers.
/// @param len Array length.
/// @param id ID of the passenger to remove.
/// @return Returns -1 if error (invalid length or NULL pointer or passenger not found), - 0 if Ok.
int removePassenger(Passenger* list, int len, int id);

/// @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order.
/// @param list Pointer to array of passengers.
/// @param len Array length.
/// @param orden [1] UP / [0] DOWN
/// @return Returns -1 if error (invalid length or NULL pointer), - 0 if Ok.
int sortPassengers(Passenger* list, int len, int order);

/// @brief Prints the content of Passenger array.
/// @param list Pointer to array of passengers.
/// @param length Array length.
/// @param listF Pointer to array of flights.
/// @param lenF Array length.
/// @return Returns -1 if error (invalid length or NULL pointer), - 0 if Ok.
int printPassengers(Passenger* list, int length, eFlight* listF, int lenF);

/// @brief Sort the elements in the array of passengers, the argument order indicates UP or DOWN order.
/// @param list Pointer to array of passengers.
/// @param len Array length.
/// @param order [1] indicate UP [0] indicate DOWN.
/// @return Returns -1 if error (invalid length or NULL pointer), - 0 if Ok.
int sortPassengersByCode(Passenger* list, int len, int order);

/// @brief Hardcode of the Flights with their Statuses.
/// @param lista Pointer to array of passengers.
/// @param len Array length.
/// @return Returns -1 if error (invalid length or NULL pointer), - 0 if Ok.
int cargaVuelos(eFlight lista[], int len);

/// @brief Hardcode of the 5 Passengers.
/// @param list Pointer to array of passengers.
/// @param len Array length.
/// @return Returns -1 if error (invalid length or NULL pointer), - 0 if Ok.
int cargaForzada(Passenger* list, int len);

/// @brief Pide datos y los valida para luego realizar una alta de un pasajero.
/// @param list Pointer to array of passengers.
/// @param len Array length.
/// @return Returns -1 if error (invalid length or NULL pointer), - 0 if Ok.
int alta(Passenger* list, int len);

/// @brief Realiza la baja logica de un pasajero (-1).
/// @param lista Pointer to array of passengers.
/// @param tam Array length.
/// @param listaF Pointer to array of flights.
/// @param tamF Array length.
/// @return Returns -1 if error (invalid length or NULL pointer), - 0 if Ok.
int baja(Passenger lista[], int tam, eFlight listaF[], int tamF);

/// @brief Realiza la modificacion de uno de los datos del pasajero.
/// @param lista Pointer to array of passengers.
/// @param tam Array length.
/// @param listaF Pointer to array of flights.
/// @param tamF Array length.
/// @return Returns -1 if error (invalid length or NULL pointer), - 0 if Ok.
int modificacion(Passenger lista[], int tam, eFlight listaF[], int tamF);

/// @brief Calcula y muestra los promedios, totales de precios y pasajeros con precio arriba del primedio.
/// @param lista Pointer to array of passengers.
/// @param tam Array length.
/// @return Returns -1 if error (invalid length or NULL pointer), - 0 if Ok.
int promedios(Passenger lista[], int tam);

/// @brief Lista todos los vuelos con estado "ACTIVO".
/// @param list Pointer to array of passengers.
/// @param length Array length.
/// @param listF Pointer to array of flights.
/// @param lenF Array length.
/// @return Returns -1 if error (invalid length or NULL pointer), - 0 if Ok.
int listarVuelosActivos(Passenger* list, int length, eFlight* listF, int lenF);

/// @brief Chequea que existan pasajeros cargados, para evitar que accedan a las opciones si no los hay.
/// @param lista Pointer to array of passengers.
/// @param tam Array length.
/// @return Returns the number of existing, ACTIVE passengers.
int existenPasajeros(Passenger lista[], int tam);

#endif /* ARRAYPASSENGER_H_ */
