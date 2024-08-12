/*
    Universidad del Valle de Guatemala
    Departamento de Ciencias de la Computacion
    Programacion Paralela y Distribuida
    Hoja de Trabajo 1


    Adrian Fulladolsa Palma - 21592
    - hello_omp.c
*/


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    int num_threads = 10;  
    if (argc > 1) {
        num_threads = atoi(argv[1]);
    }

    // Inicializacion de threads iguales al numero pasado por el usuario

    omp_set_num_threads(num_threads);
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();

        printf("Hello from thread %d of %d!\n", thread_id, total_threads);
    }

    return 0;
}
