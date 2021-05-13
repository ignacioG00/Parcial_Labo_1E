/*
 ============================================================================
 Name        : PP.c
 Author      : Ignacio Guillen
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Entidades.h"
#include "Biblioteca.h"
#define TAM_ESTRUCTURA 5

int main(void) {
	setbuf(stdout, NULL);

	int opc;
	int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	ePantalla Pantalla[TAM_ESTRUCTURA];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	ePantalla_Inicializar(Pantalla, TAM_ESTRUCTURA);

	//BUCLE DE MENU
	do {
		//MENU PRINT
		menu();
		printf("INGRESE OPCION: ");
		scanf("%d", &opc);

		//MENU SWITCH
		switch (opc)
		{
		case 0:
			/** PREGUNTAR SI DESEA SALIR */
			opc = 0;
			break;
		case 1:
			//ALTA
			if (ePantalla_Alta(Pantalla, TAM_ESTRUCTURA)) {
				puts(" * Pantalla DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * NO SE DIO DE ALTA.");
			}
			system("pause");
			break;
		case 2:
			//BAJA
			if (ePantalla_Baja(Pantalla, TAM_ESTRUCTURA)) {
				puts("\n * BAJA DE Pantalla EXITOSA");
				ePantalla_MostrarTodos(Pantalla, TAM_ESTRUCTURA);
			} else {
				puts("\n * BAJA DE Pantalla CANCELADA");
			}
			system("pause");
			break;
		case 3:
			//IMPRIMIR Pantalla
			if(ePantalla_MostrarTodos(Pantalla, TAM_ESTRUCTURA))
			{
				system("pause");
			}else{
				puts("No hay nada para mostrar pa");
			}
			break;
		case 4:
			//MODIFICACION
			if (ePantalla_Modificacion(Pantalla, TAM_ESTRUCTURA)) {
				puts("\n * MODIFICACION DE Pantalla EXITOSA\n");
				ePantalla_MostrarTodos(Pantalla, TAM_ESTRUCTURA);
			} else {
				puts("\n * MODIFICACION DE Pantalla CANCELADA");
			}
			system("pause");
			break;
		case 5:
			//ORDENAR Pantalla
			criterioDeOrdenamiento = get_IntRange("INGRESE CRITERIO DE ORDENAMIENTO [1]MAYOR A MENOR [-1]MENOR A MAYOR","ERROR REINGRESE",
					-1,1); //PEDIR CRITERIO DE ORDENAMIENTO
			ePantalla_Sort(Pantalla, TAM_ESTRUCTURA, criterioDeOrdenamiento);
			system("pause");
			break;
		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
