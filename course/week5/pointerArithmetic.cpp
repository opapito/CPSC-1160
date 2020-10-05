#include <iostream>
using namespace std;

int main(){
int x[] = { 3, 4, 5, 6, 7 };
int* y = x + 2; // y is pointing to the 5
int* z = y - 1; // z is pointer to the 4

cout << z[3] << endl; // prints out 7
  return 0;
}