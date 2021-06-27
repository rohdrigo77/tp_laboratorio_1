#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/Employee.h"
#include "../inc/parser.h"
#include "../inc/bibliogenerica.h"
#include "../inc/Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
	int estado;
	FILE* pArchivo = NULL;
	estado = -1;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		printf("entre al if del controller \n");
		pArchivo = fopen(path,"r");
		printf("abri el archivo \n");
		estado = parser_EmployeeFromText(pArchivo , pArrayListEmployee);
		fclose(pArchivo);
	}


    return estado;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int estado;
	FILE* pArchivo;
	estado = -1;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pArchivo = fopen(path,"rb");
		estado = parser_EmployeeFromBinary(pArchivo , pArrayListEmployee);
		fclose(pArchivo);
	}


    return estado;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* tempLastId)
{
	Employee* pEmpleado;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;
	int estado;

	estado = -1;

	if (pArrayListEmployee != NULL)
	{

		//*ultimoId = *lastId;

		PedirNombresOApellidos(auxNombre, 128, "Ingrese su Nombre: ",  "Dato ingresado invalido");
		PedirEntero(&auxHorasTrabajadas, "Ingrese las horas trabajadas: ", "Dato ingresado invalido");
		PedirEntero(&auxSueldo, "Ingrese el sueldo: ", "Dato ingresado invalido");

		pEmpleado = employee_newParametrosConInt((*tempLastId)+1, auxNombre, auxHorasTrabajadas, auxSueldo);
		if (pEmpleado != NULL)
		{
			*tempLastId+=1;
			estado = ll_add(pArrayListEmployee, pEmpleado);
		}

	}


    return estado;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int estado;
	int idEmpleado;
	Employee* pEmpleado;
	int contadorValidador;
	int opcion;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;

	estado = controller_ListEmployee(pArrayListEmployee);
	contadorValidador = 0;

	if (estado != -1)
	{
		PedirEntero(&idEmpleado,"Ingrese ID de empleado a modificar:","Dato Ingresado no válido");
		pEmpleado = (Employee*) ll_get(pArrayListEmployee, (idEmpleado)-1);
	}

	if (pEmpleado != NULL)
	{

		do
		{
			printf("Campos disponibles a modificar: \n");
			printf("1. Nombre \n");
			printf("2. Horas Trabajadas \n");
			printf("3. Sueldo \n");
			printf("4. Salir \n");

			PedirEntero(&opcion,"Ingrese la opción a modificar","Dato ingresado no válido");

			if (ValidarEnteroConRango(opcion, 1, 4) != 1)
			{
				estado = -1;
				printf("Revise las opciones disponibles y vuelva a intentarlo \n");
				contadorValidador++;

			}
			else
			{
				estado = 1;
				break;
			}

			if (contadorValidador == 3)
			{
				printf("Se ha alcanzado el límite de intentos. Revise las opciones disponibles y vuelva a intentarlo. \n");
				break;
			}

		}while(estado != 1);

		if (estado > 0)
		{

			switch (opcion)
			{
				case 1:
					PedirNombresOApellidos(auxNombre, 128, "Ingrese su Nombre: ",  "Dato ingresado invalido");
					estado = employee_setNombre(pEmpleado,auxNombre);
					break;
				case 2:
					PedirEntero(&auxHoras, "Ingrese las horas trabajadas: ", "Dato ingresado invalido");
					estado = employee_setHorasTrabajadas(pEmpleado,auxHoras);
					break;
				case 3:
					PedirEntero(&auxSueldo, "Ingrese el sueldo: ", "Dato ingresado invalido");
					estado = employee_setSueldo(pEmpleado,auxSueldo);
					break;
				default:
					break;
			}

		}
	}

    return estado;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int estado;
	int contadorValidador;
	int idEmpleado;
	Employee* pEmpleado;



	contadorValidador = 0;

	do
	{
		estado = controller_ListEmployee(pArrayListEmployee);
		PedirEntero(&idEmpleado,"Ingrese ID de empleado a eliminar:","Dato Ingresado no válido");
		pEmpleado = (Employee*) ll_get(pArrayListEmployee, (idEmpleado)-1);

		if (pEmpleado != NULL)
		{
			break;
		}
		else
		{
			printf("ID no encontrado. Verifique los ID disponibles y reintente. \n");
			contadorValidador++;
		}

	}while(contadorValidador < 3);

	if (contadorValidador == 3)
	{
		printf("Se ha alcanzado el máximo de intentos. \n");
		estado = -1;
	}


	if (pEmpleado != NULL)
	{

		estado = employee_showEmployee(pEmpleado);

		if(estado > 0)
		{
			estado = PedirConfirmacion("Esta seguro de que quiere eliminar este empleado? Ingrese 's' o 'n'.", "Dato ingresado no válido");
		}

		if(estado > 0)
		{
			//employee_delete(pEmpleado);
			estado = ll_remove(pArrayListEmployee,(idEmpleado)-1);

		}
	}

    return estado;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int estado;
	int isEmpty = ll_isEmpty(pArrayListEmployee);

	if (pArrayListEmployee != NULL && isEmpty == 0)
	{

		int i;
		int len;
		Employee* auxEmployee;

		len = ll_len(pArrayListEmployee);


		printf("**----------------------------------------------**\n");
		printf("%4s  %15s  %15s  %7s \n", "Id", "Nombre", "Horas Trabajadas", "Sueldo");
		printf("**----------------------------------------------**\n");

		for(i=0; i<len; i++)
		{
			auxEmployee = (Employee*) ll_get(pArrayListEmployee,i);

			if (auxEmployee != NULL)
			{
				estado = employee_showEmployee(auxEmployee);
			}
		}

	}
	else if(isEmpty)
	{
		printf("La lista de empleados está vacía. \n");
		estado = 1;
	}
	else
	{
		estado = -1;
	}

	return estado;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int estado = 0;
	int contadorValidador;
	int opcion;
	int orden;

	if(pArrayListEmployee != NULL && !(ll_isEmpty(pArrayListEmployee)))
	{
		do{
			printf("1.Ordenar por ID \n");
			printf("2.Ordenar por NOMBRE\n");
			printf("3.Ordenar por horas trabajadas\n");
			printf("4.Ordenar por SUELDO\n");
			printf("0.Salir\n");
			PedirEntero(&opcion, "Ingrese el tipo de orden:", "Dato ingresado invalido");
			estado = ValidarEnteroConRango(opcion,0,4);

			if (estado != 1)
			{
				if (contadorValidador==3)
				{
					printf("Se ha alcanzado el máximo de intentos. \n");
					estado = -1;
					break;
				}
				else
				{
					printf("Ingrese una opción válida!!!\n");
					contadorValidador++;
				}
			}
			else
			{
				break;
			}

		}while(contadorValidador<3);
	}

	if (estado != -1)
	{
		do{
			printf("1. Ascendente \n");
			printf("2. Descendente \n");
			PedirEntero(&orden, "Ingrese el tipo de orden:", "Dato ingresado invalido");
			estado = ValidarEnteroConRango(orden,1,2);

			if (estado != 1)
			{

				if (contadorValidador==3)
				{
					printf("Se ha alcanzado el máximo de intentos. \n");
					estado = -1;
					break;
				}
				else
				{
					printf("Ingrese una opción válida!!!\n");
					contadorValidador++;
				}
			}
			else
			{
				break;
			}

		}while(contadorValidador<3);
	}

	if (estado != -1)
	{

		switch(opcion)
		{
			case 1:

				if (estado != -1)
				{
					if(orden == 1)
					{
						ll_sort(pArrayListEmployee, employee_sortId, 1);
					}
					else
					{
						ll_sort(pArrayListEmployee, employee_sortId, 0);
					}
				}


				break;

			case 2:

				if(orden == 1)
				{
					ll_sort(pArrayListEmployee, employee_sortNombre, 1);
				}
				else
				{
					ll_sort(pArrayListEmployee, employee_sortNombre, 0);
				}


				estado = 1;
				break;
			case 3:

				if(orden == 1)
				{
					ll_sort(pArrayListEmployee, employee_sortHorasTrabajadas, 1);
				}
				else
				{
					ll_sort(pArrayListEmployee, employee_sortHorasTrabajadas, 0);
				}

				estado = 1;
				break;
			case 4:

				if(orden == 1)
				{
					ll_sort(pArrayListEmployee, employee_sortSueldo, 1);
				}
				else
				{
					ll_sort(pArrayListEmployee, employee_sortSueldo, 0);
				}


				estado = 1;
				break;

			default:
				estado = -1;
				break;
		}
	}

	return estado;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int estado = 0;
    int i;
    int len;
    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;
    FILE* pArchivo;
    Employee* auxEmpleado;

    if(pArrayListEmployee != NULL && path != NULL)
    {

        pArchivo = fopen(path, "w");

        if(pArchivo != NULL)
        {
        	len = ll_len(pArrayListEmployee);
        	fprintf(pArchivo,"id,nombre,horasTrabajadas,Sueldo\n");
            for(i = 0; i < len; i++)
            {
                auxEmpleado= (Employee*)ll_get(pArrayListEmployee,i);
                estado = employee_getId(auxEmpleado,&auxId);
                estado = employee_getNombre(auxEmpleado,auxNombre);
                estado = employee_getHorasTrabajadas(auxEmpleado,&auxHoras);
                estado = employee_getSueldo(auxEmpleado,&auxSueldo);

                fprintf(pArchivo,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
            }
            fclose(pArchivo);

        }
    }

    return estado;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int estado = 0;
	int i;
	int len;
	FILE* pArchivo;
	Employee* auxEmpleado;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pArchivo = fopen(path, "wb");
		if(pArchivo != NULL)
		{
			len = ll_len(pArrayListEmployee);
			for(i = 0; i < len; i++)
			{
					auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);

					if(auxEmpleado != NULL)
					{
						fwrite(auxEmpleado,sizeof(Employee),1,pArchivo);
					}
			}
			fclose(pArchivo);
			estado = 1;
		}
	}

	return estado;
}

int getLastId(char path[])
{
	int id;
	FILE* pArchivo;

	id = 0;

	pArchivo = fopen(path,"rb");

	if (pArchivo != NULL)
	{
		fread(&id,sizeof(int),1,pArchivo);
		fclose(pArchivo);
	}

	return id;
}

int setLastId(char path[],int lastId)
{
	FILE* pArchivo;
	int estado = -1;

	pArchivo = fopen(path,"wb");

	if (pArchivo != NULL)
	{
		fwrite(&lastId,sizeof(int),1,pArchivo);
		fclose(pArchivo);
		estado = 1;
	}

	return estado;
}

