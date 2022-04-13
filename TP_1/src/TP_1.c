/*
Pavlov, Valeriy
Division K
Programacion I - Laboratorio I
Trabajo Practico N°1.
*/


/// @brief Programa basico que cuenta con un menu de opciones. Su finalidad principal es calcular costos de vuelos para una agencia de viajes.
/// El objetivo es calcular y mostrar las diferentes opciones de pago y la sumas correspondientes a los vuelos de Aerolineas Argentinas y Latam.
/// @return Retorna 0 al finalizar con exito.

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "validaciones.h"

int main(void) 
{
	setbuf(stdout,NULL);
	
	int opcion;                   // Opciones del menu, seleccionables ingresando numeros enteros del 1 al 6.
	int kilometros;               // Kilometros sobre los cuales trabajara la aplicacion.
	float precioAerolineas;       // Precio total del viaje con Aerolineas.
	float precioLatam;            // Precio total del viaje con Latam.
	float debitoAerolineas;       // Precio del viaje con Aerolineas usando la tarjeta de debito.
	float debitoLatam;            // Precio del viaje con Latam usando la tarjeta de debito.
	float creditoAerolineas;      // Precio del viaje con Aerolineas usando la tarjeta de credito.
	float creditoLatam;           // Precio del viaje con Latam usando la tarjeta de credito.
	float bitcoinAerolineas;      // Precio del viaje con Aerolineas pagando con bitcoins.
	float bitcoinLatam;           // Precio del viaje con Latam pagando con bitcoins.
	float unidadAerolineas;       // Precio unitario del viaje con Aerolineas.
	float unidadLatam;            // Precio unitario del viaje con Latam.
	float diferenciaPrecios;      // Diferencia absoluta entre los precios de Aerolineas y Latam.
	float bitcoin;                // Precio de 1 Bitcoin.
	int banderaCalculo;           // Bandera de calculos, 0 por defecto y al cambiar datos, 1 tras ejecutaron las funciones de calculos.
	float descuento;              // Descuento base aplicado a las tarjetas de debito.
	float aumento;                // Interes aplicado a las tarjetas de credito.

	opcion = 0;
	kilometros = 0;
	precioAerolineas = 0;
	precioLatam = 0;
	bitcoin = 4606954.55;
	banderaCalculo = 0;
	descuento = 0.9;
	aumento = 1.25;

	do
	{   // Menu Principal
		printf("\n====================         Menu        ===================================\n||");
		printf("\n|| 1. Ingresar kilometros: (km = %d).", kilometros);
		printf("\n|| 2. Ingresar Precio de Vuelos: (Aerolineas = %.2f, Latam = %.2f).", precioAerolineas, precioLatam);
		printf("\n|| 3. Calcular todos los costos.");
		printf("\n|| 4. Informar Resultados.");
		printf("\n|| 5. Carga forzada de datos.");
		printf("\n|| 6. Salir.\n||");
		printf("\n============================================================================\n");
        // Solicitud de ingreso de las opciones del Menu.
		opcion = getIntValidado("\nIngresar opcion: ", "Error, ingrese numeros positivos: ", 0);

		switch(opcion)
		{
		case 1:
			// Opcion 1, Ingreso de Kilometros por el usuario.
			kilometros = getIntValidado("Ingresar kilometros: ", "Error, reingrese kilometros, mayores a cero: ", 1);
			banderaCalculo = 0;
			break;
		case 2:
			// Opcion 2, Ingreso de precios Aerolineas y Latam.
			precioAerolineas = getFloatValidado("Precio vuelo Aerolineas: ", "Error, reingrese precio mayor a cero: ", 1);
			precioLatam = getFloatValidado("Precio vuelo Latam: ", "Error, reingrese precio mayor a cero: ", 1);
			banderaCalculo = 0;
			break;
		case 3:
			// Opcion 3, calculos de los resultados, siempre y cuando los valores de kilometros o precios Aerolineas/Latam no sean 0.
			if(kilometros == 0 || precioAerolineas == 0 || precioAerolineas == 0)
			{
				printf("\nError, ingrese los datos antes de calcular.\n");
			}
			else
			{
				debitoAerolineas = multiplicacionFlotante(precioAerolineas, descuento);
				debitoLatam = multiplicacionFlotante(precioLatam, descuento);
				creditoAerolineas = multiplicacionFlotante(precioAerolineas, aumento);
				creditoLatam = multiplicacionFlotante(precioLatam, aumento);
				bitcoinAerolineas = divisionFlotante(precioAerolineas, bitcoin);
				bitcoinLatam = divisionFlotante(precioLatam, bitcoin);
				unidadAerolineas = divisionFlotanteEntero(precioAerolineas, kilometros);
				unidadLatam = divisionFlotanteEntero(precioLatam, kilometros);
				diferenciaPrecios = valorAbsolutoFlotante(precioAerolineas, precioLatam);
				banderaCalculo = 1;
				printf("\nLos calculos se realizaron con exito!\n");
			}
			break;
		case 4:
			// Opcion 4, muestra los resultados arrojados por la opcion 3, siempre y cuando se haya calculado anteriormente.
			if(banderaCalculo == 1)
			{
				printf("\nKMs Ingresados: %d km\n", kilometros);
				printf("\nPrecio Aerolineas: $%.2f\n", precioAerolineas);
				printf("a) Precio con tarjeta de debito: $ %.2f\n", debitoAerolineas);
				printf("b) Precio con tarjeta de credito: $ %.2f\n", creditoAerolineas);
				printf("c) Precio pagando con bitcoin: %f BTC\n", bitcoinAerolineas);
				printf("d) Mostrar precio unitario: $ %.2f\n\n", unidadAerolineas);
				printf("Precio Latam: $%.2f\n", precioLatam);
				printf("a) Precio con tarjeta de debito: $ %.2f\n", debitoLatam);
				printf("b) Precio con tarjeta de credito: $ %.2f\n", creditoLatam);
				printf("c) Precio pagando con bitcoin: %f BTC\n", bitcoinLatam);
				printf("d) Mostrar precio unitario: $ %.2f\n\n", unidadLatam);
				printf("La diferencia de precio es: $%.2f\n", diferenciaPrecios);
			}
			else
			{
				printf("\nError, debe realizar los calculos de la opcion 3 antes de mostrar resultados.\n");
			}
			break;
		case 5:
			// Opcion 5, carga forzada de datos por defecto, sus calculos y resultados.
			kilometros = 7090;
			precioAerolineas = 162965;
			precioLatam = 159339;

			debitoAerolineas = multiplicacionFlotante(precioAerolineas, descuento);
			debitoLatam = multiplicacionFlotante(precioLatam, descuento);
			creditoAerolineas = multiplicacionFlotante(precioAerolineas, aumento);
			creditoLatam = multiplicacionFlotante(precioLatam, aumento);
			bitcoinAerolineas = divisionFlotante(precioAerolineas, bitcoin);
			bitcoinLatam = divisionFlotante(precioLatam, bitcoin);
			unidadAerolineas = divisionFlotanteEntero(precioAerolineas, kilometros);
			unidadLatam = divisionFlotanteEntero(precioLatam, kilometros);
			diferenciaPrecios = valorAbsolutoFlotante(precioAerolineas, precioLatam);
			banderaCalculo = 1;

			printf("\nKMs Ingresados: %d km\n", kilometros);
			printf("\nPrecio Aerolineas: $%.2f\n", precioAerolineas);
			printf("a) Precio con tarjeta de debito: $ %.2f\n", debitoAerolineas);
			printf("b) Precio con tarjeta de credito: $ %.2f\n", creditoAerolineas);
			printf("c) Precio pagando con bitcoin: %f BTC\n", bitcoinAerolineas);
			printf("d) Mostrar precio unitario: $ %.2f\n\n", unidadAerolineas);
			printf("Precio Latam: $%.2f\n", precioLatam);
			printf("a) Precio con tarjeta de debito: $ %.2f\n", debitoLatam);
			printf("b) Precio con tarjeta de credito: $ %.2f\n", creditoLatam);
			printf("c) Precio pagando con bitcoin: %f BTC\n", bitcoinLatam);
			printf("d) Mostrar precio unitario: $ %.2f\n\n", unidadLatam);
			printf("La diferencia de precio es: $%.2f\n", diferenciaPrecios);
			break;
		case 6:
			// Opcion 6, Salida del programa.
			printf("\nPrograma Finalizado.\n");
			break;
		default:
			// Validacion de los demas casos de opciones del menu.
			printf("\n*** ERROR! La opcion ingresada es incorrecta. Por favor, vuelva a ingresar una opcion del 1 al 6.***\n");
			break;
		}

	} while(opcion != 6);

	return 0;
}
