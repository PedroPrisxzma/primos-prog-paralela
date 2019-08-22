#include <stdio.h>
#include <stdlib.h>
#include "aux.h"

// Marks all prime numbers in the array
void mark_primes(int n, int current_prime, int* nums_array){
  int aux;
  for(int i = 2; i <= (n)/current_prime; i++){
    // Find a multiple inside the array
    aux = i * current_prime;

    // Makes sure no values over n are marked causing an error
    if(aux <= n){
      // Mark the multiple as a non prime number
      nums_array[aux] = -1;
    }
    else{
      break;
    }
  }
}
