#ifndef _ENCRIPTACION_
#define _ENCRIPTACION_


int encriptar(char *data_file , char *user_key ,int zn, int lvl_seguridad);
void multiplicar(int **clave, int vector[], int size, int zn);
void imprimir_vector(int vector[], int size);
#endif