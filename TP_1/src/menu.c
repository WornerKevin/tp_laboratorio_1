
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void Menu(void)
{
		setbuf(stdout, NULL);

		int opcion;
		int km = 0;
		float y = 0;
		float z = 0;
		float debA;
		float debL;
		float credA;
		float credL;
		float bitA;
		float bitL;
		float preA;
		float preL;
		float dif;
		int flagMenu = 0;
		do
		{
			mostrarMenu(km, y, z);
			opcion = tomarOpcion();
			MostrarSeparador();

			switch(opcion)
			{
				case 1:
					km = pedirKm();
				break;

				case 2:
					if(km > 0)
					{
						y = tomarPrecio("\nIngrese el precio de Aerolineas: ");
						z = tomarPrecio("\nIngrese el precio de Latam: ");
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
						cargarResultados( km ,y, z, &debA, &debL, &credA, &credL, &bitA, &bitL, &preA, &preL, &dif);
						printf("\nSE CALCULO EXITOSAMENTE.\n");
						MostrarSeparador();
						flagMenu=1;
					}
					else
					{
						printf("\n\tERROR:\n\tDebe ingresar los precios primero (actualmente : %.2f - %.2f)\n", y, z);
						MostrarSeparador();
					}
				break;

				case 4:
					if(flagMenu == 1)
					{
						MostrarResultados( km ,y, z, debA, debL, credA, credL, bitA, bitL, preA, preL, dif);
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
					cargaForzada(&km, &y, &z);
					cargarResultados( km ,y, z, &debA, &debL, &credA, &credL, &bitA, &bitL, &preA, &preL, &dif);
					MostrarResultados( km ,y, z, debA, debL, credA, credL, bitA, bitL, preA, preL, dif);
					MostrarSeparador();
					system("pause");
					break;
			}
		}while(opcion != 6);
		printf("\nSalio del programa exitosamente.");
}
