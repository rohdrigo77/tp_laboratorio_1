/*
 * ArrayEmployees.h
 *
 *  Created on: May 15, 2021
 *      Author: rodrigo
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define MAX_EMPLEADOS 1000
#define MAX_NAME 51
#define MAX_LASTNAME 51
#define MAX_DESCRIPCION 51
#include "bibliogenerica.h"

typedef struct {
	int id;
	char name[MAX_NAME];
	char lastName[MAX_LASTNAME];
	float salary;
	int sector;
	int isEmpty;
}eEmpleado;

/** \brief To indicate that all position in the array are empty,
*
this function put the flag (isEmpty) in VACIO in all
*
position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
*/
void initEmployees(eEmpleado listaEmpleados[], int len);
/**
 * @fn int addEmployee(eEmpleado[], int, int, int)
 * @brief asigna el valor VACIO a listaEmpleados[i].isEmpty
 *
 * @param listaEmpleados
 * @param len
 * @param maxName
 * @param maxLastName
 */
int addEmployee(eEmpleado listaEmpleados[], int len, int maxName, int maxLastName);
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(eEmpleado listaEmpleados[], int len, int id);
/** \brief Remove a Employee by Id (put isEmpty Flag in BAJA)
*
* \param list Employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(eEmpleado listaEmpleados[], int len);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(eEmpleado listaEmpleados[], int len, int order);
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
*
*/
int printEmployees(eEmpleado listaEmpleados[], int len);
/**
 * @fn void ImprimirUnEmpleado(eEmpleado)
 * @brief print the content of an eEmpleado
 *
 * @param unEmpleado
 */
void ImprimirUnEmpleado(eEmpleado unEmpleado);

/**
 * @fn int ValidarArrayOcupadoTrabajos(eTrabajo[], int)
 * @brief si al menos hay un elemento en el array listaTrabajos que tenga en el campo estadoTrabajo el valor OCUPADO, asigna el valor 1 a estado, si no, -1.
 *
 * @param listaTrabajos
 * @param tamT
 * @return estado
 */
int ValidarArrayOcupadoEmpleados(eEmpleado listaEmpleados[], int len);
/**
 * @fn int ValidarArrayMasDeUnOcupadoEmpleados(eEmpleado[], int)
 * @brief Asigna -1 a estado si hay 0 o 1 solo espacio del array ocupado, 1 si hay dos o mas
 *
 * @param listaEmpleados
 * @param len
 * @return estado
 */
int ValidarArrayMasDeUnOcupadoEmpleados(eEmpleado listaEmpleados[], int len);
/**
 * @fn int ModificarEmpleado(eEmpleado[], int)
 * @brief modifica el campo deseado de un eEmpleado
 *
 * @param listaEmpleados
 * @param len
 * @return estado
 */
int ModificarEmpleado(eEmpleado listaEmpleados[], int len, int maxName, int maxSurname);
/**
 * @fn int BuscarLibreEmpleado(eEmpleado[], int)
 * @brief busca un elemento del array con .isEmpty != OCUPADO
 *
 * @param listaEmpleados
 * @param len
 * @return indexBL
 */
int BuscarLibreEmpleado(eEmpleado listaEmpleados[], int len);
/**
 * @fn int OrdenarYMostrarEmpleadosPorOrdenAlfabeticoOSector(eEmpleado[], int)
 * @brief si hay mas de un elemento en el array, hace una copia del array original y lo ordena segun ingresó el usuario, luego muestra el array ordenado. asigna -1 a estado si no hay elementos en el array y 1 si los hay.
 *
 * @param listaEmpleados
 * @param len
 * @return estado
 */
int OrdenarYMostrarEmpleadosPorOrdenAlfabeticoOSector(eEmpleado listaEmpleados[], int len);





#endif /* ARRAYEMPLOYEES_H_ */
