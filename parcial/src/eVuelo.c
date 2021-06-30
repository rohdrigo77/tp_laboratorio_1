#include "../inc/eVuelo.h"


eVuelo* eVuelo_new()
{
	eVuelo* pVuelo;

	pVuelo = (eVuelo*) malloc(sizeof(eVuelo));

	if(pVuelo != NULL)
	{
		pVuelo->idVuelo = 0;
		pVuelo->idAvion = 0;
		pVuelo->idPiloto = 0;
		pVuelo->fecha.anio = 0;
		pVuelo->fecha.mes= 0;
		pVuelo->fecha.dia = 0;
		pVuelo->cantPasajeros = 0;
		pVuelo->horaDespegue = 0;
		pVuelo->horaLlegada = 0;
	}

	return pVuelo;

}

eVuelo* eVuelo_newParametros(char* idVuelo, char* idAvion, char* idPiloto, char* charDia, char* charMes, char* charAnio, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada)
{
	eVuelo* pVuelo;
	int auxIdVuelo;
	int auxIdAvion;
	int auxIdPiloto;
	eFecha auxFecha;
	int auxCantPasajeros;
	int auxHoraDespegue;
	int auxHoraLlegada;

	pVuelo = eVuelo_new();

	if (pVuelo != NULL && idVuelo != NULL && idAvion != NULL && idPiloto !=  NULL && charDia !=  NULL && charMes !=  NULL && charAnio !=  NULL && destino !=  NULL && cantPasajeros !=  NULL && cantPasajeros !=  NULL)
	{
		auxIdVuelo= atoi(idVuelo);
	//	printf("auxIdVuelo: %d \n ",auxIdVuelo);
		auxIdPiloto= atoi(idAvion);
		auxIdAvion= atoi(idPiloto);
		auxCantPasajeros = atoi (cantPasajeros);
		auxHoraDespegue = atoi (horaDespegue);
		auxHoraLlegada = atoi (horaLlegada);
		auxFecha.dia = atoi(charDia);
		auxFecha.mes = atoi(charMes);
		auxFecha.anio = atoi(charAnio);

		eVuelo_setIdVuelo(pVuelo,auxIdVuelo);
		eVuelo_setIdAvion(pVuelo,auxIdAvion);
		eVuelo_setIdPiloto(pVuelo, auxIdPiloto);
		eVuelo_setFecha(pVuelo,auxFecha);
		eVuelo_setDestino(pVuelo,destino);
		eVuelo_setCantPasajeros(pVuelo,auxCantPasajeros);
		eVuelo_setHoraDespegue(pVuelo,auxHoraDespegue);
		eVuelo_setHoraLlegada(pVuelo,auxHoraLlegada);
	}

	return pVuelo;

}


void eVuelo_delete(eVuelo* this)
{

	if(this != NULL)
	{
		free(this);
	}

}

int eVuelo_setIdVuelo(eVuelo* this,int id)
{
	int estado;

	estado = 0;

	if (this != NULL)
	{
		this->idVuelo = id;
		estado = 1;
	}

	return estado;

}

int eVuelo_getIdVuelo(eVuelo* this,int* id)
{
	int estado;

	estado = -1;

	if (this != NULL)
	{

		*id = this->idVuelo;
		estado = 1;
	}



	return estado;

}

int eVuelo_setIdAvion(eVuelo* this,int id)
{
	int estado;

	estado = 0;

	if (this != NULL)
	{
		this->idAvion = id;
		estado = 1;
	}

	return estado;

}

int eVuelo_getIdAvion(eVuelo* this,int* id)
{
	int estado;

	estado = -1;

	if (this != NULL)
	{
		*id = this->idAvion;
		estado = 1;
	}

	return estado;

}

int eVuelo_setIdPiloto(eVuelo* this,int id)
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

int eVuelo_getIdPiloto(eVuelo* this,int* id)
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

int eVuelo_setFecha(eVuelo* this, eFecha fecha)
{
	int estado;

	estado = 0;

	if (this != NULL)
	{
		this->fecha = fecha;
		estado = 1;
	}

	return estado;

}

int eVuelo_getFecha(eVuelo* this, eFecha* fecha)
{
	int estado;

	if (this != NULL)
	{
		*fecha = this->fecha;
		estado = 1;
	}

	return estado;
}

int eVuelo_setDestino(eVuelo* this,char destino[])
{
	int estado;

	estado = 0;

	if (this != NULL)
	{
		strncpy(this->destino,destino,30);
		estado = 1;
	}

	return estado;

}

int eVuelo_getDestino(eVuelo* this, char* destino)
{
	int estado;

	if (this != NULL)
	{
		strncpy(destino,this->destino,30);
		estado = 1;
	}

	return estado;
}

int eVuelo_setCantPasajeros(eVuelo* this,int cantPasajeros)
{
	int estado;

	estado = 0;

	if (this != NULL)
	{
		this->cantPasajeros = cantPasajeros;
		estado = 1;
	}

	return estado;

}
int eVuelo_getCantPasajeros(eVuelo* this,int* cantPasajeros)
{
	int estado;

	if (this != NULL)
	{
		*cantPasajeros = this->cantPasajeros;
		estado = 1;
	}

	return estado;
}

int eVuelo_setHoraDespegue(eVuelo* this,int horaDespegue)
{
	int estado;

	estado = 0;

	if (this != NULL)
	{
		this->horaDespegue = horaDespegue;
		estado = 1;
	}

	return estado;

}
int eVuelo_getHoraDespegue(eVuelo* this,int* horaDespegue)
{
	int estado;

	if (this != NULL)
	{
		*horaDespegue = this->horaDespegue;
		estado = 1;
	}

	return estado;
}

int eVuelo_setHoraLlegada(eVuelo* this,int horaLlegada)
{
	int estado;

	estado = 0;

	if (this != NULL)
	{
		this->horaLlegada = horaLlegada;
		estado = 1;
	}

	return estado;

}

int eVuelo_getHoraLlegada(eVuelo* this,int* horaLlegada)
{
	int estado;

	if (this != NULL)
	{
		*horaLlegada = this->horaLlegada;
		estado = 1;
	}

	return estado;
}

int eVuelo_showeVuelo(eVuelo* miVuelo, LinkedList* this)
{
	int estado;
	int auxIdVuelo;
	int auxIdAvion;
	int auxIdPiloto;
	char auxPiloto[50];
	eFecha auxFecha;
	char auxDestino[30];
	int auxCantPasajeros;
	int auxHoraDespegue;
	int auxHoraLlegada;



	if (miVuelo != NULL)
	{


		estado = eVuelo_geteVuelo(this, miVuelo, &auxIdVuelo, &auxIdAvion, &auxIdPiloto, auxPiloto, &auxFecha, auxDestino, &auxCantPasajeros, &auxHoraDespegue, &auxHoraLlegada);
		//printf("termine el getter del show \n");

		if (estado != -1)
		{

			printf("%4d %15d %15s %7d/%d/%d %7s %7d %7d %7d \n",auxIdVuelo, auxIdAvion, auxPiloto, auxFecha.dia, auxFecha.mes, auxFecha.anio, auxDestino, auxCantPasajeros, auxHoraDespegue, auxHoraLlegada);

		}

	}
	else
	{
		printf("miVuelo esta vacío. \n");
		estado = -1;
	}

	return estado;
}

int eVuelo_geteVuelo(LinkedList* this, eVuelo* miVuelo, int* auxIdVuelo, int* auxIdAvion, int* auxIdPiloto, char* auxNombrePiloto, eFecha* auxFecha, char* auxDestino, int* auxCantPasajeros, int* auxHoraDespegue, int* auxHoraLlegada)
{
	int estado = -1;

	ePiloto* auxPiloto;

	if (miVuelo != NULL)
	{

		eVuelo_getIdVuelo(miVuelo,auxIdVuelo);

		eVuelo_getIdAvion(miVuelo,auxIdAvion);

		eVuelo_getIdPiloto(miVuelo,auxIdPiloto);
		auxPiloto = (ePiloto*) ll_get(this,*auxIdPiloto);
		ePiloto_getNombre(auxPiloto,auxNombrePiloto);

		eVuelo_getFecha(miVuelo, auxFecha);

		eVuelo_getDestino(miVuelo,auxDestino);

		eVuelo_getCantPasajeros(miVuelo,auxCantPasajeros);

		eVuelo_getHoraDespegue(miVuelo,auxHoraDespegue);

		eVuelo_getHoraLlegada(miVuelo,auxHoraLlegada);

		estado = 1;

	}


	return estado;


}

int eVuelo_PasajerosAChina(void* pElement)
{
	int estado = -1;
	eVuelo* miVuelo;
	char china[10] = "China";
	miVuelo = (eVuelo*)  pElement;

	if (strcmp(miVuelo->destino,china) == 0)
	{
		estado = 1;
	}

	return estado;
}

int eVuelo_vueloLargo(void* pElement)
{
	int estado = -1;
	eVuelo* miVuelo;

	miVuelo = (eVuelo*)  pElement;

	if ((miVuelo->horaDespegue - miVuelo->horaLlegada > 5) || (miVuelo->horaDespegue - miVuelo->horaLlegada < -5))
	{
		estado = 1;
	}

	return estado;
}

int eVuelo_VuelosAPortugal(void* pElement)
{
	int estado = -1;
	eVuelo* miVuelo;
	char portugal[20] = "Portugal";
	miVuelo = (eVuelo*)  pElement;

	if (strcmp(miVuelo->destino,portugal) == 0)
	{
		estado = 1;
	}

	return estado;
}

int eVuelo_VuelosSinLyB(void* pElement)
{
	int estado = -1;
	eVuelo* miVuelo;

	miVuelo = (eVuelo*)  pElement;

	if (miVuelo->idPiloto > 2)
	{
		estado = 1;
	}

	return estado;

}


