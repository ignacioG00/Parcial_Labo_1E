#include "Instrumento.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
int Instrumento_idIncremental = 0;

int eInstrumento_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Instrumento_idIncremental += 1;
}

void eInstrumento_Inicializar(eInstrumento array[], int TAM) {
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

int eInstrumento_ObtenerIndexLibre(eInstrumento array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eInstrumento_BuscarPorID(eInstrumento array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idInstrumento == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eInstrumento_MostrarUno(eInstrumento Instrumento) {
	//PRINTF DE UN SOLO Instrumento
	printf("%5d\n", Instrumento.idInstrumento);
}

int eInstrumento_MostrarTodos(eInstrumento array[], int TAM) {
	int i;
	int rtn = 0;

	//CABECERA
	puts("\n\t> LISTADO Instrumento");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Instrumento
				eInstrumento_MostrarUno(array[i]);
				//CONTADOR DE Instrumento
				rtn++;
			}
		}
	}

	return rtn;
}

int eInstrumento_MostrarDadosDeBaja(eInstrumento array[], int TAM) {
	int i;
	int rtn = 0;

	//CABECERA
	puts("\t> Instrumento\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Instrumento
				eInstrumento_MostrarUno(array[i]);
				//CONTADOR DE Instrumento
				rtn++;
			}
		}
	}

	return rtn;
}

eInstrumento eInstrumento_CargarDatos(void) {
	eInstrumento auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL eInstrumento_Alta() */
	return auxiliar;
}

eInstrumento eInstrumento_ModificarUno(eInstrumento Instrumento) {
	eInstrumento auxiliar = Instrumento;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eInstrumento_Alta(eInstrumento array[], int TAM) {
	int rtn = 0;
	eInstrumento auxInstrumento;

	//BUSCO ESPACIO EN ARRAY
	int index = eInstrumento_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Instrumento AUXILIAR
		auxInstrumento = eInstrumento_CargarDatos();
		//SETEO ID UNICO - VARIABLE AUTOINCREMENTAL
		auxInstrumento.idInstrumento = eInstrumento_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxInstrumento.isEmpty = OCUPADO;

		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxInstrumento;
		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;

	}

	return rtn;
}

int eInstrumento_Baja(eInstrumento array[], int TAM) {
	int rtn = 0;
	int idInstrumento;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Instrumento
	if (eInstrumento_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Instrumento DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Instrumento PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		idInstrumento = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (eInstrumento_BuscarPorID(array, TAM, idInstrumento) == -1) {
			puts("NO EXISTE ID.");
			idInstrumento = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO INDEX DEL ARRAY DE Instrumento A DAR DE BAJA
		index = eInstrumento_BuscarPorID(array, TAM, idInstrumento);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eInstrumento_Modificacion(eInstrumento array[], int TAM) {
	int rtn = 0;
	int idInstrumento;
	int index;
	int flag = 0;
	eInstrumento auxiliar;

	//LISTO TODOS LOS Instrumento
	if (eInstrumento_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Instrumento DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Instrumento PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		idInstrumento = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (eInstrumento_BuscarPorID(array, TAM, idInstrumento) == -1) {
			puts("NO EXISTE ID.");
			idInstrumento = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO INDEX DEL ARRAY DE Instrumento A MODIFICAR
		index = eInstrumento_BuscarPorID(array, TAM, idInstrumento);

		//LLAMO A FUNCION QUE MODIFICA Instrumento
		auxiliar = eInstrumento_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eInstrumento_Sort(eInstrumento array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eInstrumento aux;

	/** EJEMPLO DE SORT CON ID DE Instrumento */
	/** MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO */

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
						if (array[i].idInstrumento > array[j].idInstrumento) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idInstrumento < array[j].idInstrumento) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}
