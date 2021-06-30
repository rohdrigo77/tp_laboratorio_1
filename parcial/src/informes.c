/*
 * informes.c
 *
 *  Created on: Jun 29, 2021
 *      Author: rodrigo
 */

#include "../inc/informes.h"

int Informe_Cantidad_Pasajeros(LinkedList* this, char mensaje[])
{
	int estado;
	int acumulador = 0;


	if (this != NULL)
	{

		acumulador = ll_count(this,extraerCantidadPasajeros);

		printf("%s %d \n",mensaje,acumulador);

		estado = 1;
	}

	return estado;

}

int extraerCantidadPasajeros(void* pElement)
{
	int cantPasajeros;
	eVuelo* pAuxVuelo;

	if (pElement != NULL)
	{
		pAuxVuelo = (eVuelo*) pElement;
		cantPasajeros = pAuxVuelo->cantPasajeros;
	}

	return cantPasajeros;
}

