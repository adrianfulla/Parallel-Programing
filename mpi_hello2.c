//
// Created by Galaga on 29/09/24.
//
// mpi_hello2.c
#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    int world_size, world_rank;
    char message[100];

    // Inicializa el entorno MPI
    MPI_Init(&argc, &argv);

    // Obtén el número total de procesos
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Obtén el rango (id) del proceso actual
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if (world_rank == 0) {
        // Proceso 0: recibe mensajes de todos los demás
        for (int i = 1; i < world_size; i++) {
            MPI_Recv(message, 100, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Process 0 received message: %s\n", message);
        }
    } else {
        // Otros procesos: envían un mensaje al proceso 0
        sprintf(message, "Hello from process %d", world_rank);
        printf("Process %d sending message to process 0\n", world_rank);
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }

    // Finaliza MPI
    MPI_Finalize();

    return 0;
}
