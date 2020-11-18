/*
* Three functions necessary to perform a hybrid sort. Selection sort is called when the threshold is reached.
* Hybrid_sort perform a merge sort until the threshold is reached,then calls selection sort to perform the rest of sorting.
* Merge is called at the end to merge all remaning ordered arrays in a big ordered one.
* 
*Author: Pablo Bourbom Soares
* 
*/
#include <iostream>
#include "functions.h"
#define THRESHOLD 625 

/*
The function selection_sort implements the a recursive selection sort algorithm in the pointed [*array] of size [n].
The function is only called when the array size is bellow the threshold
*/
static void selection_sort(long *array, size_t n){
  if (n == 0){
   return;
  }
  long *smallest = &array[0];
  for (size_t i = 0; i < n; i++){
    if (array[i] < *smallest){
      smallest = &array[i];
    }
  }
  long temp = *smallest;
  *smallest = array[0];
  array[0] = temp;
  selection_sort(&array[1], n - 1);
}

/*
The function merge implements an algorithm that merges two pointed [*l] and [*r] of size ln and rn.
The function is only called when both arrays are already sorted
*/
static void merge(long const *l, size_t ln, long const *r, size_t rn, long *x){
  for (size_t left_i = 0, right_i = 0; left_i < ln || right_i < rn; x++){
    if (left_i >= ln){
      *x = r[right_i++];
    }           
    else if (right_i >= rn){
      *x = l[left_i++]; 
    }
    else if (l[left_i] < r[right_i])
      *x = l[left_i++];
    else
      *x = r[right_i++];
  }
    
}
/*
Function hybrid_sort implements a recursive hybrid sort algorithm in the pointed [*array] of size [n] 
starting with merge sort and goes on until the size of the array
is bellow the threshold, then the function selection sort is called to finish the sorting process.
*/
void hybrid_sort(long *xs, size_t n){
  using namespace std;
  if (n <= 1){
   return;
  }
  
  if (n <= THRESHOLD){
    selection_sort(xs, n);
    return;
  }
  
  size_t const midpoint = n / 2;
  size_t const left_n = midpoint;
  size_t const  right_n = n - midpoint;
  long left[left_n];
  long right[right_n];
  for (size_t i = 0; i < left_n; i++ ){
    left[i] = xs[i];
  }
  for (size_t i = 0; i < right_n; i++){
    right[i] = xs [i + left_n];
  }
  hybrid_sort(left, left_n);
  hybrid_sort(right, right_n);
  merge(left, left_n, right, right_n, xs);
}
