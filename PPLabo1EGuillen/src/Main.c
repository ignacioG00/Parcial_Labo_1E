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
#include "Biblioteca.h"
#include "Informes.h"
#define TAM_ESTRUCTURA 5

int main(void) {
	setbuf(stdout, NULL);

	int opc;
	int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	eContribuyente Contribuyente[TAM_ESTRUCTURA];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	eContribuyente_Inicializar(Contribuyente, TAM_ESTRUCTURA);

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
			if (eContribuyente_Alta(Contribuyente, TAM_ESTRUCTURA)) {
				puts(" * Contribuyente DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * NO SE DIO DE ALTA.");
			}
			system("pause");
			break;
		case 2:
			//MODIFICACION
			if (eContribuyente_Modificacion(Contribuyente, TAM_ESTRUCTURA)) {
				puts("\n * MODIFICACION DE Contribuyente EXITOSA\n");
				eContribuyente_MostrarTodos(Contribuyente, TAM_ESTRUCTURA);
			} else {
				puts("\n * MODIFICACION DE Contribuyente CANCELADA");
			}
			system("pause");
			break;
		case 3:
			//BAJA
			if (eContribuyente_Baja(Contribuyente, TAM_ESTRUCTURA)) {
				puts("\n * BAJA DE Contribuyente EXITOSA");
				eContribuyente_MostrarTodos(Contribuyente, TAM_ESTRUCTURA);
			} else {
				puts("\n * BAJA DE Contribuyente CANCELADA");
			}
			system("pause");
			break;

		case 4:
			//IMPRIMIR Contribuyente
			if(eContribuyente_MostrarTodos(Contribuyente, TAM_ESTRUCTURA))
			{
				system("pause");
			}else{
				puts("NO EXISTE CONTRIBUYENTE CARGADO.");
			}
			break;
		case 5:
			//ORDENAR Contribuyente
			criterioDeOrdenamiento = get_IntRange("INGRESE CRITERIO DE ORDENAMIENTO [1]MAYOR A MENOR [-1]MENOR A MAYOR","ERROR REINGRESE",
					-1,1); //PEDIR CRITERIO DE ORDENAMIENTO
			eContribuyente_Sort(Contribuyente, TAM_ESTRUCTURA, criterioDeOrdenamiento);
			system("pause");
			break;
		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
