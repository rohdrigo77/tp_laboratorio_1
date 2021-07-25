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
/**
 * @fn void InicializarClientes(eCliente listaClientes[], int tamC);
 *
 * @brief setea en VACIO el estado de los clientes
 *
 * @param listaClientes
 * @param tamC
 */
void InicializarClientes(eCliente listaClientes[], int tamC);
/**
 * @fn int BuscarIDClientes(eCliente listaClientes[], int tamC, int idCliente);
 *
 * @brief busca el id del cliente
 * @param listaClientes
 * @param tamC
 * @param idCliente
 * @return index ( retorna el indice si es que lo encuentra, sino -1)
 */
int BuscarIDClientes(eCliente listaClientes[], int tamC, int idCliente);
/**
 * @fn int BuscarLibreClientes(eCliente listaClientes[], int tamC);
 *
 * @brief Busca un espacio libre en el array
 * @param listaClientes
 * @param tamC
 * @return index ( retorna el indice si es que lo encuentra, sino -1)
 */
int BuscarLibreClientes(eCliente listaClientes[], int tamC);
/**
 * @fn void ImprimirClientes(eCliente listaClientes[], int tamC);
 *
 * @brief muestra los clientes
 * @param listaClientes
 * @param tamC
 */
void ImprimirClientes(eCliente listaClientes[], int tamC);
/**
 * @fn void ImprimirUnCliente(eCliente miCliente);
 *
 * @brief muestra un cliente
 * @param miCliente
 */
void ImprimirUnCliente(eCliente miCliente);
/**
 * @fn void HardcodeoDatosClientes(eCliente listaClientes[], int tamC, int minId);
 *
 * @brief crea, configura y almacena clientes
 * @param listaClientes
 * @param tamC
 * @param minId
 */
void HardcodeoDatosClientes(eCliente listaClientes[], int tamC, int minId);

void ImprimirAcumulacionCliente(int idCliente, char descripcionCliente[], float acumulacionCliente);


#endif /* ECLIENTES_H_ */
