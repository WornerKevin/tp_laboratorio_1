/*
 * menu.h
 *
 *  Created on: 28 abr. 2022
 *      Author: Kevin Worner
 */

#ifndef MENU_H_
#define MENU_H_

/**
 * @brief Muestra el menu de opciones y pide los datos
 *
 * @param respuesta puntero a la variable que guarda la opcion elegida
 * @return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 */
int menu(int* respuesta);


/**
 * @brief Pide los datos de los pasajeros para luego llamar a la funcion que se los asignara a el array de la estructura
 *
 * @param list puntero al array de pasajeros
 * @param id puntero al id de pasajeros
 * @param tamList tamaño del array
 * @return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 */
int agregarPasajero(Passenger* list, int* id, int tamList);


/**
 * @brief Pide el id del pasajero y los datos a modificar utilizando la funcion que busca el pasajero en la estructura
 *
 * @param list puntero al array de la estructura
 * @param tamList tamaño del array
 * @return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 */
int modificarPasajero(Passenger* list,int tamList);


/**
 * @brief Pide el id del pasajero a eliminar utilizando la funcion que busca el pasajero en la estructura
 *
 * @param list puntero al array de la estructura
 * @param tamList tamaño del array
 * @return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 */
int eliminarPasajero(Passenger* list, int tamList);


/**
 * @brief Realiza el calculo necesario para la opcion 2 del INFORMAR
 *
 * @param list puntero al array de la estrucutura
 * @param tamList tamaño del array
 * @param contadorPasajeros Promedio puntero al contador de pasajeros que superan el promedio
 * @param promedioPasajes puntero al promedio de precio de pasajes
 * @param acumuladorPasajes puntero al total de precios
 * @return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 */
int calculosPasajes(Passenger* list, int tamList, int* contadorPasajerosPromedio, float* promedioPasajes, float* acumuladorPasajes);


/**
 * @brief Muestra los calculos de Total Promedio y los pasajeros que superan el promedio
 *
 * @param contadorPasajerosPromedio puntero al contador
 * @param promedioPasajes puntero al promedio de precio de pasajes
 * @param acumuladorPasajes puntero a la suma total de precio de pasajes
 * @return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 */
int mostrarCalculos(int* contadorPasajerosPromedio, float* promedioPasajes, float* acumuladorPasajes);



/**
 * @brief Muestra el pasajero seleccionado
 *
 * @param list puntero al array de Pasajero
 * @param tamList tamaño del array
 * @param id id del pasajero a mostrar
 * @return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 */
int mostrarPasajero(Passenger* list, int tamList, int id);
#endif /* MENU_H_ */
