/*
    Universidad del Valle de Guatemala
    Departamento de Ciencias de la Computacion
    Programacion Paralela y Distribuida
    Hoja de Trabajo 1


    Adrian Fulladolsa Palma - 21592
    - hbd_omp.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    int num_threads = 10; 
    if (argc > 1) {
        num_threads = atoi(argv[1]);
    }

    // Inicializacion de hilos de OpenMP igual valor pasado como parametro por el usuario
    omp_set_num_threads(num_threads);

    #pragma omp parallel
    {
        // Obtencion de los valores del hilo
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();
        if (thread_id % 2 == 0) {
            printf("Saludos del hilo %d\n", thread_id); // Impresion de saludo si el hilo es par
        } else {
            printf("Feliz cumpleaños número %d!\n", total_threads); // Impresion de felicidades si hilo es impar
        }
    }
    return 0;
}
