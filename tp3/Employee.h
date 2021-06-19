#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/**
 * @fn Employee employee_new*()
 * @brief se reserva espacio en memoria para almacenar un empleado, y se inicializan los campos
 *
 * @return pEmpleado
 */
Employee* employee_new();
/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief se crea un empleado y se le asignan los valores char recibidos a los campos del empleado
 *
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @param sueldoStr
 * @return pEmpleado
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
/**
 * @fn Employee employee_newParametrosConInt*(int, char*, int, int)
 * @brief se crea un empleado y se le asignan los valores int recibidos a los campos del empleado
 *
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @param sueldoStr
 * @return pEmpleado
 */
Employee* employee_newParametrosConInt(int idStr, char* nombreStr, int horasTrabajadasStr, int sueldoStr);
/**
 * @fn void employee_delete(Employee*)
 * @brief se remueve empleado recibido
 *
 * @param this
 */
void employee_delete(Employee* this);
/**
 * @fn int employee_setId(Employee*, int)
 * @brief se setea el id recibido en el campo id del empleado recibido
 *
 * @param this
 * @param id
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int employee_setId(Employee* this,int id);
/**
 * @fn int employee_getId(Employee*, int*)
 * @brief se devuelve el contenido del campo id de empleado en el puntero id recibido
 *
 * @param this
 * @param id
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int employee_getId(Employee* this,int* id);
/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief se setea el nombre recibido en el campo nombre del empleado recibido
 *
 * @param this
 * @param nombre
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int employee_setNombre(Employee* this,char* nombre);
/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief se devuelve el contenido del campo nombre de empleado en el puntero nombre recibido
 *
 * @param this
 * @param nombre
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int employee_getNombre(Employee* this,char* nombre);
/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief se setea las horas trabajadas recibido en el campo horas trabajadas del empleado recibido
 *
 * @param this
 * @param horasTrabajadas
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief se devuelve el contenido del campo horas trabajadas de empleado en el puntero horas trabajadas recibido
 *
 * @param this
 * @param horasTrabajadas
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief se setea el sueldo recibido en el campo sueldo del empleado recibido
 *
 * @param this
 * @param sueldo
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int employee_setSueldo(Employee* this,int sueldo);
/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief se devuelve el contenido del campo sueldo de empleado en el puntero sueldo recibido
 *
 * @param this
 * @param sueldo
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int employee_getSueldo(Employee* this,int* sueldo);
/**
 * @fn int employee_showEmployee(Employee*)
 * @brief se muestra un empleado recibido
 *
 * @param miEmpleado
 * @return estado (-1 si falla, 1 si se muestra ok)
 */
int employee_showEmployee(Employee* miEmpleado);
/**
 * @fn int employee_getEmployee(Employee*, int*, char*, int*, int*)
 * @brief se pueblan las variables int y char con los campos del empleado recibido
 *
 * @param miEmpleado
 * @param auxId
 * @param auxNombre
 * @param auxHoras
 * @param auxSueldo
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int employee_getEmployee(Employee* miEmpleado, int* auxId, char* auxNombre, int* auxHoras, int* auxSueldo);
/**
 * @fn int employee_sortId(void*, void*)
 * @brief se reciben dos punteros void, se castean a Employee, se comparan los id de los empleados y se retorna un estado que indica si un id es menor, mayor o igual a otro
 *
 * @param e1
 * @param e2
 * @return estado (-1 si es menor, 1 si es mayor, 0 si es igual)
 */
int employee_sortId(void* e1, void* e2);
/**
 * @fn int employee_sortNombre(void*, void*)
 * @brief se reciben dos punteros void, se castean a Employee, se comparan los nombres de los empleados y se retorna un estado que indica si un nombre es menor, mayor o igual a otro
 *
 * @param e1
 * @param e2
 * @return estado (-1 si es menor, 1 si es mayor, 0 si es igual)
 */
int employee_sortNombre(void* e1, void* e2);
/**
 * @fn int employee_sortHorasTrabajadas(void*, void*)
 * @brief se reciben dos punteros void, se castean a Employee, se comparan las horas trabajadas de los empleados y se retorna un estado que indica si las horas trabajadas son menores, mayores o iguales a las de otro
 *
 * @param e1
 * @param e2
 * @return estado (-1 si es menor, 1 si es mayor, 0 si es igual)
 */
int employee_sortHorasTrabajadas(void* e1, void* e2);
/**
 * @fn int employee_sortSueldo(void*, void*)
 * @brief se reciben dos punteros void, se castean a Employee, se comparan los sueldos de los empleados y se retorna un estado que indica si un sueldo es menor, mayor o igual a otro
 *
 * @param e1
 * @param e2
 * @return estado (-1 si es menor, 1 si es mayor, 0 si es igual)
 */
int employee_sortSueldo(void* e1, void* e2);



#endif // employee_H_INCLUDED
