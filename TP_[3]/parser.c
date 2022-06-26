#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

		Passenger* auxPassenger = NULL;

		char id[50];
		char nombre[50];
		char apellido[50];
		char precio[20];
		char tipoPasajero[50];
		char codigoVuelo[50];
		char estadoVuelo[20];

		int cant;


		if(pFile != NULL && pArrayListPassenger != NULL)
		{

			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

			do
			{
				cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);


				if(cant < 7)
				{
					break;
				}

				auxPassenger = Passenger_newParametros(id, nombre, apellido,precio, codigoVuelo, tipoPasajero,estadoVuelo);

				if(auxPassenger != NULL)
				{
					ll_add(pArrayListPassenger,auxPassenger);
					retorno = 0;
				}
			}while(!feof(pFile));
		}
	    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int ret = -1;
	Passenger* auxNewPassenger = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			auxNewPassenger = Passenger_new();
			if(auxNewPassenger != NULL)
			{
				if(fread(auxNewPassenger, sizeof(Passenger),1,pFile)==1)
				{
					ll_add(pArrayListPassenger, auxNewPassenger);
					auxNewPassenger = NULL;
					ret = 0;
				}
			}
		}while(!feof(pFile));
	}
    return ret;
}
