#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "input.h"
#include "menu.h"
#include "funciones.h"
#define TAMLIST 2000

int main()
{
    setbuf(stdout, NULL);
    Passenger pasajero[TAMLIST];
    int opcion;
    int respuesta;
    int id = 0;
    int contadorPasajeros = 0;
    initPassengers(pasajero, TAMLIST); //INICIALIZO TODO EL ARRAY DE LA ESTRUCTURA PASSENGERS
    printf("\n\t***BIENVENIDO AL PROGRAMA***\n");
    do
    {

       menu(&opcion);
        switch(opcion)
        {
            case 1:
                if(contadorPasajeros < TAMLIST)
                {
                    agregarPasajero(pasajero, &id, TAMLIST);
                    contadorPasajeros++;
                    system("pause");
                }
                else
                {
                    printf("\nNo hay lugar\n");
                }
            break;
            case 2:
                if(contadorPasajeros > 0)
                {
                    modificarPasajero(pasajero,TAMLIST);
                }
                else
                {
                    printf("\nNo se cargaron pasajeros.");
                }

            break;
            case 3:
                if(contadorPasajeros > 0)
                {
                    opcion = eliminarPasajero(pasajero, TAMLIST);
					if(!opcion)
					{
						contadorPasajeros--;
					}
				}
				else
				{
					printf("No hay pasajeros para eliminar\n");
				}
            break;
            case 4:
                if(contadorPasajeros > 0)
                {
                    getInteger(&respuesta, "\n1-Listado por Apellido y Tipo de pasajero\n2-Total y promedio\n3-Listado de pasajeros por Codigo de vuelo\nIngrese una opcion: ", "\nERROR. Ingrese una opcion valida: ", 1, 3);
                    submenu(pasajero, TAMLIST, respuesta);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay pasajeros cargados.\n");
                    }
            break;
            case 5:
                hardcode(pasajero, TAMLIST, &id, &contadorPasajeros);
                printf("\nPASAJEROS CARGADOS CORRECTAMENTE\n");
                printPassenger(pasajero, TAMLIST);
                break;
        }
    }while(opcion != 6);
    printf("\n\tSALISTE EXITOSAMENTE DEL PROGRAMA");
    return 0;
}
