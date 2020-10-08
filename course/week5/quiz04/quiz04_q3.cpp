/*
Question 3 (1 point) 

Consider the following function:

int max(int const *x) {
    if (x[0] > x[1]) return x[0];
    else return x[1];
}

And further assume there as an array defined like:

int x[] = { 5, 1, 9, 2 };

Which of the following options would print out 9?

Question 3 options:

cout << max(x + 1) << endl;


cout << max(&x[0]) << endl;


cout << max(x[2]) << endl;


cout << max(x, sizeof x / sizeof x[0]) << endl;

*/

#include <iostream>

using namespace std;

int max(int const *x) {
    if (x[0] > x[1]){
      return x[0];
    }else {
      return x[1];
    } 
}

int main(){
int arr[]{5, 1, 9, 2};
  cout << max(arr+1) << endl;
  return 0;
}