/*
 * ebicicleta.c
 *
 *  Created on: May 11, 2021
 *      Author: rodrigo
 */

#include "../inc/ebicicleta.h"

void InicializarBicicletas(eBicicleta listaBicicletas[], int tamB)
{
    int i;

    for(i=0; i<tamB; i++)
    {
        listaBicicletas[i].estadoBicicleta = VACIO;
    }

}

int BuscarLibreBicicletas(eBicicleta listaBicicletas[], int tamB)
{

	    int i;
	    int indexBL;

	    indexBL = -1;

	    if (listaBicicletas != NULL)
	    {
			for(i=0; i<tamB; i++)
			{
				if(listaBicicletas[i].estadoBicicleta == VACIO || listaBicicletas[i].estadoBicicleta == BAJA)
				{
					indexBL = i;
					break;
				}
			}
	    }

	    return indexBL;
}

int BuscarIDBicicletas(eBicicleta listaBicicletas[], int tamB, int idBicicleta)
{
	int i;
	int index;

	index = -1;


	for (i=0; i < tamB; i++)
	{
		if (listaBicicletas[i].idBicicleta == idBicicleta)
		{
			index = i;
			break;
		}
	}


	return index;
}




int ValidarArrayOcupadoBicicletas(eBicicleta listaBicicletas[], int tamB)
{
	int i;
	int estado;

	estado = -1;

	for(i=0; i < tamB; i++)
	{

		if(listaBicicletas[i].estadoBicicleta == OCUPADO)
		{
			estado = OCUPADO;
			break;
		}
	}

	return estado;
}

eBicicleta PedirBicicleta(int indexBici, int tamB, int minID, int maxMarca, int maxColor)
{
	int auxInt;
	int estadoRodado;
	int validRodado;


	eBicicleta auxBici;
	/*
	 * 	int idBicicleta;
	char marcaBicicleta;
	int rodadoBicicleta;
	char colorBicicleta;
	int estadoBicicleta;
	 * */

	auxBici.idBicicleta = minID + indexBici;
	PedirCadena(auxBici.marcaBicicleta, maxMarca,"Ingrese marca de bicicleta:", "Dato ingresado inválido");

	do
	{
		auxInt = PedirEntero("Ingrese rodado de bicicleta (sólo estas opciones: 12, 14, 16, 18, 20, 22, 24, 26): ", "Dato ingresado no válido");

		switch(auxInt)
		{
			case 12:
			case 14:
			case 16:
			case 18:
			case 20:
			case 22:
			case 24:
			case 26:
				auxBici.rodadoBicicleta = auxInt;
				estadoRodado = 1;
				break;
			default:
				printf("Ingresó un rodado no disponible. Revise las opciones disponibles y reintente. \n");
				estadoRodado = -1;
				validRodado++;
		}

		if (validRodado == 3)
		{
			printf("Se ha llegado al máximo de intentos. Revise los ID disponibles y reintente. \n");
			break;
		}

	}while(estadoRodado != 1);

	PedirCadena(auxBici.colorBicicleta, maxColor,"Ingrese color de bicicleta:", "Dato ingresado inválido");

	auxBici.estadoBicicleta = OCUPADO;

	return auxBici;
}

int ValidarBicicletaRoja(eBicicleta miBicicleta)
{
	int estado = 1;

	int validacion;

	validacion = strcmp(miBicicleta.colorBicicleta,"rojo");

	if (validacion != 0)
	{
		estado = -1;
	}
	printf("estado validacion: %d \n",estado);

	return estado;
}




