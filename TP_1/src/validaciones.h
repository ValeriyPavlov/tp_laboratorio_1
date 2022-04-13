/*
Headers de la biblioteca de validaciones.c
*/

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/// @brief Funcion que pide el ingreso de un numero entero y lo valida con un minimo.
/// @param mensaje: el mensaje que se mostrara antes de pedir el ingreso.
/// @param error: el mensaje de error en caso de no cumplir con el requerimiento minimo.
/// @param minimo: el limite minimo del numero entero a ingresar.
/// @return Retorna el numero entero ingresado y validado.
int getIntValidado(char*, char*, int);

/// @brief Funcion que pide el ingreso de un numero flotante y lo valida con un minimo.
/// @param mensaje: el mensaje que se mostrara antes de pedir el ingreso.
/// @param error: el mensaje de error en caso de no cumplir con el requerimiento minimo.
/// @param minimo: el limite minimo del numero flotante a ingresar.
/// @return Retorna el numero flotante ingresado y validado.
float getFloatValidado(char*, char*, int);

#endif /* VALIDACIONES_H_ */
