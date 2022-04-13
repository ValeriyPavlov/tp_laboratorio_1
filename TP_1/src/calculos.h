/*
Headers de la biblioteca de calculos.c
*/

#ifndef CALCULOS_H_
#define CALCULOS_H_

/// @brief Funcion que calcula el valor absoluto de una resta entre 2 flotantes.
/// @param num1: Numero flotante 1.
/// @param num2: Numero flotante 2.
/// @return Retorna el resultado de la resta con su valor absoluto.
float valorAbsolutoFlotante(float num1, float num2);

/// @brief Funcion que multiplica dos numeros flotantes.
/// @param num1: Numero flotante 1.
/// @param num2: Numero flotante 2.
/// @return Retorna el resultado de la multiplicacion.
float multiplicacionFlotante(float num1, float num2);

/// @brief Funcion que divide dos numeros flotantes.
/// @param dividendo: Numero flotante dividendo.
/// @param divisor: Numero flotante divisor.
/// @return Retorna el numero flotante, resultado de la division.
float divisionFlotante(float dividendo, float divisor);

/// @brief Funcion que divide un numero flotante por un numero entero.
/// @param dividendo: Numero flotante dividendo.
/// @param divisor: Numero entero divisor.
/// @return Retorna el numero flotante, resultado de la division.
float divisionFlotanteEntero(float dividendo, int divisor);

#endif /* CALCULOS_H_ */
