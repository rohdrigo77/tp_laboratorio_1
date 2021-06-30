#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/eVuelo.h"
#include "../inc/bibliogenerica.h"
#define BIN "data.bin"
#define VUELOSCSV "Vuelos.csv"
#define PILOTOSCSV "Pilotos.csv"
#define LASTIDV "lastidvuelos.bin"
#define LASTIDP "lastidpilotos.bin"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    int estado;
    //int lastIdVuelos;
    //int lastIdPilotos;
    int listaPilotosCargada = 0;
    int listaVuelosCargada = 0;
    /*int auxLastIdVuelos;
    int auxLastIdVPilotos;
    int listaGuardada = 0;*/


    LinkedList* listaVuelos = ll_newLinkedList();
    LinkedList* listaPilotos = ll_newLinkedList();

    // lastIdVuelos = getLastId(LASTIDV);
    // lastIdPilotos = getLastId(LASTIDP);
    //lastIdVuelos= setLastId(LASTIDV,100);
    //lastIdPilotos= setLastId(LASTIDP,5);
    //printf("lastidvuelos: %d \n",lastIdVuelos);
    //printf("lastidpilotos: %d \n",lastIdPilotos);
    //auxLastIdVuelos = lastIdVuelos;
    //auxLastIdVPilotos = lastIdPilotos;

    setbuf(stdout, NULL);

    do{
    	printf("1. Cargar los datos de los pilotos desde el archivo data.csv (modo texto).\n");
    	printf("2. Cargar los datos de los vuelos desde el archivo data.csv (modo texto).\n");
    	printf("3. Listar vuelos.\n");
    	printf("4. Cantidad de pasajeros totales.\n");
    	printf("5. Cantidad de pasajeros a China.\n");
    	printf("6. Filtrar vuelos largos (Guarda Lista).\n");
    	printf("7. Filtrar vuelos a Portugal.\n");
    	printf("8. Filtrar a Alex Lifeson y Richard Bach.\n");
    	printf("10. Salir\n");
    	scanf("%d",&option);

        switch(option)
        {
            case 1:
            	if (listaPilotosCargada < 1)
            	{
					estado = bogado_controller_loadPilotosFromText(PILOTOSCSV,listaPilotos);
			        if (estado != 1)
					{
						printf("Hubo un inconveniente durante la carga del archivo. \n");
					}
					else
					{
						printf("La carga del archivo se realizó correctamente. \n");
						listaPilotosCargada = 1;
					}
					break;
            	}
            	else
            	{
            		printf("La lista ya fue cargada.\n");
            	}
                break;
            case 2:
            	if (listaVuelosCargada < 1)
                {
					estado = bogado_controller_loadVuelosFromText(VUELOSCSV,listaVuelos);
					if (estado != 1)
					{
						printf("Hubo un inconveniente durante la carga del archivo. \n");
					}
					else
					{
						printf("La carga del archivo se realizó correctamente. \n");
						listaVuelosCargada = 1;
					}
                }
            	else
            	{
            		printf("La lista ya fue cargada.\n");
            	}
                break;
            case 3:
            	if (listaVuelosCargada == 1 && listaPilotosCargada == 1)
            	{
					estado = bogado_controller_ListeVuelo(listaVuelos,listaPilotos);
            		//estado = bogado_controller_ListePiloto(listaPilotos);
					if (estado != 1)
					{
						printf("Hubo un inconveniente durante la muestra de la lista. \n");
					}
					else
					{
						printf("La muestra de la lista se realizó correctamente. \n");
					}
            	}
            	break;
            case 4:
            	if (listaVuelosCargada == 1)
            	{
            		estado = bogado_controller_cantidadPasajeros(listaVuelos);
            	}

            	if (estado > 0)
            	{
            		printf("El cálculo se realizó correctamente. \n");
            	}
            	else
            	{
            		printf("Hubo un inconveniente al realizar el cálculo. \n");
            	}
            	break;
            case 5:
            	if (listaVuelosCargada == 1)
            	{
            		estado = bogado_controller_cantidadPasajerosChinos(listaVuelos);
            	}

            	if (estado > 0)
            	{
            		printf("El cálculo se realizó correctamente. \n");
            	}
            	else
            	{
            		printf("Hubo un inconveniente al realizar el cálculo. \n");
            	}
            	break;
            case 6:
                   	if (listaVuelosCargada == 1)
                   	{
                   		estado = bogado_controller_vuelosLargos(listaVuelos,listaPilotos);
                   	}

                   	if (estado > 0)
                   	{
                   		printf("La lista realizó correctamente. \n");
                   	}
                   	else
                   	{
                   		printf("Hubo un inconveniente al realizar el cálculo. \n");
                   	}
                   	break;
            case 7:
                   	if (listaVuelosCargada == 1)
                   	{
                   		estado = bogado_controller_vuelosAPortugal(listaVuelos,listaPilotos);
                   	}

                   	if (estado > 0)
                   	{
                   		printf("La lista se realizó correctamente. \n");
                   	}
                   	else
                   	{
                   		printf("Hubo un inconveniente al realizar el cálculo. \n");
                   	}
                   	break;
            case 8:
                    if (listaVuelosCargada == 1)
					{
						estado = bogado_controller_listaSinLifesonYBach(listaVuelos,listaPilotos);
					}

					if (estado > 0)
					{
						printf("La lista se realizó correctamente. \n");
					}
					else
					{
						printf("Hubo un inconveniente al realizar el cálculo. \n");
					}
					break;
            case 10:
            	break;
        }
    }while(option != 10);
    return 0;
}

