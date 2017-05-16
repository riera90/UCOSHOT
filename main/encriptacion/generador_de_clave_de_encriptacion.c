//Author: Diego Rodríguez Riera
//Brief: crypt key generator


#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#include "../auxiliares/funciones_auxiliares.h"
#include "generador_de_clave_de_encriptacion.h"



int **creacion_clave(char *clave, int zn, int lvl_seguridad, int pasada)
{
	int **m;
	int val;
	char clave_aux[2];//cadena auxiliar para la tercera pasada de cript
	int size=((int)(pow((lvl_seguridad+1),2)));

	m=reservar_matriz( (int)(pow((lvl_seguridad+1),2)) );
	int z=0, c=0;
	
	switch (pasada)
	{
		case 0: //primera pasada de encriptacion con semilla strlen(calve)
			val=strlen(clave);
			for (int i = 0; i < size ; ++i)
			{
				for (int j = 0; j < size ; ++j)
				{
					val=prng(val);
					m[i][j]=val;
				}
			}
		break;



		case 1: //tercera pasada de encriptacion, esta vez con la clave permitada
		val=0;
		for (int i = 0; i < strlen(clave); ++i)
		{
			val+=clave[i];
		}

		for (int i = 0; i < PASADAS; ++i)//hace PASADAS pasadas de permitacion
		{
			int val_1,val_2;
			
			val=prng(val);
			clave_aux[0]=clave[val%strlen(clave)];
			val_1=val;
			
			val=prng(val);
			clave_aux[1]=clave[val%strlen(clave)];
			val_2=val;
			
			clave[val_1%strlen(clave)]=clave_aux[1];
			clave[val_2%strlen(clave)]=clave_aux[0];
		}

		for (int i = 0; i < size ; ++i)
			{
				for (int j = 0; j < size ; ++j)
				{
					if(c>clave[z])
					{
						z+=2;
						val=(int)(clave[((z+1)%size)]);
					}
					val=prng(val);
					m[i][j]=val;
					c++;
				}
			}
		break;

		//case 2: //segunda pasada de encriptacion, con los valores sin permutar de la clave
			
		//break;

	}




	return m;
}