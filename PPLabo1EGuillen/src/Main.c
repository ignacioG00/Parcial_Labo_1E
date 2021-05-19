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
		printf("* INGRESE OPCION DE MENU: ");
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
			if (eContribuyente_Alta(Contribuyente, TAM_CONTRIBUYENTE))
			{
				eContribuyente_MostrarTodos(Contribuyente, TAM_CONTRIBUYENTE);
				puts(" * CONTRIBUYENTE DADO DE ALTA EXITOSAMENTE *\n");
			} else {
				puts(" * NO SE DIO DE ALTA.");
			}
			system("pause");
			flagContrib = 1;
			break;
		case 2:
			//MODIFICACION
			if (eContribuyente_Modificacion(Contribuyente, TAM_CONTRIBUYENTE))
			{
				puts("\n * MODIFICACION DE CONTRIBUYENTE EXITOSA *\n");
				eContribuyente_MostrarTodos(Contribuyente, TAM_CONTRIBUYENTE);
			} else {
				puts("\n * MODIFICACION DE Contribuyente CANCELADA *\n");
			}
			system("pause");
			break;
		case 3:
			//BAJA
			if(flagContrib==1){
			if (bajaDeContribuyente(Recaudaciones, TAM_RECAUDACIONES, Contribuyente, TAM_CONTRIBUYENTE))
			{
				puts("\n * BAJA DE CONTRIBUYENTE EXITOSA *\n");

				eContribuyente_MostrarTodos(Contribuyente, TAM_CONTRIBUYENTE);
			} else {
				puts("\n * BAJA DE CONTRIBUYENTE CANCELADA");
			}
			system("pause");
			}else{
				opc=1;
				printf("*DEBE EXISTIR UN CONTRIBUYENTE*\n");
			}
			break;

		case 4:
			//ALTA RECAUDACIONES
			if(flagContrib==1){
			if (eRecaudacionesContribuyente_Alta(Recaudaciones, TAM_RECAUDACIONES, Contribuyente, TAM_CONTRIBUYENTE))
			{
				puts("\n* RECAUDACION DADA DE ALTA EXITOSAMENTE *\n");
				eRecaudaciones_MostrarTodos(Recaudaciones,TAM_RECAUDACIONES);
			} else {
				puts(" * NO SE DIO DE ALTA.");
			}
			system("pause");
			}else{
				opc=1;
				printf("\n* DEBE EXISTIR UN CONTRIBUYENTE *\n");
			}
			break;
		case 5:
			//CAMBIAR ESTADO A REFINANCIAR
			if(flagContrib==1){

				eRecaudaciones_MostrarTodos(Recaudaciones,TAM_RECAUDACIONES);
				refinanciar_Recaudacion(Recaudaciones,Contribuyente,TAM_CONTRIBUYENTE,TAM_RECAUDACIONES);
				puts("\n * ESTADO DE RECAUDACION CAMBIADO EXITOSAMENTE *\n");
			}else{
				opc=1;
				printf("*DEBE EXISTIR UN/A CONTRIBUYENTE/RECAUDACION*\n");
			}
			break;
		case 6:
			//CAMBIAR ESTADO A SALDADO
			if(flagContrib==1){
			eRecaudaciones_MostrarTodos(Recaudaciones,TAM_RECAUDACIONES);
			saldar_Recaudacion(Recaudaciones,Contribuyente,TAM_CONTRIBUYENTE,TAM_RECAUDACIONES);
			puts(" \n* ESTADO DE RECAUDACION CAMBIADO EXITOSAMENTE *\n");
			}else{
				opc=1;
				printf("\n* DEBE EXISTIR UN/A CONTRIBUYENTE/RECAUDACION *\n");
			}
			break;
		case 7:
			 //IMPRIMIR CONTRIBUYENTE
			if(flagContrib==1){
			if(eContribuyente_MostrarTodos(Contribuyente, TAM_CONTRIBUYENTE))
			{
				system("pause");
			}else{
				puts("NO EXISTE CONTRIBUYENTE CARGADO.");
				}
			}
			break;
		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
