#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "../auxiliares/funciones_auxiliares.h"
#include "generador_de_clave_de_encriptacion.h"
#include "encriptador.h"
#include "../lectura_imagenes/leer_imagenes_pgm.h"

int encriptar(char *data_file,
				char *user_key,
				int zn,
				int lvl_seguridad)
{
	FILE* f;
	int** clave; //clave de encriptacion
	char* header; //header de la imagen
	char* buffer_char;
	int* buffer_int;
	int tam_buffer;//tamaño del buffer (int y char)
	int tam_header;
	int size=(int)pow(lvl_seguridad+1,2);
	int vector[size];
	char aux[100];

	//llamamos a la funcion leer_imagen
	leer_imagen_pgm(data_file, &header, &buffer_char,&tam_header,&tam_buffer);

	
	//se añade los caracteres de relleno
	while ( tam_buffer%size !=0 )
	{
		buffer_char[tam_buffer-1] = VALOR_DE_RELLENO;
		tam_buffer++;
	}
	buffer_char[tam_buffer] = '\0';

	//se pasa el buffer de char a int
	buffer_int = (int*) calloc(tam_buffer,sizeof(int));
	for (int i = 0; i < tam_buffer-1; ++i)
	{
		buffer_int[i]=define_abecedario(buffer_char[i]);
	}
	/*printf("\tbuffer_int ");
	for (int i = 0; i < tam_buffer-1; ++i)
	{
		printf("<%d>",buffer_int[i] );
	}
	printf("\n");*/
	
	//se encripta
	for (int pasada = 0; pasada <2; pasada++)
	{
		//crea la clave de encriptacion
		clave=reservar_matriz(size);
		clave=creacion_clave(user_key, zn, lvl_seguridad, pasada);
		recalcular_matriz(clave, size, zn);

		//parte clave de la encriptacion
		//multiplica el buffer por la clave de enciptacion
		int k=0;
		for (int i = 0; i < tam_buffer-1;)
		{
			//guarda los datos en el vector
			for (int j = 0; j < size; ++j)
			{
				vector[j]=buffer_int[i];
				i++;
			}

			//multiplica
			multiplicar(clave, vector, size, zn);
			
			//asigna el valor (ya encriptado) del vector de vuelta al buffer
			for (int i = 0; i < size; ++i)
			{
				buffer_int[k]=vector[i];
				k++;
			}
		}
		/*printf("\tbuffer_int post cript");
		for (int i = 0; i < tam_buffer-1; ++i)
		{
			printf("<%d>",buffer_int[i] );
		}
		printf("\n");*/
	}

	
	//se pasa el buffer de int a char
	for (int i = 0; i < tam_buffer-1; ++i)
	{
		buffer_int[i]=buffer_int[i]%zn;
		buffer_char[i] = redefine_abecedario(buffer_int[i]);
		buffer_char[i+1]='\0';
	}

	//se guarda el fichero
	//abrimos el fichero en modo escritura
	if ( (f = fopen("cripted_file.pgm","w")) == NULL)
	{
		printf("ERROR: THE PROGRAM COULD NOT LOAD THE FILE\n");
		return 1;
	}

	//se guarda el header
	int c=0;
	while ( header[c] != '\0' )
	{
		fputc(header[c],f);
		c++;
	}

	//se guarda el buffer encriptado
	c=0;
	while ( buffer_char[c] != '\0' )
	{
		fputc(buffer_char[c],f);
		c++;
	}
 
	fflush(f);

	fclose(f);
	
}



//debuggin fn
void imprimir_vector(int vector[], int size)
{
	printf("\tvector ");
	for (int i = 0; i < size; ++i)
	{
		printf("<%d>", vector[i]);
	}
	printf("\n");
}
//end debuggin fn



void multiplicar(int **clave,
				int vector[],
				int size,
				int zn)
{
	//printf("multiplicando\n");
	//imprimir_matriz(clave,size);
	int vector_aux[size];
	for (int i = 0; i < size; ++i)
	{
		vector_aux[i]=0;
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			vector_aux[i]+=(vector[j]*clave[i][j]);
		}
	}

	for (int i = 0; i < size; ++i)
	{
		vector[i]=vector_aux[i];
	}
	for (int i = 0; i < size; ++i)
	{
		vector[i]=(vector[i]%zn);
		if (vector[i]<0)
		{
			vector[i]+=zn;
		}
	}
}
