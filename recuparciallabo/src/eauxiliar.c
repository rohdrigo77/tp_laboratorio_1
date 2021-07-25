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

int MostrarAuxiliarConMayorContador(eAuxiliar auxLista[],int tamL,int maximoContador, char mensaje[])
{
	int estado = -1;
	int i;

	for (i=0;i<tamL;i++)
	{
		if (auxLista[i].contador == maximoContador)
		{
			printf("%s\n",mensaje);
			printf("Descripcion: %s --- Contador: %d\n",auxLista[i].descripcion, auxLista[i].contador);
			estado =1;
		}
	}

	return estado;
}
