/*
 * eFecha.h
 *
 *  Created on: Jun 28, 2021
 *      Author: rodrigo
 */

#ifndef INC_EFECHA_H_
#define INC_EFECHA_H_

typedef struct{
	int anio;
	int mes;
	int dia;
}eFecha;

eFecha PedirFecha(int anioActual);



#endif /* INC_EFECHA_H_ */
