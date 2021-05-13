/*
 * Pantalla.c
 *
 *  Created on: 12 may. 2021
 *      Author: ignac
 */

#ifndef Pantalla_C_
#define Pantalla_C_
#include "Pantalla.h"

#include "Biblioteca.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
static int Pantalla_idIncremental = 0;

void ePantalla_Inicializar(ePantalla array[], int TAM) {
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

int ePantalla_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Pantalla_idIncremental += 1;
}

int ePantalla_ObtenerIndexLibre(ePantalla array[], int TAM) {
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

int ePantalla_BuscarPorID(ePantalla array[], int TAM, int ID) {
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idPantalla == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void ePantalla_MostrarUno(ePantalla Pantalla) {
	//PRINTF DE UN SOLO Pantalla
	printf("%5d %5d %15.2f %15s %15s %10d %10s %10s \n\n", Pantalla.idPantalla,Pantalla.tipoPantalla,Pantalla.precio,Pantalla.nombre,Pantalla.direccion.calle,
			Pantalla.direccion.numero,Pantalla.direccion.localidad,Pantalla.direccion.provincia);
}

int ePantalla_MostrarTodos(ePantalla array[], int TAM) {
	int i;
	int retorno = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Pantalla");
	printf("%5s %5s %15s %15s %15s %15s %15s %15s \n\n ",
			"ID" ,"TIPO","PRECIO","NOMBRE","CALLE","NUMERO","LOCALIDAD","PROVINCIA"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Pantalla
				ePantalla_MostrarUno(array[i]);
				//CONTADOR DE Pantalla
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Pantalla PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		retorno = 1;
	}

	return retorno;
}

int ePantalla_MostrarDadosDeBaja(ePantalla array[], int TAM) {
	int i;
	int retorno = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Pantalla\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Pantalla
				ePantalla_MostrarUno(array[i]);
				//CONTADOR DE Pantalla
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Pantalla PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		retorno = 1;
	}

	return retorno;
}

ePantalla ePantalla_CargarDatos(void) {
	ePantalla auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	get_OnlyAlphabetStringWithSpaces("INGRESE EL NOMBRE:\n-","ERROR.REINGRESE.\n",auxiliar.nombre,MAX_CHARS_CADENAS);
	auxiliar.precio =get_Float("INGRESE EL PRECIO:\n-","ERROR.REINGRESE.\n");
	get_OnlyAlphabetStringWithSpaces("INGRESE LA CALLE:\n-","ERROR.REINGRESE.\n",auxiliar.direccion.calle,MAX_CHARS_CADENAS);
	get_OnlyAlphabetStringWithSpaces("INGRESE LA LOCALIDAD:\n-","ERROR.REINGRESE.\n",auxiliar.direccion.localidad,MAX_CHARS_CADENAS);
	get_OnlyAlphabetStringWithSpaces("INGRESE LA PROVINCIA:\n-","ERROR.REINGRESE.\n",auxiliar.direccion.provincia,MAX_CHARS_CADENAS);
	auxiliar.direccion.numero=get_Int("INGRESE EL NUMERO:\n","ERROR.REINGRESE NUMERO.\n");
	switch(get_IntRange("\nSELECCIONE TIPO: \n\t1 - LED\n \t2 - LCD\n-","ERROR.REINGRESE.\n",1,2))
			{
			case LED:
				auxiliar.tipoPantalla=LED;
				break;
			case LCD:
				auxiliar.tipoPantalla=LCD;
					break;
			}

	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

ePantalla ePantalla_ModificarUno(ePantalla Pantalla) {
	ePantalla auxiliar = Pantalla;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	int opc;
	printf("INGRESE QUE QUIERE MODIFICAR: \n");
	opc=get_IntRange("\t1 - NOMBRE \n \t2 - PRECIO \n \t3 - TIPO DE Pantalla \n\t4 - DIRECCION\n-","ERROR REINGRESE EL QUE QUIERE MODIFICAR: "
			"\t1 - NOMBRE \n \t2 - PRECIO \n \t3 - TIPO DE Pantalla \n \t4 - DIRECCION\n-",1,4);
	switch(opc){
		case 1:
	get_OnlyAlphabetStringWithSpaces("INGRESE EL NOMBRE:\n-","ERROR.REINGRESE.\n",auxiliar.nombre,MAX_CHARS_CADENAS);
	break;

		case 2:
	auxiliar.precio=get_Float("INGRESE EL PRECIO:\n-","ERROR.REINGRESE.\n");
	break;

		case 3:
	printf(" \t1 - LED\n \t2 - LCD\n");
	switch(get_IntRange("\nSELECCIONE TIPO: \n-","ERROR.REINGRESE.\n",1,3))
		{
		case LED:
			auxiliar.tipoPantalla=LED;
			break;
		case LCD:
			auxiliar.tipoPantalla=LCD;
				break;
		}
	break;
	case 4:
			get_OnlyAlphabetStringWithSpaces("INGRESE LA CALLE:\n-","ERROR.REINGRESE.\n",auxiliar.direccion.calle,MAX_CHARS_CADENAS);
			get_OnlyAlphabetStringWithSpaces("INGRESE LA LOCALIDAD:\n-","ERROR.REINGRESE.\n",auxiliar.direccion.localidad,MAX_CHARS_CADENAS);
			get_OnlyAlphabetStringWithSpaces("INGRESE LA PROVINCIA:\n-","ERROR.REINGRESE.\n",auxiliar.direccion.provincia,MAX_CHARS_CADENAS);
			auxiliar.direccion.numero=get_Int("INGRESE EL NUMERO:\n","ERROR.REINGRESE NUMERO.\n");
		break;
	}
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int ePantalla_Alta(ePantalla array[], int TAM) {
	int retorno = 0;
	ePantalla auxPantalla;

	//BUSCO ESPACIO EN ARRAY
	int index = ePantalla_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Pantalla AUXILIAR
		auxPantalla = ePantalla_CargarDatos();
		if(validate_Exit_SN("DESEA CONTINUAR? SI[S] NO[N]: ","ERROR.REINGRESE")){
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxPantalla.idPantalla = ePantalla_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxPantalla.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxPantalla;
		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		retorno = 1;
		}
	}

	return retorno;
}

int ePantalla_Baja(ePantalla array[], int TAM) {
	int retorno = 0;
	int idPantalla;
	int index;
	int flag = 0;
	int flagSalir=1;//SI ES 1 SE QUEDA

	//LISTO TODOS LOS Pantalla
	if (ePantalla_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Pantalla DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Pantalla PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idPantalla);

		//BUSCO INDEX POR ID EN ARRAY
		while (ePantalla_BuscarPorID(array, TAM, idPantalla) == -1) {
			if(validate_Exit_SN("NO EXISTE ID. DESEA SALIR? SI[S] NO[N]: ","ERROR.REINGRESE"))
			{
				flagSalir=-1;//TORNO -1 PARA SALIR DIRECTAMENTE
				break;
			}
			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			idPantalla= get_IntPositive("INGRESE ID A DAR DE BAJA: ", "ERROR.REINGRESE:");
		}
		if(flagSalir==1){
		//OBTENGO INDEX DEL ARRAY DE Pantalla A DAR DE BAJA
		index = ePantalla_BuscarPorID(array, TAM, idPantalla);
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

int ePantalla_Modificacion(ePantalla array[], int TAM) {
	int retorno = 0;
	int idPantalla;
	int index;
	int flag = 0;
	ePantalla auxiliar;

	//LISTO TODOS LOS Pantalla
	if (ePantalla_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Pantalla DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Pantalla PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idPantalla);

		//BUSCO INDEX POR ID EN ARRAY
		while (ePantalla_BuscarPorID(array, TAM, idPantalla) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idPantalla);
		}

		//OBTENGO INDEX DEL ARRAY DE Pantalla A MODIFICAR
		index = ePantalla_BuscarPorID(array, TAM, idPantalla);

		//LLAMO A FUNCION QUE MODIFICA Pantalla
		auxiliar = ePantalla_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		retorno = 1;
	}

	return retorno;
}

int ePantalla_Sort(ePantalla array[], int TAM, int criterio) {
	int retorno = 0;
	int i;
	int j;
	ePantalla aux;

	/** EJEMPLO DE SORT CON ID DE Pantalla
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
						if (array[i].idPantalla > array[j].idPantalla) {
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
						if (array[i].idPantalla < array[j].idPantalla) {
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
	}
	return retorno;
}

#endif /* Pantalla_C_ */
