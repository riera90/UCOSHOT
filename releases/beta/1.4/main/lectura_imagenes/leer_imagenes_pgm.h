#ifndef _LEER_IMAGENES_PGM_
#define _LEER_IMAGENES_PGM_


void leer_imagen_pgm(char* file,
					char** header,
					char** buffer,
					int* tam_header,
					int* tam_buffer);

void leer_imagen_pgm_encriptada(char* file,
					char** header,
					int** buffer,
					int* tam_header,
					int* tam_buffer);

#endif