/*
Biblioteca de ingreso de datos y validaciones.
*/

#include <stdio.h>
#include <stdlib.h>

/// @brief Funcion que pide el ingreso de un numero entero y lo valida con un minimo.
/// @param mensaje: el mensaje que se mostrara antes de pedir el ingreso.
/// @param error: el mensaje de error en caso de no cumplir con el requerimiento minimo.
/// @param minimo: el limite minimo del numero entero a ingresar.
/// @return Retorna el numero entero ingresado y validado.
int getIntValidado(char* mensaje, char* error, int minimo)
{
	int entero;
    printf(mensaje);
    scanf("%d", &entero);
    while(entero < minimo)
    {
    	printf(error);
    	scanf("%d", &entero);
    }
    return entero;
}

/// @brief Funcion que pide el ingreso de un numero flotante y lo valida con un minimo.
/// @param mensaje: el mensaje que se mostrara antes de pedir el ingreso.
/// @param error: el mensaje de error en caso de no cumplir con el requerimiento minimo.
/// @param minimo: el limite minimo del numero flotante a ingresar.
/// @return Retorna el numero flotante ingresado y validado.
float getFloatValidado(char* mensaje, char* error, int minimo)
{
	float flotante;
	printf(mensaje);
	scanf("%f", &flotante);
	while(flotante < minimo)
	{
		printf(error);
		scanf("%f", &flotante);
	}
	return flotante;
}
