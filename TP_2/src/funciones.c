#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "input.h"
#include "menu.h"
#include "funciones.h"
#define ORDENASC 1
#define ORDENDESC 0
int submenu(Passenger* list,int tamList, int respuesta)
{
    int ret = -1;
    int opcion;
    int contadorPasajerosPromedio = 0;
    float acumuladorPasajes = 0;
    float promedioPasajes;
                switch(respuesta)
                {
                    case 1:
                        getInteger(&opcion,"\n1-Ascendente\n2-Descendente\nIngrese la opcion: ", "\nError. Ingrese una opcion valida: ", 1,2);
                        if(opcion == 1)
                        {
                            sortPassengersByName(list, tamList, ORDENASC);
                            printPassenger(list, tamList);
                        }
                        else
                        {
                           sortPassengersByName(list, tamList, ORDENDESC);
                           printPassenger(list, tamList);
                        }
                        ret = 0;
                    break;
                    case 2:
                        calculosPasajes(list, tamList, &contadorPasajerosPromedio, &promedioPasajes, &acumuladorPasajes);
                        mostrarCalculos(&contadorPasajerosPromedio, &promedioPasajes, &acumuladorPasajes);
                    break;
                    case 3:
                        getInteger(&opcion,"\n1-Ascendente\n2-Descendente\nIngrese la opcion: ", "\nError. Ingrese una opcion valida: ", 1,2);
                        if(opcion == 1)
                        {
                            sortPassengersByName(list, tamList, ORDENASC);
                            printPassenger(list, tamList);
                        }
                        else
                        {
                           sortPassengersByName(list, tamList, ORDENDESC);
                           printPassenger(list, tamList);
                        }
                    break;
                }

    return ret;
}

