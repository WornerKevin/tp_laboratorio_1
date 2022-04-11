//Kevin Worner 1A
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"//Realiza el llamado a la biblioteca de Funciones


/**
 * @fn int main(void)
 * @brief
 * MostrarSeparador() : genera un printf con guiones para dividir el menu y que sea mas legible.
 * mostrarMenu(): muestra los printf generados para el menu de opciones.
 * tomarOpcion() : toma el valor por scanf de lo que se ingrese como opcion y lo valida para luego retornar la opcion elegida.
 * pedirKm() : toma por scanf los km que ingrese el usuario, los valida y retorna los km.
 * tomarPrecio() : toma por scanf los precios que ingrese el usuario, los valida y retorna el precio.
 * precioTarjetaDebito() : funcion que toma por parametro el precio, le aplica el descuento y retorna el precio final.
 * precioTarjetaCredito() :  funcion que toma por parametro el precio, le aplica el aumento y retorna el precio final.
 * precioBitcoin() : funcion que toma por parametro el precio, realiza el calculo con el valor del BITCOIN en define y retorna el precio final.
 * precioUnitario() : funcion que toma por parametro el precio y los km, realiza el calculo para obtener el precio por unidad y retorna el precio final.
 * calcularDiferencia() : funcion que toma por parametro el precio de ambas aerolineas, realiza el calculo para obtener la diferencia y retorna esa diferencia.
 * cargaForzada() : funcion que realiza una carga forzada de datos sin la necesidad que el usuario tenga que ingresar algo previamente.
 * @return
 */
int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int km = 0;
	float y = 0;
	float z = 0;
	float debitoAerolineas;
	float creditoAerolineas;
	float bitcoinAerolineas;
	float precioUnitarioAerolineas;
	float debitoLatam;
	float creditoLatam;
	float bitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaPrecio;
	int flagMenu1 = 0;
	do
	{
		mostrarMenu(km, y, z);
		opcion = tomarOpcion();
		MostrarSeparador();

		switch(opcion)
		{
			case 1:
				km = pedirKm();
				flagMenu1 = 1;
			break;

			case 2:
				if(flagMenu1 == 1)
				{
					printf("\nIngrese el precio de Aerolineas: ");
					y = tomarPrecio();
					printf("\nIngrese el precio de Latam: ");
					z = tomarPrecio();
					MostrarSeparador();
				}
				else
				{
					printf("\n\tERROR:\n\tDebe ingresar los Kilometros primero (actualmente %d) .\n", km);
					MostrarSeparador();
				}
			break;

			case 3:
				if(z > 0 && y > 0)
				{
					debitoAerolineas = precioTarjetaDebito(y);
					creditoAerolineas = precioTarjetaCredito(y);
					bitcoinAerolineas = precioBitcoin(y);
					precioUnitarioAerolineas = precioUnitario(y, km);
					debitoLatam = precioTarjetaDebito(z);
					creditoLatam = precioTarjetaCredito(z);
					bitcoinLatam = precioBitcoin(z);
					precioUnitarioLatam = precioUnitario(z, km);
					diferenciaPrecio = calcularDiferencia(y, z);
					printf("\nSE CALCULO EXITOSAMENTE.\n");
					MostrarSeparador();
					flagMenu1=2;
				}
				else
				{
					printf("\n\tERROR:\n\tDebe ingresar los precios primero (actualmente : %.2f - %.2f)\n", y, z);
					MostrarSeparador();
				}
			break;

			case 4:
				if(flagMenu1 == 2)
				{
					printf("Kilometros Ingresados: %d\n",km);
					printf("\nPRECIO AEROLINEAS: %.2f\n"
						"\ta)-Precio con tarjeta de debito: $%.2f\n"
						"\tb)-Precio con tarjeta de credito: $%.2f\n"
						"\tc)-Precio pagando con Bitcoin: %.3f\n"
						"\td)-Precio Unitario: $%.2f\n", y, debitoAerolineas, creditoAerolineas, bitcoinAerolineas, precioUnitarioAerolineas);
					printf("\nPRECIO LATAM: %.2f\n"
						"\ta)-Precio con tarjeta de debito: $%.2f\n"
						"\tb)-Precio con tarjeta de credito: $%.2f\n"
						"\tc)-Precio pagando con Bitcoin: %.3f\n"
						"\td)-Precio Unitario: $%.2f\n", z, debitoLatam, creditoLatam, bitcoinLatam, precioUnitarioLatam);
					printf("\nLa diferencia de precio es: $%.2f\n", diferenciaPrecio);
					MostrarSeparador();
					system("pause");
				}
				else
				{
					printf("\n\tERROR:\n\t Debe calcular primero .\n");
					MostrarSeparador();
				}
				break;

			case 5:
				km = 7090;
				y = 162965;
				z = 159339;
				cargaForzada(km, y, z);
				break;
		}
	}while(opcion != 6);
	printf("\nSalio del programa exitosamente.");
	return EXIT_SUCCESS;
}
