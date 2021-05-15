/*
 * main.c
 *
 *  Created on: May 11, 2021
 *      Author: rodrigo
 */

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "nexo.h"

int main()
{

    setbuf(stdout, NULL);
    eEmpleado listaEmpleados[MAX_EMPLEADOS];
    int opcion;
    int estado;
    int estadoMenu;
    int contadorValidador;




    initEmployees(listaEmpleados, MAX_EMPLEADOS);



    do
    {
    	contadorValidador = 0;

        printf("1. ALTA\n");
        printf("2. MODIFICACION\n");
        printf("3. BAJA\n");
        printf("4. INFORMAR\n");
        printf("10. Salir\n");
        printf("Elija una opcion:");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:


            	estado = addEmployee(listaEmpleados, MAX_EMPLEADOS, MAX_NAME, MAX_LASTNAME);

            	if (estado != -1)
				{
					printf("El Empleado se agregó correctamente.\n");
				}
				else
				{
					printf("Ocurrió un inconveniente al agregar el Empleado.");
				}
                break;
            case 2:
            	estado = ModificarEmpleado(listaEmpleados, MAX_EMPLEADOS, MAX_NAME, MAX_LASTNAME);

				if (estado != -1)
				{
					printf("El Empleado se modificó correctamente.\n");
				}
				else
				{
					printf("Ocurrió un inconveniente al modificar empleado o no hay empleados disponibles para modificar.");
				}
				break;
            case 3:
            	estado = removeEmployee(listaEmpleados, MAX_EMPLEADOS);

            	if (estado != -1)
            	{
            		printf("El Empleado se eliminó correctamente.\n");
            	}
            	else
            	{
            		printf("Se respondió 'n' durante la confirmación u ocurrió un inconveniente al eliminar el Empleado.");
            	}
            	break;
            case 4:

            	do
				{
					printf("Elija tipo de orden: \n");
					printf("1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector. \n");
					printf("2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio. \n");
					opcion = PedirEntero("Ingrese una opción:","Dato ingresado no válido");
					estadoMenu = ValidarEnteroConRango(opcion, 1,2);

					if (estadoMenu != 1)
					{
						{
							printf("Seleccione una opción disponible!!!");
							contadorValidador++;
						}

						if(contadorValidador == 3)
						{
							printf("Se ha llegado al máximo de intentos. Revise las indicaciones atentamente y reintente. \n");
							estadoMenu = -1;
							break;
						}
					}
				}while(estadoMenu != 1);

            	if (estadoMenu != -1)
            	{
					if (opcion == 1)
					{
						estado = OrdenarYMostrarEmpleadosPorOrdenAlfabeticoOSector(listaEmpleados, MAX_EMPLEADOS);


						if (estado == -1)
						{
							printf("No hay empleados cargados! \n");
						}
					}
					else
					{
						estado = TotalPromedioSalariosYCantidadEmpleadosSueldosMayoresAPromedio(listaEmpleados, MAX_EMPLEADOS);

						if (estado == -1)
						{
							printf("No hay empleados cargados! \n");
						}
					}
            	}
				break;
        }
    }while(opcion!=10);


    return 0;
}



