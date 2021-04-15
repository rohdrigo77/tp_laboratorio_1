#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"
#define EXIT_SUCCESS 0

int main()
{
	int opcion;
	float primerOperando;
	float segundoOperando;
	float sumaOperandos;
	float restaOperandos;
	float divisionOperandos;
	float multiplicacionOperandos;
	float factorialResultadoUno;
	float factorialResultadoDos;
	float sumaRealizada;
	float restaRealizada;
	float divisionRealizada;
	float multiplicacionRealizada;
	float factorialesRealizados;

	sumaRealizada = 0;
	restaRealizada = 0;
	divisionRealizada = 0;
	multiplicacionRealizada = 0;
	factorialesRealizados = 0;


	setbuf(stdout, NULL);

	do
	    {
			printf("Bienvenidx a la calculadora del peluca:\n\n");
	        printf("1. Ingresar 1er operando (A=x)\n");
	        printf("2. Ingresar 2do operando (B=y)\n");
	        printf("3. Calcular todas las operaciones\n");
	        printf("4. Informar resultados\n");
	        printf("10. Salir\n");
	        printf("Elija una opcion:\n");
	        scanf("%d", &opcion);

	        switch(opcion)
	        {
	            case 1:
	            	primerOperando = PedirNumeroFlotante();
	            	break;
	            case 2:
	            	segundoOperando = PedirNumeroFlotante();
	            	break;
	            case 3:
	            	printf("a) Calcular la suma (%f+%f)\n",primerOperando,segundoOperando);
					sumaOperandos = sumaFlotantes(primerOperando, segundoOperando);
					sumaRealizada = 1;
					printf("Suma calculada exitosamente.\n");

					printf("b) Calcular la resta (%f-%f)\n",primerOperando,segundoOperando);
					restaOperandos = restaFlotantes(primerOperando, segundoOperando);
					restaRealizada = 1;
					printf("Resta calculada exitosamente.\n");

					printf("c) Calcular la división (%f/%f)\n",primerOperando,segundoOperando);
					divisionOperandos = divisionFlotantes(primerOperando, segundoOperando);
					divisionRealizada = 1;
					printf("División calculada exitosamente.\n");

					printf("d) Calcular la multiplicación (%f*%f)\n",primerOperando,segundoOperando);
					multiplicacionOperandos = multiplicacionFlotantes(primerOperando, segundoOperando);
					multiplicacionRealizada = 1;
					printf("Multiplicación calculada exitosamente.\n");

					printf("e) Calcular el factorial (%f! y %f!)\n",primerOperando, segundoOperando);
					factorialResultadoUno = factorialFlotante(primerOperando);
					factorialResultadoDos = factorialFlotante(segundoOperando);
					factorialesRealizados = 1;
					printf("Factorial calculada exitosamente.\n");

	            	break;
	            case 4:
	            	//suma

					if (sumaRealizada == 1)
					{
						printf("El resultado de %f+%f es: %f\n",primerOperando, segundoOperando, sumaOperandos);
					}
					else
					{
						printf("No se realizó el cálculo. Volver al menú principal y elegir la opción de calcular la operación.\n");
					}

					//resta

					if (restaRealizada == 1)
					{
						printf("El resultado de %f-%f es: %f\n",primerOperando, segundoOperando, restaOperandos);
					}
					else
					{
						printf("No se realizó el cálculo. Volver al menú principal y elegir la opción de calcular la operación.\n");
					}

					//division

					if (divisionRealizada == 1)
					{
						printf("El resultado de %f/%f es: %f\n",primerOperando, segundoOperando, divisionOperandos);

					}
					else if (divisionOperandos == -999999999)
					{
						printf("No se puede dividir por 0!!!!");
					}
					else
					{
						printf("No se realizó el cálculo. Volver al menú principal y elegir la opción de calcular la operación.\n");
					}

					//multiplicacion

					if (multiplicacionRealizada == 1)
					{
						printf("El resultado de %f*%f es: %f\n",primerOperando, segundoOperando, multiplicacionOperandos);

					}
					else
					{
						printf("No se realizó el cálculo. Volver al menú principal y elegir la opción de calcular la operación.\n");
					}

					// factorial

					if (factorialesRealizados == 1)
					{
						if (factorialResultadoUno == -999999999)
						{
							printf("No se puede factorear decimales o negativos!!!");
						}
						else
						{
							printf("El factorial de %f es: %f", primerOperando, factorialResultadoUno);
						}

						if (factorialResultadoDos == -999999999)
						{
							printf("No se puede factorear decimales o negativos!!!\n");
						}
						else
						{
							printf("El factorial de %f es: %f\n", segundoOperando, factorialResultadoDos);
						}
					}
					else
					{
						printf("No se realizó el cálculo. Volver al menú principal y elegir la opción de calcular la operación.\n");
					}
					break;
	            default:
	            	break;
	        }

	    }while(opcion!=10);

	return EXIT_SUCCESS;
}

