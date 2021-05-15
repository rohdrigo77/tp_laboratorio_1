/*
 * eauxiliar.h
 *
 *  Created on: May 4, 2021
 *      Author: rodrigo
 */

#ifndef EAUXILIAR_H_
#define EAUXILIAR_H_
#include "bibliogenerica.h"


typedef struct {
	int idAuxiliar;
	int contador;
	float acumulador;
	char descripcion[MAX_DESCRIPCION];
	int estadoAuxiliar;
}eAuxiliar;

/**
 * @fn int BuscarIDAuxiliares(eAuxiliar[], int, int)
 * @brief Busca al ID proporcionado por idAuxiliar en el array listaAuxiliar, asignando -1 a estado si
 * no fue exitosa la búsqueda o la posición si lo fue.
 *
 * @param listaAuxiliar
 * @param tamAuxiliar
 * @param idAuxiliar
 * @return estado
 */
int BuscarIDAuxiliares(eAuxiliar listaAuxiliar[], int tamAuxiliar, int idAuxiliar);
/**
 * @fn void ImprimirAuxiliares(eAuxiliar[], int)
 * @brief muestra todos los campos de cada eAuxiliar menos estadoAuxiliar, si el elemento de la posición tiene el campo estadoAuxiliar == 1
 *
 * @param listaAuxiliar
 * @param tamAuxiliar
 */
void ImprimirAuxiliares(eAuxiliar listaAuxiliar[], int tamAuxiliar);
/**
 * @fn void ImprimirUnAuxiliar(eAuxiliar)
 * @brief muestra todos los campos de un eAuxiliar menos estadoAuxiliar
 *
 * @param miAuxiliar
 */
void ImprimirUnAuxiliar(eAuxiliar miAuxiliar);
/**
 * @fn int ValidarArrayOcupadoAuxiliares(eAuxiliar[], int)
 * @brief Asigna -1 a estado si hay 0 o 1 solo espacio del array ocupado, 1 si hay dos o mas
 *
 * @param listaAuxiliares
 * @param len
 * @return estado
 */
int ValidarArrayOcupadoAuxiliares(eAuxiliar listaAuxiliares[], int len);


#endif /* EAUXILIAR_H_ */

