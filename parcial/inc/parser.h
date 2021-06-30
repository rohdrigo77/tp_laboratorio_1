/**
 * @fn int parser_EmployeeFromText(FILE*, LinkedList*)
 * @brief se recibe una lista que se carga con los elementos del archivo recibido
 *
 * @param pArchivo
 * @param pArrayListEmployee
 * @return estado (-1 si es menor, 1 si es mayor, 0 si es igual)
 */
int parser_eVueloFromText(FILE* pArchivo , LinkedList* pArrayListEmployee);
/**
 * @fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
 * @brief se recibe una lista que se carga con los elementos del archivo recibido
 *
 * @param pArchivo
 * @param pArrayListEmployee
 * @return estado (-1 si es menor, 1 si es mayor, 0 si es igual)
 */
int parser_eVueloFromBinary(FILE* pArchivo , LinkedList* pArrayListEmployee);
/**
 *
 */
int parser_ePilotoFromText(FILE* pArchivo , LinkedList* pArrayListEmployee);
/**
 *
 */
int parser_ePilotoFromBinary(FILE* pArchivo , LinkedList* pArrayListEmployee);
