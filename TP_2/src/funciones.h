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


#endif /* FUNCIONES_H_ */
