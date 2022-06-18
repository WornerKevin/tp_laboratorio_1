/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "mascota.h"
#include "menu.h"


int main(void)
{
	setbuf(stdout, NULL);
	LinkedList* lista = ll_newLinkedList();
	LinkedList* listaAux = NULL;
	LinkedList* listaClon = NULL;
	int opcion;
	eMascota* mascota1 = nuevaMascotaParametros(0, "Copito", "Perro", 7);
	eMascota* mascota2 = nuevaMascotaParametros(1, "Roco", "Perro", 5);
	eMascota* mascota3 = nuevaMascotaParametros(2, "Lisa", "Gato", 10);
	eMascota* mascota4 = nuevaMascotaParametros(3, "Ema", "Hamster", 1);
	eMascota* auxMascota = NULL;

	do
	{
		opcion = menu();

		switch(opcion)
		{

			case 1:
				startTesting(1);  // ll_newLinkedList
				startTesting(2);  // ll_len
				startTesting(3);  // getNode - test_getNode
				startTesting(4);  // addNode - test_addNode
				startTesting(5);  // ll_add
				startTesting(6);  // ll_get
				startTesting(7);  // ll_set
				startTesting(8);  // ll_remove
				startTesting(9);  // ll_clear
				startTesting(10); // ll_deleteLinkedList
				startTesting(11); // ll_indexOf
				startTesting(12); // ll_isEmpty
				startTesting(13); // ll_push
				startTesting(14); // ll_pop
				startTesting(15); // ll_contains
				startTesting(16); // ll_containsAll
				startTesting(17); // ll_subList
				startTesting(18); // ll_clone
				startTesting(19); // ll_sort
			break;
			case 2:
				printf("\nll_add:\n");
					    printf("Lista de Mascotas\n");
					    ll_add(lista, mascota1);
					    ll_add(lista, mascota2);
					    ll_add(lista, mascota3);
					    mostrarMascotas(lista);

					    printf("\nll_len:\n");
					    printf("\nEl tamanio de la lista es: %d\n\n", ll_len(lista));

					    printf("\nll_get:\n");
					    ll_add(lista, mascota4);
					    printf("Se agrego una mascota\n");
					    mostrarMascota( *((eMascota*) ll_get(lista, 3)));

					    printf("\nll_set:\n");
					    printf("\nModificar mascota:\nAntes\n");
					    mostrarMascota( *((eMascota*) ll_get(lista, 3)));
					    eMascota* mascota5 = nuevaMascotaParametros(3, "Rayo", "Perro", 4);
					    ll_set(lista, 3, mascota5);
					    printf("\nDespues\n");
					    mostrarMascota( *((eMascota*) ll_get(lista, 3)));

					    printf("\nll_remove:\n");
					    printf("\nEliminar una mascota\n");
					    mostrarMascotas(lista);
					    ll_remove(lista, 1);
					    printf("\n");
					    mostrarMascotas(lista);

					    printf("\nll_indexOf:\n");
					    printf("\nLa mascota: ");
					    mostrarMascota(*mascota5);
					    printf("Se encuentra en la posicion %d\n\n", ll_indexOf(lista, mascota5));

					    printf("\nll_isEmpty:\n");
					    if(ll_isEmpty(lista))
					    {
					        printf("La lista esta vacia\n");
					    }else
					    {
					        printf("La lista no esta vacia\n");
					    }

					    printf("\nll_push:\n");
					    printf("Vuelvo a agregar a la mascota que se elimino\n");
					    ll_push(lista, 1, mascota2);
					    mostrarMascotas(lista);

					    printf("\nll_pop:\n");
					    printf("Eliminar una mascota pero guardar sus datos\n");
					    auxMascota = (eMascota*) ll_pop(lista, 3);
					    mostrarMascotas(lista);
					    printf("\nMascota guardada: ");
					    mostrarMascota(*auxMascota);

					    printf("\nll_contains:\n");
					    printf("Buscar una mascota especifica: ");
					    mostrarMascota(*mascota4);
					    if(ll_contains(lista, mascota4))
					    {
					        printf("Se encuentra en la lista\n");
					    }else
					    {
					        printf("No se encuentra en la lista\n");
					    }
					    mostrarMascotas(lista);

					    printf("\nll_subList:\n");
					    listaAux = ll_subList(lista, 0, ll_len(lista));
					    if(listaAux != NULL)
					    {
					        printf("Se creo una sub lista\n");
					    }

					    printf("\nll_containsAll:\n");
					    if(ll_containsAll(lista, listaAux))
					    {
					        printf("Las mascotas se encuentran en ambas listas\n");
					    }
					    else
					    {
					        printf("Las mascotas no se encuentran en ambas listas\n");
					    }

					    printf("\nll_clone:\n");
					    listaClon = ll_clone(lista);
					    if(listaClon != NULL)
					    {
					        printf("Se clono la lista\n");
					    }
					    else
					    {
					        printf("No se pudo clonar la lista\n");
					    }
					    mostrarMascotas(listaClon);

					    printf("\nll_clear:\n");
					    printf("Se limpio la lista clonada\n");
					    ll_clear(listaClon);

					    printf("\nll_deleteLinkedList:\n");
					    ll_deleteLinkedList(listaAux);
					    ll_deleteLinkedList(listaClon);
					    printf("Se eliminaron la lista auxiliar y la clonada\n");

					    printf("\nll_sort:\n");
					    printf("\nOrdenar lista por edad\n");
					    ll_sort(lista, ordenarPorEdad, 0);
					    mostrarMascotas(lista);
					    printf("\n\n");


					    system("pause");
			break;

		}
	}while(opcion != 3);
	printf("\nSaliste del programa con exito.");

    return 0;
}

































