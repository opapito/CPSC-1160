
/*
  17.4 Write a recursive mathematical definition for computing xn for a positive integer n and a real number x.
*/
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int exp(int b, int n) {
  if (n == 0 ){
    return 1;
  } else {
    return b * exp(b, n - 1);
  }
}

int main (){
  int n {0}, b{0};
  cout << "Type a base b followed by the exponent n to calculate b^n:" ;
  cin>> b >> n;
  if (!cin){
    cin.clear(); 
    cin.ignore(SSIZE_MAX, '\n');
    cout << "Invalid entry!" << endl;
  }
  cout << exp(b, n) << endl;

  return 0;
}