#include "input.h"
#include "principal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validarString(char frase[],int tam)
{
	int flag;
	int esString;
	int i=0;
	if(frase!=NULL)
	{
		flag=0;

		while(i<strlen(frase))
		{
			esString=isalpha(frase[i]);
			if(esString!=0 || frase[i]==' ')
			{
				i++;
			}
			else
			{
				flag=1;
				printf("Error, no puede ingresar numeros, ni simbolos. \nPor favor vuelva a ingresarlo: \n");
				fflush(stdin);
				gets(frase);
				i=0;
			}
			rangoString(frase,tam);
		}
		if(!validarStringOrdenado(frase))
		{
			flag=1;
		}
	}
	return flag;
}

int rangoString(char frase[],int tam)
{
	int todoOk=0;
	if(frase!= NULL && tam>0)
	{
		while(strlen(frase) > tam)
		{
			printf("Error, lo que usted ingreso supera el maximo de caracteres (%d)."
					"\nPor favor, reingreselo: \n",tam);
			fflush(stdin);
			gets(frase);
		}
		todoOk=1;
	}
	return todoOk;
}

int validarStringOrdenado(char frase[])
{
	int todoOk=0;
	int i=0;
	if(frase!=NULL)
	{
		strlwr(frase);
		frase[0]=toupper(frase[0]);
		while(frase[i]!='\0')
		{
			if(frase[i]==' ')
			{
				frase[i+1]=toupper(frase[i+1]);
			}
			i++;
		}

		todoOk=1;
	}
	return todoOk;
}


int validarNumeros(char numeroIngresado[])
{
	int i=0;
	int flagValidar;
	if(numeroIngresado!=NULL)
	{
		flagValidar=1;
		while(numeroIngresado[i]!='\0')
		{
			if(numeroIngresado[i]<'0' || numeroIngresado[i]>'9')
			{
				flagValidar=0;
			}
			i++;
		}
	}
	return flagValidar;
}

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	int numeroIngresado;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);

		while(!scanf("%d", &numeroIngresado))
		{
			printf("Error, no puede ingresar letras en este campo. Vuelva a ingresarlo: ");
			fflush(stdin);
		}

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);

			while(!scanf("%d", &numeroIngresado))
			{
				printf("Error, no puede ingresar letras en este campo. Vuelva a ingresarlo: ");
				fflush(stdin);
			}
		}
		*entero = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}

int pedirFlotante(float* numero, char mensaje[], char mensajeError[], float min, float max)
{
    int todoOk=0;
    float numeroIngresado;

	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL && min<max)
	{
		printf("%s", mensaje);
		fflush(stdin);

		while(!scanf("%f", &numeroIngresado) )
		{
			printf("No puede ingresar valores no decimales.Vuelva a ingresarlo: \n");
			fflush(stdin);
		}

		while(numeroIngresado<min || numeroIngresado>max)
		{
			printf("%s",mensajeError);
			fflush(stdin);

			while(!scanf("%f", &numeroIngresado) )
			{
				printf("No puede ingresar valores no decimales.Vuelva a ingresarlo: \n");
				fflush(stdin);
			}
		}

		*numero=numeroIngresado;
		todoOk=1;
	}

	return todoOk;
}

int menu()
{
	char opcion;

	system("cls");
	printf("\n");
	printf("---------------------------------------------------------\n");
	printf("               ***  TALLER LO DE ANTONIO ***                \n");
	printf("----------------------------------------------------------\n");
	printf("     A-ALTA AUTO\n");
	printf("     B-MODIFICAR AUTO\n");
	printf("     C-BAJA AUTO\n");
	printf("     D-LISTAR AUTOS\n");
	printf("     E-LISTAR  MARCAS\n");
	printf("     F-LISTAR COLORES\n");
	printf("     G-LISTAR SERVICIOS\n");
	printf("     H-ALTA TRABAJO\n");
	printf("     I-LISTAR TRABAJOS\n");
	printf("     J-Salir\n");

	printf("Ingrese opcion: \n");
	fflush(stdin);
	scanf("%c",&opcion);
	opcion=toupper(opcion);
	return opcion;
}

int menuModificar()
{
	char opcion;
	system("cls");
	printf("--------------------------------------------------------\n");
	printf("              *** MODIFICAR AUTO  ***                 \n");
	printf("---------------------------------------------------------\n");
	printf("A     -MODIFICAR COLOR \n");
	printf("B     -MODIFICAR MODELO \n");
	printf("C     -Salir\n");

	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%c",&opcion);
	opcion=toupper(opcion);

	return opcion;
}

int pedirCaracter(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2)
{
	int todoOk=-1;
	char caracterIngresado;

	if(caracter!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c",&caracterIngresado);
		caracterIngresado=tolower(caracterIngresado);

		while(caracterIngresado!= caracterVal1 && caracterIngresado!=caracterVal2)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%c",&caracterIngresado);
			caracterIngresado=tolower(caracterIngresado);
		}
		*caracter=caracterIngresado;
		todoOk=0;
	}
	return todoOk;
}

int validarAutoId(eAut autos[],int tamAuto,int idAuto)
{
	int todoOk=0;
	if(autos!=NULL && tamAuto>0)
	{
		for(int i=0;i<tamAuto;i++)
		{
			if(autos[i].id==idAuto)
			{
				todoOk=1;
			}
		}
	}
	return todoOk;
}
