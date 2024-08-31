# Laboratorio 2 - Programación Paralela y Distribuida


## Instrucciones de compilación

### Requisitos
- Linux
- C
- OpenMP
- Git 

### Clonación de repositorio
El primer paso es clonar el repositorio:
```bash
git clone https://github.com/adrianfulla/Parallel-Programing.git 
```
Luego navegar a el:
```bash
cd Parallel-Programing/
```

Y por ultimo cambiar a la branch del Lab2:
```bash
git switch Lab2
```

Terminados estos comandos se debe poder visualizar todos los archivos encontrados en esta branch del repositorio.

### Compilación y ejecución de programas
Para la compilación y ejecución de los programas de debe estar dentro del directorio de esta branch del repositorio.

#### Ejercicio 1
Compilación
```bash
gcc -o lab2-ej1 lab2-ej1.c
```

Ejecución
```bash
./lab2-ej1 <Numeros a crear aleatoriamente>
```

Ejemplos:
```bash
./lab2-ej1 100
```
```bash
./lab2-ej1 10000
```

#### Ejercicio 2 - version 1
Compilación
```bash
gcc -fopenmp -o lab2-ej2-v1 lab2-ej2-v1.c
```

Ejecución
```bash
./lab2-ej2-v1 <Numeros a crear aleatoriamente>
```

Ejemplos:
```bash
./lab2-ej2-v1 100
```
```bash
./lab2-ej2-v1 10000
```

#### Ejercicio 2 - version 2
Compilación
```bash
gcc -fopenmp -o lab2-ej2-v2 lab2-ej2-v2.c
```

Ejecución
```bash
./lab2-ej2-v2 <Numeros a crear aleatoriamente>
```

Ejemplos:
```bash
./lab2-ej2-v2 100
```
```bash
./lab2-ej2-v2 10000
```

#### Ejercicio 2 - version 3
Compilación
```bash
gcc -fopenmp -o lab2-ej2-v3 lab2-ej2-v3.c
```

Ejecución
```bash
./lab2-ej2-v3 <Numeros a crear aleatoriamente>
```

Ejemplos:
```bash
./lab2-ej2-v3 100
```
```bash
./lab2-ej2-v3 10000
```