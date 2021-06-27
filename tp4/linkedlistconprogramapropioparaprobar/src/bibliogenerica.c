/*
 * bibliogenerica.c
 *
 *  Created on: May 4, 2021
 *      Author: rodrigo
 */

#include "../inc/bibliogenerica.h"

int PedirEntero(int* entero, char mensajeInicial[], char mensajeError[])
{
	int estado;
	char auxEntero[128];

	estado = -1;

	if (entero != NULL)
	{

		printf("%s \n",mensajeInicial);
		__fpurge(stdin);
		scanf("%s",auxEntero);
		estado = ValidarEntero(auxEntero);

		while (estado == -1)
		{
			printf("%s. %s \n",mensajeError, mensajeInicial);
			__fpurge(stdin);
			scanf("%s",auxEntero);
			estado = ValidarEntero(auxEntero);
		}

		*entero = atoi(auxEntero);
	}

	return estado;
}

int PedirFlotante(float* flotante, char mensajeInicial[], char mensajeError[])
{
	int estado;
	char auxFlotante[1000];

	do
	{
		printf("%s \n",mensajeInicial);
		__fpurge(stdin);
		scanf("%s",auxFlotante);
		estado = ValidarFlotante(auxFlotante);

		if (estado == -1)
		{
			printf("%s. %s \n",mensajeError, mensajeInicial);
		}
	}while (estado == -1);

	*flotante = atof(auxFlotante);


	return estado;
}

void PedirCadena(char* cadenaADevolver[], int maxCadena, char mensajeInicial[], char mensajeError[])
{
	char auxCadena[1000];
	int estadoTamano;

	if (cadenaADevolver != NULL)
	{
		do
		{
			printf("%s \n", mensajeInicial);
			__fpurge(stdin);
			scanf("%[^\n]",auxCadena);
			estadoTamano = ValidarTamanoCadena(auxCadena, maxCadena);

			if (estadoTamano == -1)
			{
				printf("%s. \n", mensajeError);
			}

		}while (estadoTamano == -1);

		strcpy(*cadenaADevolver,auxCadena);
	}

}

void PedirCadenaSoloLetras(char* cadenaADevolver[], int maxCadena, char mensajeInicial[], char mensajeError[])
{
	char auxCadena[1000];
	int estadoTamano;
	int estadoLetras;

	if (cadenaADevolver != NULL)
	{
		do
		{
			printf("%s \n", mensajeInicial);
			__fpurge(stdin);
			scanf("%[^\n]",auxCadena);
			estadoTamano = ValidarTamanoCadena(auxCadena, maxCadena);
			estadoLetras = ValidarLetrasCadena(auxCadena);

			if (estadoTamano != 1 || estadoLetras != 1 )
			{
				printf("%s. \n", mensajeError);
			}

		}while (estadoTamano != 1 || estadoLetras != 1);

		strcpy(*cadenaADevolver,auxCadena);
	}

}

void PedirNombresOApellidos(char* cadenaADevolver, int maxCadena, char mensajeInicial[], char mensajeError[])
{
	int i;
	char auxCadena[1000];
	int estadoTamano;
	int estadoLetras;

	if (cadenaADevolver != NULL)
	{
		do
		{
			printf("%s \n", mensajeInicial);
			__fpurge(stdin);
			scanf("%[^\n]",auxCadena);
			__fpurge(stdin);
			estadoTamano = ValidarTamanoCadena(auxCadena, maxCadena);
			estadoLetras = ValidarLetrasCadena(auxCadena);

			if (estadoTamano != 1 || estadoLetras != 1 )
			{
				printf("%s. \n", mensajeError);
			}

		}while (estadoTamano != 1 || estadoLetras != 1);

		for (i=0;i<maxCadena;i++)
		{
			if (!(isspace(auxCadena[i])))
			{
				auxCadena[i] = tolower(auxCadena[i]);
			}
		}

		for (i = 0; i < maxCadena ;i++)
		{
			if (isspace(auxCadena[i]))
			{
				auxCadena[i + 1] = toupper(auxCadena[i + 1]);
			}
		}

		auxCadena[0] = toupper(auxCadena[0]);

		strcpy(cadenaADevolver,auxCadena);
	}


}

int ValidarLetrasCadena(char cadenaAValidar[])
{
	int i;
	int estado;

	estado = 1;



		for(i=0;i<strlen(cadenaAValidar);i++)
		{
			if ( !( ( cadenaAValidar[i] >= 'a' && cadenaAValidar[i] <= 'z' ) || ( cadenaAValidar[i] >= 'A' && cadenaAValidar[i] <= 'Z' ) || cadenaAValidar[i] == ' ' ) )
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

int ValidarEnteroConRangoMinimo(int entero, int min)
{
	int estado;

	estado = -1;

	if (entero >= min)
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

int CalcularPromedio(float* promedio, float* precioTotal, int* cantidadTotal)
{
	int estado;

	estado = -1;

	if (promedio != NULL && precioTotal != NULL && cantidadTotal != NULL)
	{
		*promedio = *precioTotal / *cantidadTotal;
	}

	return estado;
}

int PedirConfirmacion(char mensajeInicial[], char mensajeError[])
{
	char respuesta;
	int estado;

	estado = -1;

	do
	{
		printf("%s \n",mensajeInicial);
		__fpurge(stdin);
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






