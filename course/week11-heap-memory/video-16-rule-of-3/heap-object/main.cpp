#include "array.h"
#include <iostream>

using namespace std;

int main() {
  array a;
  cout << a << endl;
  a += 12;
  a += -5;
  cout << a << endl;
  cout << a[0]<< endl;
  a[0] = 3;
  cout << a[0]<< endl;
  cout << (a + 1) << endl;

  array b;
  b = a; // assignment operator
  cout << b << endl;
  return 0;
}