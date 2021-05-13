#define EMusico_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** DEFINE
#define MAX_CHARS_CADENAS 30

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** ESTRUCTURA
typedef struct {
	int idMusico;
	char nombre[MAX_CHARS_CADENAS];
	char apellido[MAX_CHARS_CADENAS];
	int edad;
	int idOrquesta;
	int idInstrumento;
	int isEmpty;
} eMusico;
//***

/** INICIO CABECERAS DE FUNCION*/
void eMusico_Inicializar(eMusico array[], int TAM);
int eMusico_ObtenerID(void);
int eMusico_ObtenerIndexLibre(eMusico array[], int TAM);
int eMusico_BuscarPorID(eMusico array[], int TAM, int ID);
void eMusico_MostrarUno(eMusico Musico);
int eMusico_MostrarTodos(eMusico array[], int TAM);
int eMusico_MostrarDadosDeBaja(eMusico array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eMusico_Sort(eMusico array[], int TAM, int criterio);

//ABM
eMusico eMusico_CargarDatos(void);
eMusico eMusico_ModificarUno(eMusico Musico);
int eMusico_Alta(eMusico array[], int TAM);
int eMusico_Baja(eMusico array[], int TAM);
int eMusico_Modificacion(eMusico array[], int TAM);
/** FIN CABECERAS DE FUNCION*/

