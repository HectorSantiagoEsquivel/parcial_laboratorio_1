#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "eServicios.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */



int parser_eServiciosFromText(FILE* pFile , LinkedList* pArrayListseServicios)
{


	char idStr[51];
	char descripcionStr[51];
	char tipoStr[51];
	char precioUnitarioStr[51];
	char cantidadStr[51];
	char totalServicioStr[51];

	eServicio* pServicio;
	if(pFile!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,], %[^,],%[^\n]\n",idStr,descripcionStr,tipoStr,precioUnitarioStr,cantidadStr,totalServicioStr);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,], %[^,],%[^\n]\n",idStr,descripcionStr,tipoStr,precioUnitarioStr,cantidadStr,totalServicioStr)==6)
			{

				pServicio=eServicio_new();

				eServicio_setId(pServicio,atoi(idStr));
				eServicio_setDescripcion(pServicio,descripcionStr);
				eServicio_setTipo(pServicio,atoi(tipoStr));
				eServicio_setPrecioUnitario(pServicio,atof(precioUnitarioStr));
				eServicio_setCantidad(pServicio, atoi(cantidadStr));
				eServicio_setTotalServicio(pServicio,atof(totalServicioStr));

			    if (ll_add(pArrayListseServicios, pServicio)==0){
			    	printf("Se cargaron bien todos los datos\n");
			    }

			}else
			{
				break;
			}

		}while(feof(pFile)==0);


	}

    return 1;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int parser_TextFromeServicio(FILE* pFile , LinkedList* pArrayListseServicios)
{

	int id;
	char descripcionStr[51];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;

	eServicio* pServicio;
	if(pFile!=NULL)
	{
		fprintf(pFile, "%s,%s,%s,%s, %s,%s\n","id_servicio","descripcion","tipo","precioUnitario","cantidad","totalServicio");

		for(int i=0;i<ll_len(pArrayListseServicios);i++)
		{
			pServicio=ll_get(pArrayListseServicios,i);

			eServicio_getId(pServicio,&id);
			eServicio_getDescripcion(pServicio,descripcionStr);
			eServicio_getTipo(pServicio,&tipo);
			eServicio_getPrecioUnitario(pServicio,&precioUnitario);
			eServicio_getCantidad(pServicio, &cantidad);
			eServicio_getTotalServicio(pServicio,&totalServicio);

			fprintf(pFile, "%d,%s,%d,%.2f,%d,%.2f\n",id,descripcionStr,tipo, precioUnitario,cantidad,totalServicio);
		}


	}

    return 1;
}



