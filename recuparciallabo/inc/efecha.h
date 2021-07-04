/*
 * efecha.h
 *
 *  Created on: May 9, 2021
 *      Author: rodrigo
 */
#ifndef EFECHA_H_
#define EFECHA_H_
#define ANIO_ACTUAL 2021
#include "../inc/bibliogenerica.h"



typedef struct {
	int anio;
	int mes;
	int dia;
}eFecha;



/**
 * @fn eFecha PedirFecha(int, int, int)
 * @brief solicita los datos para los campos anio, mes y dia de
 *
 * @param indexFecha
 * @param minAnio
 * @param maxAnio
 * @return miFecha
 */
eFecha PedirFecha(int anioActual);





#endif /* EFECHA_H_ */
