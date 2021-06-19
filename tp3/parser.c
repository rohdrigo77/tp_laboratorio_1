#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pArchivo , LinkedList* pArrayListEmployee)
{
	int estado;
	Employee* pEmpleado;
	char auxID[15];
	char auxNombre[128];
	char auxHorasTrabajadas[5];
	char auxSueldo[10];
	int nroEmpleado;

	nroEmpleado=0;

	if (pArchivo != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",auxID,auxNombre,auxHorasTrabajadas,auxSueldo);
		do
		{
			fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",auxID,auxNombre,auxHorasTrabajadas,auxSueldo);
			//printf("valor de nombre: %s \n",auxNombre);
			pEmpleado = employee_newParametros(auxID,auxNombre,auxHorasTrabajadas,auxSueldo);
			if (pEmpleado != NULL)
			{
				ll_add(pArrayListEmployee, pEmpleado);
				estado = 1;
			}
			else
			{
				printf("pEmpleado es NULL \n");
				estado = 0;
			}
			//printf("estado: %d\n",estado);
			nroEmpleado++;
			//printf("agregue empleado n:%d\n",nroEmpleado);
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
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pArchivo , LinkedList* pArrayListEmployee)
{
	int estado;
	Employee* pEmpleado;
	int bandera;

	if (pArchivo != NULL && pArrayListEmployee != NULL)
	{
		while(feof(pArchivo) == 0)
		{
			pEmpleado = employee_new();
			bandera = fread(pEmpleado,sizeof(Employee),1,pArchivo);
			//printf("valor de nombre: %s \n",auxNombre);

			if (pEmpleado != NULL && bandera > 0)
			{
				ll_add(pArrayListEmployee, pEmpleado);
				estado = 1;
			}
			else
			{
				printf("pEmpleado es NULL \n");
				estado = 0;
			}
			//printf("estado: %d\n",estado);

			//printf("agregue empleado n:%d\n",nroEmpleado);
		}

	}
	else
	{
		estado = 0;
	}


	return estado;
}
