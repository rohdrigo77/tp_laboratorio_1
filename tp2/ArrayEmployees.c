/*
 * ArrayEmployees.c
 *
 *  Created on: May 15, 2021
 *      Author: rodrigo
 */

#include "ArrayEmployees.h"

void initEmployees(eEmpleado listaEmpleados[], int len)
{
    int i;


    for(i=0; i<len; i++)
    {
    	listaEmpleados[i].isEmpty = VACIO;
    }

}

int addEmployee(eEmpleado listaEmpleados[], int len, int maxName, int maxLastName)
{
	int indexID;
	int estado;
	int auxInt;
	int validador;
	int contadorValidador;
	int auxFloat;

	indexID = BuscarLibreEmpleado(listaEmpleados, len);
	estado = 1;

	listaEmpleados[indexID].id = indexID + 1;
	PedirNombresOApellidos(listaEmpleados[indexID].name,maxName,"Ingrese nombre:","Dato ingresado no válido");
	PedirNombresOApellidos(listaEmpleados[indexID].lastName,maxLastName,"Ingrese apellido:","Dato ingresado no válido");

	do
	{
		auxFloat = PedirFlotante("Ingrese salario:", "Dato ingresado inválido");
		validador = ValidarFlotanteConRangoMinimo(auxFloat, 0.1);
		if (validador != -1)
		{
			listaEmpleados[indexID].salary = auxFloat;
		}
		else
		{
			printf("Ingrese un valor mayor a 0.1!!!");
			contadorValidador++;
		}

		if(contadorValidador == 3)
		{
			printf("Se ha llegado al máximo de intentos. Revise las indicaciones atentamente y reintente. \n");
			estado = -1;
			break;
		}
	}while(validador != 1);

	contadorValidador = 0;

	do
	{
		auxInt = PedirEntero("Ingrese sector:", "Dato ingresado inválido");
		validador = ValidarEnteroConRangoMinimo(auxInt, 1);
		if (validador != -1)
		{
			listaEmpleados[indexID].sector = auxInt;
		}
		else
		{
			printf("Ingrese un valor mayor a 1!!!");
			contadorValidador++;
		}

		if(contadorValidador == 3)
		{
			printf("Se ha llegado al máximo de intentos. Revise las indicaciones atentamente y reintente. \n");
			estado = -1;
			break;
		}
	}while(validador != 1);

	if (estado != -1)
	{
		listaEmpleados[indexID].isEmpty = OCUPADO;
	}

	return estado;

}

int findEmployeeById(eEmpleado listaEmpleados[], int len, int id)
{
	int i;
	int index;

	index = -1;

	for (i=0; i < len; i++)
	{
		if (listaEmpleados[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

int removeEmployee(eEmpleado listaEmpleados[], int len)
{
	int idEmpleado;
	int indexEmpleado;
	int estado;
	int confirmacion;
	int validId;

	validId = 0;
	estado = printEmployees(listaEmpleados, len);

	if (estado != -1)
	{
		do
		{
			idEmpleado = PedirEntero("Ingrese ID de empleado a eliminar:", "Dato ingresado no válido");

			indexEmpleado = findEmployeeById(listaEmpleados, len, idEmpleado);

			if(indexEmpleado != -1)
			{
				printf("Se ingresó al empleado con ID: %d \n",listaEmpleados[indexEmpleado].id);
				confirmacion = PedirConfirmacion("Está seguro de que quiere eliminar este empleado? Escriba 's' o 'n' ", "Dato ingresado inválido");

				if (confirmacion != -1)
				{
					listaEmpleados[indexEmpleado].isEmpty = BAJA;
					break;
				}
			}
			else
			{
				printf("No existe un Empleado con ese ID\n");
				validId++;
			}

			if (validId == 3)
			{
				printf("Se agotó el número de intentos. Verifique el ID y vuelva a intentar.");
				break;
			}
		}while(validId != 3);
	}
	else
	{
		printf("No hay Empleados para eliminar.\n");
	}

	return estado;

}

int sortEmployees(eEmpleado listaEmpleados[], int len, int order)
{
	int i;
	int j;
	eEmpleado auxiliar;
	int estado;

	estado = -1;

	if(order==1)
	{
		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(strcmp(listaEmpleados[i].lastName, listaEmpleados[j].lastName)>0)
				{
					auxiliar=listaEmpleados[i];
					listaEmpleados[i]=listaEmpleados[j];
					listaEmpleados[j]=auxiliar;
				}
				else if(strcmp(listaEmpleados[i].lastName, listaEmpleados[j].lastName)==0)
				{
					if (listaEmpleados[i].sector > listaEmpleados[j].sector)
					{
						auxiliar=listaEmpleados[i];
						listaEmpleados[i]=listaEmpleados[j];
						listaEmpleados[j]=auxiliar;
					}
				}
			}
		}

		estado = printEmployees(listaEmpleados,len);
	}
	else if (order == 2)
	{
		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(strcmp(listaEmpleados[i].lastName, listaEmpleados[j].lastName)<0)
				{
					auxiliar=listaEmpleados[i];
					listaEmpleados[i]=listaEmpleados[j];
					listaEmpleados[j]=auxiliar;
				}
				else if(strcmp(listaEmpleados[i].lastName, listaEmpleados[j].lastName)==0)
				{
					if (listaEmpleados[i].sector < listaEmpleados[j].sector)
					{
						auxiliar=listaEmpleados[i];
						listaEmpleados[i]=listaEmpleados[j];
						listaEmpleados[j]=auxiliar;
					}
				}
			}
		}

		estado = printEmployees(listaEmpleados,len);
	}

	return estado;

}

int printEmployees(eEmpleado listaEmpleados[], int len)
{
	int i;
	int estado;

	estado = ValidarArrayOcupadoEmpleados(listaEmpleados,len);


	if (estado == OCUPADO)
	{
		for(i=0;i<len;i++)
		{
			if (listaEmpleados[i].isEmpty == OCUPADO)
			{
				ImprimirUnEmpleado(listaEmpleados[i]);
			}
		}
	}

	return estado;

}

int BuscarLibreEmpleados(eEmpleado listaEmpleados[], int len)
{
	int i;
	int indexBL;

	indexBL = -1;

	if (listaEmpleados != NULL)
	{
		for(i=0; i<len; i++)
		{
			if(listaEmpleados[i].isEmpty != OCUPADO)
			{
				indexBL = i;
				break;
			}
		}
	}

	return indexBL;
}

int ValidarArrayOcupadoEmpleados(eEmpleado listaEmpleados[], int len)
{
	int i;
	int estado;

	estado = -1;

	for(i=0; i < len; i++)
	{

		if(listaEmpleados[i].isEmpty == OCUPADO)
		{
			estado = OCUPADO;
			break;
		}
	}

	return estado;
}

int ValidarArrayMasDeUnOcupadoEmpleados(eEmpleado listaEmpleados[], int len)
{
	int i;
	int contador;
	int estado;

	estado = -1;
	contador = 0;

	for(i=0; i < len; i++)
	{

		if(listaEmpleados[i].isEmpty == OCUPADO)
		{
			contador++;
			if (contador > 1)
			{
				estado = OCUPADO;
				break;
			}
		}
	}

	return estado;
}

void ImprimirUnEmpleado(eEmpleado unEmpleado)
{

	printf("%d %s %s %f %d \n",
			unEmpleado.id,
			unEmpleado.name,
			unEmpleado.lastName,
			unEmpleado.salary,
			unEmpleado.sector);
}

int ModificarEmpleado(eEmpleado listaEmpleados[], int len, int maxName, int maxLastName)
{
	int estado;
	int idTrabajo;
	int indexID;
	int contadorValidarId;
	int opcionSegun;
	int estadoValidarOpcion;
	int contadorValidarOpcion;
	int auxInt;
	float auxFloat;

	estado = printEmployees(listaEmpleados,len);
	contadorValidarId = 0;
	contadorValidarOpcion = 0;

	if (estado == OCUPADO)
	{
		do
		{

			idTrabajo = PedirEntero("Ingrese ID de Trabajo a modificar:", "Dato ingresado no válido");
			indexID = findEmployeeById(listaEmpleados, len, idTrabajo);

			if(indexID == -1)
			{
				printf("ID no disponible. Ingrese alguna de las opciones mostradas anteriormente. \n");
				contadorValidarId++;
			}
			else
			{
				estado = 1;
			}

			if (contadorValidarId == 3)
			{
				printf("Se ha llegado al máximo de intentos. Revise las opciones disponibles y reintente. \n");
				break;
			}

		}while(indexID == -1);

		if (indexID != -1)
		{
			do
			{

				printf("Campos disponibles: \n");
				printf("1. NOMBRE \n");
				printf("2. APELLIDO \n");
				printf("3. SALARIO \n");
				printf("4. SECTOR \n");
				printf("5. Salir \n");
				opcionSegun = PedirEntero("Ingrese una opción:", "Dato ingresado inválido");
				estadoValidarOpcion = ValidarEnteroConRango(opcionSegun, 1, 5);

				if (estadoValidarOpcion == -1)
				{
					printf("Ingrese una opción disponible!!! \n");
					contadorValidarOpcion++;
				}

				if (contadorValidarOpcion == 3)
				{
					printf("Se ha llegado al máximo de intentos. Revise las opciones disponibles y reintente. \n");
					estado = -1;
					break;
				}

			}while(estadoValidarOpcion == -1);

			if (contadorValidarOpcion < 3)
			{
				switch (opcionSegun)
				{
					case 1:
						PedirNombresOApellidos(listaEmpleados[indexID].name, maxName,"Ingrese nombre:", "Dato ingresado inválido");

						break;
					case 2:
						PedirNombresOApellidos(listaEmpleados[indexID].lastName, maxLastName,"Ingrese apellido:", "Dato ingresado inválido");

						break;
					case 3:
						contadorValidarOpcion = 0;
						do
						{
							auxFloat = PedirFlotante("Ingrese salario:", "Dato ingresado inválido");
							estadoValidarOpcion = ValidarFlotanteConRangoMinimo(auxFloat, 0.1);
							if (estadoValidarOpcion != -1)
							{
								listaEmpleados[indexID].salary = auxFloat;
							}
							else
							{
								printf("Ingrese un valor mayor a 0.1!!!");
								contadorValidarOpcion++;
							}

							if(contadorValidarOpcion == 3)
							{
								printf("Se ha llegado al máximo de intentos. Revise las indicaciones atentamente y reintente. \n");
								estado = -1;
								break;
							}
						}while(estadoValidarOpcion != 1);
						break;
					case 4:
						contadorValidarOpcion = 0;
						do
						{
							auxInt = PedirEntero("Ingrese sector:", "Dato ingresado inválido");
							estadoValidarOpcion = ValidarEnteroConRangoMinimo(auxInt, 1);
							if (estadoValidarOpcion != -1)
							{
								listaEmpleados[indexID].sector = auxInt;
							}
							else
							{
								printf("Ingrese un valor mayor a 1!!!");
								contadorValidarOpcion++;
							}

							if(contadorValidarOpcion == 3)
							{
								printf("Se ha llegado al máximo de intentos. Revise las indicaciones atentamente y reintente. \n");
								estado = -1;
								break;
							}
						}while(estadoValidarOpcion != 1);
						break;
					default:
						break;
				}
			}
		}
	}

	return estado;
}

int BuscarLibreEmpleado(eEmpleado listaEmpleados[], int len)
{
	int i;
    int indexBL;

    indexBL = -1;

    if (listaEmpleados != NULL)
    {
		for(i=0; i<len; i++)
		{
			if(listaEmpleados[i].isEmpty != OCUPADO)
			{
				indexBL = i;
				break;
			}
		}
    }

    return indexBL;
}

int OrdenarYMostrarEmpleadosPorOrdenAlfabeticoOSector(eEmpleado listaEmpleados[], int len)
{
	int estado;
	int estadoOrden;
	int auxInt;
	int contadorValidador;
	int i;
	eEmpleado auxEmpleados[len];

	estado = ValidarArrayOcupadoEmpleados(listaEmpleados, len);


	if (estado == OCUPADO)
	{
		do
		{
			printf("Elija tipo de orden: \n");
			printf("1. MENOR A MAYOR \n");
			printf("2. MAYOR A MENOR \n");
			auxInt = PedirEntero("Ingrese una opción:","Dato ingresado no válido");
			estadoOrden = ValidarEnteroConRango(auxInt, 1,2);

			if (estadoOrden != 1)
			{
				{
					printf("Seleccione una opción disponible!!!");
					contadorValidador++;
				}

				if(contadorValidador == 3)
				{
					printf("Se ha llegado al máximo de intentos. Revise las indicaciones atentamente y reintente. \n");
					estado = -1;
					break;
				}
			}
		}while(estadoOrden != 1);

		if (estadoOrden != -1)
		{


			if(ValidarArrayMasDeUnOcupadoEmpleados(listaEmpleados,len) != -1)
			{
				for(i=0;i<len;i++)
				{
					auxEmpleados[i] = listaEmpleados[i];
				}

				estado = sortEmployees(auxEmpleados,len,auxInt);

			}
			else
			{
				estado = printEmployees(listaEmpleados,len);
			}
		}
	}

	return estado;

}



