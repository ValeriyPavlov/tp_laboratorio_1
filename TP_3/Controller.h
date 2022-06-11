
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param path char* Direccion del archivo a cargar.
 * \param pArrayListPassenger LinkedList* Puntero a la Linked List de los pasajeros.
 * \return Si cargo los datos del archivo retorna 0, de lo contrario retorna -1.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 * \param path char* Direccion del archivo a cargar.
 * \param pArrayListPassenger LinkedList* Puntero a la Linked List de los pasajeros.
 * \return Si cargo los datos del archivo retorna 0, de lo contrario retorna -1.
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/** \brief Alta de pasajero
 * \param pArrayListPassenger LinkedList* Puntero a la Linked List de los pasajeros.
 * \return Si logro realizar el alta retorna 0, de lo contrario retorna -1.
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);

/** \brief Modificar datos de pasajero
 * \param pArrayListPassenger LinkedList* Puntero a la Linked List de los pasajeros.
 * \return Si logro realizar una modificacion retorna 0, de lo contrario retorna -1.
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/** \brief Baja de pasajero
 * \param pArrayListPassenger LinkedList* Puntero a la Linked List de los pasajeros.
 * \return Si logro realizar una baja retorna 0, de lo contrario retorna -1.
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/** \brief Listar pasajeros
 * \param pArrayListPassenger LinkedList* Puntero a la Linked List de los pasajeros.
 * \return Si logro listar pasajeros retorna 0, de lo contrario retorna -1.
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/** \brief Ordenar pasajeros
 * \param pArrayListPassenger LinkedList* Puntero a la Linked List de los pasajeros.
 * \return Si logro ordenar pasajeros retorna 0, de lo contrario retorna -1.
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 * \param path char* Direccion del archivo donde guardara los datos.
 * \param pArrayListPassenger LinkedList* Puntero a la Linked List de los pasajeros.
 * \return Si logro guardar los datos retorna 0, de lo contrario retorna -1.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 * \param path char* Direccion del archivo donde guardara los datos.
 * \param pArrayListPassenger LinkedList* Puntero a la Linked List de los pasajeros.
 * \return Si logro guardar los datos retorna 0, de lo contrario retorna -1.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

