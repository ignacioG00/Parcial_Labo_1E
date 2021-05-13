#include "Musico.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
int Musico_idIncremental = 0;

int eMusico_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Musico_idIncremental += 1;
}

void eMusico_Inicializar(eMusico array[], int TAM) {
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

int eMusico_ObtenerIndexLibre(eMusico array[], int TAM) {
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

int eMusico_BuscarPorID(eMusico array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idMusico == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eMusico_MostrarUno(eMusico Musico) {
	//PRINTF DE UN SOLO Musico
	printf("%5d\n", Musico.idMusico);
}

int eMusico_MostrarTodos(eMusico array[], int TAM) {
	int i;
	int rtn = 0;

	//CABECERA
	puts("\n\t> LISTADO Musico");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Musico
				eMusico_MostrarUno(array[i]);
				//CONTADOR DE Musico
				rtn++;
			}
		}
	}

	return rtn;
}

int eMusico_MostrarDadosDeBaja(eMusico array[], int TAM) {
	int i;
	int rtn = 0;

	//CABECERA
	puts("\t> Musico\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Musico
				eMusico_MostrarUno(array[i]);
				//CONTADOR DE Musico
				rtn++;
			}
		}
	}

	return rtn;
}

eMusico eMusico_CargarDatos(void) {
	eMusico auxiliar;

	Get_OnlyAlphabetStringWithSpaces("INGRESE NOMBRE: ", "ERROR. REINGRESE: ", auxiliar.nombre, MAX_CHARS_CADENAS);
	Get_OnlyAlphabetStringWithSpaces("INGRESE APELLIDO: ", "ERROR. REINGRESE: ", auxiliar.apellido, MAX_CHARS_CADENAS);
	auxiliar.edad = Get_IntRange("INGRESE EDAD: ", "ERROR. REINGRESE: ", 1, 100);

	return auxiliar;
}

eMusico eMusico_ModificarUno(eMusico Musico) {
	eMusico auxiliar = Musico;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eMusico_Alta(eMusico array[], int TAM) {
	int rtn = 0;
	eMusico auxMusico;

	//BUSCO ESPACIO EN ARRAY
	int index = eMusico_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Musico AUXILIAR
		auxMusico = eMusico_CargarDatos();
		//SETEO ID UNICO - VARIABLE AUTOINCREMENTAL
		auxMusico.idMusico = eMusico_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxMusico.isEmpty = OCUPADO;

		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxMusico;
		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;

	}

	return rtn;
}

int eMusico_Baja(eMusico array[], int TAM) {
	int rtn = 0;
	int idMusico;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Musico
	if (eMusico_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Musico DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Musico PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		idMusico = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (eMusico_BuscarPorID(array, TAM, idMusico) == -1) {
			puts("NO EXISTE ID.");
			idMusico = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO INDEX DEL ARRAY DE Musico A DAR DE BAJA
		index = eMusico_BuscarPorID(array, TAM, idMusico);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eMusico_Modificacion(eMusico array[], int TAM) {
	int rtn = 0;
	int idMusico;
	int index;
	int flag = 0;
	eMusico auxiliar;

	//LISTO TODOS LOS Musico
	if (eMusico_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Musico DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Musico PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		idMusico = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (eMusico_BuscarPorID(array, TAM, idMusico) == -1) {
			puts("NO EXISTE ID.");
			idMusico = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO INDEX DEL ARRAY DE Musico A MODIFICAR
		index = eMusico_BuscarPorID(array, TAM, idMusico);

		//LLAMO A FUNCION QUE MODIFICA Musico
		auxiliar = eMusico_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eMusico_Sort(eMusico array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eMusico aux;

	/** EJEMPLO DE SORT CON ID DE Musico */
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
						if (array[i].idMusico > array[j].idMusico) {
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
						if (array[i].idMusico < array[j].idMusico) {
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


