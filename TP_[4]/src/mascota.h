/*
 * mascota.h
 *
 *  Created on: 16 jun. 2022
 *      Author: Kevin Worner
 */

#ifndef SRC_MASCOTA_H_
#define SRC_MASCOTA_H_
#include "../inc/LinkedList.h"
struct{
	int id;
	char nombre[20];
	char tipo[20];
	int edad;
}typedef eMascota;


eMascota* nuevaMascota();

eMascota* nuevaMascotaParametros(int id, char* nombre, char* tipo, int edad);

int mostrarMascotas(LinkedList* lista);
int mostrarMascota(eMascota mascota);

int mascotaSetterId(eMascota* this, int id);
int mascotaSetterNombre(eMascota* this, char* nombre);
int mascotaSetterTipo(eMascota* this, char* tipo);
int mascotaSetterEdad(eMascota* this, int edad);

int mascotaGetterId(eMascota* this, int* id);
int mascotaGetterNombre(eMascota* this, char* nombre);
int mascotaGetterTipo(eMascota* this, char* tipo);
int mascotaGetterEdad(eMascota* this, int* edad);

int ordenarPorEdad(void* pElement1, void* pElement2);


#endif /* SRC_MASCOTA_H_ */
