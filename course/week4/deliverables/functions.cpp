/*
*The two functions to called by the main program.
* The factorial function returns the factorial of a positive integer
* The probability function returns a probability of a n number to a given k number
*
*Author: Pablo Bourbom Soares
* 
*/

#include <cmath>
#include "functions.h"

int factorial (int n){
  int a = 1;
  for (size_t i = 1; i <= (unsigned) n; i++){
    a *= i;
  }  
  return a;
}

double probability (int k, int n){
  return (1 - factorial(k)/(pow(k, n) * factorial(k - n))) * 100;
}