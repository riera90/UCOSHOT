#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "decript.h"
#include "../auxiliares/funciones_auxiliares.h"
#include "generador_de_clave_de_encriptacion.h"
#include "inversor_de_clave_de_encriptacion.h"
#include "encriptador.h"
#include "../lectura_imagenes/leer_imagenes_pgm.h"


int desencriptar(char *input_path,
				char *user_key,
				char* output_path,
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
	leer_imagen_pgm_encriptada(input_path, &header, &buffer_char,&tam_header,&tam_buffer);

		printf("%s\n", buffer_char);
	//se pasa el buffer de char a int
	buffer_int = (int*) calloc(tam_buffer,sizeof(int));
	for (int i = 0; i < tam_buffer-1; ++i)
	{
		buffer_int[i]=define_abecedario(buffer_char[i]);
	}

	
	//se desencripta
	for (int pasada = 1; pasada >=0; pasada--)
	{
		//crea la clave de encriptacion
		clave=reservar_matriz(size);
		clave=creacion_clave(user_key, zn, lvl_seguridad, pasada);
		recalcular_matriz(clave, size, zn);

		//invierte la clave
		calcular_inversa_matriz(clave, size, zn);
		recalcular_matriz(clave, size, zn);

		//parte clave de la desencriptacion
		//multiplica el buffer por la clave de desenciptacion
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
			
			//asigna el valor (ya desencriptado) del vector de vuelta al buffer
			for (int i = 0; i < size; ++i)
			{
				buffer_int[k]=vector[i];
				k++;
			}
		}
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
	if ( (f = fopen(output_path,"w")) == NULL)
	{
		printf("ERROR (id:1): THE PROGRAM COULD NOT LOAD THE FILE\n");
		return 1;
	}

	//se guarda el header
	int c=0;
	while ( header[c] != '\0' )
	{
		fputc(header[c],f);
		c++;
	}

	//se guarda el buffer desencriptado
	c=0;
	while ( buffer_char[c+7] != '\0' )
	{
		//detecta los caracteres de relleno del final
		if (buffer_char[c] == VALOR_DE_RELLENO)
		{
			break;
		}
		else
		{
			//detecta si hay un caracter especial de separado
			if (buffer_char[c] == VALOR_RELLENO_BUFFER)
			{
				fputc('\n',f);
			}
			else
			{
				fputc(buffer_char[c],f);
			}

			c++;
		}
	}

	fputc(buffer_char[c-2],f);

	fputc('\n',f);

	fflush(f);

	fclose(f);

}