algoritmos: src/saxpy.c src/saxpy_par.c \
			src/serie.c src/serie_par.c

	gcc -o bin/saxpy src/saxpy.c -fopenmp -lm
	gcc -o bin/saxpy_par src/saxpy_par.c -fopenmp -lm
	gcc -o bin/serie src/serie.c -fopenmp -lm
	gcc -o bin/serie_par src/serie_par.c -fopenmp -lm