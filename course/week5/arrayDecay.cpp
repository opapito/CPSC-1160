#include <iostream>
using namespace std;


int foo(int *x) {
  return x[0] + x[1];
}

int main(){
  int z[] = {3, 4, 5};
  cout << foo(z) << endl;
  return 0;
}