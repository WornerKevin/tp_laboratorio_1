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
                            sortPassengersByCode(list, tamList, ORDENASC);
                            printPassenger(list, tamList);
                        }
                        else
                        {
                           sortPassengersByCode(list, tamList, ORDENDESC);
                           printPassenger(list, tamList);
                        }
                    break;
                }

    return ret;
}
int hardcode(Passenger* list, int* id, int* contador)
{
    int ret = -1;
    Passenger ePasajeroHarcodeado [] = {
        {0, "Kevin", "Worner", 130000, "FLY", 2, 1, 0},
        {0, "Julian", "Alvarez", 430000, "RTAN", 2, 2, 0},
        {0, "Lionel", "Messi", 1230000, "LSAN", 4, 2, 0},
        {0, "Sofia", "Lopez", 970000, "CARP", 4, 2, 0},
        {0, "Paula", "Chavez", 158888, "FLY", 2, 1, 0},
        {0, "Mauricio", "Zan", 245000, "15AS", 1, 1, 0},
        {0, "Emilia", "Mernes", 10600, "NESM", 1, 1, 0},
        {0, "Alfred", "Constanzo", 15000, "PEPAX", 3, 2, 0},
        {0, "Pilar", "Diaz", 500000, "ASDM", 4, 2, 0},
        {0, "Teo", "Gutierrez", 23000, "FLY", 3, 1, 0},
    };

    if(list != NULL && id != NULL)
    {
        for(int i=0; i < 10; i++)
        {
          list[i] = ePasajeroHarcodeado[i];
          list[i].id = *id;
          *id = *id + 1;
          *contador = *contador +1;
        }
        ret = 0;
    }
    return ret;
}
