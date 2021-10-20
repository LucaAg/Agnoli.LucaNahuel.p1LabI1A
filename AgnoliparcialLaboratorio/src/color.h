#ifndef COLOR_H_
#define COLOR_H_

struct{
	int id;
	char descripcionColor[20];
}typedef eColor;

#endif /* COLOR_H_ */

/**
 * @fn int cargarDescripcionColor(eColor[], int, int, char[])
 * @brief Carga los datos del array char descripcion, reemplazando el entero id, según el id ingresado por el usuario(el cual sea un id existente).
 *
 * @param colores
 * @param tamColor
 * @param idColor
 * @param descripcionColor
 * @return
 */
int cargarDescripcionColor(eColor colores[],int tamColor, int idColor, char descripcionColor[]);

/**
 * @fn int mostrarColores(eColor[], int)
 * @brief Muestra los datos de REEMPLAZARPALABRA.
 *
 * @param colores
 * @param tamColor
 * @return
 */
int mostrarColores(eColor colores[],int tamColor);
