/*
*The two functions to called by the main program.
* The maximum_value function returns a pointer to de largest element of an array
* The mean function determines the mean of the NOT NaN elements of an array
*
*Author: Pablo Bourbom Soares
* 
*/

#include <iostream>
#include <cmath>
#include "functions.h"


double *maximum_value(double *vals, size_t arr_size){
  double max{0};
  size_t maxInd{0};

  for (size_t i = 0; i < arr_size; i++){
    if (vals[i] > max){
      max = vals[i];
      maxInd = i;
    }
  }
return &vals[maxInd];
}

double mean (double *vals, size_t scope){
  double sum{0};
  int count{0};
  for (size_t i = 0; i < scope; i++){
    if (!std::isnan(vals[i])){
      sum += vals[i];
      count++;
    }
  }

return (count == 0 ? 0 : sum/count); // Preventing division by zero;
}