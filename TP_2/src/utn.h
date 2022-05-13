#ifndef UTN_H_
#define UTN_H_

/// @brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de 'longitud - 1' caracteres.
/// @param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida.
/// @param longitud Longitud maxima de la cadena.
/// @return Retorna 0 (SUCCESS) si se obtiene una cadena y -1 (FAILED) si no tuvo exito.
int getString(char* cadena, int longitud);

/// @brief Funcion que obtiene un numero entero y lo valida entre un minimo y maximo, estableciendo la cantidad de intentos.
/// @param pResultado Puntero a variable donde se escribira el valor ingresado en el caso de ser correcto.
/// @param mensaje Puntero a cadena de caracteres con un mensaje a imprimir antes de pedirle al usuario datos por la consola.
/// @param mensajeError Puntero a cadena de caracteres con un mensaje de error en el caso de que el dato ingresado no sea valido.
/// @param minimo Valor minimo admitido (INCLUSIVE).
/// @param maximo Valor maximo admitido (INCLUSIVE).
/// @param reintentos Cantidad de veces que se le volvera a pedir al usuario que ingrese un dato en caso de error.
/// @return Retorna 0 (SUCCESS) si se obtuvo el numero, y -1 (FAILED) si no se pudo obtener el mismo.
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @brief Funcion que pide y valida un caracter.
/// @param pResultado Puntero a la direccion de memoria de una variable donde se guardara el caracter.
/// @param mensaje Mensaje al usuario pidiendo el ingreso de un caracter.
/// @param mensajeError Mensaje de error en caso de que haya ingresado un caracter fuera del rango.
/// @param minimo Rango minimo del caracter (Incluyente).
/// @param maximo Rango maximo del caracter (Incluyente).
/// @param reintentos Numero de reintentos.
/// @return Retorna 0 (SUCCESS) Si se obtuvo el carater con exito, y -1 si se produjo un error o sobre paso el limite de reintentos.
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

/// @brief Funcion que pide el ingreso de un numero flotante y lo valida.
/// @param pResultado Puntero al lugar en memoria de la variable que guardara el numero flotante.
/// @param mensaje Mensaje pidiendole al usuario que ingrese el numero flotante.
/// @param mensajeError Mensaje de error en caso de que ingrese un numero fuera del rango.
/// @param minimo Rango minimo (Incluyente).
/// @param maximo Rango maximo (Incluyente).
/// @param reintentos Numero de reintentos.
/// @return Retorna 0 (SUCCESS) si se obtuvo el numero, y -1 (FAILED) si no se pudo obtener el mismo.
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/// @brief Gets the Flycode form the user.
/// @param flycode Pointer to the array where the result will be saved.
/// @param tam Array length.
/// @return Returns -1 if error (invalid length or NULL pointer), - 0 if Ok.
int getFlyCode(char flycode[], int tam);

/// @brief Adds Style to the string (Uppercase in the first letter and after spaces).
/// @param string String to be modified.
void estilo(char string[]);

/// @brief Gets a Name or LastName from the user, adds Camel Case style to the string.
/// @param name String with the resulting Name/Lastname.
/// @param tam Array length.
/// @return Returns -1 if error (invalid length or NULL pointer), - 0 if Ok.
int getName(char name[], int tam);

#endif /* UTN_H_ */
