/*
A program find the largest value of n which will not overflow, considering types short, int, long and long long.
Pablo Bourbom Soares

In this approach, the function names were overloaded to allowing versions for all types: short, int, long and long long.

Also, the overflow is caught by the arithmetic formula ( a != 0 && x/a != i). The first condition prevents division by zero. The second checks the overflow.
If x = a * b, then x/a must be equal b, if not, an overflow occurred.
The types variables x, a and b must be the same type of the funcion which limit is being tested.

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



short factorial_limits(short n)
{
  short a = 1;
  short x{0};

  for (short i = 1; i <= n; i++)
  {

    x = a * i;
    if (a != 0 && x / a != i)
    {
      return a; //returning the largest value of n which will not overflow.
    }
    else
    {
      a *= i;
    }
  }
  return 0;
}

int factorial_limits(int n)
{
  int a = 1;
  int x{0};

  for (int i = 1; i <= n; i++)
  {
    x = a * i;
    if (a != 0 && x / a != i)
    {
      return a; //returning the largest value of n which will not overflow.
    }
    else
    {
      a *= i;
    }
  }
  return 0;
}

long factorial_limits(long n)
{
  long a = 1;
  long x{0};

  for (long i = 1; i <= 40; i++)
  {
    x = a * i;
    if (a != 0 && x / a != i)
    {
      return a; //returning the largest value of n which will not overflow.
    }
    else
    {
      a *= i;
    }
  }
  return 0;
}

long long factorial_limits(long long n)
{
  long long a = 1;
  long long x{0};

  for (long long i = 1; i <= n; i++)
  {
    x = a * i;
    if (a != 0 && x / a != i)
    {
      return a; //returning the largest value of n which will not overflow.
    }
    else
    {
      a *= i;
    }
  }
  return 0;
}