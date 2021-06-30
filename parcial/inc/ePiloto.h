/*
 * ePiloto.h
 *
 *  Created on: Jun 28, 2021
 *      Author: rodrigo
 */

#ifndef INC_EPILOTO_H_
#define INC_EPILOTO_H_
#include "../inc/efecha.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct
{
    int idPiloto;
    char nombre[128];
}ePiloto;
/**
 *
 */
ePiloto* ePiloto_new();
/**
 *
 */
ePiloto* ePiloto_newParametros(char* idPiloto, char* nombre);
/**
 *
 */
void ePiloto_delete(ePiloto* this);
/**
 *
 */
int ePiloto_setIdPiloto(ePiloto* this, int id);
/**
 *
 */
int ePiloto_getIdPiloto(ePiloto* this, int* id);
/**
 *
 */
int ePiloto_setNombre(ePiloto* this, char nombre[]);
/**
 *
 */
int ePiloto_getNombre(ePiloto* this, char* nombre);
/**
 * @fn int ePiloto_showePiloto(ePiloto*)
 * @brief se muestra un empleado recibido
 *
 * @param miEmpleado
 * @return estado (-1 si falla, 1 si se muestra ok)
 */
int ePiloto_showePiloto(ePiloto* miEmpleado);
/**
 * @fn int ePiloto_getePiloto(ePiloto*, int*, char*, int*, int*)
 * @brief se pueblan las variables int y char con los campos del empleado recibido
 *
 * @param miEmpleado
 * @param auxId
 * @param auxNombre
 * @param auxHoras
 * @param auxSueldo
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int ePiloto_getePiloto(ePiloto* miPiloto, int* auxIdPiloto, char* auxNombre);
/**
 * @fn int ePiloto_sortId(void*, void*)
 * @brief se reciben dos punteros void, se castean a ePiloto, se comparan los id de los empleados y se retorna un estado que indica si un id es menor, mayor o igual a otro
 *
 * @param e1
 * @param e2
 * @return estado (-1 si es menor, 1 si es mayor, 0 si es igual)
 */
//int ePiloto_sortId(void* e1, void* e2);
/**
 * @fn int ePiloto_sortNombre(void*, void*)
 * @brief se reciben dos punteros void, se castean a ePiloto, se comparan los nombres de los empleados y se retorna un estado que indica si un nombre es menor, mayor o igual a otro
 *
 * @param e1
 * @param e2
 * @return estado (-1 si es menor, 1 si es mayor, 0 si es igual)
 */
//int ePiloto_sortNombre(void* e1, void* e2);
/**
 * @fn int ePiloto_sortHorasTrabajadas(void*, void*)
 * @brief se reciben dos punteros void, se castean a ePiloto, se comparan las horas trabajadas de los empleados y se retorna un estado que indica si las horas trabajadas son menores, mayores o iguales a las de otro
 *
 * @param e1
 * @param e2
 * @return estado (-1 si es menor, 1 si es mayor, 0 si es igual)
 */
//int ePiloto_sortHorasTrabajadas(void* e1, void* e2);
/**
 * @fn int ePiloto_sortSueldo(void*, void*)
 * @brief se reciben dos punteros void, se castean a ePiloto, se comparan los sueldos de los empleados y se retorna un estado que indica si un sueldo es menor, mayor o igual a otro
 *
 * @param e1
 * @param e2
 * @return estado (-1 si es menor, 1 si es mayor, 0 si es igual)
 */
//int ePiloto_sortSueldo(void* e1, void* e2);



#endif /* INC_EPILOTO_H_ */
