/*
    Universidad del Valle de Guatemala
    Departamento de Ciencias de la Computacion
    Programacion Paralela y Distribuida
    Hoja de Trabajo 1


    Adrian Fulladolsa Palma - 21592
    - riemann_omp_nocrit.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

// Funciones posibles para la suma de trapezoides
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

    if (n < threads) {
        fprintf(stderr, "El número de trapezoides debe ser mayor o igual al número de threads.\n");
        return 1;
    }

    // Inicializacion de los hilos

    omp_set_num_threads(threads);
    double *results = malloc(threads * sizeof(double));  

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        double local_result = trapezoides(a, b, n, choice);
        // Se obtiene el resultado local y se agrega al indice en el arreglo de resultados
        results[tid] = local_result;                       
    }


    // Sumatoria de valores en el arreglo
    double global_sum = 0.0;
    for (int i = 0; i < threads; i++) {
        global_sum += results[i];
    }

    printf("Con n=%d trapezoides y %d threads, nuestra aproximación de la integral de %f a %f es = %.10f\n", n, threads, a, b, global_sum);

    free(results);
    return 0;
}
