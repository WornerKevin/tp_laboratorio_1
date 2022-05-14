/*
 * funciones.h
 *
 *  Created on: 28 abr. 2022
 *      Author: Kevin Worner
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


/**
 * @brief organiza el submenu de la opcion 4(informar) manejando con un switch las posibles elecciones del usuario
 *
 * @param list puntero al array de Pasajeros
 * @param tamList tamaño del array
 * @param respuesta numero de elegido por el usuario para el submenu
 * @return retorna -1 si hubo un error y 0 si se ejecuto Ok
 */
int submenu(Passenger* list,int tamList, int respuesta);

/**
 * @brief Realiza la carga forzada de pasajeros
 *
 * @param list puntero al array de pasajeros
 * @param tamList tamaño del array
 * @param id puntero al id del pasajero
 * @param contador puntero al contador de pasajeros
 * @return retorna -1 si hubo un error y 0 si se ejecuto Ok
 */
int hardcode(Passenger* list,int* id, int* contador);

#endif /* FUNCIONES_H_ */
