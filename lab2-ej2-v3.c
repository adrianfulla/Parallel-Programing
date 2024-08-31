#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>


#define INFILE "ej2-csvs/random_numbers.csv"
#define OUTFILE "ej2-csvs/sorted_numbers.csv"

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
void par_qsort(int *data, int lo, int hi)  
{
  if(lo > hi) return;
  int l = lo;
  int h = hi;
  int p = data[(hi + lo)/2];

  while(l <= h){
    while((data[l] - p) < 0) l++;
    while((data[h] - p) > 0) h--;
    if(l<=h){
      //swap
      int tmp = data[l];
      data[l] = data[h];
      data[h] = tmp;
      l++; h--;
    }
  }
  //recursive call
  #pragma omp task shared(data) if(h-lo > 1000)
  par_qsort(data, lo, h);

  #pragma omp task shared(data) if(hi-l > 1000)   
  par_qsort(data, l, hi);

  #pragma omp taskwait
}

int main(int argc, char *argv[]) {
    time_t start_time, end_time;
    double total_time;
    if (argc != 2) {
        printf("Utilizacion: %s N\n", argv[0]);
        return 1;
    }

    time(&start_time);

    int N = atoi(argv[1]);
    if (N <= 0) {
        printf("El numero de elementos debe ser positivo.\n");
        return 1;
    }

    int *numbers = (int *)malloc(N * sizeof(int));
    if (numbers == NULL) {
        perror("Fallo para alocar memoria");
        return 1;
    }

    srand(time(NULL));
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        numbers[i] = rand() % 1000 + 1;
    }

    FILE *infile = fopen(INFILE, "w");
    if (infile == NULL) {
        printf("Falló la creación del archivo %s",INFILE);
        free(numbers);
        return 1;
    }

    long chunk_size = N / omp_get_max_threads();
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        long start_index = tid * chunk_size;
        long end_index = (tid == omp_get_max_threads() - 1) ? N : start_index + chunk_size;

        fseek(infile, start_index * 5, SEEK_SET);

        for (long i = start_index; i < end_index; i++) {
            if (i < N - 1) {
                fprintf(infile, "%d,", numbers[i]);
            } else {
                fprintf(infile, "%d", numbers[i]);
            }
        }
    }
    fclose(infile);



    infile = fopen(INFILE, "r");
    if (infile == NULL) {
        perror("Fallo la lectura del archivo de entrada");
        free(numbers);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        fscanf(infile, "%d,", &numbers[i]);
    }
    fclose(infile);


    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            par_qsort(numbers, 0, N - 1);
        }
    }
    
    
    FILE *outfile = fopen(OUTFILE, "w");
    if (outfile == NULL) {
        perror("Fallo al crear el archivo de salida");
        free(numbers);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        fprintf(outfile, "%d", numbers[i]);
        if (i < N - 1) {
            fprintf(outfile, ",");
        }
    }
    fclose(outfile);

    free(numbers);

    time(&end_time);

    total_time = difftime(end_time, start_time);

    printf("Sorteo completado. Revise %s para ver los numeros sorteados. Tomo %f segundos completar\n", OUTFILE, total_time);
    return 0;
}

