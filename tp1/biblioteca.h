#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

float sumaFlotantes (float, float);
float restaFlotantes (float, float);
float divisionFlotantes(float, float);
float multiplicaciondivisionFlotantes(float, float);
float factorialdivisionFlotante(float);
float PedirNumeroFlotante();



/**
 * @fn float PedirNumeroFlotante()
 * @brief solicita un número flotante por stdin
 *
 * @return numeroIngresado
 */

float PedirNumeroFlotante()
{
	float numeroIngresado;

	printf("Ingrese número: ");
	scanf("%f",&numeroIngresado);

	return numeroIngresado;

}

/**
 * @fn float sumaFlotantes(float, float)
 * @brief suma dos numeros flotantes dados
 *
 * @param primerNumero
 * @param segundoNumero
 * @return suma
 */

float sumaFlotantes (float primerNumero, float segundoNumero)
{
	float suma;

	suma = primerNumero + segundoNumero;

	return suma;
}

/**
 * @fn float restaFlotantes(float, float)
 * @brief resta dos numeros flotantes dados
 *
 * @param primerNumero
 * @param segundoNumero
 * @return resta
 */

float restaFlotantes (float primerNumero, float segundoNumero)
{
	float resta;

	resta = primerNumero - segundoNumero;

	return resta;
}

/**
 * @fn float divisionFlotantes(float, float)
 * @brief divide dos numeros flotantes dados si el divisor es distinto de 0, caso contrario
 * se informa mediante printf que no es posible dividir por 0 y se devuelve la variable division con valor-999999999
 *
 * @param primerNumero
 * @param segundoNumero
 * @return division
 */

float divisionFlotantes (float primerNumero, float segundoNumero)
{
	float division;

	if (segundoNumero == 0)
	{
		printf("No se puede dividir por 0!!!!");
		division = -999999999;
	}
	else
	{
		division = primerNumero / (float)segundoNumero;
	}

	return division;
}

/**
 * @fn float multiplicacionFlotantes(float, float)
 * @brief multiplica dos numeros flotantes dados
 *
 * @param primerNumero
 * @param segundoNumero
 * @return multiplicacion
 */

float multiplicacionFlotantes (float primerNumero, float segundoNumero)
{
	float multiplicacion;

	multiplicacion = primerNumero * segundoNumero;

	return multiplicacion;
}

/**
 * @fn float factorialFlotante(float)
 * @brief factorea un numero flotante dado que no sea decimal ni negativo
 *
 * @param numeroAFactorear
 * @return factorial
 */

float factorialFlotante (float numeroAFactorear)
{
	float factorial;
	float i;

	factorial = numeroAFactorear;

	if (numeroAFactorear > (int)numeroAFactorear || numeroAFactorear < 0)
	{
		factorial = -999999999;
	}
	else
	{
		for (i = numeroAFactorear -1; i > 1; i--)
		{
			factorial = factorial * i;
		}
	}

	return factorial;
}



