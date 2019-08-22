#include <stdio.h>
#include <stdlib.h>
#include "seq.h"
#include "aux.h"

// The non parallel algorithm
int *sequential(int n){
  int *nums_array = (int*) calloc(n+1, sizeof(int));// List goes from 2 to n

  for(int i = 2; i <= (n+1)/2; i++){ // Any number over half is already correctly marked, hence (n+1)/2
    if(nums_array[i] == 0){ // i is the prime numeber being looked at
      mark_primes(n, i, nums_array);
    }
  }
  return(nums_array);
}
