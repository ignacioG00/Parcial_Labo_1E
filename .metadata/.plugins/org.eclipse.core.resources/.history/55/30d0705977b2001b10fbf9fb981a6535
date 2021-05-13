#define ORQUESTA_H_

#include "Biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EOrquesta_H_
#define EOrquesta_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define SINFONICA 1
#define FILARMONICA 2
#define CAMARA 3

typedef struct {
	int dia;
	int mes;
	int anio;
} eFecha;

//*** ESTRUCTURA
typedef struct {
	int idOrquesta;
	char nombre[MAX_CHARS_CADENAS];
	char lugar[MAX_CHARS_CADENAS];
	eFecha fecha;
	int tipo;
	int isEmpty;
} eOrquesta;
//***

/** INICIO CABECERAS DE FUNCION*/
void eOrquesta_Inicializar(eOrquesta array[], int TAM);
int eOrquesta_ObtenerID(void);
int eOrquesta_ObtenerIndexLibre(eOrquesta array[], int TAM);
int eOrquesta_BuscarPorID(eOrquesta array[], int TAM, int ID);
void eOrquesta_MostrarUno(eOrquesta Orquesta);
int eOrquesta_MostrarTodos(eOrquesta array[], int TAM);
int eOrquesta_MostrarDadosDeBaja(eOrquesta array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eOrquesta_Sort(eOrquesta array[], int TAM, int criterio);

//ABM
eOrquesta eOrquesta_CargarDatos(void);
eOrquesta eOrquesta_ModificarUno(eOrquesta Orquesta);
int eOrquesta_Alta(eOrquesta array[], int TAM);
int eOrquesta_Baja(eOrquesta array[], int TAM);
int eOrquesta_Modificacion(eOrquesta array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif
