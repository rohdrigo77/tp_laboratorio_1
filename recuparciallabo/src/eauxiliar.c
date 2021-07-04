/*
 * eauxiliar.c
 *
 *  Created on: May 4, 2021
 *      Author: rodrigo
 */

#include "../inc/eauxiliar.h"

int BuscarIDAuxiliares(eAuxiliar listaAuxiliar[], int tamAuxiliar,int idAuxiliar)
{
	int i;
	int index;

	index = -1;


	for (i=0; i < tamAuxiliar; i++)
	{
		if (listaAuxiliar[i].idAuxiliar == idAuxiliar)
		{
			index = i;
			break;
		}
	}


	return index;
}

void ImprimirAuxiliares(eAuxiliar listaAuxiliar[], int tamAuxiliar)
{
	int i;

	for(i=0;i<tamAuxiliar;i++)
	{
		ImprimirUnAuxiliar(listaAuxiliar[i]);
	}

}

void ImprimirUnAuxiliar(eAuxiliar miAuxiliar)
{
	printf("%d %d %f %s \n", miAuxiliar.idAuxiliar,
			miAuxiliar.contador,
			miAuxiliar.acumulador,
			miAuxiliar.descripcion
			);
}
