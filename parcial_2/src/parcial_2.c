/*
 ============================================================================
 Name        : parcial_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"

int main()
{
    setbuf(stdout,NULL);
    int option = 0;
    int flagOne=0;


    LinkedList* pLinkedList = ll_newLinkedList();
    while(option != 10){
		printf("\n1. Cargar archivo\n"
				"2. Imprimir lista\n"
				"3. Asignar totales\n"
				"4. Filtrar por tipo\n"
				"5. Mostrar servicios\n"
				"6. Guardar servicios\n"
				"7. Salir\n");
    	scanf("%d",&option);
        switch(option)
        {
            case 1:

            	controller_loadFromText(pLinkedList);
            	flagOne=1;
                break;
            case 2:
            	if (flagOne==1)
            	{
            		controller_ListeServicios(pLinkedList);
            	}else
            	{
            		printf("Cargue servicios desde el archivo primero por favor");
            	}
            	break;
            case 3:
            	if (flagOne==1)
            	{
            		controller_mapTotal(pLinkedList);
            	}else
            	{
            		printf("Cargue servicios desde el archivo primero por favor");
            	}
            	break;
            case 4:
            	if (flagOne==1)
            	{
            		controller_filtereServicio(pLinkedList);
            	}else
            	{
            		printf("Cargue servicios desde el archivo primero por favor");
            	}

            	break;
            case 5:
            	if (flagOne==1)
            	{
            		controller_sorteServicios(pLinkedList);
            	}else
            	{
            		printf("Cargue servicios desde el archivo primero por favor");
            	}

            	break;
            case 6:
            	if (flagOne==1)
            	{
            		controller_saveAsText(pLinkedList);
            	}else
            	{
            		printf("Cargue servicios desde el archivo primero por favor");
            	}

            	break;
            case 7:
            	printf("Finalizando Programa");
            	ll_deleteLinkedList(pLinkedList);
            	break;
        }
    }
    return 0;
}
