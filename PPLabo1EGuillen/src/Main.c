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
#define TAM_CONTRIBUYENTE 50
#define TAM_RECAUDACIONES 50

int main(void) {
	setbuf(stdout, NULL);

	int opc;
//	int criterioDeOrdenamiento;
	int flagContrib = 0;

	//CREO ARRAY DE CONTRIBUYENTE
	eContribuyente Contribuyente[TAM_CONTRIBUYENTE];
	eRecaudaciones Recaudaciones[TAM_RECAUDACIONES];
	//INICIALIAZO ARRAY DE CONTRIBUYENTE
	eContribuyente_Inicializar(Contribuyente, TAM_CONTRIBUYENTE);
	eRecaudaciones_Inicializar(Recaudaciones, TAM_CONTRIBUYENTE);

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
			if (eContribuyente_Alta(Contribuyente, TAM_CONTRIBUYENTE)) {
				puts(" * Contribuyente DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * NO SE DIO DE ALTA.");
			}
			system("pause");
			flagContrib = 1;
			break;
		case 2:
			//MODIFICACION
			if (eContribuyente_Modificacion(Contribuyente, TAM_CONTRIBUYENTE)) {
				puts("\n * MODIFICACION DE Contribuyente EXITOSA\n");
				eContribuyente_MostrarTodos(Contribuyente, TAM_CONTRIBUYENTE);
			} else {
				puts("\n * MODIFICACION DE Contribuyente CANCELADA");
			}
			system("pause");
			break;
		case 3:
			//BAJA
			if (eContribuyente_Baja(Contribuyente, TAM_CONTRIBUYENTE)) {
				puts("\n * BAJA DE Contribuyente EXITOSA");
				eContribuyente_MostrarTodos(Contribuyente, TAM_CONTRIBUYENTE);
			} else {
				puts("\n * BAJA DE Contribuyente CANCELADA");
			}
			system("pause");
			break;

		case 4:
			//ALTA RECAUDACIONES
			if(flagContrib==1){
			if (eRecaudacionesContribuyente_Alta(Recaudaciones, TAM_RECAUDACIONES, Contribuyente, TAM_CONTRIBUYENTE)) {
				puts(" * RECAUDACIONES DADO DE ALTA EXITOSAMENTE");
				eRecaudaciones_MostrarTodos(Recaudaciones,TAM_RECAUDACIONES);
			} else {
				puts(" * NO SE DIO DE ALTA.");
			}
			system("pause");
			}else{
				opc=1;
				printf("*DEBE EXISTIR UN CONTRIBUYENTE*\n");
			}
			break;

		case 7:
			 //IMPRIMIR Contribuyente
			if(eContribuyente_MostrarTodos(Contribuyente, TAM_CONTRIBUYENTE))
			{
				system("pause");
			}else{
				puts("NO EXISTE CONTRIBUYENTE CARGADO.");
			}
			break;
		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
