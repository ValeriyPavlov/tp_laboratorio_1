#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int banderaCargaForzada = 1;
    int banderaGuardadoDatos = 1;
    int banderaGuardadoDatosBin = 1;
    int resultadoCarga;
    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	menu();
    	utn_getNumeroInt(&option, "Opcion: ", "Error, opcion incorrecta.\n", 1, 10, 999);
        switch(option)
        {
            case 1:
                if(banderaCargaForzada == 1)
                {
                	resultadoCarga = controller_loadFromText("data.csv", listaPasajeros);
                	if(resultadoCarga == 0)
                	{
                		banderaCargaForzada = 0;
                		printf("Se han cargado los pasajeros desde el archivo .csv\n");
                	}
                }
                else
                {
                	printf("Los pasajeros ya han sido cargados desde el archivo!\n");
                }
                break;
            case 2:
            	if(banderaCargaForzada == 1)
            	{
            		resultadoCarga = controller_loadFromBinary("data.bin", listaPasajeros);
            		if(resultadoCarga == 0)
            		{
            			banderaCargaForzada = 0;
            			printf("Se han cargado los pasajeros desde el archivo .bin\n");
            		}
            	}
                else
                {
                	printf("Los pasajeros ya han sido cargados desde el archivo!\n");
                }
            	break;
            case 3:
            	if(controller_addPassenger(listaPasajeros) == 0)
            	{
            		banderaGuardadoDatos = 1;
            		banderaGuardadoDatosBin = 1;
            		printf("Alta realizada con exito.\n");
            	}
            	break;
            case 4:
            	if(!ll_isEmpty(listaPasajeros))
            	{

            		if(controller_editPassenger(listaPasajeros) == 0)
            		{
            			banderaGuardadoDatos = 1;
            			banderaGuardadoDatosBin = 1;
            			printf("Modificacion realizada con exito.\n");
            		}
            	}
            	else
            	{
            		printf("Debe cargar algun pasajero para poder modificar.\n");
            	}
            	break;
            case 5:
            	if(!ll_isEmpty(listaPasajeros))
            	{
            		if(controller_removePassenger(listaPasajeros) == 0)
            		{
            			banderaGuardadoDatos = 1;
            			banderaGuardadoDatosBin = 1;
            			printf("Baja realizada con exito.\n");
            		}
            	}
            	else
            	{
            		printf("Debe cargar algun pasajero para poder dar de baja.\n");
            	}
            	break;
            case 6:
            	if(!ll_isEmpty(listaPasajeros))
            	{
            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Debe cargar algun pasajero para poder listar.\n");
            	}
            	break;
            case 7:
            	if(ll_len(listaPasajeros) > 1)
            	{
            		controller_sortPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Debe cargar al menos dos pasajeros para poder ordenar.\n");
            	}
            	break;
            case 8:
            	if(banderaCargaForzada == 0)
            	{
            		if(controller_saveAsText("data.csv" , listaPasajeros) == 0)
            		{
            			printf("Se han guardado los datos exitosamente.\n");
            			banderaGuardadoDatos = 0;
            		}
            		else
            		{
            			printf("Error, no se pudo guardar el archivo.\n");
            		}
            	}
            	else
            	{
            		printf("Debe cargar los datos del archivo para poder guardar y no perder los datos existentes.\n");
            	}
            	break;
            case 9:
            	if(banderaCargaForzada == 0)
            	{
            		if(controller_saveAsBinary("data.bin" , listaPasajeros) == 0)
            		{
            			printf("Se han guardado los datos exitosamente.\n");
            			banderaGuardadoDatosBin = 0;
            		}
            		else
            		{
            			printf("Error, no se pudo guardar el archivo.\n");
            		}
            	}
            	else
            	{
            		printf("Debe cargar los datos del archivo para poder guardar y no perder los datos existentes.\n");
            	}
            	break;
            case 10:
            	if(banderaGuardadoDatos == 1 || banderaGuardadoDatosBin == 1)
            	{
            		printf("Debe guardar los datos antes de salir del programa (en texto y en binario).\n");
            	}
            	break;
        }
    }while(option != 10 || banderaGuardadoDatos != 0 || banderaGuardadoDatosBin != 0);

	ll_deleteLinkedList(listaPasajeros);
	printf("Programa finalizado.\n");

    return 0;
}

