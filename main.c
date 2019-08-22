#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>
#include "seq.h"
#include "parallel.h"

int main(int argc, char *argv[]){

  // check if all inputs are given
  if(argc != 4){
    printf("Argumentos insuficientes");
    return 0;
  }

  // Argv parameters
  int n, p;
  char *exit_type;
  exit_type = (char*)calloc(4,sizeof(char));

  // Time vars
  clock_t start_time, end_time;
  clock_t seq_time, par_time;

  // Receives the sequential answer
  int* seq_list;

  // Receives the parallel answer
  int* par_list;

  n = atoi(argv[1]); // List limit
  p = atoi(argv[2]); // Number of threads
  strcpy(exit_type, argv[3]); // Type of output to use, either 'list', 'all' or 'time'

  // Calls the sequential solution
  start_time = clock();
  seq_list = sequential(n);
  end_time = clock();
  seq_time = (end_time - start_time);

  // Calls the Parallel solution
  start_time = clock();
  par_list = parallel(n, p);
  end_time = clock();
  par_time = (end_time - start_time);


  if(strcmp(exit_type, "all") == 0){
    printf("sequential solution\n");
    for(int i = 2; i<=n;i++){
      if(seq_list[i] == 0){
        printf("%d ", i);
      }
    }
    printf("\n");
    printf("Seq Time:%.6lf\n", (double)seq_time/CLOCKS_PER_SEC);
    printf("\n");

    printf("Parallel solution\n");
    for(int i = 2; i<=n;i++){
      if(par_list[i] == 0){
        printf("%d ", i);
      }
    }
    printf("\n");
    printf("Par Time:%.6lf\n", (double)par_time/CLOCKS_PER_SEC);
    printf("\n");
  }

  free(seq_list);
  free(par_list);
  free(exit_type);
  return 0;
}
