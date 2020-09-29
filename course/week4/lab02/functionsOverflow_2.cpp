/*
A program find the largest value of n which will not overflow, considering types short, int, long and long long.
Pablo Bourbom Soares

In this approach, the function names were overloaded to allowing versions for all types: short, int, long and long long.

The technique deployed consists of using a type greater than the one returned by the function to allow a comparison before the overflow occurs. Only in the SHORT version of the function, it was not necessary. In the others, it is necessary to use a type larger than the one of the function. For instance, in the INT version, one of the types was defined to LONG so that it was capable of promoting all others in the same arithmetic operation to LONG. If all types were INT, the comparison "a * i  >  n"  would overflow in the operation itself. I mean, even if the result is not assigned to a variable, the operation "a * i" overflow when "a" and "i" are INT type. So we need at least one to be of a higher type in order to be able to compare the result of the operation with "n".

*/

#include <iostream>
#include <iomanip>
#include "functions.h"
using namespace std;
//http://www.cplusplus.com/forum/beginner/40948/ 
//https://www.geeksforgeeks.org/factorial-large-number/ 


short factorial(short n)
{
  short a = 1;
  cout << "a= " << a << " SHORT LIMIT= " << n << "  short-> starting for loop..." << endl;
  for (short i = 1; i <= n; i++)
  {
    
    cout << "a= " << a << " i= " << i << endl;
  
    if ( a*i > n ){
      cout << a*i << " is greater than " << n << " when the factorial number is " << i << "\n";
      cout << "The overflow in the type short occurs from " << i - 1 << "\n";
      cout << "---------------------------------------------------------------------\n";
      break;
    } else {
      a *= i;
    }

  }
  return a;
}

int factorial(int n)
{
  long a = 1;
  
  cout << "a= " << a << " INT LIMIT= " << n <<"  int -> starting for loop..." << endl;
  for (int i = 1; i <= n; i++)
  {
   
      
    cout << "a= " << a << " i= " << i << " a * i = " << a * i <<endl;
    if ( a * i > n ){
      cout << a*i << " is greater than " << n << " when the factorial number is " << i << "\n";
      cout << "The overflow in the type int occurs from " << i - 1 << "\n";
      cout << "---------------------------------------------------------------------\n";
      break;
    } else {
      a *= i;
    }

  }
  return a;
}

long factorial(long n)
{
 double a = 1;
  cout << "a= " << a << " LONG LIMIT= " << n << "  long -> starting for loop..." << endl;
  for (long i = 1; i <= 40; i++)
  {
    
    cout << "a= " << fixed << setprecision(0) << a << " i= " << i << " a * i = " << a * i <<endl;
    if ( a*i > n ){
      cout << a*i << " is greater than " << n << " when the factorial number is " << i << "\n";
      cout << "The overflow in the type long occurs from " << i - 1 << "\n";
      cout << "---------------------------------------------------------------------\n";
      break;
    } else {
      a *= i;
    }

  }
  return a;
}

long long factorial(long long n)
{
  long double a = 1;
  cout << "a= " << a << " LONG LONG LIMIT= " << n << "  long long -> starting for loop..." << endl;
  for (long long i = 1; i <= n; i++)
  {
    
    cout << "a= " << fixed << setprecision(0)<< a << " i= " << i << " a * i = " << a * i <<endl;
    if ( a*i > n ){
      cout << a*i << " is greater than " << n << " when the factorial number is " << i << "\n";
      cout << "The overflow in the type long long occurs from " << i - 1 << "\n";
      cout << "---------------------------------------------------------------------\n";
      break;
    } else {
      a *= i;
    }

  }
  return a;
}