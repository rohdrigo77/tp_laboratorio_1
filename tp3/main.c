#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "bibliogenerica.h"
#define BIN "data.bin"
#define CSV "data.csv"
#define LASTID "lastid.bin"

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
    int lastId;
    int listaCargada = 0;
    int auxLastId;
    int listaGuardada = 0;


    LinkedList* listaEmpleados = ll_newLinkedList();

    lastId = getLastId(LASTID);
    //lastId= setLastId(LASTID,1000);
    printf("lastid: %d \n",lastId);
    auxLastId = lastId;


    setbuf(stdout, NULL);

    do{
    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    	printf("3. Alta de empleado.\n");
    	printf("4. Modificar datos de empleado.\n");
    	printf("5. Baja de empleado.\n");
    	printf("6. Listar empleados.\n");
    	printf("7. Ordenar empleados.\n");
    	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    	printf("10. Salir\n");
    	scanf("%d",&option);

        switch(option)
        {
            case 1:
            	if (listaCargada < 1)
            	{
					estado = controller_loadFromText(CSV,listaEmpleados);
			        if (estado != 1)
					{
						printf("Hubo un inconveniente durante la carga del archivo. \n");
					}
					else
					{
						printf("La carga del archivo se realiz?? correctamente. \n");
						listaCargada = 1;
					}
					break;
            	}
            	else
            	{
            		printf("La lista ya fue cargada.\n");
            	}
                break;
            case 2:
            	if (listaCargada < 1)
                {
					estado = controller_loadFromBinary(BIN,listaEmpleados);
					if (estado != 1)
					{
						printf("Hubo un inconveniente durante la carga del archivo. \n");
					}
					else
					{
						printf("La carga del archivo se realiz?? correctamente. \n");
						listaCargada = 1;
					}
                }
            	else
            	{
            		printf("La lista ya fue cargada.\n");
            	}
                break;
            case 3:
            	estado = controller_addEmployee(listaEmpleados,&auxLastId);

                if (estado != 0)
                {
                	printf("Hubo un inconveniente durante la carga del empleado. \n");
                }
                else
                {
                	printf("La carga del empleado se realiz?? correctamente. \n");
                }
            	break;
            case 4:
            	estado = controller_editEmployee(listaEmpleados);
                if (estado != 1)
                {
                	printf("Hubo un inconveniente durante la modificaci??n del empleado. \n");
                }
                else
                {
                	printf("La modificaci??n del empleado se realiz?? correctamente. \n");
                }
            	break;
            case 5:
            	estado = controller_removeEmployee(listaEmpleados);
				if (estado > 0)
				{
					printf("Hubo un inconveniente durante la modificaci??n del empleado. \n");
				}
				else
				{
					printf("La modificaci??n del empleado se realiz?? correctamente. \n");
				}
            	break;
            case 6:
            	estado = controller_ListEmployee(listaEmpleados);
				if (estado != 1)
				{
					printf("Hubo un inconveniente durante la muestra de la lista. \n");
				}
				else
				{
					printf("La muestra de la lista se realiz?? correctamente. \n");
				}
            	break;
            case 7:
            	estado = controller_sortEmployee(listaEmpleados);
				if (estado != 1)
				{
					printf("Hubo un inconveniente durante el ordenamiento. \n");
				}
				else
				{
					printf("El orden de los empleados se realiz?? correctamente. \n");
				}
            	break;
            case 8:

            	if (listaCargada == 1 && auxLastId > lastId)
            	{
                	controller_ListEmployee(listaEmpleados);
            		estado = PedirConfirmacion("Estos fueron los cambios realizados. Esta segur@ que desea guardarlos? Escriba 's' o 'n':","Dato ingresado no v??lido");
                	if (estado > 0)
                	{
						estado = controller_saveAsText(CSV , listaEmpleados);
						if (estado != 1)
						{
							printf("Hubo un inconveniente al guardar la lista de empleados. \n");
						}
						else
						{
							printf("Los cambios en la lista de empleados se guardaron correctamente. \n");
							setLastId(LASTID,auxLastId);
							listaGuardada = 1;
						}
                	}
                	else
                	{
                		break;
                	}
            	}
            	else if (listaCargada == 1 && auxLastId == lastId)
            	{
            		printf("No hay cambios para guardar \n");
            		break;
            	}
            	else
            	{
            		printf("Cargue la lista de empleados y luego realice modificaciones antes de querer guardar!!!\n");
            	}
            	break;
            case 9:
            	if (listaCargada == 1 && auxLastId > lastId)
            	{
            		controller_ListEmployee(listaEmpleados);
					estado = PedirConfirmacion("Estos fueron los cambios realizados. Esta segur@ que desea guardarlos? Escriba 's' o 'n':","Dato ingresado no v??lido");
					if (estado > 0)
					{
						estado = controller_saveAsBinary(BIN, listaEmpleados);
						if (estado != 1)
						{
							printf("Hubo un inconveniente durante la modificaci??n del empleado. \n");
						}
						else
						{
							printf("Los cambios en la lista de empleados se guardaron correctamente. \n");
							setLastId(LASTID,auxLastId);
							listaGuardada = 1;
						}
					}
					else
					{
						break;
					}
            	}
            	else if (listaCargada == 1 && auxLastId == lastId)
            	{
            		printf("No hay cambios para guardar \n");
            		break;
            	}
            	else
				{
					printf("Cargue la lista de empleados y luego realice modificaciones antes de querer guardar!!!\n");
				}
            	break;
            case 10:
            	if (listaGuardada < 1 && auxLastId > lastId)
            	{
            		estado = PedirConfirmacion("No se guardaron los cambios. Esta segur@ que desea salir sin guardar? Escriba 's' o 'n':","Dato ingresado no v??lido");
            		if (estado != -1)
            		{
            			ll_deleteLinkedList(listaEmpleados);
            			break;
            		}
            		else
            		{
            			option = 1;
            			break;
            		}
            	}
            	else
            	{
            		lastId = auxLastId;
            	}

            	ll_deleteLinkedList(listaEmpleados);
            	break;
        }
    }while(option != 10);
    return 0;
}

