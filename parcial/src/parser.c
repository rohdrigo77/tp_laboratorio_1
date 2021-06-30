#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/eVuelo.h"
#include "../inc/ePiloto.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeVuelo LinkedList*
 * \return int
 *
 */
int parser_eVueloFromText(FILE* pArchivo , LinkedList* pArrayListeVuelos)
{
	int estado;
	eVuelo* pVuelo;
	char auxIdVuelo[15];
	char auxIdPiloto[15];
	char auxIdAvion[15];
	char auxFechaDia[15];
	char auxFechaMes[15];
	char auxFechaAnio[15];
	char auxDestino[30];
	char auxCantPasajeros[10];
	char auxHoraDespegue[10];
	char auxHoraLlegada[10];


	if (pArchivo != NULL && pArrayListeVuelos != NULL)
	{
			fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdVuelo,auxIdPiloto,auxIdAvion,auxFechaDia,auxDestino,auxCantPasajeros,auxHoraDespegue,auxHoraLlegada);

		while(!feof(pArchivo))
		{
			if(fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdVuelo,auxIdPiloto,auxIdAvion,auxFechaDia,auxFechaMes,auxFechaAnio,auxDestino,auxCantPasajeros,auxHoraDespegue,auxHoraLlegada) == 10)
			{
				pVuelo = eVuelo_newParametros(auxIdVuelo, auxIdPiloto, auxIdAvion, auxFechaDia, auxFechaMes, auxFechaAnio ,auxDestino, auxCantPasajeros, auxHoraDespegue, auxHoraLlegada);

				if (pVuelo != NULL)
				{
					ll_add(pArrayListeVuelos, pVuelo);
					estado = 1;

				}
				else
				{
					printf("pVuelo es NULL \n");
					estado = 0;
				}

			}
		}

	}
	else
	{
		estado = 0;
	}


    return estado;
}

int parser_ePilotoFromText(FILE* pArchivo , LinkedList* pArrayListePilotos)
{
	int estado;
	ePiloto* pPiloto;
	char auxIdPiloto[15];
	char auxNombre[50];


	if (pArchivo != NULL && pArrayListePilotos != NULL)
	{


		do
		{
			fscanf(pArchivo,"%[^,],%[^\n]\n",auxIdPiloto,auxNombre);

			pPiloto = ePiloto_newParametros(auxIdPiloto, auxNombre);

			if (pPiloto != NULL)
			{
				ll_add(pArrayListePilotos, pPiloto);
				estado = 1;

			}
			else
			{
				printf("pVuelo es NULL \n");
				estado = 0;
			}
		}while(!feof(pArchivo));

	}
	else
	{
		estado = 0;
	}


    return estado;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeVuelo LinkedList*
 * \return int
 *
 */
int parser_eVueloFromBinary(FILE* pArchivo , LinkedList* pArrayListeVuelos)
{
	int estado;
	eVuelo* pVuelo;
	int bandera;

	if (pArchivo != NULL && pArrayListeVuelos != NULL)
	{
		while(feof(pArchivo) == 0)
		{
			pVuelo = eVuelo_new();
			bandera = fread(pVuelo,sizeof(eVuelo),1,pArchivo);

			if (pVuelo != NULL && bandera > 0)
			{
				ll_add(pArrayListeVuelos, pVuelo);
				estado = 1;
			}
			else
			{
				printf("pVuelo es NULL \n");
				estado = 0;
			}

		}

	}
	else
	{
		estado = 0;
	}


	return estado;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeVuelo LinkedList*
 * \return int
 *
 */
int parser_ePilotoFromBinary(FILE* pArchivo , LinkedList* pArrayListeVuelos)
{
	int estado;
	eVuelo* pVuelo;
	int bandera;

	if (pArchivo != NULL && pArrayListeVuelos != NULL)
	{
		while(feof(pArchivo) == 0)
		{
			pVuelo = eVuelo_new();
			bandera = fread(pVuelo,sizeof(eVuelo),1,pArchivo);

			if (pVuelo != NULL && bandera > 0)
			{
				ll_add(pArrayListeVuelos, pVuelo);
				estado = 1;
			}
			else
			{
				printf("pVuelo es NULL \n");
				estado = 0;
			}
		}

	}
	else
	{
		estado = 0;
	}


	return estado;
}

