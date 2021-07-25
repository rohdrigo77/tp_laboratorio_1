/*
 * eclientes.c
 *
 *  Created on: 01/07/2021
 *      Author: btz_p
 */
#include "../inc/eclientes.h"

void InicializarClientes(eCliente listaClientes[], int tamC)
{
    int i;

    for(i=0; i<tamC; i++)
    {
        listaClientes[i].estadoCliente = VACIO;
    }

}

int BuscarIDClientes(eCliente listaClientes[], int tamC, int idCliente)
{
	int i;
	int index;

	index = -1;


	for (i=0; i < tamC; i++)
	{
		if (listaClientes[i].idCliente == idCliente)
		{
			index = i;
			break;
		}
	}
	return index;
}

int BuscarLibreClientes(eCliente listaClientes[], int tamC)
{

	    int i;
	    int indexBL;

	    indexBL = -1;

	    if (listaClientes != NULL)
	    {
			for(i=0; i<tamC; i++)
			{
				if(listaClientes[i].estadoCliente == VACIO || listaClientes[i].estadoCliente == BAJA)
				{
					indexBL = i;
					break;
				}
			}
	    }

	    return indexBL;
}

void ImprimirClientes(eCliente listaClientes[], int tamC)
{
	int i;

	for(i=0;i<tamC;i++)
	{
	    ImprimirUnCliente(listaClientes[i]);
	}

}

void ImprimirUnCliente(eCliente miCliente)
{
	if (miCliente.estadoCliente == OCUPADO)
	{
		printf("%d %s %s \n", miCliente.idCliente,
				miCliente.nombre,
				miCliente.apellido
				);
	}
}

void HardcodeoDatosClientes(eCliente listaClientes[], int tamC, int minId)
{

    int i;
    eCliente listaAux[] = {
                                {minId++,"Carlos","Gardel", OCUPADO},
								{minId++,"Maria","Ramirez", OCUPADO},
								{minId++,"Pedro" ,"Gomez", OCUPADO},
								{minId++,"Ariel","Padilla", OCUPADO},
								{minId++,"Carmen","San Diego", OCUPADO}
    };

    for(i = 0; i < tamC; i++)
    {
    	listaClientes[i].idCliente = listaAux[i].idCliente;
    	strcpy(listaClientes[i].nombre,listaAux[i].nombre);
    	strcpy(listaClientes[i].apellido,listaAux[i].apellido);
    	listaClientes[i].estadoCliente = listaAux[i].estadoCliente;
    }

    printf("Hardcodeado con exito \n");
}

void ImprimirAcumulacionCliente(int idCliente, char descripcionCliente[], float acumulacionCliente)
{
	printf("| %d | %s | $%f |\n",idCliente,descripcionCliente,acumulacionCliente);
	printf("|---------------|\n");
}
