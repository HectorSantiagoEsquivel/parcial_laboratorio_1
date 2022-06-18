/*
 * eServicios.c
 *
 *  Created on: 17 Jun 2022
 *      Author: Santiago
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn_get.h"
#include "eServicios.h"
#include "LinkedList.h"

eServicio* eServicio_new()
{
	eServicio* peServicio=NULL;

	peServicio=(eServicio*)malloc(sizeof(eServicio));
	return peServicio;
}

void eServicio_delete()
{

}

int eServicio_setId(eServicio* this,int id)
{
	int retorno=-1;

	if(this!=NULL&&id>=0)
	{

		this->id=id;
		retorno=0;

	}

	return retorno;
}
int eServicio_getId(eServicio* this,int* id)
{
	int retorno=-1;

	if(this!=NULL&&id!=NULL)
	{

		*id=this->id;
		retorno=0;

	}

	return retorno;

}

int eServicio_setDescripcion(eServicio* this,char* descripcion)
{
	int retorno=-1;

	if(this!=NULL&&descripcion!=NULL)
	{
		if(esAlfastr(descripcion)==1)
		{
			strcpy(this->descripcion,descripcion);
			retorno=0;
		}
	}

	return retorno;

}
int eServicio_getDescripcion(eServicio* this,char* descripcion)
{
	int retorno=-1;

	if(this!=NULL&&descripcion!=NULL)
	{

		strcpy(descripcion,this->descripcion);
		retorno=0;

	}

	return retorno;
}

int eServicio_setTipo(eServicio* this,int tipo)
{
	int retorno=-1;

	if(this!=NULL&&(tipo>0 || tipo<=3))
	{

		this->tipo=tipo;
		retorno=0;

	}

	return retorno;


}
int eServicio_getTipo(eServicio* this,int* tipo)
{
	int retorno=-1;

	if(this!=NULL&&tipo!=NULL)
	{

		*tipo=this->tipo;
		retorno=0;

	}

	return retorno;

}

int eServicio_setPrecioUnitario(eServicio* this,float precioUnitario)
{
	int retorno=-1;

	if(this!=NULL&&precioUnitario>=0)
	{

		this->precioUnitario=precioUnitario;
		retorno=0;

	}

	return retorno;

}
int eServicio_getPrecioUnitario(eServicio* this,float* precioUnitario)
{
	int retorno=-1;

	if(this!=NULL&&precioUnitario!=NULL)
	{

		*precioUnitario=this->precioUnitario;
		retorno=0;

	}

	return retorno;
}

int eServicio_setCantidad(eServicio* this,int cantidad)
{
	int retorno=-1;

	if(this!=NULL&&(cantidad>0 || cantidad<=3))
	{

		this->cantidad=cantidad;
		retorno=0;

	}

	return retorno;

}
int eServicio_getCantidad(eServicio* this,int* cantidad)
{
	int retorno=-1;

	if(this!=NULL&&cantidad!=NULL)
	{

		*cantidad=this->cantidad;
		retorno=0;

	}

	return retorno;

}

int eServicio_setTotalServicio(eServicio* this,float totalServicio)
{
	int retorno=-1;

	if(this!=NULL&&totalServicio>=0)
	{

		this->totalServicio=totalServicio;
		retorno=0;

	}

	return retorno;

}
int eServicio_getTotalServicio(eServicio* this,float* totalServicio)
{
	int retorno=-1;

	if(this!=NULL&&totalServicio!=NULL)
	{

		*totalServicio=this->totalServicio;
		retorno=0;

	}

	return retorno;

}

int intTypeToChar(int tipoInt,char* tipoChar)
{
	int retorno=-1;

	if(tipoChar!=NULL)
	{
		  if(tipoInt==1){
			  strcpy(tipoChar,"Minorista");
		  }else if(tipoInt==2){
			  strcpy(tipoChar,"Mayorista");
		  }else{
			  strcpy(tipoChar,"Exportar");
		  }
	}
	return retorno;

}


int eServicio_showServicio(eServicio* this, int showHeader)
{
	int retorno=-1;
	char tipoServicioStr[51];


	if (this != NULL){

		  // usamos showHeader para saber si debemos mostrar un encabezado, o si este se mostrara a traves de la funcion printPassenger
		  if(showHeader==1){
				printf("+-----+-------------------------+--------------------+---------------+----------+---------------+\n");
				printf("|%-5s|%-25s|%-20s|%-15s|%-10s|%-15s|\n","ID", "Descripcion", "Tipo", "Precio Unitario", "Cantidad", "Precio Total");
				printf("+-----+-------------------------+--------------------+---------------+----------+---------------+\n");

		  }
		  retorno=0;
		  intTypeToChar(this->tipo,tipoServicioStr);


		  //hacemos un printf de una sola linea
		  printf("|%-5d|%-25s|%-20s|%-15.2f|%-10d|%-15.2f|\n", this->id, this->descripcion,tipoServicioStr,this->precioUnitario,this->cantidad,this->totalServicio);
		  printf("+-----+-------------------------+--------------------+---------------+----------+---------------+\n");

	}
	return retorno;

}
int eServicio_showServicioList(LinkedList* this)
{
	int retorno = -1;

	eServicio* pServicio;
	if (this != NULL)
	{

		//La funcion muestra un encabezado por lo cual a show passenger le vamos a pasar un 0 para que no lo muestre en todas las iteraciones
		printf("+-----+-------------------------+--------------------+---------------+----------+---------------+\n");
		printf("|%-5s|%-25s|%-20s|%-15s|%-10s|%-15s|\n","ID", "Descripcion", "Tipo", "Precio Unitario", "Cantidad", "Precio Total");
		printf("+-----+-------------------------+--------------------+---------------+----------+---------------+\n");

		for (int i = 0; i < ll_len(this); i++) {

			pServicio=ll_get(this,i);

			if(pServicio!=NULL){

				eServicio_showServicio(pServicio,0);
			}
		}

		retorno = 0;
	}
	return retorno;

}

int eServicio_mapTotal(void* this)
{
	int cantidad;
	float precio;
	int returnAux=-1;
	if(this!=NULL)
	{
		eServicio_getPrecioUnitario(this,&precio);
		eServicio_getCantidad(this,&cantidad);
		eServicio_setTotalServicio(this,cantidad*precio);
		returnAux=0;

	}
	return returnAux;
}

int eServicio_filterMinorista(void* this)
{
	int tipo;
	int returnAux=-1;
	if(this!=NULL)
	{
		eServicio_getTipo(this,&tipo);

		returnAux=0;
		if(tipo==1)
		{
			returnAux=1;
		}


	}
	return returnAux;
}

int eServicio_filterMayorista(void* this)
{

	int tipo;
	int returnAux=-1;
	if(this!=NULL)
	{
		eServicio_getTipo(this,&tipo);
		returnAux=0;
		if(tipo==2)
		{
			returnAux=1;
		}



	}
	return returnAux;
}

int eServicio_filterExportar(void* this)
{
	int tipo;
	int returnAux=-1;
	if(this!=NULL)
	{
		eServicio_getTipo(this,&tipo);
		returnAux=0;
		if(tipo==3)
		{
			returnAux=1;
		}



	}
	return returnAux;
}

int eServicio_sortDescripcion(void* pElementOne, void* pElementTwo)
{
	int retorno = 0;
	char descripcionOneStr[51];
	char descripcionTwoStr[51];

	if (pElementOne != NULL &&pElementTwo != NULL)
	{

		if(eServicio_getDescripcion(pElementOne, descripcionOneStr)==0 &&eServicio_getDescripcion(pElementTwo, descripcionTwoStr)==0)
		{

			if(strcmp(descripcionOneStr,descripcionTwoStr)>0)
			{
				retorno=1;
			}else if(strcmp(descripcionOneStr,descripcionTwoStr)<0)
			{
				retorno=-1;
			}
		}
	}

	return retorno;

}
