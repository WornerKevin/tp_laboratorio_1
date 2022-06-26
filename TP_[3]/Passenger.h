/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "LinkedList.h"
typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[40];
	char codigoVuelo[40];
	char estadoVuelo[40];

}Passenger;

/**
 * @brief Constructor que pide espacio en memoria dinamica
 *
 * @return direccion que se encontro
 */
Passenger* Passenger_new();

/**
 * @brief Agrega nuevos parametros para los setters
 *
 * @param idStr
 * @param nombreStr
 * @param apellidoStr
 * @param precioStr
 * @param codigoVueloStr
 * @param tipoPasajeroStr
 * @param estadoVuelo
 * @return
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr, char* codigoVueloStr,char* tipoPasajeroStr, char* estadoVuelo);

/**
 * @brief Elimina un pasajero de la lista con free()
 *
 * @param this
 */
void Passenger_delete(Passenger* this);


/**
 * @brief Setter de ID
 *
 * @param this
 * @param id
 * @return
 */
int Passenger_setId(Passenger* this,int id);

/**
 * @brief Getter de ID
 *
 * @param this
 * @param id
 * @return
 */
int Passenger_getId(Passenger* this,int* id);


/**
 * @brief Setea el Nombre
 *
 * @param this
 * @param nombre
 * @return
 */
int Passenger_setNombre(Passenger* this,char* nombre);

/**
 * @brief Obtiene el nombre
 *
 * @param this
 * @param nombre
 * @return
 */
int Passenger_getNombre(Passenger* this,char* nombre);


/**
 * @brief Setea el apellido
 *
 * @param this
 * @param apellido
 * @return
 */
int Passenger_setApellido(Passenger* this,char* apellido);

/**
 * @brief obtiene el apellido
 *
 * @param this
 * @param apellido
 * @return
 */
int Passenger_getApellido(Passenger* this,char* apellido);

/**
 * @brief setea el codigo de vuelo
 *
 * @param this
 * @param codigoVuelo
 * @return
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);


/**
 * @brief obtiene el codigo de vuelo
 *
 * @param this
 * @param codigoVuelo
 * @return
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);


/**
 * @brief setea el tipo de pasajero
 *
 * @param this
 * @param tipoPasajero
 * @return
 */
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);


/**
 * @brief obtiene el tipo de pasajero
 *
 * @param this
 * @param tipoPasajero
 * @return
 */
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);


/**
 * @brief setea el precio
 *
 * @param this
 * @param precio
 * @return
 */
int Passenger_setPrecio(Passenger* this,float precio);


/**
 * @brief obtiene el precio
 *
 * @param this
 * @param precio
 * @return
 */
int Passenger_getPrecio(Passenger* this,float* precio);


/**
 * @brief setea el estado de vuelo
 *
 * @param this
 * @param estadoVuelo
 * @return
 */
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);

/**
 * @brief Obtiene el estado de vuelo
 *
 * @param this
 * @param estadoVuelo
 * @return
 */
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

/**
 * @brief Obtiene el ID maximo de la lista
 *
 * @param listaPasajeros
 * @return
 */
int idMaximo(LinkedList* listaPasajeros);

/**
 * @brief Recibe por parametro un ID y busca un pasajero con ese numero de ID.
 *
 * @param listaPasajeros
 * @param id
 * @return
 */
int buscarPasajerosPorId(LinkedList* listaPasajeros, int id);
//SORT
/**
 * @brief Ordena la lista por nombre
 *
 * @param nombre1
 * @param nombre2
 * @return
 */
int Passenger_sortByName(void* nombre1,void* nombre2);

/**
 * @brief Ordena la lista por apellido
 *
 * @param apellido1
 * @param apellido2
 * @return
 */
int Passenger_sortByLastName(void* apellido1,void* apellido2);

/**
 * @brief Ordena la lista por precio
 *
 * @param precio1
 * @param precio2
 * @return
 */
int Passenger_sortByPrice(void* precio1,void* precio2);

/**
 * @brief Ordena la lista por codigo de vuelo
 *
 * @param codigo1
 * @param codigo2
 * @return
 */
int Passenger_sortByCode(void* codigo1,void* codigo2);

/**
 * @brief Ordena por tipo de pasajero
 *
 * @param tipo1
 * @param tipo2
 * @return
 */
int Passenger_sortByType(void* tipo1,void* tipo2);

/**
 * @brief Ordena la lista por estado de vuelo
 *
 * @param estado1
 * @param estado2
 * @return
 */
int Passenger_sortByStatus(void* estado1,void* estado2);

#endif /* PASSENGER_H_ */
