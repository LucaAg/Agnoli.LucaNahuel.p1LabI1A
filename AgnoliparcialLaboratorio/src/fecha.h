#ifndef FECHA_H_
#define FECHA_H_

struct
{
	int dia;
	int mes;
	int anio;
}typedef eFecha;

#endif /* FECHA_H_ */

/**
 * @fn int validarFecha(int, int, int)
 * @brief Recibe una fecha y valida que sea correcta(incluye los año bisiestos).
 *
 * @param dia entero que recibe el dia.
 * @param mes entero que recibe el mes.
 * @param anio entero que recibe el anio.
 * @return
 */
int validarFecha(int dia, int mes, int anio);
