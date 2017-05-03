#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "funciones_auxiliares.h"


/*
reserva dinamicamente una matriz cuadrada de orden n inicializada en 0
*/
int **reservar_matriz(int size)
{
	int **matriz;
	matriz=(int**)calloc(size,sizeof(int*));
	for (int i = 0; i < size; ++i)
	{
		matriz[i]=(int*)calloc(size,sizeof(int));
	}
	return matriz;
}

/*
rellena una matriz cuadada con valores introdicidos por teclado
funcion de  debugging
*/
void introducir_matriz(int **matriz, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf("%d",&matriz[i][j]);
		}
	}
	printf("\n");
}

/*
imprime una matriz cuadrada
*/
void imprimir_matriz(int **matriz, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			printf("%d, ",matriz[i][j]);
		}
	printf("\n");
	}
	printf("\n");
}

/*
recalcula una matriz cuadrada para que no exista ningun valor megativo ni superior
al modulo en el que se esta trabajando: "Zn"
*/
void recalcular_matriz(int **matriz, int size, int zn)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matriz[i][j]=matriz[i][j]%zn;
			if (matriz[i][j]<0)
			{
				matriz[i][j]=matriz[i][j]+zn;
			}
		}
	}
}

/*
libera una matriz cuadrada reservada de forma dimanica
*/
void liberar_matriz(int ***matriz, int size)
{
	for (int i = 0; i < size; ++i)
	{
		free((*matriz)[i]);
	}
	free(*matriz);
	*matriz=NULL;


}

/*
crea un nuevo numero pseudoaleatorio a aprtir
de el ultimo numero pseudoaleatorio
retorna el nuevo numero
prng(Pseudo Random Number Generator)
*/
int prng(int val)
{
	val=( ((69069*val)+1) % (int)(pow(2,32)) );
	return val;
}

/*
redefine el alfabeto para encritacion (en numeros)
*/
int define_abecedario(char c)
{
	switch (c)
	{
		case '0':
			return 0;
			break;

		case '1':
			return 1;
			break;

		case '2':
			return 2;
			break;

		case '3':
			return 3;
			break;

		case '4':
			return 4;
			break;

		case '5':
			return 5;
			break;

		case '6':
			return 6;
			break;

		case '7':
			return 7;
			break;

		case '8':
			return 8;
			break;

		case '9':
			return 9;
			break;

		case 'a':
			return 10;
			break;

		case 'b':
			return 11;
			break;

		case 'c':
			return 12;
			break;

		case 'd':
			return 13;
			break;
		
		case 'e':
			return 14;
			break;

		case 'f':
			return 15;
			break;

		case 'g':
			return 16;
			break;

		case 'h':
			return 17;
			break;

		case 'i':
			return 18;
			break;

		case 'j':
			return 19;
			break;

		case 'k':
			return 20;
			break;

		case 'l':
			return 21;
			break;

		case 'm':
			return 22;
			break;

		case 'n':
			return 23;
			break;

		case 'o':
			return 24;
			break;

		case 'p':
			return 25;
			break;

		case 'q':
			return 26;
			break;

		case 'r':
			return 27;
			break;

		case 's':
			return 28;
			break;
		
		case 't':
			return 29;
			break;

		case 'u':
			return 30;
			break;

		case 'v':
			return 31;
			break;

		case 'w':
			return 32;
			break;

		case 'x':
			return 33;
			break;

		case 'y':
			return 34;
			break;

		case 'z':
			return 35;
			break;

		case 'A':
			return 36;
			break;

		case 'B':
			return 37;
			break;

		case 'C':
			return 38;
			break;

		case 'D':
			return 39;
			break;
		
		case 'E':
			return 40;
			break;

		case 'F':
			return 41;
			break;

		case 'G':
			return 42;
			break;

		case 'H':
			return 43;
			break;

		case 'I':
			return 44;
			break;

		case 'J':
			return 45;
			break;

		case 'K':
			return 46;
			break;

		case 'L':
			return 47;
			break;

		case 'M':
			return 48;
			break;

		case 'N':
			return 49;
			break;

		case 'O':
			return 50;
			break;

		case 'P':
			return 51;
			break;

		case 'Q':
			return 52;
			break;

		case 'R':
			return 53;
			break;

		case 'S':
			return 54;
			break;
		
		case 'T':
			return 55;
			break;

		case 'U':
			return 56;
			break;

		case 'V':
			return 57;
			break;

		case 'W':
			return 58;
			break;

		case 'X':
			return 59;
			break;

		case 'Y':
			return 60;
			break;

		case 'Z':
			return 61;
			break;

		case ' '://space
			return 62;
			break;

		case ':':
			return 63;
			break;

		case ';':
			return 64;
			break;

		case '-':
			return 65;
			break;

		case '_':
			return 66;
			break;

		case '(':
			return 67;
			break;

		case ')':
			return 68;
			break;

		case '[':
			return 69;
			break;

		case ']':
			return 70;
			break;

		case '?':
			return 71;
			break;

		case '!':
			return 72;
			break;

		case '/':
			return 73;
			break;

		case '=':
			return 74;
			break;

		case '+':
			return 75;
			break;

		case ',':
			return 76;
			break;

		case '.':
			return 77;
			break;

		case '<':
			return 78;
	}
}
	
/*
redefine el alfabeto para ecritura en fichero
*/
char redefine_abecedario(int c)
{
	switch (c)
	{
		case 0:
			return '0';
			break;

		case 1:
			return '1';
			break;

		case 2:
			return '2';
			break;

		case 3:
			return '3';
			break;

		case 4:
			return '4';
			break;

		case 5:
			return '5';
			break;

		case 6:
			return '6';
			break;

		case 7:
			return '7';
			break;

		case 8:
			return '8';
			break;

		case 9:
			return '9';
			break;

		case 10:
			return 'a';
			break;

		case 11:
			return 'b';
			break;

		case 12:
			return 'c';
			break;

		case 13:
			return 'd';
			break;
		
		case 14:
			return 'e';
			break;

		case 15:
			return 'f';
			break;

		case 16:
			return 'g';
			break;

		case 17:
			return 'h';
			break;

		case 18:
			return 'i';
			break;

		case 19:
			return 'j';
			break;

		case 20:
			return 'k';
			break;

		case 21:
			return 'l';
			break;

		case 22:
			return 'm';
			break;

		case 23:
			return 'n';
			break;

		case 24:
			return 'o';
			break;

		case 25:
			return 'p';
			break;

		case 26:
			return 'q';
			break;

		case 27:
			return 'r';
			break;

		case 28:
			return 's';
			break;
		
		case 29:
			return 't';
			break;

		case 30:
			return 'u';
			break;

		case 31:
			return 'v';
			break;

		case 32:
			return 'w';
			break;

		case 33:
			return 'x';
			break;

		case 34:
			return 'y';
			break;

		case 35:
			return 'z';
			break;

		case 36:
			return 'A';
			break;

		case 37:
			return 'B';
			break;

		case 38:
			return 'C';
			break;

		case 39:
			return 'D';
			break;
		
		case 40:
			return 'E';
			break;

		case 41:
			return 'F';
			break;

		case 42:
			return 'G';
			break;

		case 43:
			return 'H';
			break;

		case 44:
			return 'I';
			break;

		case 45:
			return 'J';
			break;

		case 46:
			return 'K';
			break;

		case 47:
			return 'L';
			break;

		case 48:
			return 'M';
			break;

		case 49:
			return 'N';
			break;

		case 50:
			return 'O';
			break;

		case 51:
			return 'P';
			break;

		case 52:
			return 'Q';
			break;

		case 53:
			return 'R';
			break;

		case 54:
			return 'S';
			break;
		
		case 55:
			return 'T';
			break;

		case 56:
			return 'U';
			break;

		case 57:
			return 'V';
			break;

		case 58:
			return 'W';
			break;

		case 59:
			return 'X';
			break;

		case 60:
			return 'Y';
			break;

		case 61:
			return 'Z';
			break;

		case 62://space
			return ' ';
			break;

		case 63:
			return ':';
			break;

		case 64:
			return ';';
			break;

		case 65:
			return '-';
			break;

		case 66:
			return '_';
			break;

		case 67:
			return '(';
			break;

		case 68:
			return ')';
			break;

		case 69:
			return '[';
			break;

		case 70:
			return ']';
			break;

		case 71:
			return '?';
			break;

		case 72:
			return '!';
			break;

		case 73:
			return '/';
			break;

		case 74:
			return '=';
			break;

		case 75:
			return '+';
			break;

		case 76:
			return ',';
			break;

		case 77:
			return '.';
			break;

		case 78:
			return '<';
	}
}