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
    int n = 10000000; //cantidad de elementos en los arreglos
    int nprocs;
    float a;
    float *x = malloc(sizeof(float)*n);
    float *y = malloc(sizeof(float)*n);
    double start_time, run_time;

    fill_array(x, n);
    fill_array(y, n);

    nprocs=2*omp_get_num_procs();

    for (int i=1;i <= nprocs;i++){
        omp_set_num_threads(i);
        start_time = omp_get_wtime();

        #pragma omp parallel for
        for (int j = 0; j < n; j++)
            y[j] = a*x[j] + y[j];
        
        run_time = omp_get_wtime() - start_time;    

        printf("run time is %f seconds with %d threads\n", run_time, i);
    }

    return 0;
}