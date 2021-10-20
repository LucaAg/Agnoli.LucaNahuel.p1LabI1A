#include "fecha.h"
#include "servicio.h"
#include "principal.h"
#ifndef TRABAJO_H_
#define TRABAJO_H_

struct{
	int id;
	int patente;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}typedef eTrabajo;

#endif /* TRABAJO_H_ */


/**
 * @fn void mostrarTrabajo(eTrabajo, eAut[], int, eMarca[], int, eColor[], int, eServicio[], int)
 * @brief Muestra los datos de los trabajos recibidos.
 *
 * @param unTrabajo de la estructura trabajo.
 * @param autos vector de la estructura eAut.
 * @param tamAuto tamaño de la estructura eAut.
 * @param marca vector de la estrucutra marca.
 * @param tamMarca tamaño de la estructura eMarca.
 * @param colores vector de la estructura eColor.
 * @param tamColor tamaño de la estructura eColor.
 * @param servicio vector de la estructura eServicio.
 * @param tamServicio tamaño de la estructura eServicio.
 */
void mostrarTrabajo(eTrabajo unTrabajo,eAut autos[],int tamAuto,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eServicio servicio[],int tamServicio);

/**
 * @fn int iniciarTrabajos(eTrabajo*, int)
 * @brief inicializa todos los campos isEmpty en 1.
 *
 * @param trabajos
 * @param tamTrabajo
 * @return
 */
int iniciarTrabajos(eTrabajo* trabajos,int tamTrabajo);

/**
 * @fn int buscarTrabajoLibre(eTrabajo*, int)
 * @brief compara los campos isEmpty, y si es igual a 1 retorna el indice libre.
 *
 * @param trabajos
 * @param tamTrabajo
 * @return
 */
int buscarTrabajoLibre(eTrabajo* trabajos,int tamTrabajo);

/**
 * @fn int altaTrabajo(eTrabajo*, int, int*, eServicio[], int, eMarca[], int, eColor[], int, eAut[], int)
 * @brief Pide los datos al usuario e incorpora los datos al listado de trabajos.
 *
 * @param trabajos
 * @param tamTrabajo
 * @param id
 * @param servicio
 * @param tamServicio
 * @param marca
 * @param tamMarca
 * @param colores
 * @param tamColor
 * @param autos
 * @param tamAuto
 * @return
 */
int altaTrabajo(eTrabajo* trabajos,int tamTrabajo,int* id,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto);

/**´
 * @fn void mostrarTrabajo(eTrabajo, eAut[], int, eMarca[], int, eColor[], int, eServicio[], int)
 * @brief Muestra los datos recibidos de alta trabajo.
 *
 * @param unTrabajo
 * @param autos
 * @param tamAuto
 * @param marca
 * @param tamMarca
 * @param colores
 * @param tamColor
 * @param servicio
 * @param tamServicio
 */
void mostrarTrabajo(eTrabajo unTrabajo,eAut autos[],int tamAuto,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eServicio servicio[],int tamServicio);

/**
 * @fn int imprimirTrabajos(eTrabajo[], int, eServicio[], int, eMarca[], int, eColor[], int, eAut[], int)
 * @brief Muestra todos los datos recibididos en alta trabajo.
 *
 * @param trabajos
 * @param tamTrabajo
 * @param servicio
 * @param tamServicio
 * @param marca
 * @param tamMarca
 * @param colores
 * @param tamColor
 * @param autos
 * @param tamAuto
 * @return
 */
int imprimirTrabajos(eTrabajo trabajos[],int tamTrabajo,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto);


/**
 * @fn int permitirIngresoTrabajo(eTrabajo[], int, int*)
 * @brief No permite ingresar a las ultimas opciones del menu, sin antes haber ingresado un auto.
 *
 * @param trabajo
 * @param tamTrabajo
 * @param flag
 * @return
 */
int permitirIngresoTrabajo(eTrabajo trabajo[], int tamTrabajo,int* flag);
