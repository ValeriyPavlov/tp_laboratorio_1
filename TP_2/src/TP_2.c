/*
Pavlov, Valeriy
Division K
Programacion I - Laboratorio I
Trabajo Practico N°2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayPassenger.h"

#define CANT 2000
#define VACIO 1
#define OCUPADO 0
#define BAJA -1

int main(void) 
{
	setbuf(stdout,NULL);
    int opcion;
    int subOpcion;
	Passenger pasajeros[CANT];
	eFlight vuelos[5];
	
	if(initPassengers(pasajeros, CANT) != 0)
	{
		printf("Error al inicializar la lista de pasajeros.\n");
	}
	if(cargaVuelos(vuelos, 5) != 0)
	{
		printf("Error al cargar la lista de vuelos.\n");
	}
	if(cargaForzada(pasajeros, CANT) != 0)
	{
		printf("Error al cargar la lista de los pasajeros.\n");
	}

	do
	{
		utn_getNumeroInt(&opcion, "\nMENU\n1. Altas  2. Modificar  3. Bajas  4. Informar  5. Salir \nOpcion: ", "Error, reingrese numeros entre 1 y 5: ", 1, 5, 999);
		switch(opcion)
		{
		case 1:
			if(alta(pasajeros, CANT) != 0)
			{
				printf("Error al realizar la alta.\n");
			}
			else
			{
				printf("Se ha cargado un pasajero nuevo.\n");
			}
			break;
		case 2:
			if(existenPasajeros(pasajeros, CANT) > 0)
			{
				if(modificacion(pasajeros, CANT, vuelos, 5) != 0)
				{
					printf("Error al realizar la modificacion.\n");
				}
				else
				{
					printf("Se han modificado los datos del pasajero.\n");
				}
			}
			else
			{
				printf("No hay pasajeros cargados.\n");
			}
			break;
		case 3:
			if(existenPasajeros(pasajeros, CANT) > 0)
			{
				if(baja(pasajeros, CANT, vuelos, 5) == 0)
				{
					printf("Se dio de baja con exito.\n");
				}
				else
				{
					printf("No se pudo dar de baja al pasajero.\n");
				}
			}
			else
			{
				printf("No hay pasajeros cargados.\n");
			}
			break;
		case 4:
			if(existenPasajeros(pasajeros, CANT) > 0)
			{
				utn_getNumeroInt(&subOpcion, "\n1. Listado por Apellido y Tipo  2. Total y Promedio de Precios  3. Lista por Codigo y estado Activo\nOpcion: ", "Error, ingrese numeros entre 1 y 3", 1, 3, 999);
				switch(subOpcion)
				{
				case 1:
					if(sortPassengers(pasajeros, CANT, 1) == 0)
					{
						printPassengers(pasajeros, CANT, vuelos, 5);
					}
					break;
				case 2:
					if(promedios(pasajeros, CANT) != 0)
					{
						printf("Error, no se pudieron calcular los promedios.\n");
					}
					break;
				case 3:
					if(sortPassengersByCode(pasajeros, CANT, 1) == 0)
					{
						listarVuelosActivos(pasajeros, CANT, vuelos, 5);
					}
					break;
				}
			}
			else
			{
				printf("No hay pasajeros cargados.\n");
			}
			break;
		case 5:
			printf("Programa finalizado.");
			break;
		default:
			printf("La opcion elegida es incorrecta.\n");
			break;
		}
	} while(opcion != 5);

	return 0;
}
