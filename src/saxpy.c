#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>

void fill_array(float *array, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        array[i] = rand() % 255;
}

void print_array(float *array, int n) {
    for (int i = 0; i <n; i++)
        printf("elemento %i valor: %f\n", i, array[i]);
}

int main() {
    int n = 100000000; //cantidad de elementos en los arreglos
    float a;
    float *x = malloc(sizeof(float)*n);
    float *y = malloc(sizeof(float)*n);;
    double start_time, run_time;

    fill_array(x, n);
    fill_array(y, n);

	start_time = omp_get_wtime();

    for (int i = 0; i < n; ++i)
        y[i] = a*x[i] + y[i];
    
    run_time = omp_get_wtime() - start_time;    

    printf("tiempo en segundos %f\n", run_time );

    return 0;
}