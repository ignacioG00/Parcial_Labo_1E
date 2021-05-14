/*
 * Entidades.c
 *
 *  Created on: 12 may. 2021
 *      Author: ignac
 */
#ifndef ENTIDADES_C_
#define ENTIDADES_C_

#include "Contribuyente.h"
#include "Recaudaciones.h"

int eRecaudacionesContribuyente_Alta(eRecaudaciones arrayRecaudaciones[], int TAM_Recaudaciones,eContribuyente arrayContribuyente[], int TAM_Contribuyente)
{

	int rtn = 0;
	eRecaudaciones auxRecaudaciones;
	int idContribuyente;

	int index = eRecaudaciones_ObtenerIndexLibre(arrayRecaudaciones, TAM_Recaudaciones);

	if (index != -1) {
		auxRecaudaciones = eRecaudaciones_CargarDatos();

		//ID DE Contribuyente
		eContribuyente_MostrarTodos(arrayContribuyente, TAM_Contribuyente);
		idContribuyente = get_Int("SELECCIONE ID DE CONTRIBUYENTE PARA VER RECAUDACIONES: ",
				"ERROR. REINGRESE: ");

		while (eContribuyente_BuscarPorID(arrayContribuyente, TAM_Contribuyente, idContribuyente) == -1) {
			puts("ID NO EXISTE.");
			idContribuyente = get_Int("SELECCIONE ID DE CONTRIBUYENTE PARA VER RECAUDACIONES: ",
					"ERROR. REINGRESE: ");
		}
		auxRecaudaciones.idContribuyente = idContribuyente;

		//TENGO TODO CARGADO
		if (validate_Exit_SN("CONTINUAR SI[S] - NO[N]: ",
				"ERROR. REINGRESE: ")) {
			auxRecaudaciones.idRecaudaciones = eRecaudaciones_ObtenerID()+99;
			auxRecaudaciones.isEmpty = OCUPADO;
			arrayRecaudaciones[index] = auxRecaudaciones;
			rtn = 1;
		}
	}
	return rtn;
}

#endif /* ENTIDADES_C_ */
