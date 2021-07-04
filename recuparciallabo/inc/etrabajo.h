/*
 * etrabajo.h
 *
 *  Created on: May 4, 2021
 *      Author: rodrigo
 */
#ifndef ETRABAJO_H_
#define ETRABAJO_H_
#define MAX_TRABAJOS 10
#include "../inc/bibliogenerica.h"
#include "../inc/efecha.h"


typedef struct {
	int idTrabajo;
	int idBicicleta;
	int idServicio;
	eFecha fecha;
	int estadoTrabajo;
}eTrabajo;

/**
 * @fn void InicializarTrabajos(eTrabajo[], int)
 * @brief asigna el valor VACIO al campo de estadoTrabajo de cada elemento del array
 *
 * @param listaTrabajos
 * @param tamT
 */


void InicializarTrabajos(eTrabajo listaTrabajos[], int tamT);

/**
 * @fn int BuscarLibreTrabajos(eTrabajo[], int)
 * @brief busca en el array listaTrabajos una posicion que tenga el campo estadoTrabajo = 0 ó -1, asignando -1 a indexBL si
 * no fue exitosa la busqueda o una posicion si lo fue.
 *
 * @param listaTrabajos
 * @param tamT
 * @return indexBL
 */
int BuscarLibreTrabajos(eTrabajo listaTrabajos[], int tamT);
/**
 * @fn int BuscarIDTrabajos(eTrabajo[], int, int)
 * @brief busca el campo idTrabajo con valor igual al parametro idTrabajo en cada elemento del array, asignando el indice a index si lo encuentra, y -1 si no
 *
 * @param listaTrabajos
 * @param tamT
 * @param idTrabajo
 * @return index
 */
int BuscarIDTrabajos(eTrabajo listaTrabajos[], int tamT, int idTrabajo);
/**
 * @fn int ValidarArrayOcupadoTrabajos(eTrabajo[], int)
 * @brief si al menos hay un elemento en el array listaTrabajos que tenga en el campo estadoTrabajo el valor OCUPADO, asigna el valor 1 a estado, si no, -1.
 *
 * @param listaTrabajos
 * @param tamT
 * @return estado
 */
int ValidarArrayOcupadoTrabajos(eTrabajo listaTrabajos[], int tamT);
/**
 * @fn int ValidarParaDarDeBajaTrabajo(eTrabajo)
 * @brief solicita confirmacion para dar de baja un producto, si se responde 's', se asigna 1 a estado, caso contrario, se le asigna -1
 *
 * @param TrabajoADarDeBaja
 * @return estado
 */
int ValidarParaDarDeBajaTrabajo (eTrabajo TrabajoADarDeBaja);
/**
 * @fn void HardcodeoDatosTrabajos(eTrabajo[], int, int)
 * @brief asigna valores especificos a cada campo de un numero determinado elementos de listaTrabajos
 *
 * @param listaTrabajos
 * @param tamT
 * @param minId
 */
void HardcodeoDatosTrabajos(eTrabajo listaTrabajos[], int tamT, int minId, int minIdBicicleta, int anioActual);






#endif /* ETRABAJO_H_ */


