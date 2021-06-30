#include "../inc/eVuelo.h"
#include "../inc/ePiloto.h"
#include "../inc/efecha.h"
#include "../inc/LinkedList.h"
#include "../inc/parser.h"
#include "../inc/bibliogenerica.h"
#include "../inc/informes.h"

/**
 * @fn int bogado_controller_loadFromText(char*, LinkedList*)
 * @brief llama al parser de texto para cargar los campos de los elementos de la lista en memoria, desde un archivo de texto
 *
 * @param path
 * @param pArrayListeVuelo
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int bogado_controller_loadVuelosFromText(char* path , LinkedList* pArrayListeVuelo);
/**
 *
 */
int bogado_controller_loadPilotosFromText(char* path , LinkedList* pArrayListeVuelo);
/**
 * @fn int bogado_controller_loadFromBinary(char*, LinkedList*)
 * @brief llama al parser de binario para cargar los campos de los elementos de la lista en memoria, desde un archivo binario
 *
 * @param path
 * @param pArrayListeVuelo
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int bogado_controller_loadFromBinary(char* path , LinkedList* pArrayListeVuelo);
/**
 * @fn int bogado_controller_addeVuelo(LinkedList*, int*)
 * @brief llama a diferentes funciones para agregar un empleado a la lista, poblando campos que solicita.
 *
 * @param pArrayListeVuelo
 * @param tempLastId
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int bogado_controller_addeVuelo(LinkedList* pArrayListeVuelo, int* tempLastId);
/**
 * @fn int bogado_controller_editeVuelo(LinkedList*)
 * @brief llama a diferentes funciones para editar los campos de un empleado a la lista, poblando campos que el usuario indique.
 *
 * @param pArrayListeVuelo
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int bogado_controller_editeVuelo(LinkedList* pArrayListeVuelo);
/**
 * @fn int bogado_controller_removeeVuelo(LinkedList*)
 * @brief llama a diferentes funciones para eliminar un empleado
 *
 * @param pArrayListeVuelo
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int bogado_controller_removeeVuelo(LinkedList* pArrayListeVuelo);
/**
 * @fn int bogado_controller_ListeVuelo(LinkedList*)
 * @brief muestra los campos de los elementos de la lista
 *
 * @param pArrayListeVuelo
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int bogado_controller_ListeVuelo(LinkedList* pArrayListeVuelo, LinkedList* pArrayListePiloto);
/**
 * @fn int bogado_controller_sorteVuelo(LinkedList*)
 * @brief llama a diferentes funciones para ordenar los elementos de la lista segun el criterio elegido por el usuario y el tipo de orden
 *
 * @param pArrayListeVuelo
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int bogado_controller_sorteVuelo(LinkedList* pArrayListeVuelo);
/**
 * @fn int bogado_controller_saveAsText(char*, LinkedList*)
 * @brief llama a diferentes funciones para guardar los elementos de la lista en memoria, a un archivo de texto
 *
 * @param path
 * @param pArrayListeVuelo
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int bogado_controller_saveAsText(char* path , LinkedList* pArrayListeVuelo);
/**
 *
 */
int bogado_controller_cantidadPasajeros(LinkedList* this);
/**
 *
 */
int bogado_controller_cantidadPasajerosChinos(LinkedList* this);
/**
 *
 */
int bogado_controller_vuelosLargos(LinkedList* this, LinkedList* pilotos);

int bogado_controller_vuelosAPortugal(LinkedList* this, LinkedList* pilotos);

int bogado_controller_listaSinLifesonYBach(LinkedList* this, LinkedList* pilotos);









