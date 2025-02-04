/*
 * funcionesVivienda.c
 *
 *  Created on: 25 May 2022
 *      Author: Santiago
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn_get.h"
#include "funcionesVivienda.h"
#include "funcionesCensista.h"

int iniVivienda(vivienda* lista, int len)
{
	int retorno = -1;
	if (lista != NULL && len > 0) {
		retorno=0;
		for (int i = 0; i < len; i++) {
			(*(lista+i)).legajoCensista = 0;//Buscamos todos los subindices del array y cambiamos el campo isEmpty a 1 para indicar que esta vacio
		}
	}

	return retorno;
}

int buscarIndiceVacioV (vivienda* lista, int len)
{

	int retorno = -1;
	if (lista != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if ((*(lista+i)).legajoCensista == 0) {
				retorno = i;
				break; //esta funcion busca todos los espacios del array hasta encontrar un subindice vacio, cuando lo encuentra lo guarda como retorno y usamos break para parar de iterar
			}
		}
	}
	return retorno;

}

int cargarVivienda(vivienda* listaV, int lenV, censista* listaC, int lenC)
{
	int retorno = -1;
	char calleIngresada[25];
	int cantidadPersonasIngresada;
	int cantidadHabitacionesIngresada;
	int tipoViviendaIngresada;
	int legajoCensistaIngresado;
	int indiceVacio;
	int validacionIDCensista=-1;

	if (listaV != NULL && lenV > 0) {
		indiceVacio = buscarIndiceVacioV(listaV, lenV);//Llamamos a la funcion lookEmptyIndex para poder encontrar un subindice vacio
		if (indiceVacio != -1) {

			if((utn_getAlnumstr(calleIngresada, "Ingrese la calle", "\nCalle invalida\n")!=-1) &&
			(utn_getInt(&cantidadPersonasIngresada, "Ingrese la Cantidad de Personas", "\nCantidad Invalida\n",10,1,100)!=-1) &&
			(utn_getInt(&cantidadHabitacionesIngresada, "Ingrese cantidad de habitaciones", "\nPor favor ingrese un numero valido\n", 10, 1, 100)!=-1) &&
			(utn_getInt(&tipoViviendaIngresada, "Ingrese el tipo de vivienda\n1-Casa\n2-Departamento\n3-Casilla\n4-Rancho", "\nPor favor ingrese el tipo de vivienda\n", 4, 1, 100)!=-1)){

				strcpy((*(listaV+indiceVacio)).calle, calleIngresada);
				(*(listaV+indiceVacio)).cantidadPersonas=cantidadPersonasIngresada;
				(*(listaV+indiceVacio)).cantidadHabitaciones=cantidadHabitacionesIngresada;
				(*(listaV+indiceVacio)).idVivienda=2000+indiceVacio;


				while(validacionIDCensista==-1){

					mostrarCensistas(listaC, lenC);
					utn_getInt(&legajoCensistaIngresado,"\nIngrese el legajo del Censista a asignar","\nPor favor Ingrese un legajo valido", 999,100,100);
					validacionIDCensista=buscarCensistaPorID(listaC,lenC, legajoCensistaIngresado);
					if(validacionIDCensista==-1){
						printf("No se ha encontrado el legajo de censista ingresado, por favor ingrese de nuevo");
					}else{
						(*(listaV+indiceVacio)).legajoCensista=legajoCensistaIngresado;
						retorno = 0;
					}

				}


			}
		}

	}
	return retorno;

}

void mostrarVivienda(vivienda viviendaIngresada, int showHeader)
{
	char tipoVivienda[51];



	if (viviendaIngresada.legajoCensista != 0){

		  // usamos showHeader para saber si debemos mostrar un encabezado, o si este se mostrara a traves de la funcion printPassenger
		  if(showHeader==1){
				printf("\n+-----+--------------------+--------------------+---------+--------------+---------------+\n");
				printf("|%-5s|%-20s|%-20s|%-9s|%-14s|%-15s|\n","ID", "Calle", "Tipo de Vivienda", "Personas", "Habitaciones", "Legajo Censista");
				printf("+-----+--------------------+--------------------+---------+--------------+---------------+\n");

		  }

		  if(viviendaIngresada.tipoVivienda==1){
			  strcpy(tipoVivienda,"Casa");
		  }else if(viviendaIngresada.tipoVivienda==2){
			  strcpy(tipoVivienda,"Departamento");
		  }else if(viviendaIngresada.tipoVivienda==3){
			  strcpy(tipoVivienda,"Casilla");
		  }else{
			  strcpy(tipoVivienda,"Rancho");
		  }//usamos un if else if  para saber a que clase pertenece el pasajero ingresado y poder mostrarlo como una cadena de caracteres



		  //hacemos un printf de una sola linea
		  printf("|%-5d|%-20s|%-20s|%-9d|%-14d|%-15d|\n", viviendaIngresada.idVivienda, viviendaIngresada.calle, tipoVivienda,viviendaIngresada.cantidadPersonas ,viviendaIngresada.cantidadHabitaciones ,viviendaIngresada.legajoCensista);
		  printf("+-----+--------------------+--------------------+---------+--------------+---------------+\n");
	}
}

int mostrarViviendas(vivienda* lista, int length)
{
	int retorno = -1;
	if (lista != NULL && length > 0) {

		//La funcion muestra un encabezado por lo cual a show passenger le vamos a pasar un 0 para que no lo muestre en todas las iteraciones
		printf("\n+-----+--------------------+--------------------+---------+--------------+---------------+\n");
		printf("|%-5s|%-20s|%-20s|%-9s|%-14s|%-15s|\n","ID", "Calle", "Tipo de Vivienda", "Personas", "Habitaciones", "Legajo Censista");
		printf("+-----+--------------------+--------------------+---------+--------------+---------------+\n");

		for (int i = 0; i < length; i++) {

			if((*(lista+i)).legajoCensista!=0){

				mostrarVivienda((*(lista+i)),0); //utilizamos un for para buscar todos los espacion del array en donde isEmpty sea 0, y por cada uno que encuentra le pasamos los datos a showPassenger para que lo muestre
			}
		}

		retorno = 0;
	}
	return retorno;
}

int modificarVivienda(vivienda viviendaIngresada, vivienda *viviendaModificada, censista* listaC, int lenC)
{

	int retorno=-1;
	int opcion=0;
	int validacionIDCensista;


	if(viviendaModificada!=NULL){

		while(opcion!=6 && opcion!=7){

			printf("Ingrese que opcion desea modificar:" //utilizamos un menu de opciones para pedirle al usuario que ingrese el tipo de campo que desea cambiar
					"\n1-Calle"
					"\n2-Cantidad de Personas"
					"\n3-Cantidad de habitaciones"
					"\n4-Tipo de vivienda"
					"\n5-Censista"
					"\n6-Confirmar cambios"
					"\n7-Cancelar modificaciones");

			mostrarVivienda(viviendaIngresada,1); //mientras hacemos todos los cambios le mostramos al usuario los datos ingresados

			fflush(stdin);
			scanf("%d", &opcion);

			switch(opcion){

			case 1:


				utn_getAlnumstr(viviendaIngresada.calle, "Ingrese la calle", "\nCalle invalida\n");
				break;

			case 2:


				utn_getInt(&viviendaIngresada.cantidadPersonas, "Ingrese la Cantidad de Personas", "\nCantidad Invalida\n",10,1,100);
				break;

			case 3:


				utn_getInt(&viviendaIngresada.cantidadHabitaciones, "Ingrese la Cantidad de Personas", "\nCantidad Invalida\n",10,1,100);
				break;

			case 4:


				utn_getInt(&viviendaIngresada.tipoVivienda, "Ingrese el tipo de vivienda\n1-Casa\n2-Departamento\n3-Casilla\n4-Rancho", "\nPor favor ingrese el tipo de vivienda\n", 4, 1, 100);
				break;

			case 5:

				do{
					mostrarCensistas(listaC, lenC);
					utn_getInt(&viviendaIngresada.legajoCensista,"\nIngrese el legajo del Censista a asignar","\nPor favor Ingrese un legajo valido", 999,100,100);
					validacionIDCensista=buscarCensistaPorID(listaC,lenC, viviendaIngresada.legajoCensista);
					if(validacionIDCensista==-1){
						printf("No se ha encontrado el legajo de censista ingresado, por favor ingrese de nuevo");
					}
				}while(validacionIDCensista==-1);
				break;

			case 6:

				printf("\nFinalizando modificacion de la vivienda");
				*viviendaModificada=viviendaIngresada;
				break; //utillizamos la opcion 7 para confirmar los cambios y salir del programa

			case 7:

				printf("\nSe han cancelado los cambios");//utilizamos la opcion 8 para cancelar los cambios y salir del programa
				break;

			default:

				printf("\nPor favor ingrese una opcion valida");
				break;

			}

		}




	}


	return retorno;
}

int buscarViviendaPorID(vivienda* lista, int len,int id)
{
	int retorno = -1;
	if (lista != NULL && len > 0 && id > 0) {
		for (int i = 0; i < len; i++) {
			if ((lista+i)->idVivienda == id) {
				retorno = i;
				break;//esta funcion busca todos los espacios del array hasta encontrar un id igual al que le dimos, cuando lo encuentra lo guarda como retorno y usamos break para parar de iterar
			}
		}
	}
	return retorno;
}

int estaCargado(vivienda* lista, int len) //con esta funcion recorremos todas las posiciones del array hasta encontrar una en la que isEmpty sea igual a cero, es decir este cargada
{
	int retorno = -1;
	if (lista != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if((*(lista+i)).legajoCensista!=0) {
				retorno = 1;//en caso de encontrar una posicion en la cual isEmpty sea 0 retornamos 1
				return retorno;
			}
		}
		retorno=0;//en caso de no encontrar ninguna posicion cargada retornamos 0
	}

	return retorno;
}

int bajarVivienda(vivienda* lista, int len, int id)
{
	int retorno = -1;
	int index;
	int opcion=0;
	if (lista != NULL && len > 0 && id > 0) {
		index = buscarViviendaPorID(lista, len, id);
		if (index != -1) {

			while(opcion!=1 && opcion!=2){
				printf("�Seguro desea borrar la siguiente vivienda?\n");
				mostrarVivienda((*(lista+index)),1);
				printf( "\n1-Si"
						"\n2-no");
				scanf("%d", &opcion);//antes de borrar permanentemente al pasajero se l mostramos al usuario y le pedimos una confirmacion
				switch(opcion){

				case 1:
					(*(lista+index)).legajoCensista = 0;
					retorno = 1;
					printf("La vivienda ha sido borrada"); //en caso de ser si, cambiamos el campo is empty a 1
					break;

				case 2:
					printf("La vivienda no ha sido borrada");//en caso de ser no, no hacemos nada y terminamos la funcion
					break;

				default:
					printf("Por favor ingrese una opcion valida");
					break;


				}
			}

		}

	}

	return retorno;

}

int ordenarVivienda(vivienda* lista, int len)
{
	int retorno = -1;
	int i;
	vivienda aux;
	int isSorted;

	if (lista != NULL && len > 0){
			do {
				isSorted = 1;
				len--;
				for (i = 0; i < len; i++) {
					if ((*(lista+i)).cantidadPersonas > (*(lista+i+1)).cantidadPersonas){
						aux = *(lista+i);
						*(lista+i) = *(lista+i+1);
						*(lista+i+1) = aux;
						isSorted = 0;
					} else if ((*(lista+i)).cantidadPersonas == (*(lista+i+1)).cantidadPersonas && strcmp((*(lista+i)).calle, (*(lista+i)).calle)>0) {

						aux = *(lista+i);
						*(lista+i) = *(lista+i+1);
						*(lista+i+1) = aux;
						isSorted = 0;
					}
				}
			} while (isSorted == 0);

		retorno = 0;
	}

	return retorno;
}

int mostrarViviendasPorCensista(censista censistaIngresado,vivienda* listaV, int lenV, int* contadorCargado){

	int retorno = -1;
	int contadorV=0;
	if (censistaIngresado.legajoCensista != 0 && listaV != NULL){

		retorno=0;

		  // usamos showHeader para saber si debemos mostrar un encabezado, o si este se mostrara a traves de la funcion printPassenger

		printf("\n+-----+--------------------+----+---------+\n");
		printf("|%-5s|%-20s|%-4s|%-9s|\n","ID", "Nombre", "Edad", "Telefono");
		printf("+-----+--------------------+----+---------+\n");
		  //hacemos un printf de una sola linea
		printf("|%-5d|%-20s|%-4d|%-9d|\n", censistaIngresado.legajoCensista, censistaIngresado.nombre,censistaIngresado.edad ,censistaIngresado.telefono);
		printf("+-----+--------------------+----+---------+\n\n");

		printf("Las viviendas asignadas a este censista son:");

		if (listaV != NULL && lenV > 0 && censistaIngresado.legajoCensista > 0) {
			printf("\n+-----+--------------------+--------------------+---------+--------------+---------------+\n");
			printf("|%-5s|%-20s|%-20s|%-9s|%-14s|%-15s|\n","ID", "Calle", "Tipo de Vivienda", "Personas", "Habitaciones", "Legajo Censista");
			printf("+-----+--------------------+--------------------+---------+--------------+---------------+\n");

			for (int i = 0; i < lenV; i++) {
				if ((*(listaV+i)).legajoCensista == censistaIngresado.legajoCensista) {

					mostrarVivienda((*(listaV+i)),0);
					contadorV++;

				}
			}
		}

		*contadorCargado=contadorV;
	}
	return retorno;
}

int mostrarViviendasPorCensistas(censista* listaC, int lenC,vivienda* listaV, int lenV, int* indiceMayorVporC){


	int retorno = -1;
	int contadorAux;
	int contadorCargado;

	if (listaC != NULL && listaV != NULL && lenC > 0 && lenV>0) {

		for (int i = 0; i < lenC; i++) {

			if((*(listaC+i)).legajoCensista!=0){

				mostrarViviendasPorCensista((*(listaC+i)), listaV, lenV, &contadorCargado);

				if(contadorCargado>contadorAux){
					contadorAux=contadorCargado;
					*indiceMayorVporC=i;
				}
			}
		}

		retorno = 0;
	}
	return retorno;

}
