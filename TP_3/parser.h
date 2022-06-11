
/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param path char* Puntero al la direccion del archivo.
 * \param pArrayListPassenger LinkedList* Puntero a la Linked List de los pasajeros.
 * \return Retorna 0 en caso de parseo exitoso y -1 en caso de error.
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
 * \param path char* Puntero al la direccion del archivo.
 * \param pArrayListPassenger LinkedList* Puntero a la Linked List de los pasajeros.
 * \return Retorna 0 en caso de parseo exitoso y -1 en caso de error.
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

/// @brief Carga los pasajeros de la linked list a un archivo de texto/csv.
/// @param pFile Puntero al la direccion del archivo.
/// @param pArrayListPassenger  Puntero a la Linked List de los pasajeros.
/// @return Retorna 0 en caso de carga exitosa y -1 en caso de error.
int parser_PassengerToText(FILE* pFile, LinkedList* pArrayListPassenger);

/// @brief Carga los pasajeros de la linked list a un archivo binario/.data.
/// @param pFile Puntero al la direccion del archivo.
/// @param pArrayListPassenger  Puntero a la Linked List de los pasajeros.
/// @return Retorna 0 en caso de carga exitosa y -1 en caso de error.
int parser_PassengerToBinary(FILE* pFile, LinkedList* pArrayListPassenger);

/// @brief Lee el ultimo id del archivo y lo devuelve en tipos Int y char[];
/// @param pFile Puntero al la direccion del archivo.
/// @param idString Puntero a la direccion de memoria donde guardara el id en formato char[].
/// @param idInt Puntero a la direccion de memoria donde guardara el id en formato int.
/// @return Retorna 0 Si pudo obtener el ultimo ID y -1 en caso de error.
int parser_id(FILE* pFile, char* idString, int* idInt);

/// @brief Escribe el proximo id al archivo.
/// @param pFile Puntero al la direccion del archivo.
/// @param id Es el proximo ID que se utilizara para cuando ingresen un nuevo pasajero.
/// @return Retorna 0 en caso de escritura exitosa y -1 en caso de error.
int parser_idToText(FILE* pFile, int id);
