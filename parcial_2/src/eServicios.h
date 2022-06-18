/*
 * eServicios.h
 *
 *  Created on: 17 Jun 2022
 *      Author: Santiago
 */

#ifndef ESERVICIOS_H_
#define ESERVICIOS_H_
#include "LinkedList.h"


typedef struct
{
	int id;
	char descripcion[50];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;

}eServicio;


eServicio* eServicio_new();

int eServicio_setId(eServicio* this,int id);
int eServicio_getId(eServicio* this,int* id);

int eServicio_setDescripcion(eServicio* this,char* descripcion);
int eServicio_getDescripcion(eServicio* this,char* descripcion);

int eServicio_setTipo(eServicio* this,int tipo);
int eServicio_getTipo(eServicio* this,int* tipo);

int eServicio_setPrecioUnitario(eServicio* this,float precioUnitario);
int eServicio_getPrecioUnitario(eServicio* this,float* precioUnitario);

int eServicio_setCantidad(eServicio* this,int cantidad);
int eServicio_getCantidad(eServicio* this,int* cantidad);

int eServicio_setTotalServicio(eServicio* this,float totalServicio);
int eServicio_getTotalServicio(eServicio* this,float* totalServicio);

int intTypeToChar(int tipoInt,char* tipoChar);

int eServicio_showServicio(eServicio* this, int showHeader);
int eServicio_showServicioList(LinkedList* this);

int eServicio_mapTotal(void* this);
int eServicio_filterMinorista(void* this);
int eServicio_filterMayorista(void* this);
int eServicio_filterExportar(void* this);
int eServicio_sortDescripcion(void* pElementOne, void* pElementTwo);

#endif /* ESERVICIOS_H_ */
