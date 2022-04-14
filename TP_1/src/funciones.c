//Kevin Worner 1A
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define BITCOIN 4606954.55

//Muestra un separador
void MostrarSeparador(void)
{
	printf("-------------------------------------------------------------\n");
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
	while(numero < 100 || numero > 22000)
	{
		printf("\nError. Ingrese km validos (100 - 22000) : ");
		fflush(stdin);
		scanf("%d", &numero);
	}
	return numero;

}
//Toma el precio que ingresa el usuario y lo valida.
float tomarPrecio(char mensaje[])
{
	float precio;
	printf("%s", mensaje);
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


//Realiza la carga forzada de datos utilizando punteros
void cargaForzada(int* km, float* y, float* z)
{
	*km = 7090;
	*y = 162965;
	*z = 159339;

}


//Carga los resultados tomando por parametro las variables del main y pasando a puntero las variables de calculos.
void cargarResultados(int km ,float y,float z, float* debA, float* debL, float* credA, float* credL, float* bitA, float* bitL, float* preA, float* preL, float* dif )
{

	if(km > 0 && y > 0 && z > 0)
	{
		*debA = precioTarjetaDebito(y);
		*credA = precioTarjetaCredito(y);
		*bitA = precioBitcoin(y);
		*preA = precioUnitario(y, km);
		*debL = precioTarjetaDebito(z);
		*credL = precioTarjetaCredito(z);
		*bitL = precioBitcoin(z);
		*preL = precioUnitario(z, km);
		*dif = calcularDiferencia(y, z);
	}

}


//muestra los resultados tomando por parametro las variables del main
void MostrarResultados(int km ,float y,float z, float debA, float debL, float credA, float credL, float bitA, float bitL, float preA, float preL, float dif)
{
	printf("Kilometros Ingresados: %d\n",km);
	printf("\nPRECIO AEROLINEAS: %.2f\n"
							"\ta)-Precio con tarjeta de debito: $%.2f\n"
							"\tb)-Precio con tarjeta de credito: $%.2f\n"
							"\tc)-Precio pagando con Bitcoin: BTC %.6f\n"
							"\td)-Precio Unitario: $%.2f\n", y, debA, credA, bitA, preA);
						printf("\nPRECIO LATAM: %.2f\n"
							"\ta)-Precio con tarjeta de debito: $%.2f\n"
							"\tb)-Precio con tarjeta de credito: $%.2f\n"
							"\tc)-Precio pagando con Bitcoin: BTC %.6f\n"
							"\td)-Precio Unitario: $%.2f\n", z, debL, credL, bitL, preL);
						printf("\nLa diferencia de precio es: $%.2f\n", dif);
}
