/*
 * utn_get.h
 *
 *  Created on: 9 May 2022
 *      Author: Santiago
 */

#ifndef UTN_GET_H_
#define UTN_GET_H_





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @brief Esta funcion pide numeros enteros
///
/// @param pNnumeroEntero Toma el retorno por puntero
/// @param mensaje Toma el mensaje
/// @param mensajeError Toma el mensaje de error
/// @param maximo Establece un numero maximo
/// @param minimo Establece un numero minimo
/// @param maximoDeReintentos Establece el maximo de reintentos
/// @return Retorno
int utn_getInt(int * pNnumeroEntero, char*  mensaje, char*  mensajeError, int maximo, int minimo, int maximoDeReintentos);

/// @brief Esta funcion pide numeros flotantes
///
/// @param pNnumeroFlotante Esta funcion pide numeros flotantes
/// @param mensaje Toma el mensaje
/// @param mensajeError Toma el mensaje de error
/// @param maximo Establece un numero maximo
/// @param minimo Establece un numero minimo
/// @param maximoDeReintentos Establece el maximo de reintentos
/// @return Retorno
int utn_getFloat(float * pNnumeroFlotante, char * mensaje, char * mensajeError, int maximo, int minimo, int maximoDeReintentos);

/**
 * @brief esta funcion pide cadenas alfanumericas
 * @param cadena
 * @param mensaje
 * @param mensajeError
 * @return
 */

int utn_getAlnumstr(char * cadena, char * mensaje, char * mensajeError);

/**
 * @brief esta funcion pide cadenas alfabeticas
 * @param cadena
 * @param mensaje
 * @param mensajeError
 * @return
 */

int utn_getAlphastr(char * cadena, char * mensaje, char * mensajeError);
#endif /* UTN_GET_H_ */
