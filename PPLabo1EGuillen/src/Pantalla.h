/*
 * Pantalla.h
 *
 *  Created on: 12 may. 2021
 *      Author: ignac
 */

#ifndef Pantalla_H_
#define Pantalla_H_
#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** DEFINE
#define MAX_CHARS_CADENAS 20
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define LCD 1
#define LED 2

//*** ESTRUCTURA
typedef struct{
	char calle[MAX_CHARS_CADENAS];
	int numero;
	char localidad[MAX_CHARS_CADENAS];
	char provincia[MAX_CHARS_CADENAS];
}eDomicilio;

typedef struct {
	int idPantalla;
	char nombre[MAX_CHARS_CADENAS];
	eDomicilio direccion;
	int tipoPantalla;
	float precio;
	int isEmpty;
} ePantalla;
//***

/** INICIO CABECERAS DE FUNCION*/
void ePantalla_Inicializar(ePantalla array[], int TAM);
int ePantalla_ObtenerID(void);
int ePantalla_ObtenerIndexLibre(ePantalla array[], int TAM);
int ePantalla_BuscarPorID(ePantalla array[], int TAM, int ID);
void ePantalla_MostrarUno(ePantalla Pantalla);
int ePantalla_MostrarTodos(ePantalla array[], int TAM);
int ePantalla_MostrarDadosDeBaja(ePantalla array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int ePantalla_Sort(ePantalla array[], int TAM, int criterio);

//ABM
ePantalla ePantalla_CargarDatos(void);//modificar
ePantalla ePantalla_ModificarUno(ePantalla Pantalla);//modificar
int ePantalla_Alta(ePantalla array[], int TAM);
int ePantalla_Baja(ePantalla array[], int TAM);
int ePantalla_Modificacion(ePantalla array[], int TAM);
/** FIN CABECERAS DE FUNCION*/

#endif /* Pantalla_H_ */