/*
 * Entidades.h
 *
 *  Created on: 12 may. 2021
 *      Author: ignac
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Contribuyente.h"
#include "Recaudaciones.h"

int eRecaudacionesContribuyente_Alta(eRecaudaciones arrayRecaudaciones[], int TAM_Recaudaciones,eContribuyente arrayContribuyente[], int TAM_Contribuyente);
int bajaDeContribuyente(eRecaudaciones arrayRecaudaciones[], int TAM_Recaudaciones,eContribuyente arrayContribuyente[], int TAM_Contribuyente);

#endif /* INFORMES_H_ */
