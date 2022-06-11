#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			if(parser_PassengerFromText(pFile, pArrayListPassenger) == 0)
			{
				retorno = 0;
			}
			fclose(pFile);
		}
	}
    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pFile = NULL;
	if(path != NULL && pArrayListPassenger != NULL )
	{
		pFile = fopen(path, "rb");
		if(pFile != NULL)
		{
			if(parser_PassengerFromBinary(pFile, pArrayListPassenger) == 0)
			{
				retorno = 0;
			}
			fclose(pFile);
		}
	}
    return retorno;
}

int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    char id[9];
    char nombre[51];
    char apellido[51];
    char precio[9];
    char tipoPasajero[20];
    char codigoVuelo[20];
    char estadoVuelo[20];
    Passenger* unPasajero;

    if(pArrayListPassenger != NULL)
    {
    	if(altaPasajero(nombre, apellido, precio, tipoPasajero, codigoVuelo, estadoVuelo) == 0)
    	{
    		alta_id(id);
    		unPasajero = Passenger_newParametros(id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estadoVuelo);
    		if(unPasajero != NULL)
    		{
    			ll_add(pArrayListPassenger, unPasajero);
    			retorno = 0;
    		}
    	}
    }
    return retorno;
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int idIngresado, i, len, id, opcion, tipoInt;
	int index = -1;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	char estadoVuelo[20];
	int estadoVueloInt = 0;
	int correctoN = -1;
	int correctoA = -1;
	Passenger* auxPassenger;
	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		if(utn_getNumeroInt(&idIngresado, "Ingrese el ID de pasajero a modificar: ", "Error, fuera de rango.\n", 1, 10000, 10) == 0)
		{
			len = ll_len(pArrayListPassenger);
			for(i = 0; i < len; i++)
			{
				auxPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(auxPassenger, &id);
				if(id == idIngresado)
				{
					index = i;
					break;
				}
			}
			if(index != -1)
			{
				do
				{
					utn_getNumeroInt(&opcion, "Ingrese que campo desea modificar:\n1. Nombre\n2. Apellido\n3. Precio\n4. Tipo de Pasajero\n5. Codigo de Vuelo\n6. Volver al menu principal\nOpcion: ", "Error, fuera de rango.\n", 1, 6, 99);
					switch(opcion)
					{
					case 1:
						printf("Ingrese el Nombre del Pasajero: ");
						correctoN = getName(nombre, 50);
						while(correctoN == -1)
						{
							printf("Error, reingrese Nombre: ");
							correctoN = getName(nombre, 50);
						}
						if(Passenger_setNombre(auxPassenger, nombre) == 0)
						{
							printf("Se modifico el nombre con exito.\n");
							retorno = 0;
						}
						break;
					case 2:
						printf("Ingrese el Apellido del Pasajero: ");
						correctoA = getName(apellido, 50);
						while(correctoA == -1)
						{
							printf("Error, reingrese Apellido: ");
							correctoA = getName(apellido, 50);
						}
						if(Passenger_setApellido(auxPassenger, apellido) == 0)
						{
							printf("Se modifico el apellido con exito.\n");
							retorno = 0;
						}
						break;
					case 3:
						if(utn_getNumeroFlotante(&precio, "Ingrese el nuevo precio: ", "Error, fuera de rango.\n", 1, 999999, 99) == 0)
						{
							if(Passenger_setPrecio(auxPassenger, precio) == 0)
							{
								printf("Se modifico el precio con exito.\n");
								retorno = 0;
							}
						}
						break;
					case 4:
						if(utn_getNumeroInt(&tipoInt, "Ingrese el tipo del pasajero: 1. FirstClass   2. ExecutiveClass   3. EconomyClass: ", "Error, numero fuera de rango, reingrese.\n", 1, 3, 999) == 0)
						{
							if(Passenger_setTipoPasajero(auxPassenger, tipoInt) == 0)
							{
								printf("Se modifico el tipo de pasajero con exito.\n");
								retorno = 0;
							}
						}
						break;
					case 5:
						if(getFlyCode(codigoVuelo, estadoVuelo) == 0)
						{
							estadoVueloInt = estadoVuelo_Str(estadoVuelo);
							if(Passenger_setCodigoVuelo(auxPassenger, codigoVuelo) == 0 &&
							   Passenger_setEstadoVuelo(auxPassenger, estadoVueloInt) == 0)
							{
								printf("Se modificaron el codigo de vuelo y el estado de vuelo con exito.\n");
								retorno = 0;
							}
						}
						break;
					case 6:
						printf("Volviendo al menu principal...\n");
						break;
					}
				}while(opcion != 6);
			}
			else
			{
				printf("No se encontraron coincidencias.\n");
			}
		}
	}
    return retorno;
}

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int idIngresado;
	int id;
	int i;
	int len;
	int index = -1;
	int opcion = 0;
	Passenger* auxPassenger;
	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		if(utn_getNumeroInt(&idIngresado, "Ingrese el ID de pasajero a dar de baja: ", "Error, fuera de rango.\n", 1, 10000, 10) == 0)
		{
			len = ll_len(pArrayListPassenger);
			for(i = 0; i < len; i++)
			{
				auxPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(auxPassenger, &id);
				if(id == idIngresado)
				{
					index = i;
					break;
				}
			}
			if(index != -1)
			{
				utn_getNumeroInt(&opcion, "Esta seguro que desea dar de baja al pasajero seleccionado?\n1. CONFIRMAR\n2. RECHAZAR\nOPCION: ", "Error, fuera de rango.\n", 1, 2, 99);
				if(opcion == 1)
				{
					baja_logica(auxPassenger);
					ll_remove(pArrayListPassenger, i);
					retorno = 0;
				}
				else
				{
					printf("Volviendo al menu principal...\n");
				}
			}
			else
			{
				printf("No se encontraron coincidencias.\n");
			}
		}
	}
    return retorno;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;
	int cantidad, i;
	int retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		cantidad = ll_len(pArrayListPassenger);
		printf("ID:\t\tName:\t  Last Name:  Price:\t  FlyCode:    TypePassenger:  StatusFlight:\n");
		for(i = 0; i < cantidad; i++)
		{
			unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			Passenger_printOne(unPasajero);
			retorno = 0;
		}
	}
    return retorno;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int opcion, criterio;
    if(pArrayListPassenger != NULL)
    {
    	do
    	{
    		utn_getNumeroInt(&opcion, "1. Ordenar por ID\n2. Ordenar por Nombre\n3. Ordenar por Apellido\n4. Ordenar por Precio\n5. Ordenar por Estado de Vuelo\n6. Volver al menu principal.\nOpcion: ", "Error, fuera de rango.\n", 1, 6, 99);
    		if(opcion != 6)
    		{
    			utn_getNumeroInt(&criterio, "Ingrese criterio de ordenamiento (0. ASCENDIENTE | 1. DESCENDIENTE): ", "Error, fuera de rango.\n", 0, 1, 99);
    		}
    		switch(opcion)
    		{
    		case 1:
    			ll_sort(pArrayListPassenger, ordenar_id, criterio);
    			printf("Se ordenaron los pasajeros.\n");
    			opcion = 6;
    			retorno = 0;
    			break;
    		case 2:
    			ll_sort(pArrayListPassenger, ordenar_nombre, criterio);
    			printf("Se ordenaron los pasajeros.\n");
    			opcion = 6;
    			retorno = 0;
    			break;
    		case 3:
    			ll_sort(pArrayListPassenger, ordenar_apellido, criterio);
    			printf("Se ordenaron los pasajeros.\n");
    			opcion = 6;
    			retorno = 0;
    			break;
    		case 4:
    			ll_sort(pArrayListPassenger, ordenar_precio, criterio);
    			printf("Se ordenaron los pasajeros.\n");
    			opcion = 6;
    			retorno = 0;
    			break;
    		case 5:
    			ll_sort(pArrayListPassenger, ordenar_estado, criterio);
    			printf("Se ordenaron los pasajeros.\n");
    			opcion = 6;
    			retorno = 0;
    			break;
    		case 6:
    			printf("Volviendo al menu principal...\n");
    			break;
    		}
    	}while(opcion != 6);
    }
    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(path != NULL)
	{
		FILE* pFile = fopen(path, "w");
		if(pArrayListPassenger != NULL && pFile != NULL)
		{
			if(parser_PassengerToText(pFile, pArrayListPassenger) == 0)
			{
				retorno = 0;
			}
			fclose(pFile);
		}
	}
    return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(path != NULL)
	{
		FILE* pFile = fopen(path, "wb");
		if(pArrayListPassenger != NULL && pFile != NULL)
		{
			if(parser_PassengerToBinary(pFile, pArrayListPassenger) == 0)
			{
				retorno = 0;
			}
			fclose(pFile);
		}
	}
    return retorno;
}

