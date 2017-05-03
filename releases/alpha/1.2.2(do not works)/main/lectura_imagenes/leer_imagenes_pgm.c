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
		printf("ERROR (id:3): THE PROGRAM COULD NOT LOAD THE FILE\n");
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



	char linea_personalizada[48]="# encrypted / decrypted by UCOSHOT version: 1.0";

	//lee la linea comentada
	fgets(mem_temp,100,f);
	tam = strlen(mem_temp);
	for (c = 0; c < 47 ; ++c)
	{
		(*header)[(*tam_header)] = linea_personalizada[c];
		(*tam_header)++;
	}
	(*header)[(*tam_header)] = '\n';
	(*tam_header)++;


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
		/*if ((posicion+1)==((alto)*(ancho))) //es el ultimo caracter y no tiene \n
		{
			for (c = 0; c < tam-1; ++c)//se lee hasta tam-1, no hsata tam-2
			{
				(*buffer)[*tam_buffer] = mem_temp[c];
				(*tam_buffer)++;	
			}
		}*/
		(*buffer)[*tam_buffer] = VALOR_RELLENO_BUFFER;
		(*tam_buffer)++;
	}
	(*buffer)[*tam_buffer] = '\0';

	fclose (f);

}


void leer_imagen_pgm_encriptada(char* file,
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
		printf("ERROR (id:4): THE PROGRAM COULD NOT LOAD THE FILE\n");
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
	(*buffer) = (char*) calloc ( ((alto)*(ancho)*10),sizeof(char) );

	//lee la line de datos encriptados
	fgets((*buffer),((alto)*(ancho)*10),f);

	//consigue el tamaño de este
	//puntero de memoria de buffer (*tam_buffer)
	for ((*tam_buffer) = 0; (*buffer)[(*tam_buffer)] != '\0' ; ++(*tam_buffer));

	fclose (f);

}
