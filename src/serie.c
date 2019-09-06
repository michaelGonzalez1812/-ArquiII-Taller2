#include <math.h>
#include <stdio.h>
#include <omp.h>

int main() {

    long int n = 200000000; //numero de interaciones
    double s = 0;
    double start_time, run_time;
    
    start_time = omp_get_wtime();
    for(long int i = 0; i < n; i++) 
        s += pow(-1, n)/(n+1);
    run_time = omp_get_wtime() - start_time;    
    
    printf("aproximación %f en %f segundos con %i iteraciones\n", s, run_time, n);
    return 0;
}