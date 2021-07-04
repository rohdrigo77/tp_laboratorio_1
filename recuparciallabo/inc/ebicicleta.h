/*
 * ebicicleta.h
 *
 *  Created on: May 11, 2021
 *      Author: rodrigo
 */

#ifndef EBICICLETA_H_
#define EBICICLETA_H_
#define MAX_MARCA 25
#define MAX_BICICLETAS 10
#define MIN_ID_BICICLETAS 25
#define MAX_COLOR 25
#include "../inc/bibliogenerica.h"

typedef struct {
	int idBicicleta;
	int idCliente;
	char marcaBicicleta[MAX_MARCA];
	int rodadoBicicleta;
	char colorBicicleta[MAX_COLOR];
	int estadoBicicleta;
}eBicicleta;

void InicializarBicicletas(eBicicleta listaBicicletas[], int tamB);
/**
 * @fn int BuscarLibreBicicletas(eBicicleta[], int)
 * @brief busca en el array listaBicicletas una posición que tenga el campo estadoBicicleta = 0 ó -1, asignando -1 a indexBL si
 * no fue exitosa la búsqueda o una posición si lo fue.
 *
 * @param listaBicicletas
 * @param tamB
 * @return indexBL
 */
int BuscarLibreBicicletas(eBicicleta listaBicicletas[], int tamB);
/**
 * @fn int BuscarIDBicicletas(eBicicleta[], int, int)
 * @brief busca el campo idBicicleta con valor igual al parametro idBicicleta en cada elemento del array, asignando el indice a index si lo encuentra, y -1 si no
 *
 * @param listaBicicletas
 * @param tamB
 * @param idBicicletas
 * @return index
 */
int BuscarIDBicicletas(eBicicleta listaBicicletas[], int tamB,int idBicicletas);
/**
 * @fn int ValidarArrayOcupadoBicicletas(eBicicleta[], int)
 * @brief si al menos hay un elemento en el array listaBicicletas que tenga en el campo estadoBicicleta el valor OCUPADO, asigna el valor 1 a estado, si no, -1.
 *
 * @param listaBicicletas
 * @param tamB
 * @return estado
 */
int ValidarArrayOcupadoBicicletas(eBicicleta listaBicicletas[], int tamB);
/**
 * @fn int PedirBicicleta(int, int, int, int, int)
 * @brief
 *
 * @param indexBici
 * @param tamB
 * @param minID
 * @param maxMarca
 * @param maxColor
 * @return
 */
eBicicleta PedirBicicleta(int indexBici, int tamB, int minID, int maxMarca, int maxColor);

int ValidarBicicletaRoja(eBicicleta miBicicleta);



#endif /* EBICICLETA_H_ */
