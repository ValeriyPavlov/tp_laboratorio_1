#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	char id[20];
	char nombre[60];
	char apellido[60];
	char precio[20];
	char estadoVuelo[30];
	char tipoPasajero[30];
	char codigoVuelo[20];

	Passenger* unPasajero;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
			if(strlen(id) < 9 && strlen(nombre) < 51 && strlen(apellido) < 51 && strlen(precio) < 9 && strlen(codigoVuelo) < 21 && strlen(tipoPasajero) < 21 && strlen(estadoVuelo) < 21)
			{
				unPasajero = Passenger_newParametros(id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estadoVuelo);
				if(unPasajero != NULL)
				{
					ll_add(pArrayListPassenger, unPasajero);
				}
			}
		}
		retorno = 0;
	}
    return retorno;
}

int parser_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* unPasajero;
	int fin;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			unPasajero = Passenger_new();
			fin = fread(unPasajero, sizeof(Passenger), 1, pFile);
			if(unPasajero != NULL && fin == 1)
			{
				ll_add(pArrayListPassenger, unPasajero);
			}
		}while(!feof(pFile));
		retorno = 0;
	}
	return retorno;
}

int parser_PassengerToText(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int len, i;
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	int tipoPasajeroInt;
	char tipoPasajeroStr[20];
	char codigoVuelo[20];
	char estadoVuelo[20];
	int statusFlight;
	Passenger* unPasajero;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);
		fprintf(pFile, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for(i = 0; i < len; i++)
		{
			unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			if(unPasajero != NULL)
			{
				if(
					Passenger_getId(unPasajero, &id) == 0 &&
					Passenger_getNombre(unPasajero, nombre) == 0 &&
					Passenger_getApellido(unPasajero, apellido) == 0 &&
					Passenger_getPrecio(unPasajero, &precio) == 0 &&
					Passenger_getCodigoVuelo(unPasajero, codigoVuelo) == 0 &&
					Passenger_getEstadoVuelo(unPasajero, &statusFlight) == 0 &&
					Passenger_getTipoPasajero(unPasajero, &tipoPasajeroInt) == 0 &&
					tipoPasajero_Int(tipoPasajeroInt, tipoPasajeroStr) == 0 &&
					estadoVuelo_Int(statusFlight, estadoVuelo) == 0)
					{
						fprintf(pFile, "%d,%s,%s,%.0f,%s,%s,%s\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajeroStr, estadoVuelo);
					}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int parser_PassengerToBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int len, i;
	Passenger* unPasajero = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);
		for(i = 0; i < len; i++)
		{
			unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			if(unPasajero != NULL)
			{
				fwrite(unPasajero, sizeof(Passenger), 1, pFile);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int parser_id(FILE* pFile, char* idString, int* idInt)
{
	int retorno = -1;
	char buffer[10];
	if(pFile != NULL && idString != NULL)
	{
		fscanf(pFile, "%[^\n]", buffer);
		strcpy(idString, buffer);
		*idInt = atoi(buffer);
		retorno = 0;
	}
	return retorno;
}

int parser_idToText(FILE* pFile, int id)
{
	int retorno = -1;
	if(pFile != NULL)
	{
		fprintf(pFile, "%d\n", id);
		retorno = 0;
	}
	return retorno;
}
