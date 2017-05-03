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

	int zn=79; //do not change

	
	char _1[100];// input_path
	char _2[100];// c / d
	char _3[100];// password
	char _4[100];// save_path (optional)
	char _5[100];//	lvl_sec (optional)
	char _aux[100];//auxiliar

	

	
	char key[]="esto es una contrasena";
	char key2[]="esto es una contrasena";

	char file[]="file.pgm";
	char file2[]="cripted_file.pgm";	
	char file3[]="decripted_file.pgm";

	int lvl_seguridad=2;

	//leer_imagen_pgm(file,header,buffer);


	encriptar(file, key, zn, lvl_seguridad,file2);
//	printf("\n-------------------------------------------\n\n");
	

	desencriptar(file2, key2, zn, lvl_seguridad,file3);

	/*


	switch (argc)
	{
		case 1:
			printf("\n");
			printf("The program parameters works the next way:\n");
			printf("\n");
			printf("encryption.out <input_path/image.pgm> <c/d> <password> <save_path/image.pgm(optional)> <lvl_sec(optional)>\n");
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

			printf("\t6º parameter: <lvl_sec(optional)>\n");
			printf("\t\tOptional parameter, this dictate the level of security of the encryption,\n");
			printf("\t\t4 is a recommended level (if empty it would be set to 4).\n");
			printf("\n");
		break;


		case 2://error
			printf("error\n");
		break;


		case 3://error
			printf("error\n");
		break;


		case 4://ip cd pas
			printf("\t>>4\n");
			strcpy(_1,argv[1]);
			strcpy(_2,argv[2]);
			strcpy(_3,argv[3]);
			strcpy(_aux,argv[1]);


			if (_2[0]=='c')
			{
				encriptar(_1, _3, zn, 4, _aux);
				break;
			}
			if (_2[0]=='d')
			{
				desencriptar(_1, _3, zn, 4, _aux);
				break;
			}
			printf("error\n");
		break;


		case 5://ip cd pas sp

			strcpy(_1,argv[1]);
			strcpy(_2,argv[2]);
			strcpy(_3,argv[3]);
			strcpy(_4,argv[4]);

			if (_2[0]=='c')
			{
				encriptar(_1, _3, zn, 4, _4);
				break;
			}
			if (_2[0]=='d')
			{
				desencriptar(_1, _3, zn, 4, _4);
				break;
			}
			printf("error\n");
		break;


		case 6://ip cd pas sp lvl

			strcpy(_1,argv[1]);
			strcpy(_2,argv[2]);
			strcpy(_3,argv[3]);
			strcpy(_4,argv[4]);
			strcpy(_5,argv[5]);

			if (_2[0]=='c')
			{
				encriptar(_1, _3, zn, atoi(_5), _4);
				break;
			}
			if (_2[0]=='d')
			{
				desencriptar(_1, _3, zn, atoi(_5), _4);
				break;
			}
			printf("error\n");
		break;

	}


*/


	return 0;	
}