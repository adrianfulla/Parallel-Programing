/*
Universidad del Valle de Guatemala
    Departamento de Ciencias de la Computacion
    Programacion Paralela y Distribuida
    Hoja de Trabajo 2


    Adrian Fulladolsa Palma - 21592
    - mpi_hello2.c
*/

#include <mpi.h> // OpenMPI
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    int world_size, world_rank;
    char message[100]; // Tamaño de mensajes enviados desde el proceso actual hacia el proceso 0

    // Inicialización de OpenMPI obteniendo los argumentos pasados desde línea de comando
    MPI_Init(&argc, &argv);

    // Creación del comunicador global indicando la cantidad de procesos a generar
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Determinación del rank que tiene el proceso dentro del comunicador
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Separación de procesos entre el proceso 0 y el resto
    if (world_rank == 0) { // Si es el proceso 0 se mostrara el mensaje que fue obtenido por este proceso
        for (int i = 1; i < world_size; i++) { // Se realiza la espera de mensaje para cada uno de los procesos generados menos 1
            MPI_Recv(message, 100, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Process 0 received message: %s\n", message);
        }
    } else { // Si no es el proceso 0 se gestionará el envio de mensaje desde el proceso actual hacia el proceso 0
        sprintf(message, "Hello from process %d", world_rank);
        printf("Process %d sending message to process 0\n", world_rank);
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }

    // Una vez todos los procesos hayan enviado el mensaje y el proceso 0 los haya mostrado en pantalla se cierra el OpenMPI
    MPI_Finalize();

    // Fin de programa
    return 0;
}
