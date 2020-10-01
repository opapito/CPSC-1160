# include <iostream>
using namespace std;

int main(){
  int x = 5;          // x is of type "int"
  int* y = &x;        // y is of type "pointer to int"
  *y = 7;             // changing the value of the pointed variable
  cout << x << endl;  // the value printed is the new value of x changed by *y
  return 0;
}
 