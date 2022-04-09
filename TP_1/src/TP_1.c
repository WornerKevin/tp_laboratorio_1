#include <stdio.h>
#include <stdlib.h>
#include "input.h"

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
					flagMenu1 = 2;
				}
				else
				{
					printf("\nError. Debe ingresar los Kilometros primero (actualmente %d) .\n", km);
				}
			break;

			case 3:
				if(flagMenu1 == 2)
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
					flagMenu1=3;
				}
				else
				{
					printf("\nError. Debe ingresar los precios primero .\n");
				}
			break;

			case 4:
				if(flagMenu1 == 3)
				{
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
				else
				{
					printf("\nError. Debe calcular primero .\n");
				}
				break;

			case 5:
				cargaForzada();
				break;
		}
	}while(opcion != 6);
	printf("\nSalio del programa exitosamente.");
	return EXIT_SUCCESS;
}
