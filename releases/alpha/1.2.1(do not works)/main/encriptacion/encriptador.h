#ifndef _ENCRIPTACION_
#define _ENCRIPTACION_


int encriptar(char *input_path,
				char *user_key,
				char* output_path,
				int zn,
				int lvl_seguridad);
void multiplicar(int **clave, int vector[], int size, int zn);
void imprimir_vector(int vector[], int size);
#endif