#include "trabajo.h"
#include "input.h"
#include "fecha.h"
#include "principal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXS_SERVICIO 25
#define MAXS 20

int iniciarTrabajos(eTrabajo* trabajos,int tamTrabajo)
{
	int todoOk=-1;
	if(trabajos!=NULL && tamTrabajo>0)
	{
		for(int i=0; i<tamTrabajo;i++)
		{
			trabajos[i].isEmpty=1;
		}
		todoOk=0;
	}
	return todoOk;
}

int buscarTrabajoLibre(eTrabajo* trabajos,int tamTrabajo)
{
	int libre=-1;
	if(trabajos!=NULL && tamTrabajo > 0)
	{
		for(int i=0;i<tamTrabajo;i++)
		{
			if(trabajos[i].isEmpty==1)
			{
				libre=i;
				break;
			}
		}
	}
	return libre;
}

int altaTrabajo(eTrabajo* trabajos,int tamTrabajo,int* id,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto)
{
	int indice;
	int todoOk=-1;
	eTrabajo auxTrabajo;

	if(trabajos!=NULL && tamTrabajo>0 && servicio!=NULL && tamServicio>0 && marca!=NULL && tamMarca>0 && colores!=NULL && tamColor>0 && autos!=NULL && tamAuto>0)
	{
		indice=buscarTrabajoLibre(trabajos,tamTrabajo);

		if(indice>=0)
		{
			system("cls");
			printf("*----------------------------------------------------------------------------*\n");
			printf("                            *** ALTA TRABAJO ***                           \n");
			printf("*---------------------------------------------------------------------------*\n");

			auxTrabajo.id=*id;
			(*id)++;
//PATENTE
			imprimirAutos(autos, tamAuto, marca, tamMarca, colores, tamColor);
			printf("Ingrese el ID del auto: \n");
			scanf("%d",&auxTrabajo.id);
			while(validarautosId(autos, tamAuto, auxTrabajo.id)==0)
			{
				printf("Error, reingrese el ID de la  bici: \n");
				scanf("%d",&auxTrabajo.id);
			}

//ID SERVICIO
			mostrarServicios(servicio, tamServicio);
			pedirEntero(&auxTrabajo.idServicio,"Ingrese el id del servicio(20000-20003): ","Error al ingresar el ID del servicio. Ingrese el tipo de bicicleta correspondiente(20000-20003): ",servicio[0].id,servicio[tamServicio-1].id);

//FECHA
			printf("Ingrese dia: \n");
			scanf("%d",&auxTrabajo.fecha.dia);
			printf("Ingrese mes: \n");
			scanf("%d",&auxTrabajo.fecha.mes);
			printf("Ingrese año: \n");
			scanf("%d",&auxTrabajo.fecha.anio);
			validarFecha(auxTrabajo.fecha.dia,auxTrabajo.fecha.mes,auxTrabajo.fecha.anio);

			auxTrabajo.isEmpty=0;

			trabajos[indice]=auxTrabajo;

			printf("\nAlta exitosa!!\n");
			printf(" ID |               AUTOS         |PATENTE|SERVICIO|PRECIO|FECHA     | \n");
			printf("----------------------------------------------------------------------\n");
			printf("    | ID |  MARCA   | COLOR  |CAJA|\n");
			printf("------------------------------------------------------------------------*\n");
			mostrarTrabajo(trabajos[indice], autos, tamAuto, marca, tamMarca,colores, tamColor, servicio, tamServicio);
		}
		else
		{
			printf("Hubo un error al iniciar el alta!\n");
		}
		todoOk=0;
	}
	return todoOk;
}

void mostrarTrabajo(eTrabajo unTrabajo,eAut autos[],int tamAuto,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eServicio servicio[],int tamServicio)
{
	char descServicio[MAXS_SERVICIO];
	char descMarca[MAXS];
	char descColor[MAXS];
	int indiceAuto;

	if(autos!=NULL && tamAuto>0 && marca!=NULL && tamMarca>0 && colores!=NULL && tamColor>0 && servicio!=NULL && tamServicio>0)
	{
		indiceAuto=encontrarAutoId(autos, unTrabajo.id, tamAuto);

		cargarDescripcionServicio(servicio, tamServicio, unTrabajo.idServicio, descServicio);
		cargarDescripcionMarca(marca, tamMarca, autos[indiceAuto].idMarca, descMarca);
		cargarDescripcionColor(colores, tamColor, autos[indiceAuto].idColor, descColor);

		printf("%-5d%-5d%-11s%-11s%-5c%-8.d%-9s%-7d%02d/%02d/%02d\n",
		unTrabajo.id,
		autos[indiceAuto].id,
		descMarca,
		descColor,
		autos[indiceAuto].caja,
		unTrabajo.patente,
		descServicio,
		servicio->precio,
		unTrabajo.fecha.dia,
		unTrabajo.fecha.mes,
		unTrabajo.fecha.anio);
	}

}

int imprimirTrabajos(eTrabajo trabajos[],int tamTrabajo,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto)
{
	int todoOk=0;
	int flag=1;
	if(autos!=NULL && tamAuto>0 && marca!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
	{
		system("cls");
		printf("\n");
		printf(" ID |               AUTOS         |PATENTE|SERVICIO|PRECIO|FECHA     | \n");
		printf("----------------------------------------------------------------------\n");
		printf("    | ID |  MARCA   | COLOR  |CAJA|\n");
		printf("------------------------------------------------------------------------*\n");
		for(int i=0;i<tamAuto;i++)
		{
			if(trabajos[i].isEmpty==0)
			{

				mostrarTrabajo(trabajos[i], autos, tamAuto, marca, tamMarca,colores, tamColor, servicio, tamServicio);
				flag=0;
			}
		}
		if(flag==1)
		{
			printf("No hay trabajos para mostrar\n");
		}
		todoOk=1;
	}
	return todoOk;
}

int permitirIngresoTrabajo(eTrabajo trabajo[], int tamTrabajo,int* flag)
{
	int todoOk;

	if(trabajo!=NULL && tamTrabajo>0)
	{
		for(int i=0;i<tamTrabajo;i++)
		{
			if(trabajo[i].isEmpty==0)
			{
				*flag=0;
				break;
			}
			else
			{
				*flag=1;
			}
		}
		todoOk=1;
	}
	return todoOk;
}
