/*
 * utn_get.c
 *
 *  Created on: 9 May 2022
 *      Author: Santiago
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_get.h"

static int esNumerica(char * cadena);
static int getInt(int * pNnumeroEntero);
static int myGets(char * cadena, int longitud);
static int getFloat(float * pNumeroFlotante);
static int esAlfastr(char * cadena);
static int getAlphastr(char* cadenaAlpha);
static int esAlnumstr(char * cadena);
static int getAlnumstr(char* cadenaAlnum);


int utn_getInt(int * pNnumeroEntero, char * mensaje, char * mensajeError, int maximo, int minimo, int maximoDeReintentos){ //agregamos la "p" al comienzo para recordar que es un puntero

	int auxNumeroEntero;
	int retorno;
	retorno = -1; // damos por sentado que está todo mal y va a fallar

	if(pNnumeroEntero != NULL && mensaje != NULL && mensajeError != NULL && maximo >= minimo && maximoDeReintentos >= 0) // hacemos esto para asegurarnos de que la dirección sea válida y no nula, y después validamos los parámetros. Esto se hace siempre que tengamos uno o más punteros
	{
		do{
			printf("%s", mensaje);
			getInt(&auxNumeroEntero);
			maximoDeReintentos --;
			if(auxNumeroEntero >= minimo && auxNumeroEntero <= maximo)
			{
				*pNnumeroEntero = auxNumeroEntero; // asignamos el valor guardado en la variable al contenido de la direccion de memoria
				retorno = 0; // como salimos del while, el retorno pasa a estar todo ok y lo ponemos en 0
				break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno; // retornamos el retorno
}

int utn_getFloat(float * pNnumeroFlotante, char * mensaje, char * mensajeError, int maximo, int minimo, int maximoDeReintentos){ //agregamos la "p" al comienzo para recordar que es un puntero

	float auxNumeroFlotante;
	int retorno;
	retorno = -1; // damos por sentado que está todo mal y va a fallar

	if(pNnumeroFlotante != NULL && mensaje != NULL && mensajeError != NULL && maximo >= minimo && maximoDeReintentos >= 0) // hacemos esto para asegurarnos de que la dirección sea válida y no nula, y después validamos los parámetros. Esto se hace siempre que tengamos uno o más punteros
	{
		do{
			printf("%s", mensaje);
			getFloat(&auxNumeroFlotante);
			maximoDeReintentos --;
			if(auxNumeroFlotante >= minimo && auxNumeroFlotante <= maximo)
			{
				*pNnumeroFlotante = auxNumeroFlotante; // asignamos el valor guardado en la variable al contenido de la direccion de memoria
				retorno = 0; // como salimos del while, el retorno pasa a estar todo ok y lo ponemos en 0
				break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno; // retornamos el retorno
}

int utn_getAlphastr(char * cadena, char * mensaje, char * mensajeError){

	int validacion;
	int retorno;
	retorno = -1; // damos por sentado que está todo mal y va a fallar

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL) // hacemos esto para asegurarnos de que la dirección sea válida y no nula. Esto se hace siempre que tengamos uno o más punteros
	{
			retorno=0;
			printf("%s", mensaje);
			validacion=getAlphastr(cadena);

			while(validacion==-1){
				printf("%s", mensajeError);
				validacion=getAlphastr(cadena);
			}
	}

	return retorno; // retornamos el retorno
}

int utn_getAlnumstr(char * cadena, char * mensaje, char * mensajeError){

	int validacion;
	int retorno;
	retorno = -1; // damos por sentado que está todo mal y va a fallar

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL) // hacemos esto para asegurarnos de que la dirección sea válida y no nula. Esto se hace siempre que tengamos uno o más punteros
	{
			retorno=0;
			printf("%s", mensaje);
			validacion=getAlnumstr(cadena);

			while(validacion==-1){
				printf("%s", mensajeError);
				validacion=getAlnumstr(cadena);
			}
	}

	return retorno; // retornamos el retorno
}

static int myGets(char * cadena, int longitud){
	int retorno = 0;
	fflush(stdin);
	fgets(cadena, longitud, stdin);
	cadena[strlen(cadena) -1] = '\0';

	return retorno;
}

static int getInt(int * pNnumeroEntero){
	int retorno = -1;
	char auxCadena[4096];

	if(myGets(auxCadena, sizeof(auxCadena)) == 0 && esNumerica(auxCadena))
	{
		retorno = 0;
		*pNnumeroEntero = atoi(auxCadena);
	}

	return retorno;
}



static int getFloat(float * pNumeroFlotante){
	int retorno = -1;
	char auxCadena[4096];

	if(myGets(auxCadena, sizeof(auxCadena)) == 0 && esNumerica(auxCadena) )
	{
		retorno = 0;
		*pNumeroFlotante = atof(auxCadena);
	}

	return retorno;
}

static int getAlphastr(char* cadenaAlpha){
	int retorno = -1;
	char auxCadena[51];



	if(myGets(auxCadena, sizeof(auxCadena))== 0 && esAlfastr(auxCadena)){
		retorno=0;

		strcpy(cadenaAlpha,auxCadena);

	}

	return retorno;
}

static int getAlnumstr(char* cadenaAlnum){
	int retorno = -1;
	char auxCadena[51];



	if(myGets(auxCadena, sizeof(auxCadena))== 0 && esAlnumstr(auxCadena)){
		retorno=0;

		strcpy(cadenaAlnum,auxCadena);


	}

	return retorno;
}

static int esAlfastr(char * cadena){

	int retorno = 1;
	int i = 0;



	for( ; cadena[i] != '\0'; i++)
	{
		if(cadena[i]=='-' || cadena[i]==' '){

			continue;

		}else if(isalpha(cadena[i])==0)
		{
			retorno = 0;
			break;
		}
	}
	return retorno;

}

static int esAlnumstr(char * cadena){

	int retorno = 1;
	int i = 0;



	for( ; cadena[i] != '\0'; i++)
	{
		if(cadena[i]=='-' || cadena[i]==' '){

			continue;

		}else if(isalnum(cadena[i])==0)
		{
			retorno = 0;
			break;
		}
	}
	return retorno;

}

static int esNumerica(char * cadena){
	int retorno = 1;
	int i = 0;

	if(cadena[0] == '-')
	{
		i = 1;
	}

	for( ; cadena[i] != '\0'; i++)
	{
		if(cadena[i]=='.'){

			continue;

		}else if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}

