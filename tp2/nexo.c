/*
 * nexo.c
 *
 *  Created on: May 15, 2021
 *      Author: rodrigo
 */

#include "nexo.h"

int TotalPromedioSalariosYCantidadEmpleadosSueldosMayoresAPromedio(eEmpleado listaEmpleados[], int len)
{
	int estado;
	int i;
	float promedio;
	eAuxiliar auxPromedios[len];

	estado = ValidarArrayOcupadoEmpleados(listaEmpleados, len);

	if (estado == OCUPADO)
	{

		auxPromedios[0].idAuxiliar = 1;
		auxPromedios[0].contador = 0;
		auxPromedios[0].acumulador = 0;
		auxPromedios[0].estadoAuxiliar = OCUPADO;

		for ( i = 0; i < len;i++ )
		{
			if (listaEmpleados[i].isEmpty == OCUPADO)
			{
				auxPromedios[0].contador++;
				auxPromedios[0].acumulador += listaEmpleados[i].salary;

			}
		}

		promedio = CalcularPromedio(auxPromedios[0].acumulador,auxPromedios[0].contador);

		printf("El sueldo promedio es de $%f .\n",promedio);

		printf("Empleados que superan el sueldo promedio: \n");

		for(i=0;i<len;i++)
		{
			if (listaEmpleados[i].salary > promedio)
			{
				ImprimirUnEmpleado(listaEmpleados[i]);
			}
		}

	}

	return estado;
}
