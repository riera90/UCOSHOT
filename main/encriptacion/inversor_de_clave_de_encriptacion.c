//Author: Diego Rodríguez Riera
//Brief: crypt key inverter

#include <stdlib.h>


#include "../auxiliares/funciones_auxiliares.h"
#include "inversor_de_clave_de_encriptacion.h"

/*
calcula el inverso de un numeor en modulo Zn
*/
int calcular_inverso(int n, int zn)
{
	for (int i = 0; i < zn; ++i)
		{
			if ((i*n)%zn==1)
			{
				return i;
			}
		}
	return -1;
}
/*
calcula la matriz inversa de otra matriz cuadrada
la cual esta en un modulo "Zn" especifico
>> el algoritmo es el de gauss jordan
*/
int calcular_inversa_matriz(int **matriz, int size, int zn)
{
	int inverso, aux;

	/* matriz auxiliar para el algoritmo, esta se copiara en la matriz
	que es pasada la funcion.
	Todas las operaciones que se le haga a la matriz principal se les
	haran tampien a esta matriz auxiliar*/
	int **matriz_auxiliar;

	// se reserva la matriz auxiliar con las mismas dimensiones que la matriz principal
	matriz_auxiliar=reservar_matriz(size);

	// se hace que la matriz auxiliar sea una matriz identidad
	for (int i = 0; i < size; ++i)
	{
		matriz_auxiliar[i][i]=1;
	}

	//hacer 1 la diagonal principal y cero por debajo
	for (int fila = 0; fila < size; ++fila)
	{
		recalcular_matriz(matriz, size, zn);
		recalcular_matriz(matriz_auxiliar, size, zn);
		if (matriz[fila][fila]!=1)
		{
			inverso=calcular_inverso(matriz[fila][fila], zn);
			for (int columna = 0; columna < size; ++columna)
			{
				/*hace "1" el elemento correspondiente a el elemento
				de la diagonal principal usando el inverso de dicho elemento
				(multiplica la fila correspondiente de las dos matrizes por
				el inverso de elemento correspondiente de la diagonal principal
				de la matriz principal)*/
				recalcular_matriz(matriz, size, zn);
				recalcular_matriz(matriz_auxiliar, size, zn);
				matriz[fila][columna]=matriz[fila][columna]*inverso;
				matriz_auxiliar[fila][columna]=matriz_auxiliar[fila][columna]*inverso;
			}
		}
		for (int k = fila+1; k < size; ++k)
		{
			recalcular_matriz(matriz, size, zn);
			recalcular_matriz(matriz_auxiliar, size, zn);
			aux=matriz[k][fila];

			for (int i = 0; i < size; ++i)
			{
				/*hace ceros (con operaciones elementales) los elementos
				que estan situados deajo de donde con anterioridad se ha hecho "1"
				en la diagonal principal.
				los elementos de arriba no los toma en cuenta (no los hace cero)*/
				recalcular_matriz(matriz, size, zn);
				recalcular_matriz(matriz_auxiliar, size, zn);
				matriz[k][i]=matriz[k][i]-(aux*matriz[fila][i]);
				matriz_auxiliar[k][i]=matriz_auxiliar[k][i]-(aux*matriz_auxiliar[fila][i]);

			}
		}
	}

	/*se hace cero por arriba de la diagonal principal usando
	los unos de la propia diagonal*/
	for (int columna = size-1; columna > 0; --columna)
	{
		for (int fila = columna-1; fila >= 0; --fila)
		{
			recalcular_matriz(matriz, size, zn);
			aux=matriz[fila][columna];
			for (int i = 0; i < size; ++i)
			{
				recalcular_matriz(matriz, size, zn);
				recalcular_matriz(matriz_auxiliar, size, zn);
				matriz[fila][i]=matriz[fila][i]-(aux*matriz[columna][i]);
				matriz_auxiliar[fila][i]=matriz_auxiliar[fila][i]-(aux*matriz_auxiliar[columna][i]);
			}
		}
	}

	/*asigna los valores de la matriz auxiliar a la principal, haciendo que
	la propia matriz principal, la cual es pasada a la funcion sea la inversa
	de la original*/
	recalcular_matriz(matriz, size, zn);
	recalcular_matriz(matriz_auxiliar, size, zn);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matriz[i][j]=matriz_auxiliar[i][j];
		}
	}
	liberar_matriz(&matriz_auxiliar, size);
	
	return 0;
}