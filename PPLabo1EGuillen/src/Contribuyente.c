/*
 * Contribuyente.c
 *
 *  Created on: 12 may. 2021
 *      Author: ignac
 */

#ifndef Contribuyente_C_
#define Contribuyente_C_
#include "Contribuyente.h"

#include "Biblioteca.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
static int Contribuyente_idIncremental = 0;

void eContribuyente_Inicializar(eContribuyente array[], int TAM) {
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int eContribuyente_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Contribuyente_idIncremental += 1;
}

int eContribuyente_ObtenerIndexLibre(eContribuyente array[], int TAM) {
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int eContribuyente_BuscarPorID(eContribuyente array[], int TAM, int ID) {
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idContribuyente == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void eContribuyente_MostrarUno(eContribuyente Contribuyente) {
	//PRINTF DE UN SOLO Contribuyente

	printf("%5d %15s %15s %20s \n\n", Contribuyente.idContribuyente,Contribuyente.nombre,Contribuyente.apellido,Contribuyente.cuil);
}

int eContribuyente_MostrarTodos(eContribuyente array[], int TAM) {
	int i;
	int retorno = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Contribuyente");
	printf("| %5s | %15s | %15s | %15s |\n\n ",
			"ID" ,"NOMBRE","APELLIDO","CUIL"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Contribuyente
				eContribuyente_MostrarUno(array[i]);
				//CONTADOR DE Contribuyente
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Contribuyente PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		retorno = 1;
	}

	return retorno;
}

int eContribuyente_MostrarDadosDeBaja(eContribuyente array[], int TAM) {
	int i;
	int retorno = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Contribuyente\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Contribuyente
				eContribuyente_MostrarUno(array[i]);
				//CONTADOR DE Contribuyente
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Contribuyente PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		retorno = 1;
	}

	return retorno;
}

eContribuyente eContribuyente_CargarDatos(void) {
	eContribuyente auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	get_OnlyAlphabetStringWithSpaces("INGRESE EL NOMBRE:\n-","ERROR.REINGRESE.\n",auxiliar.nombre,MAX_CHARS_CADENAS);
	get_OnlyAlphabetStringWithSpaces("INGRESE EL APELLIDO:\n-","ERROR.REINGRESE.\n",auxiliar.apellido,MAX_CHARS_CADENAS);
	get_Cuil(auxiliar.cuil,"INGRESE EL CUIL:\n","ERROR.REINGRESE NUMERO.\n",2);

	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

eContribuyente eContribuyente_ModificarUno(eContribuyente Contribuyente) {
	eContribuyente auxiliar = Contribuyente;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	int opc;
	printf("INGRESE QUE QUIERE MODIFICAR: \n");
	opc=get_IntRange("\t1 - NOMBRE \n \t2 - APELLIDO \n \t3 - CUIL \n\n-","ERROR REINGRESE EL QUE QUIERE MODIFICAR:\n "
			"\t1 - NOMBRE \n \t2 - PRECIO \n \t3 - TIPO DE Contribuyente \n \t4 - DIRECCION\n-",1,3);
	switch(opc){
		case 1:
	get_OnlyAlphabetStringWithSpaces("INGRESE EL NOMBRE:\n-","ERROR.REINGRESE.\n",auxiliar.nombre,MAX_CHARS_CADENAS);
	break;

		case 2:
	get_OnlyAlphabetStringWithSpaces("INGRESE EL APELLIDO:\n-","ERROR.REINGRESE.\n",auxiliar.apellido,MAX_CHARS_CADENAS);
	break;

		case 3:
	get_Cuil(auxiliar.cuil,"INGRESE EL CUIL:\n","ERROR.REINGRESE NUMERO.\n",2);
	break;
	}
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eContribuyente_Alta(eContribuyente array[], int TAM) {
	int retorno = 0;
	eContribuyente auxContribuyente;

	int index = eContribuyente_ObtenerIndexLibre(array, TAM);

	if (index != -1) {
		auxContribuyente = eContribuyente_CargarDatos();
		if(validate_Exit_SN("DESEA CONTINUAR? SI[S] NO[N]: ","ERROR.REINGRESE")){
		auxContribuyente.idContribuyente = eContribuyente_ObtenerID() + 999;
		auxContribuyente.isEmpty = OCUPADO;
		array[index] = auxContribuyente;
		retorno = 1;
		}
	}

	return retorno;
}

int eContribuyente_Baja(eContribuyente array[], int TAM) {
	int retorno = 0;
	int idContribuyente;
	int index;
	int flag = 0;
	int flagSalir=1;//SI ES 1 SE QUEDA

	//LISTO TODOS LOS Contribuyente
	if (eContribuyente_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Contribuyente DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Contribuyente PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("REINGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idContribuyente);

		//BUSCO INDEX POR ID EN ARRAY
		while (eContribuyente_BuscarPorID(array, TAM, idContribuyente) == -1) {
			if(validate_Exit_SN("NO EXISTE ID. DESEA SALIR? SI[S] NO[N]: ","ERROR.REINGRESE"))
			{
				flagSalir=-1;//TORNO -1 PARA SALIR DIRECTAMENTE
				break;
			}
			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			idContribuyente= get_IntPositive("INGRESE ID A DAR DE BAJA: ", "ERROR.REINGRESE:");
		}
		if(flagSalir==1){
		//OBTENGO INDEX DEL ARRAY DE Contribuyente A DAR DE BAJA
		index = eContribuyente_BuscarPorID(array, TAM, idContribuyente);
		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		retorno = 1;

		}
	}

	return retorno;
}

int eContribuyente_Modificacion(eContribuyente array[], int TAM) {
	int retorno = 0;
	int idContribuyente;
	int index;
	int flag = 0;
	eContribuyente auxiliar;

	//LISTO TODOS LOS Contribuyente
	if (eContribuyente_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Contribuyente DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Contribuyente PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idContribuyente);

		//BUSCO INDEX POR ID EN ARRAY
		while (eContribuyente_BuscarPorID(array, TAM, idContribuyente) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idContribuyente);
		}

		//OBTENGO INDEX DEL ARRAY DE Contribuyente A MODIFICAR
		index = eContribuyente_BuscarPorID(array, TAM, idContribuyente);

		//LLAMO A FUNCION QUE MODIFICA Contribuyente
		auxiliar = eContribuyente_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		retorno = 1;
	}

	return retorno;
}

int eContribuyente_Sort(eContribuyente array[], int TAM, int criterio) {
	int retorno = 0;
	int i;
	int j;
	eContribuyente aux;

	/** EJEMPLO DE SORT CON ID DE Contribuyente
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)

	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idContribuyente > array[j].idContribuyente) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			retorno = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idContribuyente < array[j].idContribuyente) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			retorno = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			retorno = 0;
			break;
		}
		printf("EL ORDEN HA SIDO MODIFICADO!");
	}
	return retorno;
}

#endif /* Contribuyente_C_ */
