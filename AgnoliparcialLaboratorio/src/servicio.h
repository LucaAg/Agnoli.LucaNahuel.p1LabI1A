#ifndef SERVICIOS_H_
#define SERVICIOS_H_

struct{
	int id;
	char descripcionServicio[20];
	int precio;
}typedef eServicio;

#endif /* SERVICIOS_H_ */
int cargarDescripcionServicio(eServicio servicio[],int tamServicio, int iServicio, char descripcionServicio[]);
int mostrarServicios(eServicio servicio[],int tamServicio);
