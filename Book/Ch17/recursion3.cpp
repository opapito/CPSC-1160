
/*
  17.5 Write a recursive mathematical definition for computing 1 + 2 + 3 + c + n for a positive integer
*/
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int adding(int n) {
  if (n == 0 ){
    return 0;
  } else {
    return n + adding(n - 1);
  }
}

int main (){
  int n {0};
  cout << "Type a positive integer to calculate 1 + 2 + 3 + ....+ n:" ;
  cin>> n;
  if (!cin){
    cin.clear(); 
    cin.ignore(SSIZE_MAX, '\n');
    cout << "Invalid entry!" << endl;
  }
  cout << adding(n) << endl;

  return 0;
}