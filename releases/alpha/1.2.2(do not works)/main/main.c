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
/*char input_path[]="file.pgm";
char middle_path[]="crypted_file.pgm";
char output_path[]="decrypted_file.pgm";
int lvl_sec=4;
char key_1[]="clave";
char key_2[]="clave";
*/
//encriptar(input_path,key_1,middle_path,zn,lvl_sec);
//desencriptar(middle_path,key_2,output_path,zn,lvl_sec);



	switch(argc)
	{
		case 2:
			printf("\t>>2\n");
			strcpy(_1,argv[1]);

			printf("%s\n",_1 );
			printf("%s\n",_2 );
			printf("%s\n",_3 );
			printf("%s\n",_4 );
			printf("%s\n",_5 );

			if (strcmp("man",_1)==0)
			{
				printf("test\n");
				FILE* f;
				if ((f = fopen ("manual.txt","r"))==NULL)
				{
					printf("ERROR: THE PROGRAM COULD NOT LOAD THE FILE\n");
					return 1;
				}
				char aux[500];
				while (fgets(aux,500,f))
				{
					printf("%s\n",aux);
				}
				fclose(f);
				return 0;
			}
			else

			{
				printf("ERROR, TOO FEW ARGUMENTS, SEE MANUAL FOR MORE INFO\n");
			}
		break;

		case 3:

			printf("\t>>3\n");
			printf("ERROR, TOO FEW ARGUMENTS, SEE MANUAL FOR MORE INFO\n");
		break;

		case 4:
			printf("\t>>4\n");
			strcpy(_1,argv[1]);
			strcpy(_2,argv[2]);
			strcpy(_3,argv[3]);
			strcpy(_4,argv[4]);

			printf("%s\n",_1 );
			printf("%s\n",_2 );
			printf("%s\n",_3 );
			printf("%s\n",_4 );
			printf("%s\n",_5 );

			if ( _1 != NULL && ( _2[0] == 'd' || _2[0]=='c' ) && _3 != NULL && _4 != NULL )
			{
				if (_2[0]=='c')
				{
					encriptar(_1, _3, _1, zn, 4);
				}
				if (_2[0]=='d')
				{
					desencriptar(_1, _3, _1, zn, 4);
				}
			}
			else
			{
				printf("ERROR, INVALID INPUTS\n");
			}
		break;

		case 5:
			printf("\t>>5\n");
			strcpy(_1,argv[1]);
			strcpy(_2,argv[2]);
			strcpy(_3,argv[3]);
			strcpy(_4,argv[4]);

			printf("%s\n",_1 );
			printf("%s\n",_2 );
			printf("%s\n",_3 );
			printf("%s\n",_4 );
			printf("%s\n",_5 );

			if ( _1 != NULL && ( _2[0] == 'd' || _2[0]=='c' ) && _3 != NULL && _4 != NULL && _5!=NULL )
			{
				if (_2[0]=='c')
				{
					encriptar(_1, _3, _4, zn, 4);
				}
				if (_2[0]=='d')
				{
					desencriptar(_1, _3, _4, zn, 4);
				}
			}
			else
			{
				printf("ERROR, INVALID INPUTS\n");
			}

		break;

		case 6:
			printf("\t>>6\n");
			strcpy(_1,argv[1]);
			strcpy(_2,argv[2]);
			strcpy(_3,argv[3]);
			strcpy(_4,argv[4]);
			strcpy(_5,argv[5]);

			printf("%s\n",_1 );
			printf("%s\n",_2 );
			printf("%s\n",_3 );
			printf("%s\n",_4 );
			printf("%s\n",_5 );


			if ( _1 != NULL && ( _2[0] == 'd' || _2[0]=='c' ) && _3 != NULL && _4 != NULL && atoi(_5)>0 )
			{
				if (_2[0]=='c')
				{
					printf("encriptar\n");
					encriptar(_1, _3, _4, zn, atoi(_5));
				}
				if (_2[0]=='d')
				{
					printf("desencriptar\n");
					desencriptar(_1, _3, _4, zn, atoi(_5));
				}
			}
			else
			{
				printf("ERROR, INVALID INPUTS\n");
			}
		break;
	}	


	return 0;
}