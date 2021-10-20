#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validarFecha(int dia, int mes, int anio)
{
	int todoOk=0;
	if(dia>0 && mes>0 && anio>0)
	{

		while(anio <= 1999 || anio >= 2023)
		{
			printf("Anio incorrecto(2000-2022). Reingrese el anio : \n");
			scanf("%d",&anio);
		}

		while(mes < 1 || mes > 12)
		{
			printf("Error, mes invalido(1-12).\n Reingrese el mes deseado: ");
			scanf("%d",&mes);
		}
		switch(mes)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12: while(dia<1 || dia>31)
					{
						printf("Error dia ingresado no valido(1-31). Reingreselo: \n");
						scanf("%d",&dia);
					}
					break;
			case 4:
			case 6:
			case 9:
			case 11: while(dia<1 || dia>30)
					{
						printf("Error dia ingresado no valido(1-30). Reingreselo: \n");
						scanf("%d",&dia);
					}
					break;

			case 2: if( (anio % 4 ==0) && (anio % 100!= 0 || anio % 400 ==0) )
					{
						while(dia < 1 || dia > 29)
						{
							printf("Error dia ingresado no valido(1-29). Reingreselo: \n");
							scanf("%d",&dia);
						}
					}
					else
					{
						while(dia < 1 || dia > 28)
						{
							printf("Error dia ingresado no valido(1-28). Reingreselo: \n");
							scanf("%d",&dia);
						}
					}
					break;
		}

		printf("La fecha ingresada fue: %02d/%02d/%02d",dia,mes,anio);
		todoOk=1;
	}else
	{
		printf("Fecha no valida!\n");
	}


	return todoOk;
}
