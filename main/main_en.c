//Author: Diego Rodríguez Riera
//Brief: main for the encryption program


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
			printf("The program parameters works the next way:\n");
			printf("\n");
			printf("encryption.out <input_path/image.pgm> <c/d> <password> <save_path/image.pgm(optional)>\n");
			printf("\n");

			printf("\t1º parameter: program name (encryption.out by default)\n");

			printf("\n");

			printf("\t2º parameter: <input_path/image.pgm>\n");
			printf("\t\tInput path of the file you want to encrypt or decrypt.\n");

			printf("\n");

			printf("\t3º parameter: <c/d>\n");
			printf("\t\tIf c is selected the image would be encrypted, other ways, if d is selected,\n");
			printf("\t\tit would be decrypted.\n");
			printf("\t\tIf other character is entered it would do anything.\n");

			printf("\n");

			printf("\t4º parameter: <password>\n");
			printf("\t\tthe password which you want to encrypt, you are decrypting you must introduce\n");
			printf("\t\tthe same password with you encrypted the image.\n");
			printf("\t\tIf left empty the program would do nothing.\n");

			printf("\n");

			printf("\t5º parameter: <save_path/image.pgm(optional)>\n");
			printf("\t\tOptional parameter, destiny path of the file, this parameter is optional,\n");
			printf("\t\tmeaning that if left empty the save path would be the same as the input path.\n");
			printf("\t\tFor security reasons is recommended to save the image overwriting itself\n");
			printf("\t\t(input path = output path).\n");

			printf("\n");

		break;


		case 2://error
			printf("ERROR: NOT ENOUGH ARGUMENTS, SEE MANUAL FOR MORE INFO\n");
		break;


		case 3://error
			printf("ERROR: NOT ENOUGH ARGUMENTS, SEE MANUAL FOR MORE INFO\n");
		break;


		case 4://ip cd pas
			printf("\t>>4\n");
			strcpy(_1,argv[1]);
			strcpy(_2,argv[2]);
			strcpy(_3,argv[3]);
			strcpy(_aux,argv[1]);


			if (_2[0]=='c')
			{
				printf("\n\tProcesing...\n");
				encriptar(_1, _3, zn, lvl_seguridad, _aux);
				printf("\tDone.\n\n");
				printf("\tThe crypted image was saved as '%s'.\n\n",_aux);
				break;
			}
			if (_2[0]=='d')
			{
				printf("\n\tProcesing...\n");
				desencriptar(_1, _3, zn, lvl_seguridad, _aux);
				printf("\tDone.\n\n");
				printf("\tThe decrypted image was saved as '%s'.\n\n",_aux);

				break;
			}
			printf("ERROR: INVALID INPUT, SEE MANUAL FOR MORE INFO\n");
		break;


		case 5://ip cd pas sp

			strcpy(_1,argv[1]);
			strcpy(_2,argv[2]);
			strcpy(_3,argv[3]);
			strcpy(_4,argv[4]);

			if (_2[0]=='c')
			{
				printf("\n\tProcesing...\n");
				encriptar(_1, _3, zn, lvl_seguridad, _4);
				printf("\tDone.\n\n");
				printf("\tThe crypted image was saved as '%s'.\n\n",_4);
				break;
			}
			if (_2[0]=='d')
			{
				printf("\n\tProcesing...\n");
				desencriptar(_1, _3, zn, lvl_seguridad, _4);
				printf("\tDone.\n\n");
				printf("\tThe decrypted image was saved as '%s'.\n\n",_4);
				break;
			}
			printf("ERROR: INVALID INPUT, SEE MANUAL FOR MORE INFO\n");
		break;


		case 6:

			printf("TOO MANY ARGUMENTS, SEE MANUAL FOR MORE INFO\n");

		break;

	}

	printf("press ENTER to continue.\n");

	char a;
	scanf("%c",&a);

	system("clear");

	return 0;	
}