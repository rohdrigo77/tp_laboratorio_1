/*
 * informes.h
 *
 *  Created on: Jun 29, 2021
 *      Author: rodrigo
 */

#ifndef INC_INFORMES_H_
#define INC_INFORMES_H_

#include "../inc/eVuelo.h"
#include "../inc/efecha.h"
#include "../inc/ePiloto.h"

/**
 *
 */
int Informe_Cantidad_Pasajeros(LinkedList* this, char mensaje[]);
/**
 *
 */
int extraerCantidadPasajeros(void* pElement);



#endif /* INC_INFORMES_H_ */
