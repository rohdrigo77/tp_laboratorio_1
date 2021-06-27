/*
 * bibliogenerica.h
 *
 *  Created on: May 4, 2021
 *      Author: rodrigo
 */

#ifndef BIBLIOGENERICA_H_
#define BIBLIOGENERICA_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#define OCUPADO 1
#define VACIO 0
#define BAJA -1
#define MAX_DESCRIPCION 51

/**
 * @fn int PedirEntero(int*, char[], char[])
 * @brief se solicita un entero, se lo valida, y si pasa la validación se modifica el puntero recibido y retorna el estado
 *
 * @param entero
 * @param mensajeInicial
 * @param mensajeError
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int PedirEntero(int* entero, char mensajeInicial[], char mensajeError[]);
/***
 * @fn int PedirFlotante(float*, char[], char[])
 * @brief se solicita un flotante, se lo valida, y si pasa la validación se modifica el puntero recibido y retorna el estado
 *
 * @param flotante
 * @param mensajeInicial
 * @param mensajeError
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int PedirFlotante(float *flotante, char mensajeInicial[], char mensajeError[]);
/**
 * @fn int ValidarEntero(char[])
 * @brief se valida si el caracter ingresado es un entero, se asigna -1 a estado si no lo es, 1 si lo es.
 *
 * @param entero
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int ValidarEntero(char entero[]);
/**
 * @fn int ValidarEnteroConRango(int, int, int)
 * @brief se valida si entero esta dentro del min y el max, se asigna -1 a estado si no lo es, 1 si lo es.
 *
 * @param entero
 * @param min
 * @param max
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int ValidarEnteroConRango(int entero, int min, int max);
/**
 * @fn int ValidarEnteroConRangoMinimo(int, int)
 * @brief se valida si entero es igual o mayor al min, se asigna -1 a estado si no lo es, 1 si lo es.
 *
 * @param entero
 * @param min
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int ValidarEnteroConRangoMinimo(int entero, int min);
/**
 * @fn int ValidarFlotante(char[])
 * @brief se valida si el caracter ingresado es un flotante, se asigna -1 a estado si no lo es, 1 si lo es.
 *
 * @param flotante
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int ValidarFlotante(char flotante[]);
/**
 * @fn int ValidarFlotanteConRangoMinimo(float, float)
 * @brief se valida si flotante es igual o mayor al min, se asigna -1 a estado si no lo es, 1 si lo es.
 *
 * @param flotante
 * @param min
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int ValidarFlotanteConRangoMinimo(float flotante, float min);
/**
 * @fn void PedirCadena(char[], int, char[], char[])
 * @brief se solicita una cadena, se valida si la cadena ingresada excede en tamaño al destino, y se copia el contenido de la cadena a *cadenaADevolver
 *
 * @param cadenaADevolver
 * @param maxCadena
 * @param mensajeInicial
 * @param mensajeError
 */
void PedirCadena(char* cadenaADevolver[], int maxCadena, char mensajeInicial[], char mensajeError[]);
/**
 * @fn void PedirCadenaSoloLetras(char[], int, char[], char[])
 * @brief pide una cadena de solo letras y espacios, y si se valida correctamente, se guarda el contenido en *cadenaADevolver
 *
 * @param cadenaADevolver
 * @param maxCadena
 * @param mensajeInicial
 * @param mensajeError
 */
void PedirCadenaSoloLetras(char* cadenaADevolver[], int maxCadena, char mensajeInicial[], char mensajeError[]);
/**
 *
 * @fn void PedirNombresOApellidos(char[], int, char[], char[])
 * @brief pide una cadena de solo letras y espacios, la pasa a minuscula y luego pone mayusculas en el primer elemento del array, y los posteriores a un espacio
 * y luego se guarda en *cadenaADevolver
 * @param cadenaADevolver
 * @param maxCadena
 * @param mensajeInicial
 * @param mensajeError
 */
void PedirNombresOApellidos(char* cadenaADevolver, int maxCadena, char mensajeInicial[], char mensajeError[]);
/**
 * @fn int ValidarLetrasCadena(char[])
 * @brief se valida si la cadena contiene solo letras y espacios
 *
 * @param cadenaAValidar
 * @return estado (-1 si falla, 1 si se valida ok)
 */
int ValidarLetrasCadena(char cadenaAValidar[]);
/**
 * @fn int ValidarTamanoCadena(char[], int)
 * @brief se valida si la cadena ingresada excede en tamaño al destino, se asigna  -1 a estado si lo hace, 1 si no.
 *
 * @param cadena
 * @param maxCadena
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int ValidarTamanoCadena(char cadena[], int maxCadena);
/**
 * @fn int CalcularPromedio(float*, float*, int*)
 * @brief se calcula el promedio de una acumulacion, dividiendola por un contador, y se almacena en *promedio
 *
 * @param promedio
 * @param precioTotal
 * @param cantidadTotal
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int CalcularPromedio(float* promedio, float* precioTotal, int* cantidadTotal);
/**
 * @fn int PedirConfirmacion(char[], char[])
 * @brief se pide ingresar 's' o 'n' para confirmar algo segun los mensajes dados como parametro
 *
 * @param mensajeInicial
 * @param mensajeError
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int PedirConfirmacion(char mensajeInicial[], char mensajeError[]);







#endif /* BIBLIOGENERICA_H_ */

