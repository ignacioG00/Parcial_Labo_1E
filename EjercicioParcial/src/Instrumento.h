#define EInstrumento_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** DEFINE
#define MAX_CHARS_CADENAS 30

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define CUERDAS 1
#define VIENTO_MADERA 2
#define VIENTO_METAL 3
#define PERCUSION 4

//*** ESTRUCTURA
typedef struct {
	int idInstrumento;
	char nombre[MAX_CHARS_CADENAS];
	int tipo;
	int isEmpty;
} eInstrumento;
//***

/** INICIO CABECERAS DE FUNCION*/
void eInstrumento_Inicializar(eInstrumento array[], int TAM);
int eInstrumento_ObtenerID(void);
int eInstrumento_ObtenerIndexLibre(eInstrumento array[], int TAM);
int eInstrumento_BuscarPorID(eInstrumento array[], int TAM, int ID);
void eInstrumento_MostrarUno(eInstrumento Instrumento);
int eInstrumento_MostrarTodos(eInstrumento array[], int TAM);
int eInstrumento_MostrarDadosDeBaja(eInstrumento array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eInstrumento_Sort(eInstrumento array[], int TAM, int criterio);

//ABM
eInstrumento eInstrumento_CargarDatos(void);
eInstrumento eInstrumento_ModificarUno(eInstrumento Instrumento);
int eInstrumento_Alta(eInstrumento array[], int TAM);
int eInstrumento_Baja(eInstrumento array[], int TAM);
int eInstrumento_Modificacion(eInstrumento array[], int TAM);
/** FIN CABECERAS DE FUNCION*/

