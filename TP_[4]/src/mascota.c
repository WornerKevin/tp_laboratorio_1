/*
 * mascota.c
 *
 *  Created on: 16 jun. 2022
 *      Author: Kevin Worner
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascota.h"


eMascota* nuevaMascota()
{
    eMascota* nuevaMascota = (eMascota*) malloc(sizeof(eMascota));
    return nuevaMascota;
}

eMascota* nuevaMascotaParametros(int id, char* nombre, char* tipo, int edad)
{
	eMascota* nuevaMascotaAux = nuevaMascota();
	    if(nuevaMascotaAux != NULL)
	    {
	        if(!((mascotaSetterId(nuevaMascotaAux, id)) &&
	           (mascotaSetterNombre(nuevaMascotaAux, nombre)) &&
	           (mascotaSetterTipo(nuevaMascotaAux, tipo)) &&
	           (mascotaSetterEdad(nuevaMascotaAux, edad))))
	        {
	            free(nuevaMascotaAux);
	            nuevaMascotaAux = NULL;
	        }
	    }
	    return nuevaMascotaAux;
}

int mostrarMascotas(LinkedList* lista)
{
    int ret = 0;
    eMascota* auxMascota = NULL;
    if(lista != NULL)
    {
    	printf("  ID      NOMBRE    TIPO     EDAD  \n");
        for(int i = 0; i < ll_len(lista); i++)
        {
            auxMascota = (eMascota*) ll_get(lista, i);
            mostrarMascota(*auxMascota);
        }
        ret = 1;
    }
    return ret;
}
int mostrarMascota(eMascota mascota)
{
	int ret = -1;
	    printf("   %4d        %10s       %10s    %4d\n", mascota.id, mascota.nombre, mascota.tipo, mascota.edad);
	    ret = 1;
	    return ret;
}

int mascotaSetterId(eMascota* this, int id)
{
    int ret = 0;
    if(this != NULL)
    {
        this->id = id;
        ret = 1;
    }
    return ret;

}
int mascotaSetterNombre(eMascota* this, char* nombre)
{
    int ret = 0;
    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        ret = 1;
    }
    return ret;
}
int mascotaSetterTipo(eMascota* this, char* tipo)
{
    int ret = 0;
    if(this != NULL)
    {
        strcpy(this->tipo, tipo);
        ret = 1;
    }
    return ret;
}
int mascotaSetterEdad(eMascota* this, int edad)
{
    int ret = 0;
    if(this != NULL)
    {
        this->edad = edad;
        ret = 1;
    }

    return ret;
}

int mascotaGetterId(eMascota* this, int* id)
{
    int ret = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        ret = 1;
    }
    return ret;
}

int mascotaGetterNombre(eMascota* this, char* nombre)
{
    int ret = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        ret = 1;
    }
    return ret;
}

int mascotaGetterTipo(eMascota* this, char* tipo)
{
    int ret = 0;
    if(this != NULL && tipo != NULL)
    {
        strcpy(tipo, this->tipo);
        ret = 1;
    }
    return ret;
}

int mascotaGetterEdad(eMascota* this, int* edad)
{
    int ret = 0;
    if(this != NULL && edad != NULL)
    {
        *edad = this->edad;
        ret = 1;
    }
    return ret;
}

int ordenarPorEdad(void* pElement1, void* pElement2)
{
    int ret = 0;
    eMascota* Element1 = (eMascota*) pElement1;
    eMascota* Element2 = (eMascota*) pElement2;
    if(Element1 != NULL && Element2 != NULL)
    {
        if(Element1->edad > Element2->edad)
        {
            ret = 1;
        }
        else if(Element1->edad < Element2->edad)
        {
            ret = -1;
        }
    }
    return ret;
}
