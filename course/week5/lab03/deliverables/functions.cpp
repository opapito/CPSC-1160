
#include <iostream>
#include <cmath>
#include "functions.h"


double *maximum_value(double *vals, size_t n){
  double max{0};
  size_t maxInd{0};

  for (size_t i = 0; i < n; i++){
    if (vals[i] > max){
      max = vals[i];
      maxInd = i;
    }
  }
return &vals[maxInd];
}

double mean (double *vals, size_t n){
  int count{0};
  double sum{0};
  for (size_t i = 0; i < n; i++){
    if (!std::isnan(vals[i])){
      sum+=vals[i];
      std::cout << "Index " << i << " Value=" << vals[i] << std::endl;
      count++;
    }
  }
std::cout << "The mean is "<< sum/count << std::endl;
return 0;
}