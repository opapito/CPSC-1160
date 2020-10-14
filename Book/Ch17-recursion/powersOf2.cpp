/*
  17.3 Write a recursive mathematical definition for computing 2n for a positive integer n.
*/

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int exp(int n) {
  if (n == 0 ){
    return 1;
  } else {
    return 2 * exp(n - 1);
  }
}

int main (){
  int n {0};
  cout << "Type an integer to calculate 2^n:" ;
  cin>> n;
  if (!cin){
    cin.clear(); 
    cin.ignore(SSIZE_MAX, '\n');
    cout << "Invalid entry!" << endl;
  }
  cout << exp(n) << endl;

  return 0;
}