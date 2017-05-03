#ifndef _GENERADOR_DE_CLAVE_DE_ENCRIPTACION_
#define _GENERADOR_DE_CLAVE_DE_ENCRIPTACION_

/*
pasadas a las permutaciones de la contraseña
en la tercera pasada
*/
#define PASADAS 20 


int **creacion_clave(char *clave, int zn, int lvl_seguridad, int pasada);

#endif