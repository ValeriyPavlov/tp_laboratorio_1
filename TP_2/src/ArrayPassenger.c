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


static int obtenerID(void);
static int obtenerID(void) {
	static int Gen_idIncremental = 6;
	return Gen_idIncremental++;
}

int initPassengers(Passenger* list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i = 0; i < len ; i++)
		{
			list[i].isEmpty = VACIO;
		}
		retorno = 0;
	}
	return retorno;
}

int findEmptyPassenger(Passenger* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == VACIO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[])
{
	int retorno = -1;
    int freeIndex;

	if(list != NULL && len > 0)
	{
		freeIndex = findEmptyPassenger(list, len);
		if(freeIndex != -1)
		{
			list[freeIndex].id = id;
			strcpy(list[freeIndex].name, name);
			strcpy(list[freeIndex].lastName, lastName);
			strcpy(list[freeIndex].flycode, flycode);
			list[freeIndex].price = price;
			list[freeIndex].typePassenger = typePassenger;
			list[freeIndex].isEmpty = OCUPADO;
			retorno = 0;
		}
	}
	return retorno;
}

int findPassengerById(Passenger* list, int len, int id)
{
	int retorno = -1;
    int i;

    if(list != NULL && len > 0)
    {
    	for(i = 0; i < len; i++)
    	{
    		if(list[i].id == id && list[i].isEmpty == OCUPADO)
    		{
    			retorno = i;
    		}
    	}
    }
	return retorno;
}

int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;
	int indice;

	if(list != NULL && len > 0)
	{
		indice = findPassengerById(list, len, id);
		if(indice != -1)
		{
			list[indice].isEmpty = BAJA;
			retorno = 0;
		}
	}
	return retorno;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int retorno = -1;
	int i, j;
	Passenger aux;
	if(list != NULL && len > 0)
	{
		retorno = 0;
		if(order == 1)
		{
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++)
				{
					if(strcmp(list[i].lastName, list[j].lastName) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else
					{
						if(strcmp(list[i].lastName, list[j].lastName) == 0)
						{
							if(list[i].typePassenger > list[j].typePassenger)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
		}
		else
		{
			if(order == 0)
			{
				for (i = 0; i < len - 1; i++) {
					for (j = i + 1; j < len; j++)
					{
						if(strcmp(list[i].lastName, list[j].lastName) < 0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
						else
						{
							if(strcmp(list[i].lastName, list[j].lastName) == 0)
							{
								if(list[i].typePassenger < list[j].typePassenger)
								{
									aux = list[i];
									list[i] = list[j];
									list[j] = aux;
								}
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

int printPassengers(Passenger* list, int length, eFlight* listF, int lenF, eTypePassenger* listT, int lenT)
{
	int retorno = -1;
	int i, j, k;

	if(list != NULL && length > 0)
	{
		printf("ID:\tLASTNAME:       NAME:\tPRICE:\t FLYCODE:\tPASSENGER TYPE:\tFLIGHT STATUS:\n");
		for(i = 0; i < length; i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				for(k = 0; k < lenT; k++)
				{
					if(list[i].typePassenger == listT[k].idtype)
					{
						for(j = 0; j < lenF; j++)
						{
							if(strcmp(listF[j].flycode, list[i].flycode) == 0)
							{
								printf("%d\t%s\t\t%s\t%.2f\t %s\t%s\t%s\n", list[i].id, list[i].lastName, list[i].name, list[i].price, list[i].flycode, listT[k].descripcion, listF[j].descripcion);
							}
						}
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int retorno = -1;
	int i, j;
	Passenger aux;

	if(list != NULL && len > 0)
	{
		retorno = 0;
		if(order == 1)
		{
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++)
				{
					if(strcmp(list[i].flycode, list[j].flycode) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
		}
		else
		{
			if(order == 0)
			{
				for (i = 0; i < len - 1; i++) {
					for (j = i + 1; j < len; j++)
					{
						if(strcmp(list[i].flycode, list[j].flycode) < 0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}
	}
	return retorno;
}


int cargaVuelos(eFlight* lista, int len)
{
    int retorno = -1;
    int i;
    char flycodes[][10] = {"ATR-94521", "XER-05073", "IKQ-70952", "DMR-83501", "CNL-71901"};
    int statusFlights[] = {20, 20, 20, 21, 22};
    char desc[][15] = {"ACTIVO", "ACTIVO", "ACTIVO", "DEMORADO", "CANCELADO"};

    if(lista != NULL && len > 0)
    {
    	for(i = 0; i < len; i++)
    	{
            strcpy(lista[i].flycode, flycodes[i]);
            lista[i].statusFlight = statusFlights[i];
            strcpy(lista[i].descripcion, desc[i]);
    	}
    	retorno = 0;
    }
    return retorno;
}

int cargarTipos(eTypePassenger lista[], int len)
{
	int retorno = -1;
	int i;
	int id[] = {11, 12, 13};
	char desc[][15] = {"ECONOMICA", "EJECUTIVA", "PRIMERA CLASE"};

	if(lista != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
            lista[i].idtype = id[i];
            strcpy(lista[i].descripcion, desc[i]);
		}
		retorno = 0;
	}
	return retorno;
}


int cargaForzada(Passenger* list, int len)
{
    int retorno = -1;
    int i;

    char names[][51] = {"Pablo", "Sofia", "Val", "Ana", "Juan"};
    char lastNames[][51] = {"Romero", "Vazquez", "Grosso", "Flores", "Lopez"};
    char flycodes[][10] = {"ATR-94521", "XER-05073", "XER-05073", "DMR-83501", "CNL-71901"};
    float prices[] = {1000, 1299.99, 1475.50, 1150, 999.99};
    int typePass[] = {11, 12, 13, 11, 11};

    if(list != NULL && len > 0)
    {
    	for(i = 0; i < 5; i++)
    	{
			list[i].id = i+1;;
			strcpy(list[i].name, names[i]);
			strcpy(list[i].lastName, lastNames[i]);
			strcpy(list[i].flycode, flycodes[i]);
			list[i].price = prices[i];
			list[i].typePassenger = typePass[i];
			list[i].isEmpty = OCUPADO;
    	}
    	retorno = 0;
    }
    return retorno;
}

int alta(Passenger* list, int len)
{
	int retorno = -1;
	char nombre[51];
	char apellido[51];
	float precio;
	int tipo;
	char flycode[10];
	int correctoN = -1;
	int correctoA = -1;

	if(list != NULL && len > 0)
	{
		printf("Ingrese el Nombre del Pasajero: ");
		correctoN = getName(nombre, 51);
        while(correctoN == -1)
        {
        	printf("Reingrese Nombre: ");
        	correctoN = getName(nombre, 51);
        }
        printf("Ingrese el Apellido del Pasajero: ");
        correctoA = getName(apellido, 51);
        while(correctoA == -1)
        {
        	printf("Reingrese Apellido: ");
        	correctoA = getName(apellido, 51);
        }
        if(utn_getNumeroFlotante(&precio, "Ingrese el precio del vuelo: ", "Error, numero fuera de rango, reingrese: ", 1, 9999.99, 5) != 0)
        {
        	printf("Error no se pudo tomar el dato del precio.\n");
        }
        if(utn_getNumeroInt(&tipo, "11. ECONOMICA  12. EJECUTIVA  13. PRIMERA CLASE\nIngrese el tipo: ", "Error, numero fuera de rango, reingrese: ", 11, 13, 5) != 0)
        {
        	printf("Error no se pudo tomar el dato del tipo de pasajero.\n");
        }
        if(getFlyCode(flycode, 10) != 0)
        {
        	printf("Error no se pudo tomar el dato del codigo de vuelo.\n");
        }

		if(addPassenger(list, len, obtenerID(), nombre, apellido, precio, tipo, flycode) == 0)
		{
			retorno = 0;
		}
		else
		{
			printf("No se realizo la carga del pasajero.\n");
		}
	}
	return retorno;
}

int baja(Passenger lista[], int tam, eFlight listaF[], int tamF, eTypePassenger listaT[], int tamT)
{
	int retorno = -1;
	int indice;

	if(lista != NULL && tam > 0)
	{
		printPassengers(lista, tam, listaF, tamF, listaT, tamT);
		utn_getNumeroInt(&indice, "Ingrese el id del pasajero a dar de baja: ", "Error, numero fuera de rango, reingrese: ", 1, CANT, 3);
		if(removePassenger(lista, tam, indice) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int modificacion(Passenger lista[], int tam, eFlight listaF[], int tamF, eTypePassenger listaT[], int tamT)
{
    int retorno = -1;
    int i;
    int indice;
    char opcion;
    int correctoN = -1;
    int correctoA = -1;
    char nombre[51];
    char apellido[51];
    float precio;
    int tipo;
    char flycode[10];

    if(lista != NULL && tam > 0)
    {
    	printPassengers(lista, tam, listaF, tamF, listaT, tamT);
    	utn_getNumeroInt(&indice, "Ingrese el id del pasajero a modificar: ", "Error, numero fuera de rango, reingrese: ", 1, CANT, 3);
    	if(findPassengerById(lista, tam, indice) != -1)
    	{
    		for(i = 0; i < tam; i++)
    		{
    			if(indice == lista[i].id)
    			{
    				utn_getCaracter(&opcion, "A. Modificar Nombre   B. Modificar Apellido   C. Modificar Precio   D. Modificar Tipo de Pasajero   E. Modificar Codigo de Vuelo.\nIngrese la opcion: ", "Error, letra fuera de rango, reingrese: ", 'A', 'E', 3);
    				switch(opcion)
    				{
    				case 'A':
    					printf("Ingrese el Nuevo Nombre del Pasajero: ");
    					correctoN = getName(nombre, 51);
    					while(correctoN == -1)
    					{
    						printf("Reingrese Nombre: ");
    						correctoN = getName(nombre, 51);
    					}
    					strcpy(lista[i].name, nombre);
    					retorno = 0;
    					break;
    				case 'B':
    					printf("Ingrese el Nuevo Apellido del Pasajero: ");
    					correctoA = getName(apellido, 51);
    					while(correctoA == -1)
    					{
    						printf("Reingrese Apellido: ");
    						correctoA = getName(apellido, 51);
    					}
    					strcpy(lista[i].lastName, apellido);
    					retorno = 0;
    					break;
    				case 'C':
    					utn_getNumeroFlotante(&precio, "Ingrese el nuevo precio del vuelo: ", "Error, numero fuera de rango, reingrese: ", 1, 9999.99, 5);
    					lista[i].price = precio;
    					retorno = 0;
    					break;
    				case 'D':
    					utn_getNumeroInt(&tipo, "11. ECONOMICA  12. EJECUTIVA  13. PRIMERA CLASE\nIngrese el tipo: ", "Error, numero fuera de rango, reingrese: ", 11, 13, 5);
    					lista[i].typePassenger = tipo;
    					retorno = 0;
    					break;
    				case 'E':
    					getFlyCode(flycode, 5);
    					strcpy(lista[i].flycode, flycode);
    					retorno = 0;
    					break;
    				}
    				break;
    			}
    		}
    	}
    }
	return retorno;
}

int promedios(Passenger lista[], int tam)
{
	int retorno = -1;
	int i;
	int contador = 0;
	float promedio = 0;
	float total;
	int contadorChetos = 0;

	if(lista != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == OCUPADO)
			{
				contador++;
				total += lista[i].price;
			}
		}
		promedio = total / contador;
		for(i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == OCUPADO && lista[i].price > promedio)
			{
				contadorChetos++;
			}
		}
		printf("El precio total de los pasajes es de: $%.2f\n", total);
		printf("El promedio de los precios de pasajes es de: $%.2f\n", promedio);
		printf("Cantidad de pasajeros que superan el precio promedio: %d\n", contadorChetos);
		retorno = 0;
	}
    return retorno;
}


int listarVuelosActivos(Passenger* list, int length, eFlight* listF, int lenF, eTypePassenger listT[], int lenT)
{
	int retorno = -1;
	int i, j, k;

	if(list != NULL && length > 0)
	{
		printf("ID:\tLASTNAME:       NAME:\tPRICE:\t FLYCODE:\tPASSENGER TYPE:\tFLIGHT STATUS:\n");
		for(i = 0; i < length; i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				for(k = 0; k < lenT; k++)
				{
					if(list[i].typePassenger == listT[k].idtype)
					{
						for(j = 0; j < lenF; j++)
						{
							if(strcmp(listF[j].flycode, list[i].flycode) == 0)
							{
								if(listF[j].statusFlight == 20)
								{
									printf("%d\t%s\t\t%s\t%.2f\t %s\t%s\t%s\n", list[i].id, list[i].lastName, list[i].name, list[i].price, list[i].flycode, listT[k].descripcion, listF[j].descripcion);
								}
							}
						}
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int existenPasajeros(Passenger lista[], int tam)
{
	int retorno = 0;
	int i;
	for(i = 0; i < tam; i++)
	{
		if(lista[i].isEmpty == OCUPADO)
		{
			retorno = 1;
			break;
		}
	}
	return retorno;
}
