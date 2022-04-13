/*
Biblioteca de calculos matematicos.
*/

#include <stdio.h>
#include <stdlib.h>

/// @brief Funcion que multiplica dos numeros flotantes.
/// @param num1: Numero flotante 1.
/// @param num2: Numero flotante 2.
/// @return Retorna el resultado de la multiplicacion.
float multiplicacionFlotante(float num1, float num2)
{
	float resultado;
	resultado = num1 * num2;
	return resultado;
}

/// @brief Funcion que divide dos numeros flotantes.
/// @param dividendo: Numero flotante dividendo.
/// @param divisor: Numero flotante divisor.
/// @return Retorna el numero flotante, resultado de la division.
float divisionFlotante(float dividendo, float divisor)
{
	float resultado = 0;
	if(divisor != 0)
	{
		resultado = dividendo / divisor;
	}
	else
	{
		printf("Error, division por cero");
	}
	return resultado;
}

/// @brief Funcion que divide un numero flotante por un numero entero.
/// @param dividendo: Numero flotante dividendo.
/// @param divisor: Numero entero divisor.
/// @return Retorna el numero flotante, resultado de la division.
float divisionFlotanteEntero(float dividendo, int divisor)
{
	float resultado = 0;
		if(divisor != 0)
		{
			resultado = dividendo / divisor;
		}
		else
		{
			printf("Error, division por cero");
		}
		return resultado;
}

/// @brief Funcion que calcula el valor absoluto de una resta entre 2 flotantes.
/// @param num1: Numero flotante 1.
/// @param num2: Numero flotante 2.
/// @return Retorna el resultado de la resta con su valor absoluto.
float valorAbsolutoFlotante(float num1, float num2)
{
	float resultado;
	resultado = num1 - num2;
	if(resultado < 0)
	{
		resultado = resultado * -1;
	}
	return resultado;
}
