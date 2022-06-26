#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"
#include "funciones.h"

/*------------------------------------------------------------------------------------------------*/

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int ret = -1;
	FILE* f;
	f = fopen(path, "r");
	if(f != NULL && path != NULL && pArrayListPassenger != NULL)
	{
		parser_PassengerFromText(f, pArrayListPassenger);
		ret = 0;
	}
	fclose(f);
    return ret;
}
/*------------------------------------------------------------------------------------------------*/

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int ret = -1;
	FILE* f = NULL;
	f = fopen(path, "rb");
	if(f != NULL && path != NULL && pArrayListPassenger != NULL)
	{
		parser_PassengerFromBinary(f, pArrayListPassenger);
		ret = 0;
	}
	fclose(f);
    return ret;
}
/*------------------------------------------------------------------------------------------------*/

int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int ret = -1;
	Passenger* auxNewPassenger = NULL;
	int id;
	char nombre[128];
	char apellido[128];
	float precio;
	char tipoPasajero[30];
	char codigoVuelo[40];
	char estadoVuelo[30];
	int tipo;
	int estado;
	int tam;

	if(pArrayListPassenger != NULL)
	{
		tam = ll_len(pArrayListPassenger);
		auxNewPassenger = (Passenger*) ll_get(pArrayListPassenger, tam-1);
		id = idMaximo(pArrayListPassenger);
		auxNewPassenger = NULL;
		auxNewPassenger = Passenger_new();
		if(auxNewPassenger != NULL)
		{
			id++;
			Passenger_setId(auxNewPassenger, id);
			printf("\nAlta Pasajero\n");
			printf("ID: %d\n", id);
			getString(nombre, "\nIngrese el nombre: ", "\nError. Vuelva a ingresar el nombre: ", 16);
			Passenger_setNombre(auxNewPassenger, nombre);
			getString(apellido, "\nIngrese el apellido: ", "\nError. Vuelva a ingresar el apellido: ", 16);
			Passenger_setApellido(auxNewPassenger, apellido);
			getFloat(&precio, "\nIngrese el precio (10000-50000): ", "\nError. Vuelva a ingresar el precio: ", 10000, 50000);
			Passenger_setPrecio(auxNewPassenger, precio);
			getString(codigoVuelo,"\nIngrese el codigo de vuelo: ", "\nError. Ingrese un codigo de vuelo valido: ", 8);

			for(int i = 0; i < 8; i++)
			{
				codigoVuelo[i] = toupper(codigoVuelo[i]);
			}
			Passenger_setCodigoVuelo(auxNewPassenger, codigoVuelo);
			getInteger(&tipo, "\n1-Economy Class\n2-Executive Class\n3-First Class\nIngrese el tipo de pasajero: ",
					"\nIngrese un tipo de pasajero valido: ", 1,3);
			switch(tipo)
			{
				case 1:
					strcpy(tipoPasajero, "EconomyClass");
				break;
				case 2:
					strcpy(tipoPasajero, "ExecutiveClass");
				break;
				case 3:
					strcpy(tipoPasajero, "FirstClass");
				break;
			}
			Passenger_setTipoPasajero(auxNewPassenger, tipoPasajero);
			getInteger(&estado,"\n1-En Horario\n2-Aterrizado\n3-Demorado\nIngrese el estado de vuelo: ","\nIngrese un estado de vuelo valido: ",1,3);
			switch(estado)
			{
				case 1:
					strcpy(estadoVuelo, "En Horario");
				break;
				case 2:
					strcpy(estadoVuelo, "Aterrizado");
					break;
				case 3:
					strcpy(estadoVuelo, "Demorado");
					break;
			}
			Passenger_setEstadoVuelo(auxNewPassenger, estadoVuelo);
			ll_add(pArrayListPassenger, auxNewPassenger);
			printf("\nEl Pasajero se dio de alta exitosamente.\n");
			ret = 0;
		}
	}
    return ret;
}
/*------------------------------------------------------------------------------------------------*/

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int ret = -1;
	int indice;
	int opcion;
	int id;
	char nombre[128];
	char apellido[128];
	float precio;
	char tipoPasajero[30];
	char codigoVuelo[40];
	char estadoVuelo[30];
	int tipo;
	int estado;
	int idMax;
	char seguir = 'S';
	char salir;

	Passenger* auxPassenger;

	if(pArrayListPassenger != NULL)
	 {
		printf("\t***MODIFICAR PASAJEROS***\n");
		controller_ListPassenger(pArrayListPassenger);
		idMax = idMaximo(pArrayListPassenger);
		getInteger(&id, "\nIngrese el ID del pasajero a modificar: ", "\nERROR.Ingrese el ID de un pasajero valido",  1, idMax);
		indice = buscarPasajerosPorId(pArrayListPassenger, id);

		if(indice == -1)
		{
			printf("\nEl pasajero ingresado con el ID %d  no existe.\n", id);
		}
		else
		{
			auxPassenger = ll_get(pArrayListPassenger, indice);

			do
			{
				getInteger(&opcion, "\nModificar:\n1-Nombre\n2-Apellido\n3-Precio\n4-CodigoVuelo\n5-TipoPasajero\n6-EstadoVuelo\n7-Finalizar\nIngrese su opcion: ","\nError.Reingrese una opcion valida\n1-Nombre\n2-Apellido\n3-Precio\n4-CodigoVuelo\n5-TipoPasajero\n6-EstadoVuelo\n7-Finalizar\nIngrese su opcion: ", 1, 7);
				switch(opcion)
				{
				case 1:
					getString(nombre, "\nIngrese el nombre: ", "\nError. Vuelva a ingresar el nombre: ", 16);
					Passenger_setNombre(auxPassenger, nombre);
					printf("Nombre cambiado con exito \n");
					break;
				case 2:
					getString(apellido, "\nIngrese el apellido: ", "\nError. Vuelva a ingresar el apellido: ", 16);
					Passenger_setApellido(auxPassenger, apellido);
					printf("Apellido cambiado con exito \n");
					break;
				case 3:
					getFloat(&precio, "\nIngrese el precio (10000-50000): ", "\nError. Vuelva a ingresar el precio: ", 10000, 50000);
					Passenger_setPrecio(auxPassenger, precio);
					printf("Precio cambiado con exito \n");
					break;
				case 4:
					getString(codigoVuelo,"\nIngrese el codigo de vuelo: ", "\nError. Ingrese un codigo de vuelo valido: ", 8);

					for(int i = 0; i < 8; i++)
					{
						codigoVuelo[i] = toupper(codigoVuelo[i]);
					}
					Passenger_setCodigoVuelo(auxPassenger, codigoVuelo);
					printf("Codigo de vuelo cambiado con exito \n");
					break;

				case 5:
					getInteger(&tipo, "\n1-Economy Class\n2-Executive Class\n3-First Class\nIngrese el tipo de pasajero: ",
										"\nIngrese un tipo de pasajero valido: ", 1,3);
					switch (tipo)
					{
					case 1:
						strcpy(tipoPasajero, "FirstClass");
						break;
					case 2:
						strcpy(tipoPasajero, "ExecutiveClass");
						break;
					case 3:
						strcpy(tipoPasajero, "EconomyClass");
						break;
					}
					Passenger_setTipoPasajero(auxPassenger, tipoPasajero);
					printf("Tipo de pasajero cambiado con exito \n");
					break;

					case 6:
						getInteger(&estado,"\n1-En Horario\n2-Aterrizado\n3-Demorado\nIngrese el estado de vuelo: ","\nIngrese un estado de vuelo valido: ",1,3);
									switch(estado)
									{
										case 1:
											strcpy(estadoVuelo, "En Horario");
										break;
										case 2:
											strcpy(estadoVuelo, "Aterrizado");
											break;
										case 3:
											strcpy(estadoVuelo, "Demorado");
											break;
									}
						Passenger_setEstadoVuelo(auxPassenger, estadoVuelo);
						printf("Estado de vuelo cambiado con exito \n");
					break;

					case 7:
						 printf("\n¿Desea terminar las modificaciones? (S/N): ");
						 fflush(stdin);
						 scanf("%c", &salir);
						 salir = toupper(salir);
						 while(salir != 'S' && salir != 'N')
						 {
							 printf("\nERROR, Ingrese un caracter valido:\n¿Desea terminar las modificaciones? (S/N): ");
							 fflush(stdin);
							 scanf("%c", &salir);
							 salir = toupper(salir);
						 }
						 if(salir == 'S')
						 {
						    seguir = 'N';
						 }
						 else
						    {
						         break;
						    }
						break;
				   }

			}while(seguir != 'N');
		}
		ret = 0;
	 }
		return ret;
}
/*------------------------------------------------------------------------------------------------*/

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    int ret = 0;
    int id;
    int indice;
    Passenger* auxPassenger;

    if(pArrayListPassenger!= NULL)
    {
        controller_ListPassenger(pArrayListPassenger);
        printf("Introduzca el ID a borrar: ");
        scanf("%d", &id);
        for(int i = 0; i < ll_len(pArrayListPassenger); i++)
        {
        	auxPassenger = ll_get(pArrayListPassenger, i);
            if(auxPassenger->id == id)
            {
                indice = i;
                ll_remove(pArrayListPassenger, indice);
                ret = 1;
                break;
            }
        }

        if(ret == 0)
        {
            printf("Error. No existe el pasajero con ID: %d\n", id);
        }else
        {
            printf("El pasajero se elimino exitosamente\n");
        }
    }
    return ret;
}
/*------------------------------------------------------------------------------------------------*/

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int ret = -1;
	Passenger* auxPassenger = NULL;
	int id;
	char nombre[16];
	char apellido[16];
	float precio;
	char codigoVuelo[30];
	char tipoPasajero[30];
	char estadoVuelo[30];

	if(pArrayListPassenger != NULL)
	{
		printf("\t***PASAJEROS***\n");
		printf("   ID       Nombre        Apellido    Precio  Codigo Vuelo  Tipo Pasajero  Estado Vuelo\n");
		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_getId(auxPassenger, &id);
			Passenger_getNombre(auxPassenger, nombre);
			Passenger_getApellido(auxPassenger, apellido);
			Passenger_getPrecio(auxPassenger, &precio);
			Passenger_getCodigoVuelo(auxPassenger, codigoVuelo);
			Passenger_getTipoPasajero(auxPassenger, tipoPasajero);
			Passenger_getEstadoVuelo(auxPassenger, estadoVuelo);

			printf("  %4d  %13s   %13s  %2.f  %7s  %15s  %15s \n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
		}
		ret = 0;
	}
    return ret;
}
/*------------------------------------------------------------------------------------------------*/

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int ret = -1;
	int option;

	if(pArrayListPassenger != NULL)
	{
		getInteger(&option,"Menu Ordenar:\n1.Por Nombre.\n2.Por Apellido.\n3.Por Precio.\n4.Por CodigoVuelo.\n5.Por TipoPasajero.\n6 Por EstadoVuelo.\nElija la opcion: ",
				"Error. Ingreso una opcion no valida.\nMenu Ordenar:\n1.Por Nombre.\n2.Por Apellido.\n3.Por Precio.\n4.Por CodigoVuelo.\n5.Por TipoPasajero.\n6 Por EstadoVuelo.\nElija la opcion: ", 1,6);
		printf("\n\n");
					switch(option)
					{
					case 1:
						printf("\nLa Lista esta cargando...\n");
						ll_sort(pArrayListPassenger, Passenger_sortByName, 1);
						break;
					case 2:
						printf("\nLa Lista esta cargando...\n");
						ll_sort(pArrayListPassenger, Passenger_sortByLastName, 1);
						break;
					case 3:
						printf("\nLa Lista esta cargando...\n");
						ll_sort(pArrayListPassenger, Passenger_sortByPrice, 1);
						break;
					case 4:
						printf("\nLa Lista esta cargando...\n");
						ll_sort(pArrayListPassenger, Passenger_sortByCode, 1);
						break;
					case 5:
						printf("\nLa Lista esta cargando...\n");
						ll_sort(pArrayListPassenger, Passenger_sortByType, 1);
						break;
					case 6:
						printf("\nLa Lista esta cargando...\n");
						ll_sort(pArrayListPassenger, Passenger_sortByStatus, 1);
						break;
					}
		printf("\n\n");

		ret = 1;
	}
	    return ret;
}
/*------------------------------------------------------------------------------------------------*/

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	FILE* pFile = fopen(path,"w");
	Passenger* auxPassenger;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	char tipoPasajero[20];
	char codigoVuelo[20];
	char estadoVuelo[30];
	float precio;

	if (pFile !=NULL && pArrayListPassenger != NULL)
	{
        fprintf(pFile,"ID,NOMBRE,APELLIDO,PRECIO,CODIGO VUELO,TIPO PASAJERO,ESTADO VUELO\n");
        for(int i = 1; i < ll_len(pArrayListPassenger); i++)
        {
        		auxPassenger = ll_get(pArrayListPassenger, i);

            		Passenger_getId(auxPassenger, &auxId);
                    Passenger_getNombre(auxPassenger, auxNombre);
					Passenger_getApellido(auxPassenger, auxApellido);
					Passenger_getPrecio(auxPassenger, &precio);
					Passenger_getCodigoVuelo(auxPassenger, codigoVuelo);
					Passenger_getTipoPasajero(auxPassenger, tipoPasajero);
					Passenger_getEstadoVuelo(auxPassenger, estadoVuelo);



                fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n", auxId, auxNombre, auxApellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);

        }
        todoOk = 1;
        fclose(pFile);
	}
	return todoOk;
}
/*------------------------------------------------------------------------------------------------*/

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int ret = 0;
	    Passenger* auxPassenger = NULL;
	    FILE* f = NULL;
	    f = fopen(path, "wb");
	    if(f != NULL && pArrayListPassenger != NULL)
	    {
	        for(int i = 0; i < ll_len(pArrayListPassenger); i++)
	        {
	            auxPassenger = ll_get(pArrayListPassenger, i);
	            if(auxPassenger != NULL)
	            {
	               fwrite(auxPassenger, 1 ,sizeof(Passenger), f);
	            }
	        }
	    }

	    fclose(f);
	    return ret;
}
