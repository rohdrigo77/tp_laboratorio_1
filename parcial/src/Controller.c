#include <stdio.h>
#include <stdlib.h>

#include "../inc/Controller.h"


/** \brief Carga los datos de los vuelos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeVuelo LinkedList*
 * \return int
 *
 */
int bogado_controller_loadVuelosFromText(char* path, LinkedList* pArrayListeVuelo)
{
	int estado;
	FILE* pArchivo = NULL;
	estado = -1;

	if (path != NULL && pArrayListeVuelo != NULL)
	{
		pArchivo = fopen(path,"r");
		estado = parser_eVueloFromText(pArchivo, pArrayListeVuelo);
		fclose(pArchivo);
	}


    return estado;
}

int bogado_controller_loadPilotosFromText(char* path, LinkedList* pArrayListeVuelo)
{
	int estado;
	FILE* pArchivo = NULL;
	estado = -1;

	if (path != NULL && pArrayListeVuelo != NULL)
	{
		pArchivo = fopen(path,"r");
		estado = parser_ePilotoFromText(pArchivo, pArrayListeVuelo);
		fclose(pArchivo);
	}


    return estado;
}

/** \brief Carga los datos de los vuelos desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeVuelo LinkedList*
 * \return int
 *
 */
int bogado_controller_loadFromBinary(char* path , LinkedList* pArrayListeVuelo)
{
	int estado;
	FILE* pArchivo;
	estado = -1;

	if (path != NULL && pArrayListeVuelo != NULL)
	{
		pArchivo = fopen(path,"rb");
		estado = parser_eVueloFromBinary(pArchivo , pArrayListeVuelo);
		fclose(pArchivo);
	}


    return estado;
}

int bogado_controller_ListeVuelo(LinkedList* pArrayListeVuelo,LinkedList* pArrayListePiloto)
{
	int estado;
	int isEmpty = ll_isEmpty(pArrayListeVuelo);



	if (pArrayListeVuelo != NULL && isEmpty == 0)
	{

		int i;
		int len;
		eVuelo* auxeVuelo;
		len = ll_len(pArrayListeVuelo);


		printf("-------------------------------------------------------------------------------------------\n");
		printf("| ID VUELO | ID AVION | PILOTO | FECHA | DESTINO | CANT PASAJEROS | DESPEGUE | LLEGADA |\n");
		printf("-------------------------------------------------------------------------------------------\n");

		for(i=0; i<len; i++)
		{
			auxeVuelo = (eVuelo*) ll_get(pArrayListeVuelo,i);
			//printf("ID VUELO: %d \n", auxeVuelo->idVuelo);

			//printf("Estoy en el for del list \n");
			estado = eVuelo_showeVuelo(auxeVuelo,pArrayListePiloto);


		}


	}
	else if(isEmpty)
	{
		printf("La lista de vuelos está vacía. \n");
		estado = 1;
	}
	else
	{
		estado = -1;
	}

	return estado;
}

int bogado_controller_ListePiloto(LinkedList* pArrayListePiloto)
{
	int estado;
	int isEmpty = ll_isEmpty(pArrayListePiloto);



	if (pArrayListePiloto != NULL && isEmpty == 0)
	{

		int i;
		int len;
		ePiloto* auxePiloto;
		len = ll_len(pArrayListePiloto);


		printf("-------------------------------------------------------------------------------------------\n");
		printf("| ID PILOTO | NOMBRE |\n");
		printf("-------------------------------------------------------------------------------------------\n");

		for(i=0; i<len; i++)
		{
			auxePiloto = (ePiloto*) ll_get(pArrayListePiloto,i);
			//printf("ID VUELO: %d \n", auxeVuelo->idVuelo);

			//printf("Estoy en el for del list \n");
			estado = ePiloto_showePiloto(auxePiloto);


		}


	}
	else if(isEmpty)
	{
		printf("La lista de vuelos está vacía. \n");
		estado = 1;
	}
	else
	{
		estado = -1;
	}

	return estado;
}

/** \brief Guarda los datos de los vuelos en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeVuelo LinkedList*
 * \return int
 *
 */
int bogado_controller_saveAsText(char* path , LinkedList* pArrayListeVuelo)
{
    int estado = 0;
    int i;
    int len;
	int auxIdVuelo;
	int auxIdAvion;
	int auxIdPiloto;
	eFecha auxFecha;
	int auxCantPasajeros;
	int auxHoraDespegue;
	int auxHoraLlegada;
    char auxDestino[30];
    FILE* pArchivo;
    eVuelo* auxVuelo;

    if(pArrayListeVuelo != NULL && path != NULL)
    {

        pArchivo = fopen(path, "w");

        if(pArchivo != NULL)
        {
        	len = ll_len(pArrayListeVuelo);
        	fprintf(pArchivo,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
            for(i = 0; i < len; i++)
            {
            	auxVuelo= (eVuelo*) ll_get(pArrayListeVuelo,i);


                estado = eVuelo_getIdVuelo(auxVuelo,&auxIdVuelo);

                estado = eVuelo_getIdAvion(auxVuelo,&auxIdAvion);

                estado = eVuelo_getIdPiloto(auxVuelo,&auxIdPiloto);

                estado = eVuelo_getFecha(auxVuelo, &auxFecha);
                estado = eVuelo_getDestino(auxVuelo,auxDestino);

                estado = eVuelo_getCantPasajeros(auxVuelo,&auxCantPasajeros);

                estado = eVuelo_getHoraDespegue(auxVuelo,&auxHoraDespegue);

                estado = eVuelo_getHoraLlegada(auxVuelo,&auxHoraLlegada);


                fprintf(pArchivo,"%d,%d,%d,%d/%d/%d,%s,%d,%d,%d\n",auxIdVuelo,auxIdAvion,auxIdPiloto,auxFecha.dia,auxFecha.mes,auxFecha.anio,auxDestino,auxCantPasajeros,auxHoraDespegue,auxHoraLlegada);
            }
            fclose(pArchivo);

        }
    }

    return estado;
}

/** \brief Guarda los datos de los vuelos en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeVuelo LinkedList*
 * \return int
 *
 */

int bogado_controller_cantidadPasajeros(LinkedList* this)
{
	int estado = -1;

	if (this != NULL)
	{
		estado = Informe_Cantidad_Pasajeros(this,"La cantidad total de pasajeros es:");
	}

	return estado;
}

int bogado_controller_cantidadPasajerosChinos(LinkedList* this)
{
	int estado = -1;
	LinkedList* vuelosAChina;

	if (this != NULL)
	{
		vuelosAChina = ll_newLinkedList();
		vuelosAChina = ll_filter(this, eVuelo_PasajerosAChina);
		estado = Informe_Cantidad_Pasajeros(vuelosAChina,"La cantidad total de pasajeros con destino a China es:");
	}

	return estado;

}

int bogado_controller_vuelosLargos(LinkedList* this, LinkedList* pilotos)
{
	int estado = -1;

	if (this != NULL)
	{
		LinkedList* vuelosLargos = ll_newLinkedList();

		vuelosLargos = ll_filter(this, eVuelo_vueloLargo);

		bogado_controller_ListeVuelo(vuelosLargos, pilotos);

		estado = bogado_controller_saveAsText("VuelosLargos.csv" , vuelosLargos);
	}

	return estado;

}

int bogado_controller_vuelosAPortugal(LinkedList* this, LinkedList* pilotos)
{
	int estado = -1;

	if (this != NULL)
	{
		LinkedList*  vuelosAPortugal = ll_newLinkedList();

		vuelosAPortugal = ll_filter(this, eVuelo_VuelosAPortugal);

		estado =  bogado_controller_ListeVuelo(vuelosAPortugal, pilotos);

	}

	return estado;

}

int bogado_controller_listaSinLifesonYBach(LinkedList* this, LinkedList* pilotos)
{
	int estado = -1;

	if (this != NULL)
	{
		LinkedList*  vuelosSinLyB = ll_newLinkedList();

		vuelosSinLyB = ll_filter(this, eVuelo_VuelosSinLyB);

		estado =  bogado_controller_ListeVuelo(vuelosSinLyB, pilotos);

	}

	return estado;

}


