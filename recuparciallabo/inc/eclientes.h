/*
 * eclientes.h
 *
 *  Created on: 01/07/2021
 *      Author: btz_p
 */

#ifndef ECLIENTES_H_
#define ECLIENTES_H_
#define MAX_CLIENTES 5
#define MIN_ID_CLIENTES 1000
#define MAX_NOMBRE 50
#define MAX_APELLIDO 50
#include "../inc/bibliogenerica.h"

typedef struct{
	int idCliente;
	char nombre[50];
	char apellido[50];
	int estadoCliente;
}eCliente;

void InicializarClientes(eCliente listaClientes[], int tamC);

int BuscarIDClientes(eCliente listaClientes[], int tamC, int idCliente);

int BuscarLibreClientes(eCliente listaClientes[], int tamC);

void ImprimirClientes(eCliente listaClientes[], int tamC);

void ImprimirUnCliente(eCliente miCliente);

void HardcodeoDatosClientes(eCliente listaClientes[], int tamC, int minId);

#endif /* ECLIENTES_H_ */
