#Fichero: makefile


#construlle el ejecutable encriptacion.out

encryption.out: lib_encriptacion.a main.c
	gcc -o ../encriptacion.out main.c lib_encriptacion.a -lm



#creacion de librerias

lib_encriptacion.a: ./encriptacion/encriptador.o ./encriptacion/decript.o ./encriptacion/generador_de_clave_de_encriptacion.o ./encriptacion/inversor_de_clave_de_encriptacion.o ./auxiliares/funciones_auxiliares.o ./lectura_imagenes/leer_imagenes_pgm.o
	ar -rsv lib_encriptacion.a ./encriptacion/encriptador.o ./encriptacion/decript.o ./encriptacion/generador_de_clave_de_encriptacion.o ./encriptacion/inversor_de_clave_de_encriptacion.o ./auxiliares/funciones_auxiliares.o ./lectura_imagenes/leer_imagenes_pgm.o



#creacion de .o


#encriptacion

./encriptacion/encriptador.o:  ./encriptacion/encriptador.c

	gcc -c -o ./encriptacion/encriptador.o ./encriptacion/encriptador.c

./encriptacion/decript.o:  ./encriptacion/decript.c
	gcc -c -o ./encriptacion/decript.o ./encriptacion/decript.c

./encriptacion/generador_de_clave_de_encriptacion.o:  ./encriptacion/generador_de_clave_de_encriptacion.c
	gcc -c -o ./encriptacion/generador_de_clave_de_encriptacion.o ./encriptacion/generador_de_clave_de_encriptacion.c

./encriptacion/inversor_de_clave_de_encriptacion.o:  ./encriptacion/inversor_de_clave_de_encriptacion.c
	gcc -c -o ./encriptacion/inversor_de_clave_de_encriptacion.o ./encriptacion/inversor_de_clave_de_encriptacion.c
 

 #auxiliares

./auxiliares/funciones_auxiliares.o: ./auxiliares/funciones_auxiliares.c
	gcc -c -o ./auxiliares/funciones_auxiliares.o ./auxiliares/funciones_auxiliares.c


#lectura de imagenes

./lectura_imagenes/leer_imagenes_pgm.o: ./lectura_imagenes/leer_imagenes_pgm.c
	gcc -c -o ./lectura_imagenes/leer_imagenes_pgm.o ./lectura_imagenes/leer_imagenes_pgm.c




clear:
	@echo borrando ficheros ".o" ...
	@rm -rf *.o