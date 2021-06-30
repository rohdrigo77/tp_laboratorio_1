#ifndef eVuelo_H_INCLUDED
#define eVuelo_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/eVuelo.h"
#include "../inc/ePiloto.h"
#include "../inc/efecha.h"
#define MAX_NOMBRE 128
#define MAX_DESTINO 128

typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    eFecha fecha;
    char destino[128];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}eVuelo;

/**
 * @fn eVuelo eVuelo_new*()
 * @brief se reserva espacio en memoria para almacenar un empleado, y se inicializan los campos
 *
 * @return pEmpleado
 */
eVuelo* eVuelo_new();
/**
 * @fn eVuelo eVuelo_newParametros*(char*, char*, char*, char*)
 * @brief se crea un empleado y se le asignan los valores char recibidos a los campos del empleado
 *
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @param sueldoStr
 * @return pEmpleado
 */
eVuelo* eVuelo_newParametros(char* idVuelo, char* idAvion, char* idPiloto, char* charDia, char* charMes, char* charAnio, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada);
/**
 * @fn eVuelo eVuelo_newParametrosConInt*(int, char*, int, int)
 * @brief se crea un empleado y se le asignan los valores int recibidos a los campos del empleado
 *
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @param sueldoStr
 * @return pEmpleado
 */
//eVuelo* eVuelo_newParametrosConInt(int idStr, char* nombreStr, int horasTrabajadasStr, int sueldoStr);
/**
 * @fn void eVuelo_delete(eVuelo*)
 * @brief se remueve empleado recibido
 *
 * @param this
 */
void eVuelo_delete(eVuelo* this);

int eVuelo_setIdVuelo(eVuelo* this, int id);

int eVuelo_getIdVuelo(eVuelo* this, int* id);

int eVuelo_setIdAvion(eVuelo* this, int id);

int eVuelo_getIdAvion(eVuelo* this, int* id);

int eVuelo_setIdPiloto(eVuelo* this, int id);

int eVuelo_getIdPiloto(eVuelo* this, int* id);

int eVuelo_setFecha(eVuelo* this, eFecha fecha);

int eVuelo_getFecha(eVuelo* this, eFecha* fecha);

int eVuelo_setDestino(eVuelo* this, char* destino);

int eVuelo_getDestino(eVuelo* this, char* destino);

int eVuelo_setCantPasajeros(eVuelo* this, int cantPasajeros);

int eVuelo_getCantPasajeros(eVuelo* this, int* cantPasajeros);

int eVuelo_setHoraDespegue(eVuelo* this,int horaDespegue);

int eVuelo_getHoraDespegue(eVuelo* this,int* horaDespegue);

int eVuelo_setHoraLlegada(eVuelo* this,int horaLlegada);

int eVuelo_getHoraLlegada(eVuelo* this,int* horaLlegada);
/**
 * @fn int eVuelo_showeVuelo(eVuelo*)
 * @brief se muestra un empleado recibido
 *
 * @param miEmpleado
 * @return estado (-1 si falla, 1 si se muestra ok)
 */
int eVuelo_showeVuelo(eVuelo* miEmpleado, LinkedList* this);
/**
 * @fn int eVuelo_geteVuelo(eVuelo*, int*, char*, int*, int*)
 * @brief se pueblan las variables int y char con los campos del empleado recibido
 *
 * @param miEmpleado
 * @param auxId
 * @param auxNombre
 * @param auxHoras
 * @param auxSueldo
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int eVuelo_geteVuelo(LinkedList* this, eVuelo* miVuelo, int* auxIdVuelo, int* auxIdAvion, int* auxIdPiloto, char* auxNombrePiloto, eFecha* auxFecha, char* auxDestino, int* auxCantPasajeros, int* auxHoraDespegue, int* auxHoraLlegada);

/**
 * @fn int eVuelo_sortId(void*, void*)
 * @brief se reciben dos punteros void, se castean a eVuelo, se comparan los id de los empleados y se retorna un estado que indica si un id es menor, mayor o igual a otro
 *
 * @param e1
 * @param e2
 * @return estado (-1 si es menor, 1 si es mayor, 0 si es igual)
 */
//int eVuelo_sortId(void* e1, void* e2);
/**
 * @fn int eVuelo_sortNombre(void*, void*)
 * @brief se reciben dos punteros void, se castean a eVuelo, se comparan los nombres de los empleados y se retorna un estado que indica si un nombre es menor, mayor o igual a otro
 *
 * @param e1
 * @param e2
 * @return estado (-1 si es menor, 1 si es mayor, 0 si es igual)
 */
//int eVuelo_sortNombre(void* e1, void* e2);
/**
 * @fn int eVuelo_sortHorasTrabajadas(void*, void*)
 * @brief se reciben dos punteros void, se castean a eVuelo, se comparan las horas trabajadas de los empleados y se retorna un estado que indica si las horas trabajadas son menores, mayores o iguales a las de otro
 *
 * @param e1
 * @param e2
 * @return estado (-1 si es menor, 1 si es mayor, 0 si es igual)
 */
//int eVuelo_sortHorasTrabajadas(void* e1, void* e2);
/**
 * @fn int eVuelo_sortSueldo(void*, void*)
 * @brief se reciben dos punteros void, se castean a eVuelo, se comparan los sueldos de los empleados y se retorna un estado que indica si un sueldo es menor, mayor o igual a otro
 *
 * @param e1
 * @param e2
 * @return estado (-1 si es menor, 1 si es mayor, 0 si es igual)
 */
//int eVuelo_sortSueldo(void* e1, void* e2);

int eVuelo_PasajerosAChina(void* pElement);

int eVuelo_vueloLargo(void* pElement);

int eVuelo_VuelosAPortugal(void* pElement);

int eVuelo_VuelosSinLyB(void* pElement);






#endif // eVuelo_H_INCLUDED
