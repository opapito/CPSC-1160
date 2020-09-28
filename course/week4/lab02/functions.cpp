#include <iostream>
#include "functions.h"
using namespace std;
//http://www.cplusplus.com/forum/beginner/40948/ 
//https://www.geeksforgeeks.org/factorial-large-number/ 


short factorial(short n)
{
  short a = 1;
  cout << "a= " << a << " short-> starting for loop..." << endl;
  for (short i = 1; i <= n; i++)
  {
    
    cout << "a= " << a << " i= " << i << endl;
    if ( a*a*i > n ){
      cout << a*a*i << " is greater than " << n << " when the factorial number is " << i << "\n";
      cout << "The overflow in the type short occurs from " << i - 1 << "\n";
      break;
    } else {
      a *= i;
    }

  }
  return a;
}

int factorial(int n)
{
  int a = 1;
  cout << "a= " << a << " LIMIT= " << n <<" int -> starting for loop..." << endl;
  for (int i = 1; i <= n; i++)
  {
    
    cout << "a= " << a << " i= " << i << endl;
    if ( a*a*i > n || a*a*i < 0){
      cout << a*a*i << " is greater than " << n << " when the factorial number is " << i << "\n";
      cout << "The overflow in the type int occurs from " << i - 1 << "\n";
      break;
    } else {
      a *= i;
    }

  }
  return a;
}
long factorial(long n)
{
  long a = 1;
  cout << "a= " << a << "long -> starting for loop..." << endl;
  for (long i = 1; i <= n; i++)
  {
    
    cout << "a= " << a << " i= " << i << endl;
    if ( a*a*i > n ){
      cout << a*a*i << " is greater than " << n << " when the factorial number is " << i << "\n";
      cout << "The overflow in the type long occurs from " << i - 1 << "\n";
      break;
    } else {
      a *= i;
    }

  }
  return a;
}

long long factorial(long long n)
{
  long long a = 1;
  cout << "a= " << a << "long long -> starting for loop..." << endl;
  for (long long i = 1; i <= n; i++)
  {
    
    cout << "a= " << a << " i= " << i << endl;
    if ( a*a*i > n ){
      cout << a*a*i << " is greater than " << n << " when the factorial number is " << i << "\n";
      cout << "The overflow in the type long long occurs from " << i - 1 << "\n";
      break;
    } else {
      a *= i;
    }

  }
  return a;
}