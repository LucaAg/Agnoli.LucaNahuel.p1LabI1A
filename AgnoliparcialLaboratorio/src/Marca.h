#ifndef SECTOR_H_
#define SECTOR_H_

typedef struct
{
	int id;
	char descripcionMarca[20];
}eMarca;

#endif  /* SECTOR_H_ */

/**
 * @fn int cargarDescripcionMarca(eMarca[], int, int, char[])
 * @brief Iguala un id existente(isEmpty=0), ingresado por el usuario, con un vector de char ,y muestra su nombre segun id.
 *
 * @param marcas
 * @param tamMarca
 * @param idMarca
 * @param descripcionMarca
 * @return
 */
int cargarDescripcionMarca(eMarca marcas[],int tamMarca, int idMarca, char descripcionMarca[]);


/**
 * @fn int mostrarMarcas(eTipo[], int)
 * @brief Muestra los datos de PALABRAREEMPLAZAR.
 *
 * @param tipos
 * @param tamMarca
 * @return
 */
int mostrarMarcas(eMarca marcas[],int tamMarca);

