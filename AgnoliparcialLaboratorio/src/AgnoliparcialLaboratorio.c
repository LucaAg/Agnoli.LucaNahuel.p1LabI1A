/*
 ============================================================================
 Name        : parcialLaboratorio1.c
 Author      : Agnoli, Luca Nahuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "principal.h"
#include "servicio.h"
#include "trabajo.h"

#define TAM_AUTO 5
#define TAM_COLOR 5
#define TAM_MARCA 5
#define TAM_SERVICIO 4
#define TAM_TRABAJO 4

int main(void)
{
	setbuf(stdout,NULL);

	char seguir='s';
	int flagEntro=1;
	int flagTrabajo=1;
	eAut autos[TAM_AUTO];
	eAut auxAuto;
	eTrabajo auxTrabajo[TAM_TRABAJO];
	int nextId=1;
	int nextIdTrabajo=1;
	eColor colores[TAM_COLOR]={
	    		{5000,"NEGRO"},
	    		{5001,"BLANCO"},
	    		{5002,"ROJO"},
	    		{5003,"GRIS"},
				{5004,"AZUL"},
	    	};

	eMarca marcas[TAM_MARCA]= {
	    		{1000,"RENAULT"},
	    		{1001,"FORD"},
	    		{1002,"FIAT"},
	    		{1003,"CHEVROLET"},
				{1004,"PEUGEOT"},
	    	};
	eServicio servicios[TAM_SERVICIO]={
    		{20000,"LAVADO",450},
    		{20001,"PULIDO",500},
    		{20002,"ENCERADO",600},
    		{20003,"COMPLETO",900},
    	};

	iniciarAutos(autos,TAM_AUTO);

	iniciarTrabajos(auxTrabajo, TAM_TRABAJO);


	do
	{
		system("cls");
		switch(menu())
		{
			case 'A':
				altaAuto(autos, TAM_AUTO, &nextId, marcas, TAM_MARCA, colores, TAM_COLOR);
				flagEntro=0;
				break;
			case 'B':
				if(flagEntro==0)
				{
					modificarAuto(autos, TAM_AUTO, marcas, TAM_MARCA, colores, TAM_COLOR);
				}
				else
				{
					printf("No se puede ingresar a esta opción, sin antes ingresar por la opción A\n");
				}
				break;
			case 'C':
				if(flagEntro==0)
				{
					removerAuto(autos, TAM_AUTO, auxAuto.id, marcas, TAM_MARCA, colores, TAM_COLOR);
				}
				else
				{
					printf("No se puede ingresar a esta opción, sin antes ingresar la opcion A\n");
				}
				permitirIngreso(autos, TAM_AUTO, &flagEntro);
				permitirIngresoTrabajo(auxTrabajo, TAM_TRABAJO, &flagTrabajo);
				break;
			case 'D':
				if(flagEntro==0)
				{
					ordenarAutosMarcaxPatente(autos, TAM_AUTO, marcas, TAM_MARCA, colores, TAM_COLOR);
				}
				else
				{
					printf("No se puede ingresar a esta opción, sin antes ingresar la opcion A\n");
				}
				break;
			case 'E':
				mostrarMarcas(marcas, TAM_MARCA);
				break;
			case 'F':
				mostrarColores(colores, TAM_COLOR);
				break;
			case 'G':
				mostrarServicios(servicios, TAM_SERVICIO);
				break;
			case 'H':
				if(flagEntro==0)
				{
					altaTrabajo(auxTrabajo, TAM_TRABAJO, &nextIdTrabajo, servicios, TAM_SERVICIO, marcas, TAM_MARCA, colores, TAM_COLOR, autos, TAM_AUTO);
					flagTrabajo=0;
				}
				else
				{
					printf("No hay trabajos disponibles. Para listar un trabajo primero debe dar de alta a minimo 1 auto.\nGracias por su atención\n");
				}
				break;
			case 'I':
				if(flagTrabajo==0)
				{
					imprimirTrabajos(auxTrabajo, TAM_TRABAJO, servicios, TAM_SERVICIO, marcas, TAM_MARCA, colores, TAM_COLOR, autos, TAM_AUTO);
				}
				else
				{
					printf("No hay trabajos disponibles para mostrar, primero debe dar de alta un trabajo\n");
				}
				break;
			case 'J':
				pedirCaracter(&seguir, "Desea cotinuuar en este menu?(s/n)", "Error, opción incorrecta(s/n)", 's', 'n');
				break;

			default:
				printf("Error, opción invalida!");
				fflush(stdin);
				break;
		}
		system("pause"); //YO NO LO UTILIZO PORQUE ECLIPSE NO LO RECONOCE.
	}while(seguir=='s');



	return EXIT_SUCCESS;
}


