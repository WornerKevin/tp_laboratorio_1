/*
 * ArrayPassenger.c
 *
 *  Created on: 17 abr. 2022
 *      Author: Kevin Worner
 */
#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "menu.h"
#include <string.h>
#include <ctype.h>

int initPassengers(Passenger* list, int len)
{
    int ret = -1;
    if(list != NULL && len > 0)
    {
		for(int i=0; i<len; i++)
		{
			list[i].id = -1;
			list[i].isEmpty = 1;//INICIALIZA EL ARRAY DE PASAJEROS EN ESTADO VACIO ( 1 ) Y CON EL ID EN -1
			list[i].statusFlight = 0;
		}
        ret = 0;
    }
    return ret;
}

int printPassenger(Passenger* list, int length)
{
    char tipo[16];
    char estado[16];
	printf("ID\t|   Name \t|   Last Name  \t|   Price   \t|  Fly Code \t|   Type Passenger  \t| Status Flight |\n");
	printf("--------|---------------|---------------|---------------|---------------|-----------------------|---------------|\n");
    for(int i = 0; i < length; i++)
    {
            if(list[i].isEmpty ==  0)//BUSCO LA POSICION QUE CONTENGA UN PASAJERO
            {
                switch(list[i].typePassenger)//GENERO EL TIPO DE PASAJERO PARA QUE MUESTRE SU CLASE A PARTIR DEL N INGRESADO
                {
                    case 1:
                        strcpy(tipo, "CLASE TURISTA");
                        break;
                    case 2:
                        strcpy(tipo, "CLASE PREMIUM");
                        break;
                    case 3:
                        strcpy(tipo, "CLASE EJECUTIVO");
                        break;
                    case 4:
                        strcpy(tipo, "PRIMERA CLASE");
                        break;
                }
                switch(list[i].statusFlight)
                {
                    case 1:
                        strcpy(estado, "ACTIVO");
                    break;
                    case 2:
                        strcpy(estado, "REPROGRAMADO");
                    break;
                }

               printf("%2d  \t|%9s\t|   %9s   |   %10.2f  |  %7s      |  \t%15s | %12s  |\n", list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flycode, tipo, estado);
            }

    }
	return 0;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[], float price, int typePassenger, char flycode[], int statusFlight)
{
    int ret = -1;
    if(list != NULL && len > 0 && name != NULL && lastName != NULL && price > 10000 && typePassenger > 0 && flycode != NULL)
    {
     for(int i = 0; i < len; i++)
     {
         if(list[i].isEmpty == 1)
         {
             list[i].id = id;
             strcpy(list[i].name, name);
             strcpy(list[i].lastName, lastName);
             strcpy(list[i].flycode, flycode);
             list[i].price = price;
             list[i].typePassenger = typePassenger;
             list[i].statusFlight = statusFlight;
             list[i].isEmpty = 0; // LE PASO A LA ESTRUCTURA TODOS LOS DATOS DEL PASAJERO Y CAMBIO EL ESTADO A LLENO(0)
             ret = 0;
             break;
         }
     }
    }
    return ret;
}
int findPassengerById(Passenger* list, int len,int id)
{
    int ret = -1;
    if(list !=NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0 && list[i].id == id )
            {
                ret = i; //RETORNO EL INDICE DEL PASAJERO
                break;
            }
        }

    }
    return ret;
}
int removePassenger(Passenger* list, int len, int id)
{
    int ret = -1;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0 && list[i].id == id)
            {
                list[i].isEmpty = 1; //CAMBIO EL ESTADO DE LLENO(0) A VACIO(1)
                ret = 0;
                break;
            }
        }
    }

    return ret;
}

int sortPassengersByName(Passenger* list, int len, int order)
{
    int ret = -1;
    Passenger aux;
    int i;
    int j;
    if(list != NULL && len > 0 && order > -1 && order < 2)
    {
		switch (order)
		{
            case 1:
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
                {
					//PREGUNTO POR ESTADO VACIO DE AMBOS
					if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
                    {
						//CRITERIO DE ORDENAMIENTO
						if ((list[i].typePassenger == list[j].typePassenger && strcmp(list[i].lastName, list[j].lastName)== 1 )|| list[i].typePassenger > list[j].typePassenger)
                        {
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			ret = 0;
			break;
            case 0:
                for (i = 0; i < len - 1; i++)
                {
                    for (j = i + 1; j < len; j++)
                    {
                        //PREGUNTO POR ESTADO VACIO DE AMBOS
                        if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
                        {
                            //CRITERIO DE ORDENAMIENTO
                            if ((list[i].typePassenger == list[j].typePassenger && strcmp(list[i].lastName, list[j].lastName)==-1)||list[i].typePassenger < list[j].typePassenger)
                            {

                                aux = list[i];
                                list[i] = list[j];
                                list[j] = aux;
                            }
                        }
                    }
                }
			ret = 0;
			break;
            default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			ret = -1;
			break;
		}
	}
    return ret;
}
int sortPassengersByCode(Passenger* list, int len, int order)
{
    int ret = -1;
    Passenger aux;
    int j;
    int i;
    if(list != NULL && len > 0 && order > -1)
    {
        switch(order)
        {
            case 1:
            for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
                {
					//PREGUNTO POR ESTADO VACIO DE AMBOS
					if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
                    {
						//CRITERIO DE ORDENAMIENTO
						if ((list[i].statusFlight == list[j].statusFlight && strcmp(list[i].flycode, list[j].flycode)== 1 )|| list[i].statusFlight > list[j].statusFlight)
                        {
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			ret = 0;
			break;


            case 0:
                for (i = 0; i < len - 1; i++)
                {
                    for (j = i + 1; j < len; j++)
                    {
                        //PREGUNTO POR ESTADO VACIO DE AMBOS
                        if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
                        {
                            //CRITERIO DE ORDENAMIENTO
                            if ((list[i].statusFlight == list[j].statusFlight && strcmp(list[i].flycode, list[j].flycode)==-1)||list[i].statusFlight< list[j].statusFlight)
                            {

                                aux = list[i];
                                list[i] = list[j];
                                list[j] = aux;
                            }
                        }
                    }
                }
			ret = 0;
			break;
            default:
            ret = -1;
            break;
        }
    }
    return ret;
}

