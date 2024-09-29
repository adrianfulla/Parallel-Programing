cmake_minimum_required(VERSION 3.29)
project(Parallel_Programing C)

set(CMAKE_C_STANDARD 11)
find_package(MPI REQUIRED C)

#add_executable(Parallel_Programing
#    mpi_hello.c
#    mpi_hello2.c
#    mpi_hello3.c)

add_executable(mpi_hello mpi_hello.c)
add_executable(mpi_hello2 mpi_hello2.c)
add_executable(mpi_hello3 mpi_hello3.c)

#target_link_libraries(Parallel_Programing PRIVATE MPI::MPI_C)
target_link_libraries(mpi_hello PRIVATE MPI::MPI_C)
target_link_libraries(mpi_hello2 PRIVATE MPI::MPI_C)
target_link_libraries(mpi_hello3 PRIVATE MPI::MPI_C)


set(PROC 4 CACHE STRING "Cantidad de procesos para ejecutar MPI")
message(STATUS "Número de procesos: ${PROC}")

add_custom_target(run_hello
        COMMAND mpirun -np ${PROC} ./mpi_hello
        DEPENDS mpi_hello
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Ejecutando mpi_hello con ${PROC} procesos")

add_custom_target(run_hello2
        COMMAND mpirun -np ${PROC} ./mpi_hello2
        DEPENDS mpi_hello2
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Ejecutando mpi_hello2 con ${PROC} procesos")

add_custom_target(run_hello3
        COMMAND mpirun -np ${PROC} ./mpi_hello3
        DEPENDS mpi_hello3
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Ejecutando mpi_hello3 con ${PROC} procesos")