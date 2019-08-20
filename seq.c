#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"
#include "seq.h"

// The non parallel algorithm
Number *sequential(int n){
  Number *nums_array = (Number*) calloc(n-1, sizeof(Number));// List goes from 2 to n

  // Building the list
  for(int i = 0; i < n-1; i++){
    nums_array[i].value = i+2;
    nums_array[i].prime = 0;
//  printf("%d, %d\n", nums_list[i].value, nums_list[i].prime);
  }

  int current_prime = 2; // The first prime number in a given array
  int start_index = 0; // The first prime index

  while(current_prime < n){
    printf("%d, %d\n", current_prime, n);
    mark_primes(n, current_prime, nums_array);
    current_prime = find_next_prime(n, nums_array, &start_index);
  }

  return(nums_array);
}

// Marks all prime numbers in the array
void mark_primes(int n, int current_prime, Number* nums_array){
  int aux;
  for(int i = 0; i < (n-1)/current_prime; i++){
    // Find a multiple inside the array
    aux = nums_array[i].value * current_prime;

    // Mark the multiple as a non prime number
    nums_array[aux-2].prime = -1;

    printf("value: %d, aux: %d, prime: %d\n",nums_array[i].value, aux, nums_array[i].prime);
  }
}

// Finds the next prime number, returns n+1 if no prime numbers are left
int find_next_prime(int n, Number* nums_array, int *index){
  printf("finding next prime\n%d, %d\n", index[0], n-1);
  for(int i = index[0]+1; i < n-1; i++){
    if(nums_array[i].prime == 0){
      return nums_array[i].value;
    }
  }
  return(n+1);
}
