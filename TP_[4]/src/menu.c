/*
 * menu.c
 *
 *  Created on: 17 jun. 2022
 *      Author: Kevin Worner
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int menu()
{
	 	int opcion;
	    printf("\t***TRABAJO PRACTICO LINKEDLIST***\n\n");
	    printf("1. Testear con los testings.\n");
	    printf("2. Testear en programa.\n");
	    printf("3. Salir\n");
	    printf("Seleccione una opcion: ");
	    fflush(stdin);
	    scanf("%d", &opcion);
	    while(opcion < 1 || opcion > 3)
	    {
	        printf("\nError. Seleccione una opcion valida: ");
	        fflush(stdin);
	        scanf("%d", &opcion);
	    }
	    return opcion;
}
