/*
 * nexo.h
 *
 *  Created on: May 4, 2021
 *      Author: rodrigo
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "../inc/bibliogenerica.h"
#include "../inc/etrabajo.h"
#include "../inc/eservicio.h"
#include "../inc/efecha.h"
#include "../inc/eauxiliar.h"
#include "../inc/ebicicleta.h"
#include "../inc/eclientes.h"

/**
 * @fn int CargarTrabajo(eTrabajo[], eServicio[], eFecha[], int, int, int, int, int, int)
 * @brief se llama a la función  BuscarLibreTrabajos, y si hay lugar en el array listaTrabajos, se llama a PedirDatos,
 * luego se le asigna un entero automaticamente a idTrabajo
 *
 * @param listaTrabajos
 * @param listaServicios
 * @param listaFechas
 * @param tamT
 * @param tamS
 * @param tamF
 * @param minAnio
 * @param maxAnio
 * @param maxMarca
 * @return index
 */
int CargarTrabajo(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], eCliente listaClientes[], int tamT, int tamS, int tamB, int tamC, int anioActual, int maxDescripcion, int maxMarca, int minID, int maxColor);
/**
 * @fn eTrabajo PedirDatos(eServicio[], eFecha[], int, int, int, int, int)
 * @brief Se solicitan enteros y cadenas segun el campo y se retorna un eTrabajo con campos poblados por los datos antes solicitados
 *
 * @param listaServicios
 * @param listaFechas
 * @param maxMarca
 * @param tamS
 * @param tamF
 * @param minAnio
 * @param maxAnio
 * @return eTrabajo
 */
eTrabajo PedirDatos(eServicio listaServicios[], eBicicleta listaBicicletas[], eCliente listaClientes[], int tamS, int tamB, int tamC, int anioActual, int maxDescripcion, int maxMarca, int minID, int maxColor);
/**
 * @fn int ModificarTrabajo(eTrabajo[], eServicio[], eFecha[], int, int, int, int, int, int)
 * @brief solicita un campo a modificar, y luego pide los datos para modificarlo. asigna -1 a estado si la modificación no fue exitosa, 1 si lo fue.
 *
 * @param listaTrabajos
 * @param listaServicios
 * @param listaFechas
 * @param tamT
 * @param tamS
 * @param tamF
 * @param minAnio
 * @param maxAnio
 * @param maxDescripcion
 * @return estado
 */
int ModificarTrabajo(eTrabajo listaTrabajos[], eServicio listaServicios[],  eBicicleta listaBicicletas[], int tamT, int tamS,  int tamB, int anioActual, int maxDescripcion, int maxMarca);
/**
 * @fn int ImprimirTrabajos(eTrabajo[], eServicio[], eFecha[], int, int, int, int)
 * @brief muestra todos los campos de cada eTrabajo en el array menos estadoTrabajo, mientras tengan el campo estadoTrabajo == OCUPADO
 * y asigna el valor 1 a estado si el array no esta vacío, -1 si lo está
 *
 * @param listaTrabajos
 * @param listaServicios
 * @param listaFechas
 * @param tamT
 * @param tamS
 * @param tamF
 * @param maxDescripcion
 * @return estado
 */
int ImprimirTrabajos(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], int tamT, int tamS, int tamB, int maxDescripcion, int maxMarca);
/**
 * @fn void ImprimirUnTrabajo(eTrabajo, eServicio[], eFecha[], int, int, int)
 * @brief muestra todos los campos de cada eTrabajo en el array menos estadoTrabajo, mientras tengan el campo estadoTrabajo == OCUPADO
 * y busca los valores iguales de  idFecha e idServicio con los id de las estructuras eFecha y eServicio en listaFechas y listaServicios para mostrar
 * la fecha separada por / y la descripcion del servicio
 *
 * @param miTrabajo
 * @param listaServicios
 * @param listaFechas
 * @param tamS
 * @param tamF
 * @param maxDescripcion
 */
void ImprimirUnTrabajo(eTrabajo miTrabajo, eServicio listaServicios[],  eBicicleta listaBicicletas[], int tamS,  int tamB, int maxDescripcion, int maxMarca);
/**
 * @fn void DarDeBajaTrabajo(eTrabajo[], eServicio[], eFecha[], int, int, int, int)
 * @brief muestra todos los trabajos con estadoTrabajo == OCUPADO y solicita el id del trabajo que se desea dar de baja, si el id se encuentra en el array listaTrabajos
 * se solicita confirmación, si se confirma se asigna BAJA a estadoTrabajo del elemento del array
 *
 * @param listaTrabajos
 * @param listaServicios
 * @param listaFechas
 * @param tamT
 * @param tamS
 * @param tamF
 * @param maxDescripcion
 */
void DarDeBajaTrabajo(eTrabajo listaTrabajos[], eServicio listaServicios[],  eBicicleta listaBicicletas[], int tamT, int tamS, int tamB, int maxDescripcion, int maxMarca);
/**
 * @fn void TotalEnPesosPorServicios(eTrabajo[], eServicio[], eFecha[], int, int, int, int)
 * @brief se muestra el total en $ por servicio en trabajos registrados
 *
 * @param listaTrabajos
 * @param listaServicios
 * @param listaFechas
 * @param tamT
 * @param tamS
 * @param tamF
 * @param maxDescripcion
 */
void TotalEnPesosPorServicios(eTrabajo listaTrabajos[], eServicio listaServicios[],  int tamT, int tamS, int maxDescripcion);
/**
 * @fn int ListarTrabajos(eTrabajo[], eServicio[], eFecha, int, int, int, int, int)
 * @brief ordena desde el año mas reciente (si tienen el mismo año, por marca) los trabajos cargados, asigna 1 a estado si hay datos para mostrar, -1 si no
 *
 * @param listaTrabajos
 * @param listaServicios
 * @param listaFechas
 * @param tamT
 * @param tamS
 * @param tamF
 * @param maxDescripcion
 * @param maxMarca
 * @return estado
 */

int ListarTrabajos(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], int tamT, int tamS, int tamB, int maxDescripcion, int maxMarca);
/**
 *
 */
int ServicioConMasTrabajosRealizados(eTrabajo listaTrabajos[],eServicio listaServicios[], int tamT, int tamS, int maxDescripcion);
/**
 *
 */
int TrabajosOrdenadosPorMarca(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], int tamS, int tamB, int tamT, int maxDescripcion, int maxMarca);
/**
 *
 */
int CantidadBicicletasColorRojoPorServicio(eTrabajo listaTrabajos[],eServicio listaServicios[],eBicicleta listaBicicletas[],int tamT,int tamS, int tamB, int maxDescripcion, int maxMarca);
/**
 *
 */
int ServiciosConDatosDeLasBicicletas(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], eCliente listaClientes[], int tamT, int tamS, int tamB, int tamC, int maxDescripcion, int maxMarca, int maxNombre, int maxApellido);
/**
 * @fn void ImprimirBicicletas(eBicicleta[], int)
 * @brief muestra todos los campos de cada eBicicleta en el array menos estadoBicicleta, mientras tengan el campo estadoBicicleta == OCUPADO
 *
 * @param listaBicicletas
 * @param tamB
 */
void ImprimirBicicletas(eBicicleta listaBicicletas[], eCliente listaClientes[], int tamB, int tamC);
/**
 * @fn void ImprimirUnBicicleta(eBicicleta)
 * @brief muestra todos los campos de un eBicicleta en el array menos estadoBicicleta
 *
 * @param miBicicleta
 */
void ImprimirUnaBicicleta(eBicicleta miBicicleta,eCliente listaClientes[], int tamC);
/**
 * @fn void HardcodeoDatosBicicletas(eBicicleta[], int, int)
 * @brief asigna valores especificos a cada campo de un numero determinado elementos de listaBicicletas
 *
 * @param listaBicicletas
 * @param tamB
 * @param minId
 */
void HardcodeoDatosBicicletas(eBicicleta listaBicicletas[], int tamB, int minId, int minIdC);
/**
 *
 */
int ListarTrabajosSegunCliente(eTrabajo listaTrabajos[],eServicio listaServicios[],eBicicleta listaBicicletas[],eCliente listaClientes[],int tamT,int tamS, int tamB, int tamC, int maxDescripcion, int maxMarca, int maxColor, int maxNombre, int maxApellido);

int TotalServiciosPorCliente(eTrabajo listaTrabajos[],eServicio listaServicios[],eBicicleta listaBicicletas[],eCliente listaClientes[],int tamT,int tamS, int tamB, int tamC, int maxDescripcion, int maxMarca, int maxColor, int maxNombre, int maxApellido);



#endif /* NEXO_H_ */
