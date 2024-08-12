/*
    Universidad del Valle de Guatemala
    Departamento de Ciencias de la Computacion
    Programacion Paralela y Distribuida
    Hoja de Trabajo 1


    Adrian Fulladolsa Palma - 21592
    - remann_omp2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

// Funciones posibles para la suma del trapezoide
double funcion(double x, int choice) {
    switch(choice) {
        case 1: // x^2
            return x * x;
        case 2: // 2x^3
            return 2 * x * x * x;
        case 3: // sin(x)
            return sin(x);
        default:
            return 0.0;
    }
}

// Funcion de trapezoide paralela
double trapezoides(double a, double b, int n, int choice) {
    // Creacion de variables locales
    double h = (b - a) / n;
    double local_sum = 0.0;
    int tid = omp_get_thread_num();
    int num_threads = omp_get_num_threads();
    int n_local = n / num_threads;
    double a_local = a + tid * n_local * h;
    double b_local = a_local + n_local * h;

    // Suma local del hilo
    local_sum += 0.5 * (funcion(a_local, choice) + funcion(b_local, choice));
    for (int i = 1; i < n_local; i++) {
        local_sum += funcion(a_local + i * h, choice);
    }

    return h * local_sum;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("No se pasaron suficientes parametros\n");
        return 1;
    }

     // Obtencion de parametros pasados por usuario
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    int n = atoi(argv[3]);
    int choice = atoi(argv[4]);

    int threads = n/10;
    if (threads == 0 ){
        threads = 1;
    }

    // Inicializacion de los hilos
    omp_set_num_threads(threads);
    double global_sum = 0.0;

    #pragma omp parallel
    {
        double local_result = trapezoides(a, b, n, choice);
        // Seccion critica de la ejecucion del hilo
        #pragma omp critical
        {
            global_sum += local_result;     // Suma a la variable global
        }
    }

    printf("Con n=%d trapezoides y %d threads, nuestra aproximación de la integral de %f a %f es = %.10f\n", n, threads, a, b, global_sum);

    return 0;
}
