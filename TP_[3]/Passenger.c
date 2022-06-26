#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* newPassenger = (Passenger*) malloc(sizeof(Passenger));

	return newPassenger;
}
/*-----------------------------------------------------------------------------------------------*/
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr, char* codigoVueloStr,char* tipoPasajeroStr, char* estadoVuelo)
{
	Passenger* newPassenger = Passenger_new();
	int auxId;
	int auxPrecio;

	if(newPassenger != NULL)
	{
		auxId = atoi(idStr);
		auxPrecio = atof(precioStr);
		Passenger_setId(newPassenger, auxId);
		Passenger_setNombre(newPassenger, nombreStr);
		Passenger_setApellido(newPassenger, apellidoStr);
		Passenger_setPrecio(newPassenger, auxPrecio);
		Passenger_setCodigoVuelo(newPassenger, codigoVueloStr);
		Passenger_setTipoPasajero(newPassenger, tipoPasajeroStr);
		Passenger_setEstadoVuelo(newPassenger, estadoVuelo);

	}
	return newPassenger;
}
/*-----------------------------------------------------------------------------------------------*/
void Passenger_delete(Passenger* this)
{
	free(this);
}
/*-----------------------------------------------------------------------------------------------*/
//SETTERS
int Passenger_setId(Passenger* this,int id)
{
	int ret = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		ret = 0;
	}
	return ret;
}
/*------------------------------------------------------------------------------------------------*/
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int ret = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		ret = 0;
	}

	return ret;
}
/*-------------------------------------------------------------------------------------------------*/
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int ret = -1;
	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------------*/
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int ret = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------------*/
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int ret = -1;
	if(this != NULL)
	{
		strcpy(this->tipoPasajero, tipoPasajero);
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------------*/
int Passenger_setPrecio(Passenger* this,float precio)
{
	int ret = -1;
	if(this != NULL)
	{
		this->precio = precio;
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int ret = -1;
	if(this != NULL)
	{
		strcpy(this->estadoVuelo, estadoVuelo);
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
//GETTERS
int Passenger_getId(Passenger* this,int* id)
{
	int ret = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int ret = -1;
	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int ret = -1;
	if(this != NULL)
	{
		strcpy(apellido, this->apellido);
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int ret = -1;
	if(this != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int ret = -1;
	if(this != NULL)
	{
		strcpy(tipoPasajero, this->tipoPasajero);
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int ret = -1;
	if(this != NULL)
	{
		*precio = this->precio;
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int ret = -1;
	if(this != NULL)
	{
		strcpy(estadoVuelo, this->estadoVuelo);
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int idMaximo(LinkedList* listaPasajeros)
{
	int id;
    Passenger* auxPassenger = NULL;
    int maximo= 0;
    if(listaPasajeros != NULL)
    {

        for( int i = 0; i < ll_len(listaPasajeros); i++)
        {
        	auxPassenger = (Passenger*) ll_get(listaPasajeros, i);
            Passenger_getId(auxPassenger, &id);
            if( i==0 || id > maximo)
            {
                maximo = id;
            }
        }

    }
    return maximo;
}
/*-----------------------------------------------------------------------------------------------*/
int buscarPasajerosPorId(LinkedList* listaPasajeros, int id)
{
	Passenger* auxPassenger;
	int indice = -1;
	int tam;

	tam = ll_len(listaPasajeros);
	for(int i = 0; i < tam; i++)
	{
	      auxPassenger = ll_get(listaPasajeros, i);
	      if(auxPassenger->id == id)
	      {
	                indice = i;
	                break;
	      }
	}

	    return indice;
}
/*-----------------------------------------------------------------------------------------------*/
int Passenger_sortByName(void* nombre1,void* nombre2)
{
	int ret = 0;
	Passenger* passenger1 = NULL;
	Passenger* passenger2 = NULL;
	if(nombre2 != NULL && nombre1 != NULL)
	{
		passenger1 = (Passenger*) nombre1;
		passenger2 = (Passenger*) nombre2;

		ret = strcmp(passenger1->nombre,passenger2->nombre);
	}

	    return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Passenger_sortByLastName(void* apellido1,void* apellido2)
{
	int ret = 0;
	Passenger* passenger1 = NULL;
	Passenger* passenger2 = NULL;

	if(apellido1 != NULL && apellido2 != NULL)
	{
		passenger1 = (Passenger*) apellido1;
		passenger2 = (Passenger*) apellido2;

		ret = strcmp(passenger1->apellido,passenger2->apellido);
	}

	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Passenger_sortByPrice(void* precio1,void* precio2)
{
	int ret = 0;
	Passenger* passenger1 = NULL;
	Passenger* passenger2 = NULL;

	if(precio1 != NULL && precio2 != NULL)
	{
		passenger1 = (Passenger*) precio1;
		passenger2 = (Passenger*) precio2;

		 if(passenger1->precio > passenger2->precio)
		 {
		         ret = 1;
		 }
		 else if(passenger1->precio <passenger2->precio)
		 {
		            ret = -1;
		 }
	}

	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Passenger_sortByCode(void* codigo1,void* codigo2)
{
	int ret = 0;
	Passenger* passenger1 = NULL;
	Passenger* passenger2 = NULL;

	if(codigo1 != NULL && codigo2 != NULL)
	{
		passenger1 = (Passenger*) codigo1;
		passenger2 = (Passenger*) codigo2;

		ret = strcmp(passenger1->codigoVuelo,passenger2->codigoVuelo);
	}

	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Passenger_sortByType(void* tipo1,void* tipo2)
{
	int ret = 0;
	Passenger* passenger1 = NULL;
	Passenger* passenger2 = NULL;

	if(tipo1 != NULL && tipo2 != NULL)
	{
		passenger1 = (Passenger*) tipo1;
		passenger2 = (Passenger*) tipo2;

		ret = strcmp(passenger1->tipoPasajero,passenger2->tipoPasajero);
	}

	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Passenger_sortByStatus(void* estado1,void* estado2)
{
	int ret = 0;
	Passenger* passenger1 = NULL;
	Passenger* passenger2 = NULL;

	if(estado1 != NULL && estado2 != NULL)
	{
		passenger1 = (Passenger*) estado1;
		passenger2 = (Passenger*) estado2;
		ret = strcmp(passenger1->estadoVuelo,passenger2->estadoVuelo);
	}

	return ret;
}
/*------------------------------------------------------------------------------------------------*/
