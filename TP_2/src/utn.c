#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
static int esFlotante(char* cadena, int limite);
static int getFloat(float* pResultado);

int getString(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[4096]; // Se modificara mas tarde usando memoria dinamica.

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]  == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
    return retorno;
}

static int esNumerica(char* cadena, int limite)
{
	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[128];

    if(pResultado != NULL && getString(bufferString, sizeof(bufferString)) == 0 && esNumerica(bufferString, sizeof(bufferString)))
    {
    	retorno = 0;
    	*pResultado = atoi(bufferString);
    }
    return retorno;
}

int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
			    printf("%s", mensajeError);
			    reintentos--;
			}
		} while(reintentos >= 0);
	}
	return retorno;
}

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		} while(reintentos >= 0);
	}
	return retorno;
}

static int esFlotante(char* cadena, int limite)
{
	int retorno = -1;
	int i;
	int banderaFloat = 0;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] == '.' && banderaFloat == 0)
			{
				banderaFloat = 1;
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int getFloat(float* pResultado)
{
    int retorno = -1;
    char buffer[128];

    if(pResultado != NULL)
    {
    	if(getString(buffer, sizeof(buffer)) == 0 && esFlotante(buffer, sizeof(buffer)))
    	{
            retorno = 0;
            *pResultado = atof(buffer);
    	}
    }

    return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		} while(reintentos >= 0);
	}
	return retorno;
}

int getFlyCode(char flycode[], int tam)
{
	int retorno = -1;
	int opcion;
	if(flycode != NULL && tam > 0)
	{
		utn_getNumeroInt(&opcion, "1. ATR-94521, 2. XER-05073, 3. IKQ-70952,  4. DMR-83501, 5. CNL-71901\nIngrese opcion para elegir el codigo de vuelo: ", "Error, numero fuera de rango, reingrese: ", 1, 5, 10);
		switch(opcion)
		{
		case 1:
			strcpy(flycode, "ATR-94521");
			break;
		case 2:
			strcpy(flycode, "XER-05073");
			break;
		case 3:
			strcpy(flycode, "IKQ-70952");
			break;
		case 4:
			strcpy(flycode, "DMR-83501");
			break;
		case 5:
			strcpy(flycode, "CNL-71901");
			break;
		}
		retorno = 0;
	}
	return retorno;
}

void estilo(char string[])
{
	int tam;
	int i;

	strlwr(string);
	string[0] = toupper(string[0]);

	tam = strlen(string);
	for (i = 0; i < tam; i++) {
		if(string[i] == ' ')
		{
			string[i + 1] = toupper(string[i + 1]);
		}
	}
}

int getName(char name[], int tam)
{
	int retorno = -1;
	char aux[51];
	int contadorEspacios = 0;
	int banderaError = 0;
	int i;
	if(name != NULL && tam > 0)
	{
        if(getString(aux, 51) == 0)
        {
        	for(i = 0; i<strlen(aux); i++)
        	{
        		if(aux[i] == ' ')
        		{
        			contadorEspacios++;
        		}
        	}
        	if(contadorEspacios < 3)
        	{
        		for(i = 0; i<strlen(aux); i++)
        		{
        			if(isalpha(aux[i]) == 0 && aux[i] != ' ')
        			{
        				printf("Nombre Invalido.");
        				banderaError = 1;
        				break;
        			}
        		}
        		if(banderaError == 0)
        		{
        			estilo(aux);
        			strcpy(name, aux);
        			retorno = 0;
        		}
        	}
        }
	}
	return retorno;
}
