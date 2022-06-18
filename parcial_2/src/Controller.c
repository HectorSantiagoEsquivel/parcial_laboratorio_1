#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn_get.h"
#include "Controller.h"
#include "eServicios.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* this)
{
	int retorno=-1;
	char path[51];
	FILE* pFile;
	if(this!=NULL)
	{
		utn_getAlnumstr(path,"Ingrese la direccion del archivo que desea cargar", "Por favor ingrese una direcccion valida");
		pFile = fopen(path,"r");
		if(pFile!=NULL)
		{
			parser_eServiciosFromText(pFile , this);

			retorno=1;
			fclose(pFile);
		}else
		{
			printf("Error al abrir el archivo");
		}
	}

    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListeServicios(LinkedList* this)
{
	if(this!=NULL)
	{
		eServicio_showServicioList(this);
	}
    return 1;
}

int controller_filtereServicio(LinkedList* this)
{
	int retorno=-1;
	int option;
	LinkedList* pLinkedList=ll_newLinkedList();



	if(this!=NULL&&pLinkedList!=NULL)
	{
		retorno=0;
		printf("\n1-Mostrar Minoristas\n"
				"2-Mostrar Mayoristas \n"
				"3-Mostrar Exportar\n"
				"4-Cancelar\n"); //Informo al usuario las opciones disponibles

		printf("Ingrese el numero de opcion");
		scanf("%d", &option);
		switch(option){

		case 1:

			printf("Ordenando...\n");
			pLinkedList=ll_filter(this,eServicio_filterMinorista);
			controller_ListeServicios(pLinkedList);
			break;

		case 2:

			printf("Ordenando...\n");
			pLinkedList=ll_filter(this,eServicio_filterMayorista);
			eServicio_showServicioList(pLinkedList);
			break;

		case 3:
			printf("Ordenando...\n");
			pLinkedList=ll_filter(this,eServicio_filterExportar);
			eServicio_showServicioList(pLinkedList);
			break;

		case 4:
			printf("Cancelando");
			break;


		}
	}


    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sorteServicios(LinkedList* this)
{
	int retorno=-1;
	int order=1;

	if(this!=NULL)
	{
		retorno=0;
		printf("Ordenando Servicios...\n");
		ll_sort(this,eServicio_sortDescripcion,order);
		controller_ListeServicios(this);
	}
    return retorno;
}

int controller_mapTotal(LinkedList* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=0;
		printf("Cargando Totales...\n");
		ll_map(this,eServicio_mapTotal);
		controller_ListeServicios(this);
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(LinkedList* this)
{
	int retorno=-1;
	FILE* pFile;
	char path[51];
	if(this!=NULL)
	{
		utn_getAlnumstr(path,"Ingrese la direccion donde desea guardar el archivo", "Por favor ingrese una direcccion valida");
		pFile = fopen(path,"w");
		if(pFile!=NULL)
		{
			parser_TextFromeServicio(pFile ,this);
			printf("Se cargo todo bien!");
			retorno=1;
			fclose(pFile);
		}else
		{
			printf("Error al abrir el archivo");
		}
	}

    return retorno;
}

