/*
Question 2 (1 point)
What is the output of the following code snippet?

int x = -1;
x &= ~2;
x ^= 9;
cout << (x >> 1) << endl;

*/
#include <iostream>
using namespace std;

int main(){
  int x = -1;
  cout << "x -> " << x << endl;
  int clear_x = x & ~1;
  cout << "x &= ~1 -> " << clear_x << endl;
  x &= ~2;
  cout << "x &= ~2 -> " << x << endl;
  x ^= 9;
  cout << (x >> 1) << endl;
/*
  1110 (-1 singed one's complement)
& 1101 (~2 number 2 (0010) after flip)
-------
  1100 (-3 signed one's complement)

*/



}


