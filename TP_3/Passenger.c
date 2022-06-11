#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"


Passenger* Passenger_new()
{
	Passenger* unPasajero = NULL;
	unPasajero = (Passenger*)malloc(sizeof(Passenger));
	return unPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr)
{
	Passenger* unPasajero = NULL;
	unPasajero = Passenger_new();
	int banderaPasajero = 0;
	if(unPasajero != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL && estadoVueloStr != NULL)
	{
		if(Passenger_setId(unPasajero, atoi(idStr)) == 0)
		{
			if(Passenger_setNombre(unPasajero, nombreStr) == 0)
			{
				if(Passenger_setApellido(unPasajero, apellidoStr) == 0)
				{
					if(Passenger_setPrecio(unPasajero, atof(precioStr)) == 0)
					{
						if(Passenger_setTipoPasajero(unPasajero, tipoPasajero_Str(tipoPasajeroStr)) == 0)
						{
							if(Passenger_setCodigoVuelo(unPasajero, codigoVueloStr) == 0)
							{
								if(Passenger_setEstadoVuelo(unPasajero, estadoVuelo_Str(estadoVueloStr)) == 0)
								{
									banderaPasajero = 1;
								}
							}
						}
					}
				}
			}
		}
	}
	if(banderaPasajero == 0)
	{
		Passenger_delete(unPasajero);
		unPasajero = NULL;
	}
	return unPasajero;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this, int id)
{
	int retorno = -1;
	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getId(Passenger* this, int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this, char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL && strlen(nombre) > 0)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this, char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this, char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL && strlen(apellido) > 0)
	{
		strcpy(this->apellido, apellido);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getApellido(Passenger* this, char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL && strlen(codigoVuelo) > 0)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero > 0 && tipoPasajero < 4)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this, float precio)
{
	int retorno = -1;
	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this, float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo > 0 && estadoVuelo < 5)
	{
		this->estadoVuelo = estadoVuelo;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		*estadoVuelo = this->estadoVuelo;
		retorno = 0;
	}
	return retorno;
}

void Passenger_printOne(Passenger* unPasajero)
{
	int id;
	char nombre[50];
	char apellido[50];
	int estadoVueloInt;
	char estadoVuelo[20];
	char codigoVuelo[20];
	float precio;
	int tipoPasajero;
	char tipoPasajeroStr[20];

	Passenger_getId(unPasajero, &id);
	Passenger_getNombre(unPasajero, nombre);
	Passenger_getApellido(unPasajero, apellido);
	Passenger_getPrecio(unPasajero, &precio);
	Passenger_getEstadoVuelo(unPasajero, &estadoVueloInt);
	Passenger_getCodigoVuelo(unPasajero, codigoVuelo);
	Passenger_getTipoPasajero(unPasajero, &tipoPasajero);
	tipoPasajero_Int(tipoPasajero, tipoPasajeroStr);
	estadoVuelo_Int(estadoVueloInt, estadoVuelo);
	if(unPasajero != NULL)
	{
		printf("%4d %15s %15s %.0f %15s %15s %15s\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajeroStr, estadoVuelo);
	}
}

int tipoPasajero_Str(char* tipoStr)
{
	int retorno = -1;
	if(tipoStr != NULL)
	{
		if(strcmp(tipoStr, "FirstClass") == 0)
		{
			retorno = 1;
		}
		else
		{
			if(strcmp(tipoStr, "ExecutiveClass") == 0)
			{
				retorno = 2;
			}
			else
			{
				if(strcmp(tipoStr, "EconomyClass") == 0)
				{
					retorno = 3;
				}
			}
		}
	}
	return retorno;
}

int tipoPasajero_Int(int tipo, char* tipoStr)
{
	int retorno = -1;
	if(tipoStr != NULL)
	{
		switch(tipo)
		{
		case 1:
			strcpy(tipoStr, "FirstClass");
			break;
		case 2:
			strcpy(tipoStr, "ExecutiveClass");
			break;
		case 3:
			strcpy(tipoStr, "EconomyClass");
			break;
		}
		retorno = 0;
	}
	return retorno;
}

int estadoVuelo_Str(char* estadoVuelo)
{
	int retorno = -1;
	if(estadoVuelo != NULL)
	{
		if(strcmp(estadoVuelo, "En Horario") == 0)
		{
			retorno = 1;
		}
		else
		{
			if(strcmp(estadoVuelo, "Aterrizado") == 0)
			{
				retorno = 2;
			}
			else
			{
				if(strcmp(estadoVuelo, "En Vuelo") == 0)
				{
					retorno = 3;
				}
				else
				{
					if(strcmp(estadoVuelo, "Demorado") == 0)
					{
						retorno = 4;
					}
					else
					{
						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}

int estadoVuelo_Int(int estadoVueloInt, char* estadoVueloStr)
{
	int retorno = -1;
	if(estadoVueloStr != NULL)
	{
		switch(estadoVueloInt)
		{
		case 1:
			strcpy(estadoVueloStr, "En Horario");
			break;
		case 2:
			strcpy(estadoVueloStr, "Aterrizado");
			break;
		case 3:
			strcpy(estadoVueloStr, "En Vuelo");
			break;
		case 4:
			strcpy(estadoVueloStr, "Demorado");
			break;
		}
		retorno = 0;
	}
	return retorno;
}

int altaPasajero(char* nombre, char* apellido, char* precio, char* tipoPasajero, char* codigoVuelo, char* estadoVuelo)
{
	int correctoN, correctoA, tipoInt;
	int retorno = -1;
	if(nombre != NULL && apellido != NULL && precio != NULL && tipoPasajero != NULL && codigoVuelo != NULL && estadoVuelo != NULL)
	{
		printf("Ingrese el Nombre del Pasajero: ");
		correctoN = getName(nombre, 50);
		while(correctoN == -1)
		{
			printf("Error, reingrese Nombre: ");
			correctoN = getName(nombre, 50);
		}
		printf("Ingrese el Apellido del Pasajero: ");
		correctoA = getName(apellido, 50);
		while(correctoA == -1)
		{
			printf("Error, reingrese Apellido: ");
			correctoA = getName(apellido, 50);
		}
		if(getPrecioStr(precio) != 0)
		{
			printf("No se pudo obtener el precio.\n");
		}
		if(utn_getNumeroInt(&tipoInt, "Ingrese el tipo del pasajero: 1. FirstClass   2. ExecutiveClass   3. EconomyClass: ", "Error, numero fuera de rango, reingrese.\n", 1, 3, 999) != 0)
		{
			printf("Error no se pudo tomar el dato del tipo de pasajero.\n");
		}
		else
		{
			tipoPasajero_Int(tipoInt, tipoPasajero);
		}
		if(getFlyCode(codigoVuelo, estadoVuelo) != 0)
		{
			printf("Error, no se pudo obtener el codigo de vuelo.\n");
		}
		retorno = 0;
	}
	return retorno;
}

int baja_logica(Passenger* unPasajero)
{
	int retorno = -1;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	int statusFlight;
	int tipoPasajeroInt;
	char tipoPasajeroStr[20];
	char estadoVuelo[20];
	if(unPasajero != NULL)
	{
		FILE* pFile = fopen("data_bajas.csv", "a");
		if(pFile != NULL)
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
				retorno = 0;
			}
			fclose(pFile);
		}
	}
	return retorno;
}

int ordenar_id(void* pPassengerOne, void* pPassengerTwo)
{
	int retorno = -1;
	int oneId, twoId;
	Passenger* passengerOne;
	Passenger* passengerTwo;

	if(pPassengerOne != NULL && pPassengerTwo != NULL)
	{
		passengerOne = (Passenger*)pPassengerOne;
		passengerTwo = (Passenger*)pPassengerTwo;
		Passenger_getId(passengerOne, &oneId);
		Passenger_getId(passengerTwo, &twoId);
		if(oneId < twoId)
		{
			retorno = 1;
		}
		else
		{
			if(oneId == twoId)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

int ordenar_nombre(void* pPassengerOne, void* pPassengerTwo)
{
	int retorno = -1;
	char nombreOne[50];
	char nombreTwo[50];
	Passenger* passengerOne;
	Passenger* passengerTwo;

	if(pPassengerOne != NULL && pPassengerTwo != NULL)
	{
		passengerOne = (Passenger*)pPassengerOne;
		passengerTwo = (Passenger*)pPassengerTwo;
		Passenger_getNombre(passengerOne, nombreOne);
		Passenger_getNombre(passengerTwo, nombreTwo);
		retorno = strcmp(nombreTwo, nombreOne);
	}
	return retorno;
}

int ordenar_apellido(void* pPassengerOne, void* pPassengerTwo)
{
	int retorno = -1;
	char apellidoOne[50];
	char apellidoTwo[50];
	Passenger* passengerOne;
	Passenger* passengerTwo;

	if(pPassengerOne != NULL && pPassengerTwo != NULL)
	{
		passengerOne = (Passenger*)pPassengerOne;
		passengerTwo = (Passenger*)pPassengerTwo;
		Passenger_getApellido(passengerOne, apellidoOne);
		Passenger_getApellido(passengerTwo, apellidoTwo);
		retorno = strcmp(apellidoTwo, apellidoOne);
	}
	return retorno;
}

int ordenar_precio(void* pPassengerOne, void* pPassengerTwo)
{
	int retorno = -1;
	float priceOne, priceTwo;
	Passenger* passengerOne;
	Passenger* passengerTwo;

	if(pPassengerOne != NULL && pPassengerTwo != NULL)
	{
		passengerOne = (Passenger*)pPassengerOne;
		passengerTwo = (Passenger*)pPassengerTwo;
		Passenger_getPrecio(passengerOne, &priceOne);
		Passenger_getPrecio(passengerTwo, &priceTwo);
		if(priceOne < priceTwo)
		{
			retorno = 1;
		}
		else
		{
			if(priceOne == priceTwo)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

int ordenar_estado(void* pPassengerOne, void* pPassengerTwo)
{
	int retorno = -1;
	int oneStatus, twoStatus;
	Passenger* passengerOne;
	Passenger* passengerTwo;

	if(pPassengerOne != NULL && pPassengerTwo != NULL)
	{
		passengerOne = (Passenger*)pPassengerOne;
		passengerTwo = (Passenger*)pPassengerTwo;
		Passenger_getEstadoVuelo(passengerOne, &oneStatus);
		Passenger_getEstadoVuelo(passengerTwo, &twoStatus);
		if(oneStatus < twoStatus)
		{
			retorno = 1;
		}
		else
		{
			if(oneStatus == twoStatus)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

int alta_id(char* idString)
{
	int retorno = -1;
	int id;
	if(idString != NULL)
	{
		FILE* pFile = fopen("ides.txt", "r");
		if(pFile != NULL)
		{
			parser_id(pFile, idString, &id);
			fclose(pFile);
			id++;
			pFile = fopen("ides.txt", "w");
			if(pFile != NULL)
			{
				parser_idToText(pFile, id);
				fclose(pFile);
				retorno = 1;
			}
		}
		retorno = 0;
	}
	return retorno;
}
