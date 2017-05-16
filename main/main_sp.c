//Author: Diego Rodriguez Riera
//Brief: Main del programa de encriptacion
//traduccion por Carlos


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


#include "encriptacion/decript.h"
#include "auxiliares/funciones_auxiliares.h"
#include "encriptacion/generador_de_clave_de_encriptacion.h"
#include "encriptacion/inversor_de_clave_de_encriptacion.h"
#include "encriptacion/encriptador.h"
#include "lectura_imagenes/leer_imagenes_pgm.h"



int main(int argc, char const *argv[])
{
	system("clear");

	int zn=79; //do not change

	
	char _1[100];// input_path
	char _2[100];// c / d
	char _3[100];// password
	char _4[100];// save_path (optional)
	char _aux[100];//auxiliar

	

	int lvl_seguridad=2;//do not change



	switch (argc)
	{
		case 1:
			printf("\n");
			printf("Los parametros del progrma trabajan de la siguiente manera:\n");
			printf("\n");
			printf("encryption.out <input_path/image.pgm> <c/d> <password> <save_path/image.pgm(optional)>\n");
			printf("\n");

			printf("\t1º Parametro. Nombre del programa (encryption.out by default)\n");

			printf("\n");

			printf("\t2º Parametro. <input_path/image.pgm>\n");
			printf("\t\tRuta de entrada del fichero que se desea encriptar o desencriptar.\n");

			printf("\n");

			printf("\t3º Parametro. <c/d>\n");
			printf("\t\tSi <c> es seleccionado la imagen sera encriptada,\n");
			printf("\t\tsi se selecciona <d>, la imangen sera desencriptada.\n");
			printf("\t\tSi se introduce otro caracter no surtira efecto.\n");

			printf("\n");

			printf("\t4º Parametro. <password>\n");
			printf("\t\tLa contrasenia que con la cual se desea encriptar,\n");
			printf("\t\tse debe proporcionar para desencriptar.\n");
			printf("\t\t Si se deja vacio no se hace nada.\n");

			printf("\n");

			printf("\t5º Parametro. <save_path/image.pgm(optional)>\n");
			printf("\t\tParametro opcional, ruta destino del fichero,\n");
			printf("\t\tsi se deja en blanco, la ruta destino sera la misma que la ruta origen.\n");
			printf("\t\tPor razones de seguridad se recomienda guardar la imagen sobreescribiendola.\n");
			printf("\t\t(input path = output path).\n");

			printf("\n");

		break;


		case 2://error
			printf("ERROR: NO SE ENCONTRARON SUFIENTES ARGUMENTOS, VER EL MANUAL PARA MAS INFORMACION.\n");
		break;


		case 3://error
			printf("ERROR: NO SE ENCONTRARON SUFIENTES ARGUMENTOS, VER EL MANUAL PARA MAS INFORMACION.\n");
		break;


		case 4://ipath cd pas
			printf("\t>>4\n");
			strcpy(_1,argv[1]);
			strcpy(_2,argv[2]);
			strcpy(_3,argv[3]);
			strcpy(_aux,argv[1]);


			if (_2[0]=='c')
			{
				printf("\n\t Procesando...\n");
				encriptar(_1, _3, zn, lvl_seguridad, _aux);
				printf("\t Fiinalizado.\n\n");
				printf("\t La imagen encriptada ha sido guardada como:  '%s'.\n\n",_aux);
				break;
			}
			if (_2[0]=='d')
			{
				printf("\n\tProcesando...\n");
				desencriptar(_1, _3, zn, lvl_seguridad, _aux);
				printf("\tFinalizado.\n\n");
				printf("\tLa imagen desencriptada ha sido guardada como: '%s'.\n\n",_aux);

				break;
			}
			printf("ERROR: ENTRADA NO VALIDA, CONSULTAR EL MANUAL PARA MAS INFORMACION.\n");
		break;


		case 5://ip cd pas sp

			strcpy(_1,argv[1]);
			strcpy(_2,argv[2]);
			strcpy(_3,argv[3]);
			strcpy(_4,argv[4]);

			if (_2[0]=='c')
			{
				printf("\n\tProcesando...\n");
				encriptar(_1, _3, zn, lvl_seguridad, _4);
				printf("\tFinalizado.\n\n");
				printf("\tLa imagen encriptada ha sido guardada como: '%s'.\n\n",_4);
				break;
			}
			if (_2[0]=='d')
			{
				printf("\n\tProcesando...\n");
				desencriptar(_1, _3, zn, lvl_seguridad, _4);
				printf("\tFinalizado.\n\n");
				printf("\tLa imagen desencriptada ha sido guardada como: '%s'.\n\n",_4);
				break;
			}
			printf("ERROR: ENTRADA NO VALIDA, VER EL MANUAL PARA MAS INFORMACION.\n");
		break;


		case 6:

			printf("DEMASIADOS ARGUMENTOS, VER EL MANUAL PARA MAS INFORMACION.\n");

		break;

	}

	printf("Presione ENTER para continuar.\n");

	char a;
	scanf("%c",&a);

	system("clear");

	return 0;	
}
