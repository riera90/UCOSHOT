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

	int ancho; //aparece primero en la linea de la imagen
	int alto; //aparece segundo en la linea
	int maxval;
	char *header;
	char *buffer;


	int lvl_seguridad=2;


	

	int zn=79;
	char file[]="file.pgm";
	char key[]="esto es una contrasena";
	char file2[]="cripted_file.pgm";
	char key2[]="esto es una contrasena";


	//leer_imagen_pgm(file,header,buffer);


	encriptar(file, key, zn, lvl_seguridad);
	printf("\n-------------------------------------------\n\n");
	

	desencriptar(file2, key2, zn, lvl_seguridad);

	return 0;
}


	/*
		int size=0;
		char c[100];
		FILE* pfile;//se abre el fichero;
		if((pfile=fopen("file.txt", "r"))==NULL);
		{
			printf("error\n");
			//return -1; //el fichero no se pudo abrir
		}
		fgets(c,100,pfile);
		printf("test\n");
		fseek(pfile, 0, SEEK_END);
		size = ftell(pfile);
		printf("%s\n", c);
		printf("el tamaño es:%d\n", size);
		fclose(pfile);

	*/
	/*
	char menu='a';
	int size, zn;
	char file[]="file.txt";
	char key[]="contra";
	int **matriz;
	int lvl_seguridad;
	char clave[100];
	if (&matriz==NULL)printf("test\n");

	

	while(menu!='y')
	{	
		//printf("introduce clave, lvl_seguridad");
		
		zn=79;
		lvl_seguridad=2;

		printf("test\n");
		//int size_matriz=(int)(pow((lvl_seguridad+1),2));
		//matriz = reservar_matriz( size_matriz );
		//printf("asd\n");
		//matriz = creacion_clave(key, zn, lvl_seguridad, 0);

		//encriptar(file, key, zn, lvl_seguridad);
		desencriptar(file, key, zn, lvl_seguridad);

		printf("desea cerrar el programa?\nEscribe y para cerrar el programa\n");
		//scanf("%s",&menu);
		menu='y';
		//printf("\n");
	}
	return 0;	
}*/