//
// Created by Galaga on 29/09/24.
//
// mpi_hello.c
#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int world_size, world_rank;

    // Inicializa el entorno MPI
    MPI_Init(&argc, &argv);

    // Obtén el número total de procesos
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Obtén el rango (id) del proceso actual
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Imprime el mensaje desde cada proceso
    printf("Hello World, I'm process %d of %d!\n", world_rank, world_size);

    // Finaliza MPI
    MPI_Finalize();

    return 0;
}
