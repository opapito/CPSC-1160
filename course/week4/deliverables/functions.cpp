#include "functions.h"

int factorial (int n){
  int a = 1;
  for (size_t i = 1; i <= n; i++){
    a *= i;
  }  
  return a;
}
