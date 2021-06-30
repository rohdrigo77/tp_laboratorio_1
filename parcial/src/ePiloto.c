/*
 * ePiloto.c
 *
 *  Created on: Jun 28, 2021
 *      Author: rodrigo
 */


#include "../inc/ePiloto.h"


ePiloto* ePiloto_new()
{
	ePiloto* pPiloto;

	pPiloto = (ePiloto*) malloc(sizeof(ePiloto));

	if(pPiloto != NULL)
	{
		pPiloto->idPiloto = 0;
	}

	return pPiloto;

}

ePiloto* ePiloto_newParametros(char* idPiloto, char* nombre)
{
	ePiloto* pPiloto;
	int auxIdPiloto;

	pPiloto = ePiloto_new();

	if (pPiloto != NULL && idPiloto != NULL && nombre != NULL)
	{
		auxIdPiloto= atoi(idPiloto);
	//	printf("auxIdPiloto: %d \n ",auxIdPiloto);

		ePiloto_setIdPiloto(pPiloto,auxIdPiloto);
		ePiloto_setNombre(pPiloto,nombre);
	}

	return pPiloto;

}

int ePiloto_setIdPiloto(ePiloto* this,int id)
{
	int estado;

	estado = 0;

	if (this != NULL)
	{
		this->idPiloto = id;
		estado = 1;
	}

	return estado;

}

int ePiloto_getIdPiloto(ePiloto* this,int* id)
{
	int estado;

	estado = -1;

	if (this != NULL)
	{
		*id = this->idPiloto;
		estado = 1;
	}

	return estado;

}

int ePiloto_setNombre(ePiloto* this, char nombre[])
{
	int estado;

	estado = 0;

	if (this != NULL)
	{
		strcpy(this->nombre,nombre);
		estado = 1;
	}

	return estado;

}

int ePiloto_getNombre(ePiloto* this, char* nombre)
{
	int estado;

	if (this != NULL)
	{
		strcpy(nombre,this->nombre);
		estado = 1;
	}

	return estado;
}

int ePiloto_showePiloto(ePiloto* miPiloto)
{
		int estado;
		int auxIdPiloto;
		char auxNombre[50];



		if (miPiloto != NULL)
		{


			estado = ePiloto_getePiloto(miPiloto, &auxIdPiloto, auxNombre);


			if (estado != -1)
			{

				printf("%4d %15s \n",auxIdPiloto, auxNombre);
			}

		}
		else
		{
			printf("miPiloto esta vacío. \n");
			estado = -1;
		}

		return estado;

}

int ePiloto_getePiloto(ePiloto* miPiloto, int* auxIdPiloto, char* auxNombre)
{
	int estado = -1;

		if (miPiloto != NULL)
		{
			ePiloto_getIdPiloto(miPiloto,auxIdPiloto);

			ePiloto_getNombre(miPiloto,auxNombre);

			estado = 1;
		}


		return estado;
}

