/*
Question 3 (1 point) 

How could you determine if an int x is divisible by 8? Fill in the blank:

if (           ) {
    // ...
}

Question 3 options:

~(x | 8)


!(x & 7)


(x >> 3) > 0


(x ^ 1 ^ 2 ^ 4)

*/

#include <iostream>
using namespace std;

int main(){
  int x = 24;

  cout << ~( x | 8) << endl;
  cout << !( x & 7) << endl;
  cout << (( x >> 3) > 0) << endl;
  cout << (x^1^2^4) << endl;
 return 0; 



}