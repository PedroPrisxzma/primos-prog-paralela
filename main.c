#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliar.h"
#include "seq.h"
#include "parallel.h"

int main(int argc, char *argv[]){
  // Argv parameters
  int n, p;
  char *exit_type;
  exit_type = (char*)calloc(4,sizeof(char));

  // Receives the sequential answer
  Number* nums_list;

  n = atoi(argv[1]); // List superior limit
  p = atoi(argv[2]); // Number of threads
  strcpy(exit_type, argv[3]); // Type of output to use, either 'list', 'all' or 'time'

  // Calls the sequential solution
  nums_list = sequential(n);

  printf("%d\n", nums_list[0].value);
  printf("%d, %d, %s, %d, %d\n", n, p, exit_type, argc, 10/3);

  free(exit_type);
  return 0;
}
