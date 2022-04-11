#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define BITCOIN 4606954.55

//Muestra un separador
void MostrarSeparador(void)
{
	printf("--------------------------------------\n");
}
//Funcion que muestra el menu de opciones.
void mostrarMenu(int km, float y, float z)
{
	printf("\n*** AGENCIA DE VIAJES ***\n");
	printf("1- Ingresar Kilometros: (km = %d ) \n", km);
	printf("2- Ingresar Precio de Vuelos: (Aerolineas = %.2f, Latam = %.2f) \n", y, z);
	printf("3- Calcular todos los costos: \n");
	printf("4- Informar Resultados: \n");
	printf("5- Carga forzada de datos \n");
	printf("6- Salir \n");
}
//Toma la opcion del usuario y lo valida.
int tomarOpcion(void)
{
	int opcion;
	printf("\nIngrese una opcion: ");
	scanf("%d", &opcion);
	while(opcion < 1 || opcion > 6)
	{
		printf("\nError. Ingrese opcion valida: ");
		fflush(stdin);
		scanf("%d", &opcion);
	}
	return opcion;
}
//Pide los kilometros al usuario y los valida.
int pedirKm(void)
{
	int numero;
	printf("\nIngrese los km: ");
	scanf("%d", &numero);
	while(numero < 50 || numero > 25000)
	{
		printf("\nError. Ingrese km validos (50 - 25000) : ");
		fflush(stdin);
		scanf("%d", &numero);
	}
	return numero;

}
//Toma el precio que ingresa el usuario y lo valida.
float tomarPrecio(void)
{
	float precio;
	scanf("%f", &precio);
	fflush(stdin);
	while(precio < 10000 || precio > 2000000)
	{
		printf("\nError. Ingrese un precio valido(10000 - 2000000: ");
		scanf("%f", &precio);
		fflush(stdin);
	}
	return precio;
}
//Calcula el precio del descuento del 10% en tarjeta de debito.
float precioTarjetaDebito(float precio)
{
	float descuento;
	descuento = precio * 0.10;
	precio = precio - descuento;

	return precio;
}
//Calcula los intereses del 25% de la tarjeta de credito
float precioTarjetaCredito(float precio)
{
	float interes;
	interes = precio * 0.25;
	precio = precio + interes;

	return precio;
}
//Calcula el valor en Bitcoins a pagar.
float precioBitcoin(float precio)
{
	float precioEnBitcoin;

	precioEnBitcoin = precio / BITCOIN;

	return precioEnBitcoin;
}
//Calcula el precio por Kilimetro del viaje.
float precioUnitario(float precio, int km)
{
	float precioxKm;
	precioxKm = precio / km;

	return precioxKm;
}
//Calcula la diferencia entre el precio de Aerolineas y el de Latam.
float calcularDiferencia(float y,float z)
{
	float diferencia;
	if(y < z)
	{
		diferencia = z - y;
	}
		else if(y > z)
		{
			diferencia = y - z;
		}
			else
			{
				diferencia = 0;
			}
	return diferencia;
}
/*Realiza la carga forzada de datos utilizando las funciones
para calcular los medios de pago pasando por referencia su valor e imprimiendo los calculos en pantalla*/
void cargaForzada(int km, float y, float z)
{
	float debitoAerolineas;
	float creditoAerolineas;
	float bitcoinAerolineas;
	float precioUnitarioAerolineas;
	float debitoLatam;
	float creditoLatam;
	float bitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaPrecio;


	debitoAerolineas = precioTarjetaDebito(y);
	creditoAerolineas = precioTarjetaCredito(y);
	bitcoinAerolineas = precioBitcoin(y);
	precioUnitarioAerolineas = precioUnitario(y, km);
	debitoLatam = precioTarjetaDebito(z);
	creditoLatam = precioTarjetaCredito(z);
	bitcoinLatam = precioBitcoin(z);
	precioUnitarioLatam = precioUnitario(z, km);
	diferenciaPrecio = calcularDiferencia(y, z);

	printf("Kilometros Ingresados: %d\n",km);
	printf("\nPRECIO AEROLINEAS: %.2f\n"
			"\ta)-Precio con tarjeta de debito: $%.2f\n"
			"\tb)-Precio con tarjeta de credito: $%.2f\n"
			"\tc)-Precio pagando con Bitcoin: %f\n"
			"\td)-Precio Unitario: $%.2f\n", y, debitoAerolineas, creditoAerolineas, bitcoinAerolineas, precioUnitarioAerolineas);
	printf("\nPRECIO LATAM: %.2f\n"
			"\ta)-Precio con tarjeta de debito: $%.2f\n"
			"\tb)-Precio con tarjeta de credito: $%.2f\n"
			"\tc)-Precio pagando con Bitcoin: %f\n"
			"\td)-Precio Unitario: $%.2f\n", z, debitoLatam, creditoLatam, bitcoinLatam, precioUnitarioLatam);
	printf("\nLa diferencia de precio es: $%.2f\n", diferenciaPrecio);
	MostrarSeparador();
	system("pause");
}
