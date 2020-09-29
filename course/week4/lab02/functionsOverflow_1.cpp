#include <iostream>
#include <iomanip>
#include "functions.h"
using namespace std;
//http://www.cplusplus.com/forum/beginner/40948/ 
//https://www.geeksforgeeks.org/factorial-large-number/ 


short factorial(short n)
{
  short a = 1;
  short x{0};
  cout << "a= " << a << " SHORT LIMIT= " << n << "  short-> starting for loop..." << endl;
  for (short i = 1; i <= n; i++)
  {
    
    cout << "a= " << a << " i= " << i << endl;
    x = a * i;
    if ( a != 0 && x/a != i) {
      cout << "\nSHORT LIMIT -> overflow detected at " << i << endl;
      return a;
    }

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
  int a = 1;
  int x{0};
  cout << "a= " << a << " INT LIMIT= " << n <<"  int -> starting for loop..." << endl;
  for (int i = 1; i <= n; i++)
  {
   
    x = a * i;
    if ( a != 0 && x/a != i) {
      cout << "\nINT LIMIT -> overflow detected at " << i << endl;
      return a;
    }

    
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
 long a = 1;
 long x{0};
  
  cout << "a= " << a << " LONG LIMIT= " << n << "  long -> starting for loop..." << endl;
  for (long i = 1; i <= 40; i++)
  {
    x = a * i;
    if ( a != 0 && x/a != i) {
      cout << "\nLONG LIMIT -> overflow detected at " << i << endl;
      return a;
    }

    
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
  long long a = 1;
  long long x{0};


  cout << "a= " << a << " LONG LONG LIMIT= " << n << "  long long -> starting for loop..." << endl;
  for (long long i = 1; i <= n; i++)
  {
    x = a * i;
    if ( a != 0 && x/a != i) {
      cout << "\nLONG LONG LIMIT -> overflow detected at " << i << endl;
      return a;
    }
   
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