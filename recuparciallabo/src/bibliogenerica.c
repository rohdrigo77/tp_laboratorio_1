/*
 * bibliogenerica.c
 *
 *  Created on: May 4, 2021
 *      Author: rodrigo
 */

#include "../inc/bibliogenerica.h"

int PedirEntero(char mensajeInicial[], char mensajeError[])
{
	char entero[50];
	int estado;
	int idInt;


	printf("%s \n",mensajeInicial);
	fflush(stdin);
	scanf("%s",entero);
	estado = ValidarEntero(entero);

	while (estado == -1)
	{
		printf("%s. %s \n",mensajeError, mensajeInicial);
		fflush(stdin);
		scanf("%s",entero);
		estado = ValidarEntero(entero);
	}

	idInt = atoi(entero);


	return idInt;
}

float PedirFlotante(char mensajeInicial[], char mensajeError[])
{
	char flotante[50];
	int estado;
	int idFloat;

	do
	{
		printf("%s \n",mensajeInicial);
		fflush(stdin);
		scanf("%s",flotante);
		estado = ValidarFlotante(flotante);

		if (estado == -1)
		{
			printf("%s. %s \n",mensajeError, mensajeInicial);
		}
	}while (estado == -1);

	idFloat = atof(flotante);


	return idFloat;
}

void PedirCadena(char cadenaADevolver[], int maxCadena, char mensajeInicial[], char mensajeError[])
{
	char auxCadena[1000];
	int estadoTamano;


	do
	{
		printf("%s \n", mensajeInicial);
		fflush(stdin);
		scanf("%[^\n]",auxCadena);
		estadoTamano = ValidarTamanoCadena(auxCadena, maxCadena);

		if (estadoTamano == -1)
		{
			printf("%s. \n", mensajeError);
		}

	}while (estadoTamano == -1);

	strcpy(cadenaADevolver,auxCadena);

}

void PedirCadenaSoloLetras(char cadenaADevolver[], int maxCadena, char mensajeInicial[], char mensajeError[])
{
	char auxCadena[1000];
	int estadoTamano;
	int estadoLetras;


	do
	{
		printf("%s \n", mensajeInicial);
		fflush(stdin);
		scanf("%[^\n]",auxCadena);
		estadoTamano = ValidarTamanoCadena(auxCadena, maxCadena);
		estadoLetras = ValidarLetrasCadena(auxCadena);
		if (estadoTamano == -1 || estadoLetras != -1 )
		{
			printf("%s. \n", mensajeError);
		}

	}while (estadoTamano == -1 || estadoLetras != -1);

	strcpy(cadenaADevolver,auxCadena);

}

int ValidarLetrasCadena(char cadenaAValidar[])
{
	int i=0;
	int estado;

	estado = 1;

	while(cadenaAValidar[i] != '\0')
	{
		if((cadenaAValidar[i] != ' ') && (cadenaAValidar[i] < 'a' || cadenaAValidar[i] > 'z') && (cadenaAValidar[i] < 'A' || cadenaAValidar[i] > 'Z'))
		{
			i++;

		}
		else
		{
			estado = -1;
			break;
		}

	}

	return estado;
}



int ValidarEntero(char entero[])
{
	int i;
	int estado;

	estado = 1;

	for (i=0; i < strlen(entero); i++)
	{
		if (!(isdigit(entero[i])))
		{
			estado = -1;
			break;
		}

	}
	return estado;
}

int ValidarEnteroConRango(int entero, int min, int max)
{
	int estado;

	estado = -1;

	if (entero >= min && entero <= max)
	{
		estado = 1;
	}

	return estado;

}

int ValidarFlotante(char flotante[])
{
	int estado = 1;
	int esNegativo = 0;
	int contarSigno = 0;
	if(strlen(flotante) > 0)
	{
		for(int i = 0; i < strlen(flotante); i++)
		{
			if(flotante[0] == '-' && esNegativo == 0)
			{
				esNegativo = 1;
			}
			if(i > 0 || esNegativo == 1)
			{
				if(flotante[i] == '.' || flotante[i] == ',')
				{
					contarSigno++;

				}
				else
				{
					if(isdigit(flotante[i]) == 0)
					{
						estado = 1;
						break;
					}
				}
			}
		}
		if(contarSigno > 1)
		{
			estado = 1;
		}

	}
	else
	{
		estado = 1;
	}

	return estado;


}

int ValidarFlotanteConRangoMinimo(float flotante, float min)
{
	int estado;

	estado = -1;

	if (flotante >= min)
	{
		estado = 1;
	}

	return estado;
}

int ValidarTamanoCadena(char cadena[], int maxCadena)
{
	int estado;

	estado = 1;

	if (strlen(cadena) > maxCadena || strlen(cadena) == 0)
	{
		estado = -1;
	}


	return estado;
}

float CalcularPromedio(float precioTotal, int cantidadTotal)
{
	float promedio;

	promedio = precioTotal / cantidadTotal;

	return promedio;
}

int PedirConfirmacion(char mensajeInicial[], char mensajeError[])
{
	char respuesta;
	int estado;

	estado = -1;

	do
	{
		printf("%s \n",mensajeInicial);
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta = tolower(respuesta);

		if (respuesta != 's' && respuesta != 'n')
		{

			printf("%s \n",mensajeError);

		}
	}while (respuesta != 's' && respuesta != 'n');

	if(respuesta == 's')
	{
		estado = 1;

	}


	return estado;

}
