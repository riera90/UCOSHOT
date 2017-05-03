#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../auxiliares/funciones_auxiliares.h"

void leer_imagen_pgm(char* file,
					char** header,
					char** buffer,
					int* tam_header,
					int* tam_buffer)
{
	int alto;
	int ancho;
	*tam_header=0;
	char mem_temp[100];
	//memoria para header
	(*header) = (char*) calloc (100,sizeof(char));
	FILE* f;
	if ((f = fopen (file,"r"))==NULL)
	{
		printf("ERROR: THE PROGRAM COULD NOT LOAD THE FILE\n");
		return;
	}
	int tam;
	int c;

	char aux[10];//es un auxiliar

	//lee el numero magico
	fgets(mem_temp,100,f);
	tam = strlen(mem_temp);
	for (c = 0; c < tam; ++c)
	{
		(*header)[*tam_header] = mem_temp[c];
		(*tam_header)++;
	}


	//lee la linea comentada
	fgets(mem_temp,100,f);
	tam = strlen(mem_temp);
	for (c = 0; c < tam; ++c)
	{
		(*header)[(*tam_header)] = mem_temp[c];
		(*tam_header)++;
	}


	//lee las dimensiones de la imagen

	fgets(mem_temp,100,f);
	c=0;
	tam = strlen(mem_temp);
	for (int i = 0; mem_temp[c]!=' ' ; ++i)
	{
		aux[i]=mem_temp[c];
		aux[i+1]='\0';
		c++;
	}

	(ancho)=atoi(aux);

	c++;
	
	for (int i = 0; mem_temp[c]!='\n' ; ++i)
	{
		aux[i]=mem_temp[c];
		aux[i+1]='\0';
		c++;
	}

	(alto)=atoi(aux);



	for (c = 0; c < tam; ++c)
	{
		char ancho_temp[10];
		char alto_temp[10];

		(*header)[*tam_header] = mem_temp[c];
		(*tam_header)++;
	}


	//lee maxval
	fgets(mem_temp,100,f);
	tam = strlen(mem_temp);
	for (c = 0; c < tam; ++c)
	{
		(*header)[*tam_header] = mem_temp[c];
		(*tam_header)++;
	}


	//lee la matriz de imagen

	//memoria para header
	//puntero de memoria de buffer
	(*tam_buffer)=0;
	(*buffer) = (char*) calloc ( ((alto)*(ancho)*10),sizeof(char) );
	
	for (int posicion = 0; posicion < (alto)*(ancho); ++posicion)
	{
		fgets(mem_temp,10,f);
		tam = strlen(mem_temp);
		for (c = 0; c < tam-1; ++c)
		{
			(*buffer)[*tam_buffer] = mem_temp[c];
			(*tam_buffer)++;
		}
		if ((posicion+1)==((alto)*(ancho))) //es el ultimo caracter y no tiene \n
		{
			for (c = 0; c < tam; ++c)//se lee hasta tam-1, no hsata tam-2
			{
				(*buffer)[*tam_buffer] = mem_temp[c];
				(*tam_buffer)++;	
			}
		}
		(*buffer)[*tam_buffer] = VALOR_RELLENO_BUFFER;
		(*tam_buffer)++;
	}
	(*buffer)[*tam_buffer] = '\0';

	//printf("header completo:\n<%s>\n",*header);
	//printf("buffer completo:\n[%s]\n",*buffer);
/*
	printf("<%c>\n",buffer[*tam_buffer-2]);
	printf("<%c>\n",buffer[*tam_buffer-1]);
	printf("<%c>\n",buffer[*tam_buffer]);
	printf("tamano buffer<%d>\n",*tam_buffer );
	printf("tamano header<%d>\n",*tam_header );
*/


	fclose (f);

}


void leer_imagen_pgm_encriptada(char* file,
					char** header,
					int** buffer,
					int* tam_header,
					int* tam_buffer)
{
	int alto;
	int ancho;
	*tam_header=0;
	char mem_temp[100];
	//memoria para header
	(*header) = (char*) calloc (100,sizeof(char));
	FILE* f;
	if ((f = fopen (file,"r"))==NULL)
	{
		printf("ERROR: THE PROGRAM COULD NOT LOAD THE FILE\n");
		return;
	}
	int tam;
	int c;

	char aux[10];//es un auxiliar

	//lee el numero magico
	fgets(mem_temp,100,f);
	tam = strlen(mem_temp);
	for (c = 0; c < tam; ++c)
	{
		(*header)[*tam_header] = mem_temp[c];
		(*tam_header)++;
	}


	//lee la linea comentada
	fgets(mem_temp,100,f);
	tam = strlen(mem_temp);
	for (c = 0; c < tam; ++c)
	{
		(*header)[(*tam_header)] = mem_temp[c];
		(*tam_header)++;
	}


	//lee las dimensiones de la imagen

	fgets(mem_temp,100,f);
	c=0;
	tam = strlen(mem_temp);
	for (int i = 0; mem_temp[c]!=' ' ; ++i)
	{
		aux[i]=mem_temp[c];
		aux[i+1]='\0';
		c++;
	}

	(ancho)=atoi(aux);

	c++;
	
	for (int i = 0; mem_temp[c]!='\n' ; ++i)
	{
		aux[i]=mem_temp[c];
		aux[i+1]='\0';
		c++;
	}

	(alto)=atoi(aux);



	for (c = 0; c < tam; ++c)
	{
		char ancho_temp[10];
		char alto_temp[10];

		(*header)[*tam_header] = mem_temp[c];
		(*tam_header)++;
	}


	//lee maxval
	fgets(mem_temp,100,f);
	tam = strlen(mem_temp);
	for (c = 0; c < tam; ++c)
	{
		(*header)[*tam_header] = mem_temp[c];
		(*tam_header)++;
	}


	//lee la matriz de imagen

	//memoria para header
	(*buffer) = (int*) calloc ( ((alto)*(ancho)*10),sizeof(int) );
	int a=1;
	int b;
	(*tam_buffer)=0;
	//lee la line de datos encriptados
	for (int i = 0; (a=(int)(fscanf(f,"%i",&b)))>0 ; ++i)
	{
		(*buffer)[*tam_buffer] = b;
		(*tam_buffer)++;
		//printf("%i\n",a);
		//printf("\t%i\n",b );
	}

	/*while ((fgets(mem_temp,10,f))!=NULL);
	{
		(*buffer)[*tam_buffer] =atoi(mem_temp);
		printf("%i",(*buffer)[*tam_buffer] );
		(*tam_buffer)++;
	}
	(*buffer)[*tam_buffer] ='\0';
	printf("\n");*/


	//printf("header completo:\n<%s>\n",*header);
	//printf("buffer completo:\n[%s]\n",*buffer);

/*
	printf("<%c>\n",buffer[*tam_buffer-2]);
	printf("<%c>\n",buffer[*tam_buffer-1]);
	printf("<%c>\n",buffer[*tam_buffer]);
	printf("tamano buffer<%d>\n",*tam_buffer );
	printf("tamano header<%d>\n",*tam_header );
*/


	fclose (f);

}
