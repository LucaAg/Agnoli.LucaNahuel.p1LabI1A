#include "marca.h"
#include "color.h"
#ifndef PRINCIPAL_H_
#define PRINCIPAL_H_

struct{
	int id;
	int idMarca;
	int idColor;
	char caja;
	int isEmpty;
}typedef eAut;

#endif /* PRINCIPAL_H_ */
/**
 * @fn int iniciarautos(eAut*, int)
 * @brief Inicicializa la autos en el indice i en 0.
 *
 * @param autos
 * @param tamAuto
 * @return
 */
int iniciarAutos(eAut* autos,int tamAuto);

/**
 * @fn int buscarautosLibre(eAut[], int)
 * @brief Busca en la autos un indice libre(isEmpty=1).
 *
 * @param autos
 * @param tamAuto
 * @return
 */
int buscarAutosLibre(eAut autos[],int tamAuto);

/**
 * @fn int altaBici(eAut[], int, int*, eMarca[], int, eColor[], int)
 * @brief Da de alta una PALABRAREEMPLAZAR en el indice libre.
 *
 * @param autos
 * @param tamAuto
 * @param id
 * @param marcas
 * @param tamMarca
 * @param colores
 * @param tamColor
 * @return
 */
int altaAuto(eAut autos[],int tamAuto,int* id,eMarca marcas[],int tamMarca,eColor colores[],int tamColor);

/**
 * @fn void mostrarAuto(eAut, eMarca[], int, eColor[], int)
 * @brief Muestra un auto junto a todos sus datos.
 *
 * @param unAuto
 * @param marcas
 * @param tamMarca
 * @param colores
 * @param tamColor
 */
void mostrarAuto(eAut unAuto,eMarca marcas[],int tamAuto,eColor colores[],int tamColor);


/**
 * @fn int imprimirPrincipal(eAut[], int, eMarca[], int, eColor[], int)
 * @brief Imprime todos los datos ingresados de la autos de PALABRAREEMPLAZAR.
 *
 * @param principal
 * @param tamAuto
 * @param marcas
 * @param tamMarca
 * @param colores
 * @param tamColor
 * @return
 */
int imprimirAutos(eAut autos[],int tamAuto,eMarca marcas[],int tamMarca,eColor colores[],int tamColor);

/**
 * @fn int encontrarBiciId(eAut[], int, int)
 * @brief Encuentra un id con el indice ocupado(isEmpty==0) de PALABRAREEMPLAZAR.
 *
 * @param principal
 * @param iD
 * @param tamAuto
 * @return
 */

int encontrarAutoId(eAut autos[],int iD,int tamAuto);

/**
 * @fn int modificarBicicleta(eAut[], int, eMarca[], int, eColor[], int)
 * @brief Permite modifica los datos de la autos de PALABRAREEMPLAZAR.
 *
 * @param principal
 * @param tamAuto
 * @param marcas
 * @param tamMarca
 * @param colores
 * @param tamColor
 * @return
 */
int modificarAuto(eAut autos[],int tamAutos,eMarca marcas[],int tamMarca,eColor colores[],int tamColor);


/**
 * @fn int removerBicicleta(eAut[], int, int, eMarca[], int, eColor[], int)
 * @brief Permite remover permanentemente los datos en el id indicado, de la autos de PALABRAREEMPLAZAR.
 *
 * @param principal
 * @param tamAuto
 * @param idAutos
 * @param marcas
 * @param tamMarca
 * @param colores
 * @param tamColor
 * @return
 */
int removerAuto(eAut autos[],int tamAuto, int idautos ,eMarca marcas[],int tamMarca,eColor colores[],int tamColor);

/**
 * @fn int validarPrincipalId(eAut[], int, int)
 * @brief Verifica que exista la PALABRAREEMPLAZAR en el id indicado.
 *
 * @param principal
 * @param tamAuto
 * @param idAutos
 * @return
 */
int validarautosId(eAut autos[],int tamAuto,int idAutos);


/**
 * @fn int permitirIngreso(autos[], int, int*)
 * @brief Recibe una bandera y la retorna por referencia.
 *
 * @param autos
 * @param tamAuto tamaño del vector
 * @param flag puntero a entero, retorna el valor por referencia.
 * @return todoOk(0) si hay error. todoOk(1) si no hay errores.
 */
int permitirIngreso(eAut autos[], int tamAuto,int* flag);

/**
 * @fn int ordenarAutosMarcaxPatente(eAut[], int, eMarca[], int, eColor[], int)
 * @brief Ordena los autos por marca, y en caso de ser iguales por patente.
 *
 * @param autos vector de autos, en la estructura autos.
 * @param tamAuto tamaño de la estructura de autos.
 * @param marca vector de la estructura eMarca.
 * @param tamMarca tamaño de la estructura eMarca.
 * @param colores vector de la estructura eColores.
 * @param tamColor tamaño del a estructura eColor.
 * @return todoOk(-1) si hay un error. todoOk(0) si no hay errores.
 */
int ordenarAutosMarcaxPatente(eAut autos[],int tamAuto,eMarca marca[],int tamMarca,eColor colores[],int tamColor);
