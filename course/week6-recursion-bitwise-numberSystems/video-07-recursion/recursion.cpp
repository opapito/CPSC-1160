/*
* recursion
* - examples of writing recursive functions;
* - NOT a demonstration of the MECHANISM of recursion (call stack)
*   - computer executes recursive function just like any other function call
* - general rules of recursion:
*   - we need at least 1 base case (where there is NO recursion)
*      - introduced by an "if" at the top of the function, usually
*   - when recursing, the "recursive parameter" must get "smaller"
      - there must be one parameter which is used in the logic of the function
      - that parameter must get closer to the base case every time we recurse
*/
#include <iostream>
using namespace std;

long long factorial (int n){
    if ( n <= 1 ){
      return 1;
    } else {
      return n * factorial(n - 1);
    }
}

long long power ( int x, unsigned int y){
  // 2^80 = (2^40)^2 = ((2^20)^2)^2
  // 2^81 = 2 * 2^80
  if (y == 0){
    return 1;
  } else if (y % 2 == 1){ // odd cases
    return x * power (x, y - 1);
  } else {
      long long half_power = power (x, y / 2);
      return half_power * half_power;
  }

}

double sum(double const *x, size_t n){
  if (n == 0) {
    return 0;
  } else {
    return x[0] + sum(&x[1], n - 1);
  }

}

bool is_palindrome(char const *x, size_t n){
  if (n <= 1) {
    return true;
  } else if (x[0] != x[n - 1]) {
    return false;
  } else {
    return is_palindrome (&x[1], n - 2);
  }

}

bool is_palindrome2(char const *x, size_t n){
  return n <= 1 || x[0] == x[n - 1] && is_palindrome (&x[1], n - 2);
}


int main(){
    //int x;
    //unsigned y;
    //cin >> x >> y;
    //cout << factorial(x) << endl;
    //cout << power(x, y) << endl;
    //double x [] = { 5, -3.5, -2, 6 };
    string x;
    cin >> x;
    cout << is_palindrome(x.c_str(), x.length()) << endl;
    //cout << sum (x, sizeof x / sizeof x[0]) << endl;
    return 0;
}