#ifndef _FUNCIONES_AUXILIARES_
#define _FUNCIONES_AUXILIARES_

#define VALOR_DE_RELLENO '!'
#define VALOR_RELLENO_BUFFER '<'

/*
reserva dinamicamente una matriz cuadrada de orden n inicializada en 0
*/
int **reservar_matriz(int size);

/*
rellena una matriz cuadada con valores introdicidos por teclado
*/
void introducir_matriz(int **matriz, int size);

/*
libera una matriz cuadrada reservada de forma dimanica
*/
void liberar_matriz(int ***matriz, int size);

/*
imprime una matriz cuadrada
*/
void imprimir_matriz(int **matriz, int size);

/*
recalcula una matriz cuadrada para que no exista ningun valor megativo ni superior
al modulo en el que se esta trabajando: "Zn"
*/
void recalcular_matriz(int **matriz, int size, int zn);

/*
crea un nuevo numero pseudoaleatorio a aprtir
de el ultimo numero pseudoaleatorio
retorna el nuevo numero
prng(Pseudo Random Number Generator)
*/
int prng(int val);

/*
redefine el alfabeto para encritacion (en numeros)
*/
int define_abecedario(char c);

/*
redefine el alfabeto para ecritura en fichero
*/
char redefine_abecedario(int c);
#endif