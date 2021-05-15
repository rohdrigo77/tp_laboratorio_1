/*
 * nexo.h
 *
 *  Created on: May 15, 2021
 *      Author: rodrigo
 */

#ifndef NEXO_H_
#define NEXO_H_
#include "ArrayEmployees.h"
#include "eauxiliar.h"

/**
 * @fn int TotalPromedioSalariosYCantidadEmpleadosSueldosMayoresAPromedio(eEmpleado[], int)
 * @brief calcula el salario promedio entre empleados, lo muestra, y muestra tambien aquellos empleados con sueldo por encima del promedio.
 *
 * @param listaEmpleados
 * @param len
 * @return estado (asigna -1 si no hay empleados cargados, y 1 si los hay.
 */
int TotalPromedioSalariosYCantidadEmpleadosSueldosMayoresAPromedio(eEmpleado listaEmpleados[], int len);

#endif /* NEXO_H_ */

//test
