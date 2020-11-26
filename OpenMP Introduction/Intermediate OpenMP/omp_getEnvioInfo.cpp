/******************************************************************************
* FILE: omp_getEnvInfo.c
* DESCRIPTION:
*   OpenMP Example - Get Environment Information - C/C++ Version
*   The master thread queries and prints selected environment information.
* AUTHOR: Blaise Barney  7/06
* LAST REVISED: 05/18/16
******************************************************************************/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main () {
    int nthreads, tid, procs, maxt, inpar, dynamic, nested;

    /* Start parallel region */
    #pragma omp parallel private(nthreads, tid)
    {

        /* Obtain thread number */
        tid = omp_get_thread_num();

        #pragma parallel for
        for(int i = 0;i<50;i++){
            printf(" Thread: = %d\n", tid);
        }

        /* Only master thread does this */
        if (tid == 0) 
        {
            printf("Thread %d getting environment info...\n", tid);

            /* Get environment information */
            procs = omp_get_num_procs();
            nthreads = omp_get_num_threads();
            inpar = omp_in_parallel();
            maxt = omp_get_max_threads();
            dynamic = omp_get_dynamic();
            nested = omp_get_nested();

            /* Print environment information */
            printf("Number of processors = %d\n", procs);
            printf("Number of threads = %d\n", nthreads);
            printf("Max threads = %d\n", maxt);
            printf("In parallel? = %d\n", inpar);
            printf("Dynamic threads enabled? = %d\n", dynamic);
            printf("Nested parallelism enabled? = %d\n", nested);

        }

    }  /* Done */

    return 0;

}
