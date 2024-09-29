# Hoja de trabajo 2 - Computación Paralela y Distribuida
## Adrian Fulladolsa

### Requisitos
- C
- OpenMPI
- CMake

### Compilacion
Con el proposito de simplificar el proceso de compilacion de los programas se
incluye el archivo CMakeLists.txt, utilizando la herramienta CMake se pueden 
compilar los programas y crear objetivos para make de forma que se simplifica
tambien la ejecución de estos programas.

Para compilar los programas se debe ejecutar las siguientes líneas:
```bash
cmake -S . -B build
cmake --build build
```

Esto ejecutara CMake sobre el CMakeLists.txt y creara un directorio builds 
que contiene el Makefile, los tres programas generados y los archivos necesarios 
para ejecutar los. No es necesario entrar a este directorio para ejecutarlos ya
que se crearon los objetivos se puede utilizar `cmake` para correrlos:

### Ejecución de programas
Ejecución de programa creado para mpi_hello.c
```bash
cmake --build build --target run_hello
```

Ejecución de programa creado para mpi_hello2.c
```bash
cmake --build build --target run_hello2
```

Ejecución de programa creado para mpi_hello3.c
```bash
cmake --build build --target run_hello3
```

Cada uno de estos programas se inicializara con 4 procesos, si se desea modificar este valor
se puede realizar utilizando este comando:
```bash
cmake -S . -B build -DPROC=<procesos>
```

Alternativamente se pueden ejecutar cada programa individualmente sin utilizar cmake con el siguiente comando:
```bash
mpirun -np <procesos> ./build/mpi_hello
```
Siempre se sugiere utilizar CMake para compilar los programas.