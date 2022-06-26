#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();

int main()
{
	setbuf(stdout,NULL);

	int flag = 0;
    int opcion = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    if(listaPasajeros == NULL)
    {
    	exit(1);
    }

    do{

    	opcion = menu();

        switch(opcion)
        {
            case 1:
            	if(!flag)
            	{
            		controller_loadFromText("data.csv",listaPasajeros);
            		printf("El archivo de texto se cargo con exito \n");
            		flag = 1;
            	}
            	break;

            case 2:
            	if(!flag)
            	{
            		controller_loadFromBinary("data.bin",listaPasajeros);
            		printf("El archivo binario se cargo con exito \n");
            		flag = 1;
            	}
            	break;
            case 3:
            	if(flag)
            	{
            		controller_addPassenger(listaPasajeros);
            	}else
            	{
            		printf("\nDebe cargar los archivos de los pasajeros previamente \n\n");
            	}
            	break;
            case 4:
            	if(flag)
            	{
            		controller_editPassenger(listaPasajeros);
        		}
            	else
            	{
            		printf("\nDebe cargar los archivos de los pasajeros previamente \n\n");
            	}
            	break;
            case 5:
            	if(flag)
            	{
            		controller_removePassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nDebe cargar los archivos de los pasajeros previamente\n\n");
            	}
            	break;

            case 6:
            	if(flag)
            	{
            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nDebe cargar los archivos de los pasajeros previamente \n\n");
            	}
            	system("pause");
            	break;
            case 7:
            	if(flag)
            	{

            		controller_sortPassenger(listaPasajeros);
            		controller_ListPassenger(listaPasajeros);
            		system("pause");
            	}
            	else
            	{
            		printf("\nDebe cargar los archivos de los pasajeros previamente \n\n");
            	}
            	break;
            case 8:
            	if(flag)
            	{
            		controller_saveAsText("data.csv", listaPasajeros);
            		printf("Archivo de texto guardado correctamente\n");
            		flag = 0;
            	}
            	else
            	{
            		printf("\nDebe cargar el archivo de texto de los pasajeros previamente \n\n");
            	}
            	break;
            case 9:
            	if(flag)
            	{
            		controller_saveAsBinary("data.bin", listaPasajeros);
            		printf("Archivo binario guardado correctamente\n");
            		flag = 0;
            	}
            	else
            	{
            		printf("\nDebe cargar el archivo binario de los pasajeros previamente \n\n");
            	}
            	break;
            case 10:
            	printf("\nSaliste del programa exitosamente.\n");
            	break;

        }
    }while(opcion != 10);
    return 0;
}

int menu()
{
	 	int opcion;
	    printf("\t***Bienvenido a la Agencia de Vuelos***\n");
	    printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
	    printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
	    printf("3. Alta de pasajero\n");
	    printf("4. Modificar datos de pasajero\n");
	    printf("5. Baja de pasajero\n");
	    printf("6. Listar pasajeros\n");
	    printf("7. Ordenar pasajeros\n");
	    printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
	    printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
	    printf("10. Salir\n");
	    printf("Elija una opcion: ");
	    fflush(stdin);
	    scanf("%d", &opcion);
	    while(opcion < 1 || opcion > 10)
	    {
	        printf("Error. Elija una opcion valida: ");
	        fflush(stdin);
	        scanf("%d", &opcion);
	    }
	    return opcion;
}

