#include "Recaudaciones.h"

#include "Biblioteca.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
static int Recaudaciones_idIncremental = 0;

void eRecaudaciones_Inicializar(eRecaudaciones array[], int TAM) {
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

int eRecaudaciones_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Recaudaciones_idIncremental += 1;
}

int eRecaudaciones_ObtenerIndexLibre(eRecaudaciones array[], int TAM) {
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

int eRecaudaciones_BuscarPorID(eRecaudaciones array[], int TAM, int ID) {
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idRecaudaciones == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void eRecaudaciones_MostrarUno(eRecaudaciones Recaudaciones) {
	//PRINTF DE UN SOLO Recaudaciones
	printf("%5d %15d %15f %10s %20d %20s \n\n", Recaudaciones.idRecaudaciones,Recaudaciones.mes,Recaudaciones.importe
			,Recaudaciones.tipoRecaudacion,Recaudaciones.idContribuyente,Recaudaciones.estado);
}

int eRecaudaciones_MostrarTodos(eRecaudaciones array[], int TAM) {
	int i;
	int retorno = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t>*** LISTADO RECAUDACIONES ***");
	printf("| %5s | %5s | %10s | %15s | %15s | %10s |\n\n ",
			"ID RECAUDACION" ,"MES","IMPORTE","TIPO RECAUDACION", "ID CONTRIBUYENTE", "ESTADO"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Recaudaciones
				eRecaudaciones_MostrarUno(array[i]);
				//CONTADOR DE Recaudaciones
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Recaudaciones PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		retorno = 1;
	}

	return retorno;
}

int eRecaudaciones_Baja(eRecaudaciones array[], int TAM) {
	int retorno = 0;
	int idRecaudaciones;
	int index;
	int flag = 0;
	int flagSalir=1;//SI ES 1 SE QUEDA

	//LISTO TODOS LOS Recaudaciones
	if (eRecaudaciones_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Recaudaciones DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Recaudaciones PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idRecaudaciones);

		//BUSCO INDEX POR ID EN ARRAY
		while (eRecaudaciones_BuscarPorID(array, TAM, idRecaudaciones) == -1) {
			if(validate_Exit_SN("NO EXISTE ID. DESEA SALIR? SI[S] NO[N]: ","ERROR.REINGRESE"))
			{
				flagSalir=-1;//TORNO -1 PARA SALIR DIRECTAMENTE
				break;
			}
			printf("INGRESE ID A DAR DE BAJA: ");
			idRecaudaciones= get_IntPositive("INGRESE ID A DAR DE BAJA: ", "ERROR.REINGRESE:");
		}
		if(flagSalir==1){
		//OBTENGO INDEX DEL ARRAY DE Recaudaciones A DAR DE BAJA
		index = eRecaudaciones_BuscarPorID(array, TAM, idRecaudaciones);
		if(validate_Exit_SN("DESEA CONTINUAR? SI[S] NO[N]: ","ERROR.REINGRESE"))
			{
		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		retorno = 1;
			}
		}
	}

	return retorno;
}

int eRecaudaciones_MostrarDadosDeBaja(eRecaudaciones array[], int TAM) {
	int i;
	int retorno = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> ***RECAUDACIONES***\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Recaudaciones
				eRecaudaciones_MostrarUno(array[i]);
				//CONTADOR DE Recaudaciones
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Recaudaciones PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		retorno = 1;
	}

	return retorno;
}


eRecaudaciones eRecaudaciones_CargarDatos(void) {
	eRecaudaciones auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	int opc;
	auxiliar.mes = get_IntRange("INGRESE MES: ", "ERROR. REINGRESE MES: ", 1, 12);
	get_FloatRange(&auxiliar.importe,"INGRESE IMPORTE: ", "ERROR.REINGRESE IMPORTE:",0,250000,2);
	opc=get_IntRange("INGRESE TIPO DE RECAUDACION \n \t1- ARBA \n\t2 - IIBB \n\t3 - GANANCIAS\n","ERROR REINGRESE EL TIPO DE RECAUDACION:\n "
			"INGRESE TIPO DE RECAUDACION \t1 - ARBA \n\t2 - IIBB \n\t3 - GANANCIAS\n",1,3);
	switch(opc){
	case 1:
		strcpy(auxiliar.tipoRecaudacion, "ARBA");
		break;
	case 2:
		strcpy(auxiliar.tipoRecaudacion, "IIBB");
		break;
	case 3:
		strcpy(auxiliar.tipoRecaudacion, "GANANCIAS");
		break;
	}
	strcpy(auxiliar.estado,"PENDIENTE");
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

eRecaudaciones eRecaudaciones_ModificarUno(eRecaudaciones Recaudaciones) {
	eRecaudaciones auxiliar = Recaudaciones;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	int opc;
	printf("INGRESE QUE QUIERE MODIFICAR: \n");
	opc=get_IntRange("\t1 - NOMBRE \n \t2 - APELLIDO \n \t3 - CUIL \n\n-","ERROR REINGRESE EL QUE QUIERE MODIFICAR:\n "
			"\t1 - NOMBRE \n \t2 - PRECIO \n \t3 - TIPO DE RECAUDACIONES \n-",1,3);
	switch(opc){
		case 1:
	auxiliar.mes = get_IntRange("INGRESE MES: ", "ERROR. REINGRESE MES: ", 1, 12);
	break;

		case 2:
	get_FloatRange(&auxiliar.importe,"INGRESE IMPORTE: ", "ERROR.REINGRESE IMPORTE:",0,250000,2);
	break;

		case 3:
	opc=get_IntRange("\t1- ARBA \n\t2 - IIBB \n\t3 - GANANCIAS","ERROR REINGRESE EL TIPO DE RECAUDACION:\n "
				"\t1- ARBA \n\t2 - IIBB \n\t3 - GANANCIAS",1,3);
		switch(opc){
		case 1:
			strcpy(auxiliar.tipoRecaudacion, "ARBA");
			break;
		case 2:
			strcpy(auxiliar.tipoRecaudacion, "IIBB");
			break;
		case 3:
			strcpy(auxiliar.tipoRecaudacion, "GANANCIAS");
			break;
		}
	break;
	}
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eRecaudaciones_Alta(eRecaudaciones array[], int TAM) {
	int retorno = 0;
	eRecaudaciones auxRecaudaciones;

	//BUSCO ESPACIO EN ARRAY
	int index = eRecaudaciones_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Recaudaciones AUXILIAR
		auxRecaudaciones = eRecaudaciones_CargarDatos();
		if(validate_Exit_SN("DESEA CONTINUAR? SI[S] NO[N]: ","ERROR.REINGRESE")){
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxRecaudaciones.idRecaudaciones = eRecaudaciones_ObtenerID() ;
		//CAMBIO SU ESTADO A "OCUPADO"
		auxRecaudaciones.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxRecaudaciones;
		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		retorno = 1;
		}
	}

	return retorno;
}



int eRecaudaciones_Modificacion(eRecaudaciones array[], int TAM) {
	int retorno = 0;
	int idRecaudaciones;
	int index;
	int flag = 0;
	eRecaudaciones auxiliar;

	//LISTO TODOS LOS Recaudaciones
	if (eRecaudaciones_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Recaudaciones DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Recaudaciones PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idRecaudaciones);

		//BUSCO INDEX POR ID EN ARRAY
		while (eRecaudaciones_BuscarPorID(array, TAM, idRecaudaciones) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idRecaudaciones);
		}

		//OBTENGO INDEX DEL ARRAY DE Recaudaciones A MODIFICAR
		index = eRecaudaciones_BuscarPorID(array, TAM, idRecaudaciones);

		//LLAMO A FUNCION QUE MODIFICA Recaudaciones
		auxiliar = eRecaudaciones_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		retorno = 1;
	}

	return retorno;
}

int eRecaudaciones_Sort(eRecaudaciones array[], int TAM, int criterio) {
	int retorno = 0;
	int i;
	int j;
	eRecaudaciones aux;

	/** EJEMPLO DE SORT CON ID DE Recaudaciones
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
						if (array[i].idRecaudaciones > array[j].idRecaudaciones) {
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
						if (array[i].idRecaudaciones < array[j].idRecaudaciones) {
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
