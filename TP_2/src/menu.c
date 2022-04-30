/*
 * menu.c
 *
 *  Created on: 28 abr. 2022
 *      Author: Kevin Worner
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "input.h"
#include "menu.h"
#include "funciones.h"
#include <string.h>
#define ORDENASC 1
#define ORDENDESC 0



int menu(int* respuesta)
{
	int ret = -1;
	int r;

	if(respuesta != NULL)
	{
		printf("\n1-ALTAS\n");
		printf("2-MODIFICAR\n");
		printf("3-BAJA\n");
		printf("4-INFORMAR\n");
		printf("5-ALTA FORZADA DE PASAJEROS\n");
		printf("6-SALIR\n");
		printf("Ingrese una opcion: ");
		r = scanf("%d", respuesta);
		while(r==0 || *respuesta > 6)
		{
			printf("Error, reingrese una opcion valida: ");
			fflush(stdin);
			r = scanf("%d", respuesta);
		}
		ret=0;
	}
	return ret;
}

int agregarPasajero(Passenger* list,int* id, int tamList)
{
    int ret = -1;

    char nombre[51];
    char apellido[51];
    float precio;
    char codigoVuelo[10];
    int tipoPasajero;

    if(list != NULL && id != NULL && tamList > 0)
    {
        printf("\nID = %d\n", *id);
        getString(nombre,"\nIngrese el nombre: ", "\nError. Vuelva a ingresar el nombre: ", 10);
        getString(apellido, "\nIngrese el apellido: ", "\nError. Vuelva a ingresar el apellido: ", 10);
        getFloat(&precio, "\nIngrese el precio: ", "\nError. Vuelva a ingresar el precio: ", 10000, 2000000);
        getString(codigoVuelo, "\nIngrese el codigo de vuelo: ", "\nError. Vuelva a ingresar el codigo de vuelo: ", 7);
        getInteger(&tipoPasajero, "\nIngrese el tipo de pasajero: ", "\nError. Vuelva a ingresar el tipo de pasajero: ", 1, 4);
        addPassenger(list, tamList, *id, nombre, apellido, precio, tipoPasajero, codigoVuelo);
        *id = *id + 1;
        printf("\nSe creo Exitosamente.\n");
        ret = 0;
    }
    return ret;
}
int modificarPasajero(Passenger* list,int tamList)
{
    Passenger pasajeroModificado;
    int ret = -1;
    int id;
    int opcion;
    int i = -1;

    if(list != NULL && tamList > 0)
    {
        printPassenger(list, tamList);
        printf("\nIngrese el numero de ID del pasajero: ");
        scanf("%d", &id);
        i = findPassengerById(list, tamList, id);
        if(i != -1)
        {
            pasajeroModificado = list[i];
            printf("\nID = %d\n", id);
            printf("\nMODIFICAR:\n1-Nombre\n2-Apellido\n3-Precio\n4-Codigo de vuelo\n5-Tipo de pasajero\nIngrese la opcion: ");
            scanf("%d", &opcion);
            switch(opcion)
            {
                case 1:
                    getString(pasajeroModificado.name,"\nIngrese el nombre: ", "\nError. Vuelva a ingresar el nombre: ", 10);
                    break;
                case 2:
                    getString(pasajeroModificado.lastName, "\nIngrese el apellido: ", "\nError. Vuelva a ingresar el apellido: ", 10);
                    break;
                case 3:
                    getFloat(&pasajeroModificado.price, "\nIngrese el precio: ", "\nError. Vuelva a ingresar el precio: ", 10000, 2000000);
                    break;
                case 4:
                    getString(pasajeroModificado.flycode, "\nIngrese el codigo de vuelo: ", "\nError. Vuelva a ingresar el codigo de vuelo: ", 7);
                    break;
                case 5:
                    getInteger(&pasajeroModificado.typePassenger, "\nIngrese el tipo de pasajero: ", "\nError. Vuelva a ingresar el tipo de pasajero: ", 1, 4);
                    break;
            }
            list[i] = pasajeroModificado;
            printf("\nSe modifico Exitosamente.\n");
            ret = 0;
        }
        else
        {
            printf("\nError. El ID ingresado no existe.\n");
        }
    }
        return ret;
}

int eliminarPasajero(Passenger* list, int tamList)
{
    int ret = -1;
    int id;
    int i = -1;
    if(list != NULL && tamList > 0)
    {
        printPassenger(list, tamList);
        printf("\nIngrese el ID del pasajero que desea eliminar: ");
        scanf("%d", &id);
        i = removePassenger(list, tamList, id);
        if(i == 0)
        {
            printf("\nPasajero eliminado correctamente.");
            ret = 0;
        }
            else
            {
                printf("ERROR. El ID ingresado no existe.");
            }



    }
    return ret;
}
int calculosPasajes(Passenger* list, int tamList, int* contadorPasajerosPromedio, float* promedioPasajes, float* acumuladorPasajes)
{
    int ret = -1;
    int contadorPasajeros = 0;

    if(list != NULL && tamList > 0)
    {
        for(int i = 0; i < tamList; i++)
        {
            if(list[i].isEmpty == 0)
            {
                contadorPasajeros++;
                *acumuladorPasajes = *acumuladorPasajes + list[i].price;
            }
        }
        *promedioPasajes = *acumuladorPasajes / (float)contadorPasajeros;
        for(int i = 0; i < tamList; i++)
        {
            if(list[i].isEmpty == 0 && list[i].price > *promedioPasajes)
            {
                *contadorPasajerosPromedio = *contadorPasajerosPromedio + 1;
            }
        }
        ret = 0;
    }
    return ret;
}
int mostrarCalculos(int* contadorPasajerosPromedio, float* promedioPasajes, float* acumuladorPasajes)
{
    int ret = -1;
    if(contadorPasajerosPromedio > 0 && promedioPasajes > 0 && acumuladorPasajes > 0)
    {
        printf("\n|\tTOTAL PRECIO\t|\tPROMEDIO DE PRECIO\t|\tPASAJEROS QUE SUPERAN EL PROMEDIO\t|\n");
        printf("|-----------------------|-------------------------------|-----------------------------------------------|\n");
        printf("|\t%7.2f\t|\t%7.2f\t        |\t\t%d\t\t                |\n", *acumuladorPasajes, *promedioPasajes, *contadorPasajerosPromedio);
        ret = 0;
    }
    return ret;
}
