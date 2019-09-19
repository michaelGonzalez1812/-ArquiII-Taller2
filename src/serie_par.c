#include <math.h>
#include <stdio.h>
#include <omp.h>

int main() {

    long int n = 100000000; //numero de interaciones
    double s = 0;
    double start_time, run_time;
    
    int nprocs = 4*omp_get_num_procs();

    for(int j = 1; j < nprocs; j++) {
        start_time = omp_get_wtime();
        omp_set_num_threads(j);
        s = 0;
        #pragma omp parallel for reduction(+:s)
        for(long int i = 0; i < n; i++) 
            s = s + pow((double)(-1), (double)i)/((double)i+(double)1);
    
        run_time = omp_get_wtime() - start_time;    
        
        printf("aproximación %f en %f segundos con %i iteraciones y %i hilos\n", s, run_time, n, j);
    }

    return 0;
}