/*
    Universidad del Valle de Guatemala
    Departamento de Ciencias de la Computacion
    Programacion Paralela y Distribuida
    Hoja de Trabajo 1


    Adrian Fulladolsa Palma - 21592
    - riemann.c
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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

// Funcion de trapezoide
double trapezoides(double a, double b, int n, int choice) {
    double h = (b - a) / n;                                         // Segmento
    double sum = 0.5 * (funcion(a, choice) + funcion(b, choice));   // Suma inicial
    for (int i = 1; i < n; i++) {                                   //Sumatoria para el tramo n
        sum += funcion(a + i * h, choice);
    }
    return h * sum; 
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

    double result = trapezoides(a, b, n, choice);
    printf("Con n=%d trapezoides, nuestra aproximación de la integral de %f a %f es = %.10f\n", n, a, b, result);

    return 0;
}
