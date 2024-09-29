/*
Universidad del Valle de Guatemala
    Departamento de Ciencias de la Computacion
    Programacion Paralela y Distribuida
    Hoja de Trabajo 2


    Adrian Fulladolsa Palma - 21592
    - mpi_hello.c
*/

#include <mpi.h> // OpenMPI
#include <stdio.h>

int main(int argc, char** argv) {
    int world_size, world_rank;

    // Inicializacion de OpenMPI obteniendo los arguemntos que fueron pasados por la línea de comandos
    MPI_Init(&argc, &argv);

    // Creación del comunicador global indicando la cantidad de procesos a generar
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Determinación del rank que tiene el proceso dentro del comunicador
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Impresión del mensaje desde cada proceso
    printf("Hello World, I'm process %d of %d!\n", world_rank, world_size);

    // Finalización de OpenMPI
    MPI_Finalize();

    // Fin del programa
    return 0;
}
