/**
 * @fn int controller_loadFromText(char*, LinkedList*)
 * @brief llama al parser de texto para cargar los campos de los elementos de la lista en memoria, desde un archivo de texto
 *
 * @param path
 * @param pArrayListEmployee
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/**
 * @fn int controller_loadFromBinary(char*, LinkedList*)
 * @brief llama al parser de binario para cargar los campos de los elementos de la lista en memoria, desde un archivo binario
 *
 * @param path
 * @param pArrayListEmployee
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/**
 * @fn int controller_addEmployee(LinkedList*, int*)
 * @brief llama a diferentes funciones para agregar un empleado a la lista, poblando campos que solicita.
 *
 * @param pArrayListEmployee
 * @param tempLastId
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* tempLastId);
/**
 * @fn int controller_editEmployee(LinkedList*)
 * @brief llama a diferentes funciones para editar los campos de un empleado a la lista, poblando campos que el usuario indique.
 *
 * @param pArrayListEmployee
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/**
 * @fn int controller_removeEmployee(LinkedList*)
 * @brief llama a diferentes funciones para eliminar un empleado
 *
 * @param pArrayListEmployee
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/**
 * @fn int controller_ListEmployee(LinkedList*)
 * @brief muestra los campos de los elementos de la lista
 *
 * @param pArrayListEmployee
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/**
 * @fn int controller_sortEmployee(LinkedList*)
 * @brief llama a diferentes funciones para ordenar los elementos de la lista segun el criterio elegido por el usuario y el tipo de orden
 *
 * @param pArrayListEmployee
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/**
 * @fn int controller_saveAsText(char*, LinkedList*)
 * @brief llama a diferentes funciones para guardar los elementos de la lista en memoria, a un archivo de texto
 *
 * @param path
 * @param pArrayListEmployee
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/**
 * @fn int controller_saveAsBinary(char*, LinkedList*)
 * @brief
 *
 * @param path
 * @param pArrayListEmployee
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/**
 * @fn int getLastId(char[])
 * @brief
 *
 * @param path
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int getLastId(char path[]);
/**
 * @fn int setLastId(char[], int)
 * @brief
 *
 * @param path
 * @param lastId
 * @return estado (-1 si falla, 1 si se carga ok)
 */
int setLastId(char path[],int lastId);





